## Features

- Random Number Generation: The game generates a random number between 1 and 100 using the C++ random library.
- Difficulty Levels:
  - Easy: 10 attempts to guess the number.
  - Medium: 5 attempts to guess the number.
  - Hard: 3 attempts to guess the number.
- Input Validation: Ensures valid inputs for difficulty level and guesses.
- Replay Option: Players can choose to play again after each game session.

## How to Play

1. **Select Difficulty Level**: When prompted, enter the desired difficulty level (1 for Easy, 2 for Medium, or 3 for Hard).
2. **Guess the Number**: Enter your guesses when prompted. The game will provide feedback on whether the guess is too high, too low, or correct.
3. **Play Again**: After the game ends, you will be asked if you want to play again. Enter 'y' or 'n' to continue or exit the game.

## Code Explanation

- **menu() Function**: Displays the welcome message and prompts the player to select the difficulty level.
- **playAgain() Function**: Asks the player if they want to play again and handles the reset or exit of the game.
- **main() Function**: The main game loop that handles random number generation, input validation, and game logic based on the selected difficulty level.

## Installation

To run the game, you need to have a C++ compiler installed. You can use any IDE or compiler, such as GCC, Clang, or Visual Studio.

1. Clone the repository or download the source code.
2. Compile the code using your preferred C++ compiler.
3. Run the executable to start the game.

## Enjoy the game and happy guessing! 🎮
