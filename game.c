#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playRound()
{
    int secretNumber = (rand() % 50) + 1;
    int guess;
    int attempts = 0;

    printf("\n  I've picked a number between 1 and 50.\n");
    printf("  Can you guess it? (unlimited guesses)\n\n");

    while (1)
    {
        printf("  Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < 1 || guess > 50)
        {
            printf("  Please enter a number between 1 and 50!\n\n");
            attempts--;
        }
        else if (guess < secretNumber)
        {
            printf("  Too LOW! Go higher...\n\n");
        }
        else if (guess > secretNumber)
        {
            printf("  Too HIGH! Go lower...\n\n");
        }
        else
        {
            printf("\n  Correct! The number was %d.\n", secretNumber);
            printf("  You got it in %d guess%s!\n", attempts, attempts == 1 ? "" : "es");
            return attempts;
        }
    }
}

void displayScore(int totalRounds, int totalGuesses, int bestScore)
{
    printf("\n  --- YOUR STATS ---\n");
    printf("  Rounds played : %d\n", totalRounds);
    printf("  Total guesses : %d\n", totalGuesses);
    printf("  Average/round : %.1f\n", (float)totalGuesses / totalRounds);
    printf("  Best round    : %d guess%s\n", bestScore, bestScore == 1 ? "" : "es");
    printf("  ------------------\n");
}

int main()
{
    srand(time(NULL));

    int totalRounds = 0;
    int totalGuesses = 0;
    int bestScore = -1;
    char playAgain;

    printf("\n  === NUMBER GUESSING GAME ===\n");
    printf("  Difficulty: EASY (1-50)\n");

    do
    {
        int guesses = playRound();
        totalRounds++;
        totalGuesses += guesses;

        if (bestScore == -1 || guesses < bestScore)
        {
            bestScore = guesses;
            if (totalRounds > 1)
            {
                printf("  New best score!\n");
            }
        }

        displayScore(totalRounds, totalGuesses, bestScore);

        printf("\n  Play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\n  Thanks for playing! Final stats:\n");
    displayScore(totalRounds, totalGuesses, bestScore);
    printf(" Goodbye!\n");
    printf("Have A Good Day\n");

    return 0;
}