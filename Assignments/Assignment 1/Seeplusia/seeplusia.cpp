#include "seeplusia.hpp"

#include "mover.hpp"

// Stub Functions
void checkForCrystal(string currLocation);                     // To check for Crystals at a Location
void checkForApples(string currLocation);                      // To check for Apples Bonus
void checkDirectionAndMove(string direction);                  // To move in East, West, North or South Direction
void moveTo(string direction, string location, int appleFee);  // To move to a location with all the parameters
void invalidMove();                                            // To check Invalid Move

// Crystals
int nCrystalsFound = 0;        // Initialized with 0 crystals
bool swampCrystal = false;     // Boolean Condition to check if Crystal has been found in Swamps of Despair yet
bool marshCrystal = false;     // Boolean Condition to check if Crystal has been found in Marsh of Undead yet
bool werewolfCrystal = false;  // Boolean Condition to check if Crystal has been found in Werewolf Hil yet
bool eistenCrystal = false;    // Boolean Condition to check if Crystal has been found in Eisten Tunnel yet

// Initializing Apples
int applesLeft = 20;
bool applesBonusAvailed = false;  // Initial Bonus = False if the player has not already gotten apples from the Apples Orchard

// Initializing Game State
string gameState = "Running";  // Running, Won, Lost

// Places
string wizardCastle = "Wizards's Castle";
string bridgeOfDeath = "Bridge of Death";
string enchantedForest = "Enchanted Forest";
string swampsOfDespair = "Swaps of Despair";
string ApplesOrchard = "Apples Orchard";
string wampireCove = "Wampire Cove";
string marshOfUndead = "Marsh of Undead";
string eistenTunnel = "Eisten Tunnel";
string elvinWaterfall = "Elvin Waterfall";
string werewolfHill = "Werewolf Hill";
string sandsOfQuick = "Sands of Quick";

// Initialize the starting location as Enchanted Forest
string currLocation = enchantedForest;

void makeMove(string direction) {
    if (gameState == "Running") {   // When Game is running
        if (direction == "East") {  // When Right Arrow is pressed
            // Conditions to Check where the current location is then appropriate moving function is called
            if (currLocation == enchantedForest) {
                moveTo(direction, swampsOfDespair, 1);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == bridgeOfDeath) {
                moveTo(direction, enchantedForest, 2);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == ApplesOrchard) {
                moveTo(direction, wampireCove, 1);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == wampireCove) {
                moveTo(direction, marshOfUndead, 1);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == werewolfHill) {
                moveTo(direction, sandsOfQuick, 1);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == elvinWaterfall) {
                moveTo(direction, werewolfHill, 2);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == eistenTunnel) {
                moveTo(direction, elvinWaterfall, 2);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else {
                invalidMove();  // Invalid Move if there is no valid move
            }

        } else if (direction == "West") {  //When Left Arrow is pressed
            // Conditions to Check where the current location is then appropriate moving function is called
            if (currLocation == enchantedForest) {
                moveTo(direction, bridgeOfDeath, 2);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == bridgeOfDeath) {
                if (nCrystalsFound >= 4) {               // Check if the Player has collected all 4 Crystals before moving
                    moveTo(direction, wizardCastle, 6);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
                }
            } else if (currLocation == swampsOfDespair) {
                moveTo(direction, enchantedForest, 1);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == wampireCove) {
                moveTo(direction, ApplesOrchard, 1);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == marshOfUndead) {
                moveTo(direction, wampireCove, 1);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == werewolfHill) {
                moveTo(direction, elvinWaterfall, 2);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == elvinWaterfall) {
                moveTo(direction, eistenTunnel, 2);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else {
                invalidMove();  // Invalid Move if there is no valid move
            }

        } else if (direction == "North") {  //When Up Arrow is pressed
            // Conditions to Check where the current location is then appropriate moving function is called
            if (currLocation == wampireCove) {
                moveTo(direction, enchantedForest, 3);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == werewolfHill) {
                moveTo(direction, wampireCove, 3);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == eistenTunnel) {
                if (nCrystalsFound >= 3) {                // Check if the player has collected atleast 3 crystals before moving
                    moveTo(direction, wizardCastle, 10);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
                }
            } else {
                invalidMove();  // Invalid Move if there is no valid move
            }

        } else if (direction == "South") {  //When Down Arrow is pressed
            // Conditions to Check where the current location is then appropriate moving function is called
            if (currLocation == enchantedForest) {
                moveTo(direction, wampireCove, 3);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == wampireCove) {
                moveTo(direction, werewolfHill, 3);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else if (currLocation == marshOfUndead) {
                moveTo(direction, sandsOfQuick, 1);  // (Direction, Location the Player wants to move to, Apple fee to move to that location)
            } else {
                invalidMove();  // Invalid Move if there is no valid move
            }
        }
    }
}

void moveTo(string direction, string location, int appleFee) {
    if (applesLeft >= appleFee) {                                        // Check if there are enough apples to move
        if (currLocation == eistenTunnel && location == wizardCastle) {  // Check if the player is moving to the Wizard's Castle from Eisten Tunnel
            moveNorth();                                                 // If yes then to call moveNorth() for a longer jump
        }
        checkDirectionAndMove(direction);  // Check what direction the player wants to move to and move
        applesLeft -= appleFee;            // Deduct Apple Fee
        currLocation = location;           // Set the new curLocation to the location player just moved to
        checkForCrystal(currLocation);     // Check if there are any Crystals at this location
        checkForApples(currLocation);      // Check if there are any apples at this location
    } else {                               // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;                    // If there are no apples then
        gameState = "Lost";                // The player dies of starvation and loses the game
    }
    if (currLocation == sandsOfQuick) {
        gameState = "Lost";  // If location is Sands of Quick then the player dies and loses the game
    } else if (currLocation == wizardCastle) {
        gameState = "Won";  // If the Player has reached wizard's castle and rescued then player wins
    }
}

// To move in East, West, North or South Direction
void checkDirectionAndMove(string direction) {
    if (direction == "East") {
        moveEast();
    } else if (direction == "West") {
        moveWest();
    } else if (direction == "North") {
        moveNorth();
    } else if (direction == "South") {
        moveSouth();
    }
}

// For Invalid Move
void invalidMove() {
    if (applesLeft > 1) {  // Check if the player has atleast 2 Apples for the penalty
        applesLeft--;
    } else {  // If the Player only has 1 apple then he dies after an invalid move and loses the game
        applesLeft--;
        applesLeft = 0;
        gameState = "Lost";
    }
}

// Check if there is any Crystal at the Current Location
void checkForCrystal(string currLocation) {
    if (currLocation == swampsOfDespair) {
        if (!swampCrystal) {
            nCrystalsFound++;
            swampCrystal = true;
        }
    } else if (currLocation == marshOfUndead) {
        if (!marshCrystal) {
            nCrystalsFound++;
            marshCrystal = true;
        }
    } else if (currLocation == werewolfHill) {
        if (!werewolfCrystal) {
            nCrystalsFound++;
            werewolfCrystal = true;
        }
    } else if (currLocation == eistenTunnel) {
        if (!eistenCrystal) {
            nCrystalsFound++;
            eistenCrystal = true;
        }
    }
}

// Check if there are any Apples at the Current Location
void checkForApples(string currLocation) {
    if (currLocation == ApplesOrchard) {
        if (!applesBonusAvailed) {
            applesLeft += 6;
            applesBonusAvailed = true;
        }
    }
}