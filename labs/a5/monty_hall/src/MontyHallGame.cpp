#include "MontyHallGame.h"
#include <algorithm>
#include <chrono>

using namespace std;

MontyHallGame::MontyHallGame() : doors(3), playerChoice(-1), revealedDoor(-1) {
    initializeRNG();
    generate();
}

void MontyHallGame::initializeRNG() {
    auto seed = chrono::system_clock::now().time_since_epoch().count();
    gen.seed(seed);
}

void MontyHallGame::generate() {
    vector<string> prizes = {"car", "goat", "goat"};
    shuffle(prizes.begin(), prizes.end(), gen);
    doors = prizes;
    playerChoice = -1;
    revealedDoor = -1;
}

bool MontyHallGame::makeChoice(int door) {
    if (door < 0 || door >= 3 || isDoorOpen(door)) {
        return false;
    }
    playerChoice = door;
    return true;
}

int MontyHallGame::revealDoor() {
    for (int i = 0; i < 3; ++i) {
        if (i != playerChoice && doors[i] == "goat") {
            revealedDoor = i;
            return i;
        }
    }
    return -1;
}

bool MontyHallGame::switchDoor() {
    if (playerChoice == -1 || revealedDoor == -1) {
        return false;
    }
    
    for (int i = 0; i < 3; ++i) {
        if (i != playerChoice && i != revealedDoor) {
            playerChoice = i;
            return true;
        }
    }
    return false;
}

bool MontyHallGame::stickWithChoice() {
    return playerChoice != -1;
}

bool MontyHallGame::hasWon() const {
    return playerChoice != -1 && doors[playerChoice] == "car";
}

string MontyHallGame::getPrize(int door) const {
    return doors[door];
}

bool MontyHallGame::isDoorOpen(int door) const {
    return door == revealedDoor;
}

void MontyHallGame::reset() {
    generate();
}