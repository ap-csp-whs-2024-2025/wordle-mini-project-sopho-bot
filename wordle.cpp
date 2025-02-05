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

std::vector<int> createSecret()
{
    std::vector<int> code = {};
    int counter =0;
    while (counter<4) 
    {
        int val = rand() % 10;
        code.push_back(val); 
        counter = counter + 1;
    }
    return code;    
}

std::vector<std::string> getHint(std::vector<int> code, std::vector<int> guess)
{
    std::vector<std::string> hint = {}; // Tracks if a guess position has been matched
    int curr_index=0; 

    while(curr_index < length(guess))
    {
        if (guess[curr_index] != code[curr_index])
        {
            hint.push_back("X");
        }
        else 
        {
            hint.push_back("✧");
        }
        curr_index = curr_index + 1;
    }
 
    return hint;
}

bool winGame(std::vector<int> secret, std::vector<int> guess) 
{
    for (int counter=0; counter<4; counter++) {
        if (secret[counter] != guess[counter])
         {
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
     //std::cout << "Here is the secret code: ";
     //display(secret_code);
    
    std::vector<int> user_guess = {-1,-1,-1,-1};
    std::vector<std::string> hint = {};    // an empty list

    int secret_code_length = 4;
    int num_guesses = 0;

    std::cout << " ｡⋆୨୧˚Welcome to Number Wordle!⋆⋆୨୧˚ You have 10 guesses to figure out the 4 digit code. A letter X means INCORRECT and ✧ means CORRECT! \n";
    
    while (!winGame(secret_code, user_guess))    // while you have not won the game yet
    {
        std::cout << "\nEnter your 4 digit guess in separate rows vertically: ";
        user_guess= {};    // reset the hint for the next guess
        for (int counter = 0; counter < secret_code_length; counter = counter + 1)
        {
            int input;
            std::cin >> input;
            user_guess.push_back(input);    // can also do append(guess, input);
        }

        hint = getHint(secret_code, user_guess);
        for (const auto& h : hint) {
            std::cout << h << " " ; 
        }
        std::cout << std::endl;
        num_guesses++;

        if (num_guesses == 10)
        {
            std::cout << "You've made 10 guesses! You lost! :( The secret code was:  ";
            for (const auto& val : secret_code)
            {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
        
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
