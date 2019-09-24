#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Greet and explain story to the user.
    std::cout << "\n\nYou are trying to hack into your work's level " << Difficulty;
    std::cout << " server so you can increase your salary.\nOne wrong guess and you're out.";
    std::cout << "\nEnter the correct codes to continue.\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    // declare and initialize variables
    const int CodeA = (rand() % Difficulty) + Difficulty;
    const int CodeB = (rand() % Difficulty) + Difficulty;
    const int CodeC = (rand() % Difficulty) + Difficulty;

    // calculate the sum and product of the variables
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // print the sum and product to the terminal.
    std::cout << "+ There are 3 numbers in the code.";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to: " << CodeProduct << std::endl;

    // Store player guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou extracted a file, on to the next level.";
        return true;
    }
    else 
    {
        std::cout << "You weren't able to steal a raise, GTFO before they find you.\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    // Loop game until all levels are cleared
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();   // clears any errors in cin
        std::cin.ignore();  // discards the buffer in cin

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        else
        {
            return 0;
        }
        
    }  

    std::cout << "\nCongratulations, you hacked into your server and stole $1M.\n";

    return 0;
}