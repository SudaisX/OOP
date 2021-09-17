#include "seeplusia.hpp"

#include "mover.hpp"

// Stub Functions
void enchantedEast();     // To move to the East of Enchanted Forest
void enchantedWest();     // To move to the West of Enchanted Forest
void enchantedSouth();    // To move to the South of Enchanted Forest
void bridgeWest();        // To move to the West of Bridge of Death
void bridgeEast();        // To move to the East of Bridge of Death
void swampsWest();        // To move to the West of Swamps of Despair
void wampireWest();       // To move to the West of Wampire Cove
void wampireEast();       // To move to the East of Wampire Cove
void wampireNorth();      // To move to the North of Wampire Cove
void wampireSouth();      // To move to the South of Wampire Cove
void applesOrchadEast();  // To move to the East of Apples Orchard
void marshWest();         // To move to the West of Marsh of Undead
void marshSouth();        // To move to the South of Marsh of Undead
void werewolfWest();      // To move to the West of Werewolf Hil
void werewolfEast();      // To move to the East of Werewolf Hil
void werewolfNorth();     // To move to the North of Werewolf Hil
void elvinEast();         // To move to the East of Elvin Waterfall
void elvinWest();         // To move to the West of Elvin Waterfall
void eistenNorth();       // To move to the North of Eisten Tunnel
void eistenEast();        // To move to the East of Eisten Tunnel
void invalidMove();       // To check Invalid Move

// Crystals
int nCrystalsFound = 0;        // Initialized with 0 crystals
bool swampCrystal = false;     // Boolean Condition to check if Crystal has been found in Swamps of Despair yet
bool marshCrystal = false;     // Boolean Condition to check if Crystal has been found in Marsh of Undead yet
bool werewolfCrystal = false;  // Boolean Condition to check if Crystal has been found in Werewolf Hil yet
bool eistenCrystal = false;    // Boolean Condition to check if Crystal has been found in Eisten Tunnel yet

// Initializing Apples
int applesLeft = 20;

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
                enchantedEast();
            } else if (currLocation == bridgeOfDeath) {
                bridgeEast();
            } else if (currLocation == ApplesOrchard) {
                applesOrchadEast();
            } else if (currLocation == wampireCove) {
                wampireEast();
            } else if (currLocation == werewolfHill) {
                werewolfEast();
            } else if (currLocation == elvinWaterfall) {
                elvinEast();
            } else if (currLocation == eistenTunnel) {
                eistenEast();
            } else {
                invalidMove();  // Invalid Move if there is no valid move
            }

        } else if (direction == "West") {  //When Left Arrow is pressed
            // Conditions to Check where the current location is then appropriate moving function is called
            if (currLocation == enchantedForest) {
                enchantedWest();
            } else if (currLocation == bridgeOfDeath) {
                bridgeWest();
            } else if (currLocation == swampsOfDespair) {
                swampsWest();
            } else if (currLocation == wampireCove) {
                wampireWest();
            } else if (currLocation == marshOfUndead) {
                marshWest();
            } else if (currLocation == werewolfHill) {
                werewolfWest();
            } else if (currLocation == elvinWaterfall) {
                elvinWest();
            } else {
                invalidMove();  // Invalid Move if there is no valid move
            }

        } else if (direction == "North") {  //When Up Arrow is pressed
            // Conditions to Check where the current location is then appropriate moving function is called
            if (currLocation == wampireCove) {
                wampireNorth();
            } else if (currLocation == werewolfHill) {
                werewolfNorth();
            } else if (currLocation == eistenTunnel) {
                eistenNorth();
            } else {
                invalidMove();  // Invalid Move if there is no valid move
            }

        } else if (direction == "South") {  //When Down Arrow is pressed
            // Conditions to Check where the current location is then appropriate moving function is called
            if (currLocation == enchantedForest) {
                enchantedSouth();
            } else if (currLocation == wampireCove) {
                wampireSouth();
            } else if (currLocation == marshOfUndead) {
                marshSouth();
            } else {
                invalidMove();  // Invalid Move if there is no valid move
            }
        }
    }
}

void enchantedEast() {
    int appleFee = 1;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveEast();
        if (!swampCrystal) {  // Check if the Crystal has already been found here, if not then add 1 to the total crystal count and set the crystal's boolean condition to true
            nCrystalsFound++;
            swampCrystal = true;
        }
        applesLeft -= appleFee;
        currLocation = swampsOfDespair;  // Set the new curLocation to the location player just moved to
    } else {                             // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void enchantedWest() {
    int appleFee = 2;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveWest();
        applesLeft -= appleFee;
        currLocation = bridgeOfDeath;  // Set the new curLocation to the location player just moved to
    } else {                           // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void enchantedSouth() {
    int appleFee = 3;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveSouth();
        applesLeft -= appleFee;
        currLocation = wampireCove;  // Set the new curLocation to the location player just moved to
    } else {                         // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void bridgeWest() {
    int appleFee = 5;  // Apple fee to move to a location
    if (nCrystalsFound == 4) {
        if (applesLeft >= appleFee) {  // Check if there are enough apples to move
            moveWest();
            applesLeft -= appleFee;
            currLocation = wizardCastle;  // Set the new curLocation to the location player just moved to
            gameState = "Won";
        } else {  // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
            applesLeft = 0;
            gameState = "Lost";
        }
    }
}

void bridgeEast() {
    int appleFee = 2;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveEast();
        applesLeft -= appleFee;
        currLocation = enchantedForest;  // Set the new curLocation to the location player just moved to
    } else {                             // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void swampsWest() {
    int appleFee = 1;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveWest();
        applesLeft -= appleFee;
        currLocation = enchantedForest;  // Set the new curLocation to the location player just moved to
    } else {                             // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
};

bool applesBonusAvailed = false;
void wampireWest() {
    int appleFee = 1;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveWest();
        applesLeft -= appleFee;
        // Check if the Apples bonus has already been availed, if not then add 6 apples
        if (!applesBonusAvailed) {
            applesLeft += 6;
            applesBonusAvailed = true;
        }
        currLocation = ApplesOrchard;  // Set the new curLocation to the location player just moved to
    } else {                           // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void wampireEast() {
    int appleFee = 1;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveEast();
        applesLeft -= appleFee;
        if (!marshCrystal) {  // Check if the Crystal has already been found here, if not then add 1 to the total crystal count and set the crystal's boolean condition to true
            nCrystalsFound++;
            marshCrystal = true;
        }
        currLocation = marshOfUndead;  // Set the new curLocation to the location player just moved to
    } else {                           // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void wampireNorth() {
    int appleFee = 3;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveNorth();
        applesLeft -= appleFee;
        currLocation = enchantedForest;  // Set the new curLocation to the location player just moved to
    } else {                             // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void wampireSouth() {
    int appleFee = 3;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveSouth();
        applesLeft -= appleFee;
        if (!werewolfCrystal) {  // Check if the Crystal has already been found here, if not then add 1 to the total crystal count and set the crystal's boolean condition to true
            nCrystalsFound++;
            werewolfCrystal = true;
        }
        currLocation = werewolfHill;  // Set the new curLocation to the location player just moved to
    } else {                          // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void applesOrchadEast() {
    int appleFee = 1;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveEast();
        applesLeft -= appleFee;
        currLocation = wampireCove;  // Set the new curLocation to the location player just moved to
    } else {                         // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void marshWest() {
    int appleFee = 1;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveWest();
        applesLeft -= appleFee;
        if (!marshCrystal) {  // Check if the Crystal has already been found here, if not then add 1 to the total crystal count and set the crystal's boolean condition to true
            nCrystalsFound++;
            marshCrystal = true;
        }
        currLocation = wampireCove;  // Set the new curLocation to the location player just moved to
    } else {                         // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void marshSouth() {
    int appleFee = 1;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveSouth();
        applesLeft -= appleFee;
        currLocation = sandsOfQuick;  // Set the new curLocation to the location player just moved to
        gameState = "Lost";
    }
}

void werewolfWest() {
    int appleFee = 2;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveWest();
        applesLeft -= appleFee;
        currLocation = elvinWaterfall;  // Set the new curLocation to the location player just moved to
    } else {                            // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void werewolfEast() {
    int appleFee = 1;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveEast();
        applesLeft -= appleFee;
        currLocation = sandsOfQuick;  // Set the new curLocation to the location player just moved to
        gameState = "Lost";
    }
}

void werewolfNorth() {
    int appleFee = 3;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveNorth();
        applesLeft -= appleFee;
        currLocation = wampireCove;  // Set the new curLocation to the location player just moved to
    } else {                         // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void elvinEast() {
    int appleFee = 2;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveEast();
        applesLeft -= appleFee;
        currLocation = werewolfHill;  // Set the new curLocation to the location player just moved to
    } else {                          // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void elvinWest() {
    int appleFee = 2;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveWest();
        applesLeft -= appleFee;
        if (!eistenCrystal) {  // Check if the Crystal has already been found here, if not then add 1 to the total crystal count and set the crystal's boolean condition to true
            nCrystalsFound++;
            eistenCrystal = true;
        }
        currLocation = eistenTunnel;  // Set the new curLocation to the location player just moved to
    } else {                          // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
    }
}

void eistenNorth() {
    int appleFee = 10;  // Apple fee to move to a location
    if (nCrystalsFound >= 3) {
        if (applesLeft >= appleFee) {  // Check if there are enough apples to move
            moveNorth();
            moveNorth();
            applesLeft -= appleFee;
            currLocation = wizardCastle;  // Set the new curLocation to the location player just moved to
            gameState = "Won";
        } else {  // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
            applesLeft = 0;
            gameState = "Lost";
        }
    }
}

void eistenEast() {
    int appleFee = 2;              // Apple fee to move to a location
    if (applesLeft >= appleFee) {  // Check if there are enough apples to move
        moveEast();
        applesLeft -= appleFee;
        currLocation = elvinWaterfall;  // Set the new curLocation to the location player just moved to
    } else {                            // If you have no apples or dont have enough apples to move then you die of starvation and game is lost
        applesLeft = 0;
        gameState = "Lost";
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