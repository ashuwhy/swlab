#include <iostream>
#include <iomanip>
#include "MontyHallGame.h"

void playOneRound() {
    MontyHallGame game;
    int choice;
    
    std::cout << "\nWelcome to the Monty Hall Game!\n";
    std::cout << "There are three doors (0, 1, 2). Behind one is a car, behind the others are goats.\n";
    
    do {
        std::cout << "Choose a door (0-2): ";
        std::cin >> choice;
    } while (!game.makeChoice(choice));
    
    int revealed = game.revealDoor();
    std::cout << "Host opens door " << revealed << " revealing a goat!\n";
    
    char switchChoice;
    std::cout << "Would you like to switch doors? (y/n): ";
    std::cin >> switchChoice;
    
    if (switchChoice == 'y' || switchChoice == 'Y') {
        game.switchDoor();
    } else {
        game.stickWithChoice();
    }
    
    std::cout << (game.hasWon() ? "Congratulations! You won the car!\n" : "Sorry! You got a goat!\n");
}

void simulateGames() {
    const int simulations = 1000;
    int switchWins = 0, stickWins = 0;
    
    // Simulate switching strategy
    for (int i = 0; i < simulations; ++i) {
        MontyHallGame game;
        game.makeChoice(0);  // Always choose door 0 initially
        game.revealDoor();
        game.switchDoor();
        if (game.hasWon()) switchWins++;
    }
    
    // Simulate sticking strategy
    for (int i = 0; i < simulations; ++i) {
        MontyHallGame game;
        game.makeChoice(0);  // Always choose door 0 initially
        game.revealDoor();
        game.stickWithChoice();
        if (game.hasWon()) stickWins++;
    }
    
    std::cout << "\nResults after " << simulations << " simulations:\n";
    std::cout << "Switching doors wins: " << std::fixed << std::setprecision(1) 
              << (switchWins * 100.0 / simulations) << "%\n";
    std::cout << "Sticking with choice wins: " << std::fixed << std::setprecision(1) 
              << (stickWins * 100.0 / simulations) << "%\n";
}

int main() {
    playOneRound();
    simulateGames();
    return 0;
}