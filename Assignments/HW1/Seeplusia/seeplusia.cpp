#include "seeplusia.hpp"

#include "mover.hpp"

// Stub Functions
void enchantedEast();
void enchantedWest();
void enchantedSouth();
void bridgeWest();
void bridgeEast();
void swampsWest();
void wampireWest();
void wampireEast();
void wampireNorth();
void wampireSouth();
void applesOrchadEast();
void marshWest();
void marshSouth();
void sandsWest();
void sandsNorth();
void werewolfWest();
void werewolfEast();
void werewolfNorth();
void elvinEast();
void elvinWest();
void eistenNorth();
void eistenEast();

void invalidMove();
void crystalCheck(bool diamondFound);

// Crystals
int nCrystalsFound = 0;
bool swampCrystal = false;
bool marshCrystal = false;
bool werewolfCrystal = false;
bool eistenCrystal = false;

// Initializing Apples
int applesLeft = 20;

// Initializing Game State
string gameState = "Running";

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

string currLocation = enchantedForest;

void makeMove(string direction) {
    if (gameState == "Running") {
        if (direction == "East") {  //When Right Arrow is pressed
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
                invalidMove();
            }

        } else if (direction == "West") {  //When Left Arrow is pressed
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
                invalidMove();
            }

        } else if (direction == "North") {  //When Up Arrow is pressed
            if (currLocation == wampireCove) {
                wampireNorth();
            } else if (currLocation == werewolfHill) {
                werewolfNorth();
            } else if (currLocation == eistenTunnel) {
                eistenNorth();
            } else {
                invalidMove();
            }

        } else if (direction == "South") {  //When Down Arrow is pressed

            if (currLocation == enchantedForest) {
                enchantedSouth();
            } else if (currLocation == wampireCove) {
                wampireSouth();
            } else if (currLocation == marshOfUndead) {
                marshSouth();
            } else {
                invalidMove();
            }
        }
    }
}

void enchantedEast() {
    int appleFee = 1;
    if (applesLeft >= appleFee) {
        moveEast();
        // crystalCheck(swampCrystal);
        if (!swampCrystal) {
            nCrystalsFound++;
            swampCrystal = true;
        }
        applesLeft -= appleFee;
        currLocation = swampsOfDespair;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void enchantedWest() {
    int appleFee = 2;
    if (applesLeft >= appleFee) {
        moveWest();
        applesLeft -= appleFee;
        currLocation = bridgeOfDeath;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void enchantedSouth() {
    int appleFee = 3;
    if (applesLeft >= appleFee) {
        moveSouth();
        applesLeft -= appleFee;
        currLocation = wampireCove;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void bridgeWest() {
    int appleFee = 5;
    if (nCrystalsFound == 4) {
        if (applesLeft >= appleFee) {
            moveWest();
            applesLeft -= appleFee;
            currLocation = wizardCastle;
            gameState = "Won";
        } else {
            applesLeft = 0;
            gameState = "Lost";
        }
    }
}

void bridgeEast() {
    int appleFee = 2;
    if (applesLeft >= appleFee) {
        moveEast();
        applesLeft -= appleFee;
        currLocation = enchantedForest;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void swampsWest() {
    int appleFee = 1;
    if (applesLeft >= appleFee) {
        moveWest();
        applesLeft -= appleFee;
        currLocation = enchantedForest;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
};

bool applesBonusAvailed = false;
void wampireWest() {
    int appleFee = 1;
    if (applesLeft >= appleFee) {
        moveWest();
        applesLeft -= appleFee;
        if (!applesBonusAvailed) {
            applesLeft += 6;
            applesBonusAvailed = true;
        }
        currLocation = ApplesOrchard;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void wampireEast() {
    int appleFee = 1;
    if (applesLeft >= appleFee) {
        moveEast();
        applesLeft -= appleFee;
        if (!marshCrystal) {
            nCrystalsFound++;
            marshCrystal = true;
        }
        currLocation = marshOfUndead;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void wampireNorth() {
    int appleFee = 3;
    if (applesLeft >= appleFee) {
        moveNorth();
        applesLeft -= appleFee;
        currLocation = enchantedForest;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void wampireSouth() {
    int appleFee = 3;
    if (applesLeft >= appleFee) {
        moveSouth();
        applesLeft -= appleFee;
        if (!werewolfCrystal) {
            nCrystalsFound++;
            werewolfCrystal = true;
        }
        currLocation = werewolfHill;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void applesOrchadEast() {
    int appleFee = 1;
    if (applesLeft >= appleFee) {
        moveEast();
        applesLeft -= appleFee;
        currLocation = wampireCove;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void marshWest() {
    int appleFee = 1;
    if (applesLeft >= appleFee) {
        moveWest();
        applesLeft -= appleFee;
        if (!marshCrystal) {
            nCrystalsFound++;
            marshCrystal = true;
        }
        currLocation = wampireCove;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void marshSouth() {
    int appleFee = 1;
    if (applesLeft >= appleFee) {
        moveSouth();
        applesLeft -= appleFee;
        currLocation = sandsOfQuick;
        gameState = "Lost";
    }
}

void werewolfWest() {
    int appleFee = 2;
    if (applesLeft >= appleFee) {
        moveWest();
        applesLeft -= appleFee;
        currLocation = elvinWaterfall;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void werewolfEast() {
    int appleFee = 1;
    if (applesLeft >= appleFee) {
        moveEast();
        applesLeft -= appleFee;
        currLocation = sandsOfQuick;
        gameState = "Lost";
    }
}

void werewolfNorth() {
    int appleFee = 3;
    if (applesLeft >= appleFee) {
        moveNorth();
        applesLeft -= appleFee;
        currLocation = wampireCove;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void elvinEast() {
    int appleFee = 2;
    if (applesLeft >= appleFee) {
        moveEast();
        applesLeft -= appleFee;
        currLocation = werewolfHill;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void elvinWest() {
    int appleFee = 2;
    if (applesLeft >= appleFee) {
        moveWest();
        applesLeft -= appleFee;
        if (!eistenCrystal) {
            nCrystalsFound++;
            eistenCrystal = true;
        }
        currLocation = eistenTunnel;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void eistenNorth() {
    int appleFee = 10;
    if (nCrystalsFound >= 3) {
        if (applesLeft >= appleFee) {
            moveNorth();
            moveNorth();
            applesLeft -= appleFee;
            currLocation = wizardCastle;
            gameState = "Won";
        } else {
            applesLeft = 0;
            gameState = "Lost";
        }
    }
}

void eistenEast() {
    int appleFee = 2;
    if (applesLeft >= appleFee) {
        moveEast();
        applesLeft -= appleFee;
        currLocation = elvinWaterfall;
    } else {
        applesLeft = 0;
        gameState = "Lost";
    }
}

void invalidMove() {
    if (applesLeft > 1) {
        applesLeft--;
    } else {
        applesLeft--;
        applesLeft = 0;
        gameState = "Lost";
    }
}

void crystalCheck(bool crystalFound) {
    if (!crystalFound) {
        nCrystalsFound++;
        crystalFound = true;
    }
}