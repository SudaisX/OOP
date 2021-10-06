#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>

using namespace std;

//Structure to keep track of various locations
struct Point {
    int x;
    int y;

    Point(int _x, int _y) : x(_x), y(_y) {
    }  // What was this for?
};
//Structure for the Player object
struct Player {
    int food;
    int health;
    bool alive;
    int x;
    int y;
    Player() {
        food = 64;
        health = 10;
        alive = true;
    }
    void loseHealth() {  // Function to lose health
        if (health > 0)
            health--;
        if (health == 0)
            alive = false;
    }
    void gainHealth() {  // Function to gain health
        if (health < 10)
            health++;
    }
    void loseFood() {  // Function to lose food
        if (food > 0)
            food--;
        if (food == 0)
            alive = false;
    }
    void gainFood() {  // Function to gaid food between 4 and 8
        food += (5 + (rand() % 4));
    }
};

typedef const int cint;
typedef const Point cPoint;

char* CreateDungeon(int, int, Point&, Point&);            // Creates the dungeon
void Traversal(char*, Player&, cint, cint, char, bool&);  // Used for moving inside dungeon
void Combat(Player&, int);                                // Used for simulating combat
void TrapStatements();                                    // 3 statements that show at random when the player activates a trap
void FoodStatements();                                    // 3 statements that show at random when the player finds food
void HitStatements();                                     // 3 statements that show at random when the player hits enemy
void GetHitStatements();                                  // 3 statements that show at random when the player gets hit

void setDungeonSize(int* height, int* width);             // Collect input for dungeon size
void printDungeon(char* dungeon, int height, int width);  // Code to print the dungeon for debugging and testing. Lookup "// ENABLE FOR DEBUGGING" and uncomment those lines to use it.

int main() {
    srand(time(0));

    int height = 0;
    int width = 0;
    setDungeonSize(&height, &width);

    Point startPoint(1, 1);         // Player's default start position if the random position doesnt work
    Point exitPoint(width - 2, 1);  // Default exit  position if the random position doesnt work

    char* dungeon = nullptr;
    dungeon = CreateDungeon(width, height, startPoint, exitPoint);

    Player player;            // define player
    player.x = startPoint.x;  // initializing player's spawn x
    player.y = startPoint.y;  // initializing player's spawn x

    cout << "Player Health: " << player.health << " | "
         << "Player Food: " << player.food << endl;
    // printDungeon(dungeon, height, width);  // ENABLE FOR DEBUGGING // ENABLE THE OTHER ONE AT LINE 284 AS WELL

    cout << "After being captured by a raid of some robbers on your caravan,\n"
         << "you find yourself alone in a dark dungeon. With nothing but your\n"
         << "wits, you choose to take a step..." << endl;  // Game intro message

    bool hasWon;     // Boolean condition to keep track of if the game has been won
    char direction;  // direction character (user will input)
    do {
        cout << "In which direction do you want to move? (U,D,L,R; Press X if you want to give up and die.)" << endl;
        cin >> direction;
        switch (direction) {
            case 'U':
            case 'u':
                Traversal(dungeon, player, width, height, 'u', hasWon);
                break;
            case 'D':
            case 'd':
                Traversal(dungeon, player, width, height, 'd', hasWon);
                break;
            case 'L':
            case 'l':
                Traversal(dungeon, player, width, height, 'l', hasWon);
                break;
            case 'R':
            case 'r':
                Traversal(dungeon, player, width, height, 'r', hasWon);
                break;
            default:
                break;
        }
    } while (direction != 'X' && direction != 'x' && player.health > 0 && !hasWon && player.alive);  // exit loop if x is entered or health is 0 or the game is lost or the player died
    if (!hasWon) {
        cout << "You didn't make it. Was it hunger? Was it poor health?\n"
             << "It seems the world might never know.\n"
             << "Try living to tell the story next time, relaunch by restarting the game. :)" << endl;
    } else {
        cout << "You found the exit... You are free!" << endl;
    }
    system("pause");  // Gives you a nice "Press any key to continue . . . " message
    return 0;
}

void TrapStatements() {
    int picker = rand() % 2;  // goes from 0 to 2 (3 possibilities)
    switch (picker) {
        case 0:
            cout << "You stepped into a bear trap and got yourself injured." << endl;
            break;
        case 1:
            cout << "You walked into some spikes that sprung out of the floor." << endl;
            break;
        case 2:
            cout << "An arrow flew out of a nearby wall and hit you in your posterior. That will leave a scar!" << endl;
            break;
        default:
            cout << "Hmm... You ran into a trap alright, but it also seems our program might've run into a bug just now." << endl;  // a debug statement that should hopefully never run
            break;
    }
}

void FoodStatements() {
    int days = rand() % 5 + 4;  // goes from 0+4 to 4+4
    int picker = rand() % 2;
    cout << "You found some food that will last you for " << days << " more days." << endl;  // Also it seems this makes no difference
    switch (picker) {
        case 0:
            cout << "It is a bread roll in this dungeon? Maybe there is a secret bakery around here." << endl;
            break;
        case 1:
            cout << "You looked at the food and it was a well cooked chicken ... well at least it looked like one." << endl;
            break;
        case 2:
            cout << "It is a rat as big as a rabbit. It will go down well with a bit of wasp juice." << endl;
            break;
        default:
            cout << "Hmm... You found some food alright, but it also seems our program might've run into a bug just now." << endl;  // another debug statement that should hopefully never run
            break;
    }
}

void HitStatements() {  // for when you hit an enemy
    int picker = rand() % 2;
    switch (picker) {
        case 0:
            cout << "Your speed is unmatched and delivered a Stone Cold Stunner" << endl;
            break;
        case 1:
            cout << "Your roundhouse kick sent your enemy flying right into a gutter." << endl;
            break;
        case 2:
            cout << "You made an excellent jab that knocked the lights out of your enemy." << endl;
            break;
        default:
            cout << "Hmm... You hit the enemy alright, but it also seems our program might've run into a bug just now." << endl;  // another debug statement that should hopefully never run
            break;
    }
}

void GetHitStatements() {  // for when you get hit by an enemy
    int picker = rand() % 2;
    switch (picker) {
        case 0:
            cout << "The enemy threw a rock that hit you on the temple and shook you bad." << endl;
            break;
        case 1:
            cout << "The enemy avoided your attack and gave you a nasty scratch." << endl;
            break;
        case 2:
            cout << "You were not prepared for a sudden lunging attack that hit you hard." << endl;
            break;
        default:
            cout << "Hmm... You got hit by the enemy alright, but it also seems our program might've run into a bug just now." << endl;  // another debug statement that should hopefully never run
            break;
    }
}

void Traversal(char* dungeon, Player& player, cint width, cint height, char direction, bool& hasWon) {  // changed default parameters, instead of having a point to startPoint and exitPoint, theres a point to the player now
    int currPos = player.x + player.y * width;                                                          // Turn a 2D index into a 1D array index
    int nextPos, nextX, nextY;                                                                          // Next Position's variables
    if (direction == 'u') {
        nextPos = player.x + (player.y - 1) * width;  // Calculate next position's index in the 1D array
        nextX = player.x;
        nextY = player.y - 1;  // add -1 in the y's point to move up

    } else if (direction == 'd') {
        nextPos = player.x + (player.y + 1) * width;  // Calculate next position's index in the 1D array
        nextX = player.x;
        nextY = player.y + 1;  // add 1 in the y's point to move down

    } else if (direction == 'l') {
        nextPos = (player.x - 1) + player.y * width;  // Calculate next position's index in the 1D array
        nextX = player.x - 1;                         // add -1 in the x's point to move left
        nextY = player.y;

    } else if (direction == 'r') {
        nextPos = (player.x + 1) + player.y * width;  // Calculate next position's index in the 1D array
        nextX = player.x + 1;                         // add 1 in the x's point to move right
        nextY = player.y;
    }

    if (dungeon[nextPos] == 'W') {  // encountered_wall
        cout << "There is a wall here." << endl;
        player.loseFood();  // We felt it's more sensible for the player
                            // to not lose food, when they're not covering any distance.
                            // (Un)comment this statement to toggle between them to lose food for bumping into walls.

    } else if (dungeon[nextPos] == ' ') {
        player.loseFood();
        cout << "There is nothing here." << endl;
        dungeon[currPos] = ' ';  // Remove P from the old position
        dungeon[nextPos] = 'P';  // Add P to the new position
        player.x = nextX;        // Update the (x,y) index of the player to the newly moved position
        player.y = nextY;
    } else if (dungeon[nextPos] == 'X') {  // exit found, game won!
        player.loseFood();
        dungeon[currPos] = ' ';  // Remove P from the old position
        dungeon[nextPos] = 'P';  // Add P to the new position
        player.x = nextX;        // Update the (x,y) index of the player to the newly moved position
        player.y = nextY;
        hasWon = true;
    } else if (dungeon[nextPos] == 'E') {
        player.loseFood();
        dungeon[currPos] = ' ';  // Remove P from the old position
        dungeon[nextPos] = 'P';  // Add P to the new position
        player.x = nextX;        // Update the (x,y) index of the player to the newly moved position
        player.y = nextY;
        int noOfEnemies = (rand() % 3) + 2;  // probability ranges from 0+2 to 2+2 (i.e. 2 to 4)
        Combat(player, noOfEnemies);         // Initiate fight with number_of_enemies

    } else if (dungeon[nextPos] == 'F') {  // Food found
        player.loseFood();
        player.gainFood();
        dungeon[currPos] = ' ';  // Remove P from the old position
        dungeon[nextPos] = 'P';  // Add P to the new position
        player.x = nextX;        // Update the (x,y) index of the player to the newly moved position
        player.y = nextY;
        FoodStatements();

    } else if (dungeon[nextPos] == 'T') {  // Trap found
        player.loseFood();
        player.loseHealth();
        dungeon[currPos] = ' ';  // Remove P from the old position
        dungeon[nextPos] = 'P';  // Add P to the new position
        player.x = nextX;        // Update the (x,y) index of the player to the newly moved position
        player.y = nextY;
        TrapStatements();

    } else if (dungeon[nextPos] == 'H') {
        player.loseFood();
        cout << "You found some health." << endl;
        player.gainHealth();
        cout << "Your current health is: " << player.health << endl;
        dungeon[currPos] = ' ';  // Remove P from the old position
        dungeon[nextPos] = 'P';  // Add P to the new position
        player.x = nextX;        // Update the (x,y) index of the player to the newly moved position
        player.y = nextY;
    }

    cout << "Player Health: " << player.health << " | "
         << "Player Food: " << player.food << endl;
    // printDungeon(dungeon, height, width);  // ENABLE FOR DEBUGGING
}

void Combat(Player& player, int enemies) {  // used for simulating combat
    cout << "You came across " << enemies << ". You will have to fight!" << endl;
    int attac_probability;
    int defend_probability;
    while (enemies > 0) {
        for (int enemy = 0; enemy < enemies; enemy++) {
            defend_probability = rand() % 100;  // probability from 0 to 99
            if (defend_probability < 10) {      // defend probability from 0 to 9
                GetHitStatements();
                cout << "You lost 1 health." << endl;
                player.loseHealth();
            }
        }
        attac_probability = rand() % 100;  // probability from 0 to 99
        if (attac_probability <= 30) {     // Each fighter goes turn by turn;
                                           // to give the player the ability to attack
                                           // after each enemy attempts to attack,
                                           // move this if block within the while loop.
            HitStatements();
            enemies--;
            cout << "You killed one enemy!" << endl;
        }
    }
}

char* CreateDungeon(int width, int height, Point& ref_startPoint, Point& ref_exitPoint) {
    char* dungeon = new char[width * height];  // Create a new dungeon of size w*h

    for (int i = 0; i < height; i++) {
        for (int j = i * width; j < (i + 1) * width; j++) {
            if (i == 0 || i == height - 1) {  // Add a Wall at the borders
                dungeon[j] = 'W';
            } else if (j == i * width || j == (i + 1) * width - 1) {
                dungeon[j] = 'W';
            } else {  // If not at border then add other items
                int probability = rand() % 100;
                if (probability < 20) {  // if probability is from 0 to 19 (chance of 20 out of 100)
                    probability = rand() % 100;
                    if (probability >= 0 && probability < 15) {
                        dungeon[j] = 'E';  // Add Enemy
                    } else if (probability >= 15 && probability < 30) {
                        dungeon[j] = 'H';  // Add Health
                    } else if (probability >= 30 && probability < 45) {
                        dungeon[j] = 'T';  // Add Trap
                    } else if (probability >= 45 && probability < 60) {
                        dungeon[j] = 'F';  // Add Food
                    } else {
                        dungeon[j] = 'W';  // Add Wall
                    }
                } else {
                    dungeon[j] = ' ';  // Empty Space for the place to move
                }
            }
        }
    }

    bool player = false;  // Boolean condition to check if the player has been added to the map
    bool exit = false;    // Boolean condition to check if the exit has been added to the map
    for (int i = 0; i < height; i++) {
        if (i != 0 && i != height - 1) {
            for (int j = i * width; j < (i + 1) * width; j++) {
                if (!player && j == i * width + 1 && dungeon[j] == ' ') {
                    int r = rand() % 2;
                    if (r == 1) {  // Add P randomly to the left side beside the wall
                        dungeon[j] = 'P';
                        ref_startPoint.y = i;  // Update Start Point via pointer
                        ref_startPoint.x = (j - i * width);
                        player = true;
                    }
                }

                if (!exit && j == (i + 1) * width - 2 && dungeon[j] == ' ') {
                    int r = rand() % 2;
                    if (r == 1) {
                        dungeon[j] = 'X';     // Add X randomly to the right side beside the wall
                        ref_exitPoint.y = i;  // Update Exit Point via pointer
                        ref_exitPoint.x = (j - i * width);
                        exit = true;
                    }
                }
            }
        }
    }

    // Check if the Player or Exit has not already been randomly added then add them and update their Start and Exit point via the pointer
    if (!player) {
        dungeon[ref_startPoint.x + ref_startPoint.y * width] = 'P';
        player = true;
    }
    if (!exit) {
        dungeon[ref_exitPoint.x + ref_exitPoint.y * width] = 'X';
    }

    return dungeon;
}

void setDungeonSize(int* height, int* width) {
    cout << "Please Enter a Grid size no less than 8x8." << endl;

    cout << "Please Enter Width Size >= 8: ";
    cin >> *width;
    // int num; // The commented lines in this block are a potential
    // fix for when a value other than an integer is entered.
    // It hasn't been implemented because of stability reasons
    // and because the example we got didn't have it,
    // and because the fix isn't as simple as it would be in Python.
    // Ver2.0 of the game may feature this change.
    while (*width < 8 /*&& !(cin >> num)*/) {
        cout << "Please Enter Width Size >= 8: ";
        // Clear input stream
        // cin.clear();
        cin >> *width;
        // Discard previous input
        // cin.ignore(123, '\n');
    }

    cout << "Please Enter Height Size >= 8: ";
    cin >> *height;
    while (*height < 8) {
        cout << "Please Enter Height Size >= 8: ";
        cin >> *height;
    }
}

// Function to print/display the dungeon
void printDungeon(char* dungeon, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = i * width; j < (i + 1) * width; j++) {
            cout << dungeon[j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}