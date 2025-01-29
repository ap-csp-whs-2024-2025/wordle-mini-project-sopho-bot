/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

std::vector<int> createSecret() {
    std::vector<int> secret;
    for (int i = 0; i<4; ++i) {
        secret.push_back(rand() % 10); 
    }
    return secret;    // replace this with your code
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess) {
    std::vector<std::string> hint(4, "X");
    for (int i=0; i<4; ++i) {
        if (secret[i] == guess [i]) {
            hint [i] = "O";
        }
    }

for (int i= 0; i<4; ++i) {
    if (hint[i] == "O") continue; 
    for (int j = 0; j<4; ++j) {
        if (i ! = j && guess[i] == secret [j] && hint [j] ! = "O") {
            hint [i] = "X";
            break;
        }
    }
}  

    return hint;
}

bool winGame(std::vector<int> secret, std::vector<int> guess) {
    for (int i=0; i<4; ++i) {
        if (secret[i] ! = guess[i]) {
            return false;
        }
    }
    return true;    // replace this with your code
}

int main()
{
    // Seeding the random number generator
    // Uncomment the code when you are finished testing your program
    // and want to have the program run for real
     srand(time(0));
    
    std::vector<int> secret_code = createSecret();
    std::vector<int> user_guess = {};
    std::vector<std::string> hint = {};    // an empty list

    int secret_code_length = 4;
    int num_guesses = 0;

    std::cout << "Welcome to Number Wordle!\n";
    
    while (!winGame(secret_code, user_guess))    // while you have not won the game yet
    {
        std::cout << "\nEnter your guess: ";
        hint = {};    // reset the hint for the next guess
        for (int counter = 0; counter < secret_code_length; counter = counter + 1)
        {
            int input;
            std::cin >> input;
            append (guess,input);    // can also do append(guess, input);
        }

        hint = getHint(secret_code, user_guess);
        for (const auto& h : hint) {
            std::cout << h << " " ; 
        }
        std::cout << std:endl;
        num_guesses++;
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
