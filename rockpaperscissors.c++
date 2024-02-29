#include <iostream>
#include <cstdlib> 
#include <ctime>   

// Define ANSI escape codes for text colors
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */

using namespace std;

void Computer(void) {
    srand(time(nullptr));
    int randomNumber = rand() % 3; 

    if (randomNumber == 0) {
        cout << "Computer chose: " << RED << "Rock" << RESET << endl;
    } else if (randomNumber == 1) {
        cout << "Computer chose: " << GREEN << "Paper" << RESET << endl;
    } else if (randomNumber == 2) {
        cout << "Computer chose: " << BLUE << "Scissors" << RESET << endl;
    }
}

int main() {
    int choice;
    string userChoice; // Define a string to store user's choice
    int pointUser = 0, pointComputer = 0; // Initialize points for user and computer

    do {
        cout << "==============================" << endl;
        cout << "          " << CYAN << "Rock Paper Scissors" << RESET << endl;
        cout << "==============================" << endl;
        cout << "GAME MENU" << endl;
        cout << "---------" << endl;
        cout << "1. " << RED << "Rock" << RESET << endl;
        cout << "2. " << GREEN << "Paper" << RESET << endl;
        cout << "3. " << BLUE << "Scissors" << RESET << endl;
        cout << "4. " << YELLOW << "Exit" << RESET << endl;
        cout << "=============" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                userChoice = "Rock";
                break;
            case 2:
                userChoice = "Paper";
                break;
            case 3:
                userChoice = "Scissors";
                break;
            case 4:
                cout << "Exiting the game." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
                continue; // Go back to the start of the loop
        }

        cout << "You chose: " << userChoice << endl;
        Computer(); 

        // Compare choices and determine the winner
        int userIndex, computerIndex;
        if (userChoice == "Rock") userIndex = 0;
        else if (userChoice == "Paper") userIndex = 1;
        else if (userChoice == "Scissors") userIndex = 2;

        if (choice != 4) {
            computerIndex = rand() % 3;
            if (userIndex == computerIndex) {
                cout << "It's a tie!" << endl;
            } else if ((userIndex == 0 && computerIndex == 2) || 
                       (userIndex == 1 && computerIndex == 0) || 
                       (userIndex == 2 && computerIndex == 1)) {
                cout << "You win!" << endl;
                ++pointUser;
            } else {
                cout << "Computer wins!" << endl;
                ++pointComputer;
            }
            cout << "User Points: " << GREEN << pointUser << RESET << ", Computer Points: " << RED << pointComputer << endl;

        }

    } while (choice != 4);// For exit the game

    return 0;
}
