#ifndef MONTYHALLGAME_H
#define MONTYHALLGAME_H

#include <vector>
#include <random>
#include <string>

using namespace std;

class MontyHallGame {
public:
    MontyHallGame();
    void generate();  // Generate a new game scenario
    bool makeChoice(int door);  // Player makes initial choice
    int revealDoor();  // Host reveals a door with goat
    bool switchDoor();  // Switch to the other unopened door
    bool stickWithChoice();  // Stick with original choice
    bool hasWon() const;  // Check if player won
    string getPrize(int door) const;  // Get prize behind a door
    bool isDoorOpen(int door) const;  // Check if door is opened
    void reset();  // Reset game state

private:
    vector<string> doors;  // Prizes behind doors
    int playerChoice;  // Player's chosen door
    int revealedDoor;  // Door revealed by host
    mt19937 gen;  // Random number generator
    void initializeRNG();  // Initialize random number generator
};

#endif // MONTYHALLGAME_H