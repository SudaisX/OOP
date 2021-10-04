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
    }
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
    void loseHealth() {
        if (health > 0)
            health--;
        if (health == 0)
            alive = false;
    }
    void gainHealth() {
        if (health < 10)
            health++;
    }
    void loseFood() {
        if (food > 0)
            food--;
        if (food == 0)
            alive = false;
    }
    void gainFood() {
        food += (4 + (rand() % 4));
    }
};

typedef const int cint;  //Google typedef to see what this means
typedef const Point cPoint;

char* CreateDungeon(int, int, Point&, Point&);            //Creates the dungeon
void Traversal(char*, Player&, cint, cint, char, bool&);  //Used for moving inside dungeon
void Combat(Player&, int);                                //Used for simulating combat
void TrapStatements();                                    //3 statements that show at random when the player activates a trap
void FoodStatements();                                    //3 statements that show at random when the player finds food
void HitStatements();                                     //3 statements that show at random when the player hits enemy
void GetHitStatements();                                  //3 statements that show at random when the player gets hit

void setDungeonSize(int* height, int* width);
void printDungeon(char* dungeon, int height, int width);

int main() {
    srand(time(0));

    int height = 0;
    int width = 0;
    setDungeonSize(&height, &width);

    Point startPoint(1, 1);
    Point exitPoint(width - 2, 1);

    char* dungeon = nullptr;
    dungeon = CreateDungeon(width, height, startPoint, exitPoint);

    Player player;
    player.x = startPoint.x;
    player.y = startPoint.y;

    cout << "Player Health: " << player.health << " | "
         << "Player Food: " << player.food << endl;
    printDungeon(dungeon, height, width);

    bool hasWon;
    char direction;
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
    } while (direction != 'X' && direction != 'x' && player.health > 0 && !hasWon);

    return 0;
}

void TrapStatements() {
    /*
    *   ADD YOUR CODE HERE AS REQUIRED
    */
}

void FoodStatements() {
    /*
    *   ADD YOUR CODE HERE AS REQUIRED
    */
}

void HitStatements() {
    /*
    *   ADD YOUR CODE HERE AS REQUIRED
    */
}

void GetHitStatements() {
    /*
    *   ADD YOUR CODE HERE AS REQUIRED
    */
}

void Traversal(char* dungeon, Player& player, cint width, cint height, char direction, bool& hasWon) {
    int currPos = player.x + player.y * width;
    int nextPos, nextX, nextY;
    if (direction == 'u') {
        nextPos = player.x + (player.y - 1) * width;
        nextX = player.x;
        nextY = player.y - 1;

    } else if (direction == 'd') {
        nextPos = player.x + (player.y + 1) * width;
        nextX = player.x;
        nextY = player.y + 1;

    } else if (direction == 'l') {
        nextPos = (player.x - 1) + player.y * width;
        nextX = player.x - 1;
        nextY = player.y;

    } else if (direction == 'r') {
        nextPos = (player.x + 1) + player.y * width;
        nextX = player.x + 1;
        nextY = player.y;
    }

    if (dungeon[nextPos] == 'W') {
        player.loseFood();
    } else if (dungeon[nextPos] == ' ') {
        player.loseFood();
        dungeon[currPos] = ' ';
        dungeon[nextPos] = 'P';
        player.x = nextX;
        player.y = nextY;
    } else if (dungeon[nextPos] == 'X') {
        player.loseFood();
        dungeon[currPos] = ' ';
        dungeon[nextPos] = 'P';
        player.x = nextX;
        player.y = nextY;
        hasWon = true;
    } else if (dungeon[nextPos] == 'E') {
        player.loseFood();
        dungeon[currPos] = ' ';
        dungeon[nextPos] = 'P';
        player.x = nextX;
        player.y = nextY;
        // Implement Combat

    } else if (dungeon[nextPos] == 'F') {
        player.loseFood();
        player.gainFood();
        dungeon[currPos] = ' ';
        dungeon[nextPos] = 'P';
        player.x = nextX;
        player.y = nextY;
        FoodStatements();

    } else if (dungeon[nextPos] == 'T') {
        player.loseFood();
        player.loseHealth();
        dungeon[currPos] = ' ';
        dungeon[nextPos] = 'P';
        player.x = nextX;
        player.y = nextY;
        TrapStatements();

    } else if (dungeon[nextPos] == 'H') {
        player.loseFood();
        player.gainHealth();
        dungeon[currPos] = ' ';
        dungeon[nextPos] = 'P';
        player.x = nextX;
        player.y = nextY;
    }

    cout << "Player Health: " << player.health << " | "
         << "Player Food: " << player.food << endl;
    printDungeon(dungeon, height, width);
}

void Combat(Player& player, int enemies) {
    /*
    *   ADD YOUR CODE HERE AS REQUIRED
    */
}

char* CreateDungeon(int width, int height, Point& ref_startPoint, Point& ref_exitPoint) {
    char* dungeon = new char[width * height];

    for (int i = 0; i < height; i++) {
        for (int j = i * width; j < (i + 1) * width; j++) {
            if (i == 0 || i == height - 1) {
                dungeon[j] = 'W';
            } else if (j == i * width || j == (i + 1) * width - 1) {
                dungeon[j] = 'W';
            } else {
                int probability = rand() % 100;
                if (probability <= 20) {
                    probability = rand() % 100;
                    if (probability >= 0 && probability < 15) {
                        dungeon[j] = 'E';
                    } else if (probability >= 15 && probability < 30) {
                        dungeon[j] = 'H';
                    } else if (probability >= 30 && probability < 45) {
                        dungeon[j] = 'T';
                    } else if (probability >= 45 && probability < 60) {
                        dungeon[j] = 'F';
                    } else {
                        dungeon[j] = 'W';
                    }
                } else {
                    dungeon[j] = ' ';
                }
            }
        }
    }

    bool player = false;
    bool exit = false;
    for (int i = 0; i < height; i++) {
        if (i != 0 && i != height - 1) {
            for (int j = i * width; j < (i + 1) * width; j++) {
                if (!player && j == i * width + 1 && dungeon[j] == ' ') {
                    int r = rand() % 2;
                    if (r == 1) {
                        dungeon[j] = 'P';
                        ref_startPoint.y = i;
                        ref_startPoint.x = (j - i * width);
                        player = true;
                    }
                }

                if (!exit && j == (i + 1) * width - 2 && dungeon[j] == ' ') {
                    int r = rand() % 2;
                    if (r == 1) {
                        dungeon[j] = 'X';
                        ref_exitPoint.y = i;
                        ref_exitPoint.x = (j - i * width);
                        exit = true;
                    }
                }
            }
        }
    }

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
    while (*width < 8) {
        cout << "Please Enter Width Size >= 8: ";
        cin >> *width;
    }

    cout << "Please Enter Height Size >= 8: ";
    cin >> *height;
    while (*height < 8) {
        cout << "Please Enter Height Size >= 8: ";
        cin >> *height;
    }
}

void printDungeon(char* dungeon, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = i * width; j < (i + 1) * width; j++) {
            cout << dungeon[j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
