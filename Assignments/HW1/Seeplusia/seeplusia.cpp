#include "seeplusia.hpp"

#include "mover.hpp"

// Stub Functions
void checkForCrystal(string currLocation);
void checkForApples(string currLocation);
void checkDirectionAndMove(string direction);
void moveTo(string direction, string location, int appleFee);
void invalidMove();  // To check Invalid Move

// Crystals
int nCrystalsFound = 0;        // Initialized with 0 crystals
bool swampCrystal = false;     // Boolean Condition to check if Crystal has been found in Swamps of Despair yet
bool marshCrystal = false;     // Boolean Condition to check if Crystal has been found in Marsh of Undead yet
bool werewolfCrystal = false;  // Boolean Condition to check if Crystal has been found in Werewolf Hil yet
bool eistenCrystal = false;    // Boolean Condition to check if Crystal has been found in Eisten Tunnel yet

// Initializing Apples
int applesLeft = 20;
bool applesBonusAvailed = false;

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
                moveTo(direction, swampsOfDespair, 1);
            } else if (currLocation == bridgeOfDeath) {
                moveTo(direction, enchantedForest, 2);
            } else if (currLocation == ApplesOrchard) {
                moveTo(direction, wampireCove, 1);
            } else if (currLocation == wampireCove) {
                moveTo(direction, marshOfUndead, 1);
            } else if (currLocation == werewolfHill) {
                moveTo(direction, sandsOfQuick, 1);
            } else if (currLocation == elvinWaterfall) {
                moveTo(direction, werewolfHill, 2);
            } else if (currLocation == eistenTunnel) {
                moveTo(direction, elvinWaterfall, 2);
            } else {
                invalidMove();  // Invalid Move if there is no valid move
            }

        } else if (direction == "West") {  //When Left Arrow is pressed
            // Conditions to Check where the current location is then appropriate moving function is called
            if (currLocation == enchantedForest) {
                moveTo(direction, bridgeOfDeath, 2);
            } else if (currLocation == bridgeOfDeath) {
                if (nCrystalsFound >= 4) {
                    moveTo(direction, wizardCastle, 6);
                }
            } else if (currLocation == swampsOfDespair) {
                moveTo(direction, enchantedForest, 1);
            } else if (currLocation == wampireCove) {
                moveTo(direction, ApplesOrchard, 1);
            } else if (currLocation == marshOfUndead) {
                moveTo(direction, wampireCove, 1);
            } else if (currLocation == werewolfHill) {
                moveTo(direction, elvinWaterfall, 2);
            } else if (currLocation == elvinWaterfall) {
                moveTo(direction, eistenTunnel, 2);
            } else {
                invalidMove();  // Invalid Move if there is no valid move
            }

        } else if (direction == "North") {  //When Up Arrow is pressed
            // Conditions to Check where the current location is then appropriate moving function is called
            if (currLocation == wampireCove) {
                moveTo(direction, enchantedForest, 3);
            } else if (currLocation == werewolfHill) {
                moveTo(direction, wampireCove, 3);
            } else if (currLocation == eistenTunnel) {
                if (nCrystalsFound >= 3) {
                    moveTo(direction, wizardCastle, 10);
                }
            } else {
                invalidMove();  // Invalid Move if there is no valid move
            }

        } else if (direction == "South") {  //When Down Arrow is pressed
            // Conditions to Check where the current location is then appropriate moving function is called
            if (currLocation == enchantedForest) {
                moveTo(direction, wampireCove, 3);
            } else if (currLocation == wampireCove) {
                moveTo(direction, werewolfHill, 3);
            } else if (currLocation == marshOfUndead) {
                moveTo(direction, sandsOfQuick, 1);
            } else {
                invalidMove();  // Invalid Move if there is no valid move
            }
        }
    }
}

void moveTo(string direction, string location, int appleFee) {
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        if (currLocation == eistenTunnel && location == wizardCastle) {
            moveNorth();
        }
        checkDirectionAndMove(direction);
        applesLeft -= appleFee;
        currLocation = location;  // Set the new curLocation to the location player just moved to
        checkForCrystal(currLocation);
        checkForApples(currLocation);
    } else {  // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
    if (currLocation == sandsOfQuick) {
        gameState = "Lost";
    } else if (currLocation == wizardCastle) {
        gameState = "Won";
    }
}

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

void invalidMove() {
    if (applesLeft > 1) {  // 1 Apple for the invalid move penalty fee
        applesLeft--;
    } else {  // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft--;
        applesLeft = 0;
        gameState = "Lost";
    }
}

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

void checkForApples(string currLocation) {
    if (currLocation == ApplesOrchard) {
        if (!applesBonusAvailed) {
            applesLeft += 6;
            applesBonusAvailed = true;
        }
    }
}