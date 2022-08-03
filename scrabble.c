#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int score[1]; //score to be returned outside of for loop
int compute_score(string word); //function that caluclates score of each word
int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int w1len = strlen(word1); //calculates length of both words
    int w2len = strlen(word2);
    for (int i = 0; i < w1len; i++)
    {
        word1[i] = toupper(word1[i]); //converts both words to uppercase
    }
    for (int j = 0; j < w2len; j++)
    {
        word2[j] = toupper(word2[j]);
    }
    int score1 = compute_score(word1); //calls own function to score each word
    int score2 = compute_score(word2);
if (score1 > score2)
{
    printf("Player 1 Wins!\n");
}
else if (score2 > score1)
{
    printf("Player 2 Wins!\n");
}
else
{printf("Players tied!\n");
}
    // Prints the winner depending on higher score or tie.
}

int compute_score(string word)
{
    for (int m = 0, z = 0; m < strlen(word) && isupper(word[m]) != 0 ; m++) //score computation for each character, except non uppercase letters
    {
        int b = 0;
        int f = word[m] - 65;
        b = POINTS[f];
        z = z + b; //keeps track of point count for each iteration
        score[0] = z; //global scope needed to return score after for loop

    }
    return score[0]; 
}
