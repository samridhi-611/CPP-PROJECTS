#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int maxNumber = 100; // Maximum number in the range
    srand(time(0)); // Seed the random number generator with the current time
    int targetNumber = (rand() % maxNumber) + 1; // Generate a random number between 1 and 100
    int userGuess;
    int attempts = 0;

    cout << "A random number has been generated from 1 to " << maxNumber << ". Try to guess it!" << endl;

    // Loop until the user guesses the correct number
    while (true) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess < targetNumber) {
            cout << "Your guess is less than the target number. Try again." << endl;
        } else if (userGuess > targetNumber) {
            cout << "Your guess is greater than the target number. Try again." << endl;
        } else {
            // Correct guess
            cout << "Congratulations! You've guessed the number correctly in " << attempts << " attempts!" << endl;
            break;
        }
    }

    return 0;
}
