#include <iostream>
#include <random>

using std::cin;
using std::cout;

void menu(int& difficulty)
{
    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I'm thinking of a number between 1 and 100.\n\n";

    cout << "Please select the difficulty level:\n";
    cout << "1. Easy (10 chances)\n";
    cout << "2. Medium (5 chances)\n";
    cout << "3. Hard (3 chances)\n\n";
    cout << "Enter your choice: ";
    cin >> difficulty;
}

void playAgain()
{
    std::string resetGame;
    cout << "Do you want to play again? (y/n)\n";
    cin >> resetGame;
    if (resetGame == "y" || resetGame == "Y" || resetGame == "yes" || resetGame == "YES")
        system("cls");
    else if (resetGame == "n" || resetGame == "N" || resetGame == "no" || resetGame == "NO")
        exit(1);
}

int main()
{
    bool hasFound = false;

    int difficulty, myNumber;
    
    while (true)
    {
        srand(time(0));
        int randomNumber = rand() % 101;

        menu(difficulty);

        if (difficulty == 1)
        {
            cout << "\nGreat! You have selected the Easy difficulty level.\n";
            cout << "Let's start the game!\n\n";

            for (int i = 10; i > 0; i--)
            {
                cout << "Enter your guess: ";
                cin >> myNumber;
                if (myNumber < 0)
                    cout << "\nInvalid number!\n\n";
                else if (myNumber > 100)
                    cout << "\nInvalid number!\n\n";
                else if (myNumber < randomNumber)
                    cout << "Incorrect! The number is greater than " << myNumber << ".\n\n";
                else if (myNumber > randomNumber)
                    cout << "Incorrect! The number is less than " << myNumber << ".\n\n";
                else if (myNumber == randomNumber)
                {
                    cout << "Congratulations! You guessed the correct number in " << 10 - i + 1 << " attempts.\n\n";
                    hasFound = true;
                    playAgain();
                    break;
                }
            }

            if (!hasFound)
            {
                cout << "The number was " << randomNumber << "!\n";
                playAgain();
            }
         
        }
        else if (difficulty == 2)
        {
            cout << "\nGreat! You have selected the Medium difficulty level.\n";
            cout << "Let's start the game!\n\n";

            for (int i = 5; i > 0; i--)
            {
                cout << "Enter your guess: ";
                cin >> myNumber;
                if (myNumber < 0)
                    cout << "\nInvalid number!\n\n";
                else if (myNumber > 100)
                    cout << "\nInvalid number!\n\n";
                else if (myNumber < randomNumber)
                    cout << "Incorrect! The number is greater than " << myNumber << ".\n\n";
                else if (myNumber > randomNumber)
                    cout << "Incorrect! The number is less than " << myNumber << ".\n\n";
                else if (myNumber == randomNumber)
                {
                    cout << "Congratulations! You guessed the correct number in " << 5 - i + 1 << " attempts.\n\n";
                    hasFound = true;
                    playAgain();
                    break;
                }
            }

            if (!hasFound)
            {
                cout << "The number was " << randomNumber << "!\n";
                playAgain();
            }
        }
        else if (difficulty == 3)
        {
            cout << "\nGreat! You have selected the Hard difficulty level.\n";
            cout << "Let's start the game!\n\n";

            for (int i = 3; i > 0; i--)
            {
                cout << "Enter your guess: ";
                cin >> myNumber;
                if (myNumber < 0)
                    cout << "\nInvalid number!\n\n";
                else if (myNumber > 100)
                    cout << "\nInvalid number!\n\n";
                else if (myNumber < randomNumber)
                    cout << "Incorrect! The number is greater than " << myNumber << ".\n\n";
                else if (myNumber > randomNumber)
                    cout << "Incorrect! The number is less than " << myNumber << ".\n\n";
                else if (myNumber == randomNumber)
                {
                    cout << "Congratulations! You guessed the correct number in " << 3 - i + 1 << " attempts.\n\n";
                    hasFound = true;
                    playAgain();
                    break;
                }
            }

            if (!hasFound)
            {
                cout << "The number was " << randomNumber << "!\n";
                playAgain();
            }
        }
    }
    return 0;
}

