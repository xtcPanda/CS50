#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cs50.h>

/*
the Coleman-Liau index : index = 0.0588 * L - 0.296 * S - 15.8
L is the average number of letters per 100 words in the text
S is the average number of sentences per 100 words in the text

rounded

must prompt the user for a string of text (using get_string("Text: ")).

Your program should count the number of letters, words, and sentences in the text.
You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z,
any sequence of characters separated by spaces should count as a word, and that any occurrence of a period,
exclamation point, or question mark indicates the end of a sentence.

Your program should print as output "Grade X"

16 or higher output "Grade 16+"
less than 1 output "Before Grade 1"
*/

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);



int main(void)
{
    string txt = get_string("Text: ");
    // 100 * result
    float L = 100 * ((float) count_letters(txt) / (float) count_words(txt));
    float S = 100 * ((float) count_sentences(txt) / (float) count_words(txt));
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 16 && index >= 0)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }


}



int count_letters(string text)
{
    int s = strlen(text), count = 0;
    for (int i = 0 ; i < s ; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int s = strlen(text), count = 0;
    for (int i = 0 ; i < s ; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    //+1 for the last word
    return count + 1;
}

int count_sentences(string text)
{
    int s = strlen(text), count = 0;
    for (int i = 0 ; i < s ; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
