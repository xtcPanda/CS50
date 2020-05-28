/*
encrypt a message by replacing every letter with another letter.

the Range from a - z and from A - Z
dont care about anything else
change the char to the same char order in the normal alphabet from a - z using the key
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
output:
plaintext:  hello, world
ciphertext: jrssb, ybwsp

solution:
for to get the index of the char then take this index and get the same place from the key
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>


int main(int argc, string argv[])
{
    //checking if there is a key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //validating the key
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int argvs = strlen(argv[1]); //size
    for (int i = 0 ; i < argvs ; i++)
    {
        if (!((argv[1][i] >= 'a' || argv[1][i] >= 'A') && (argv[1][i] <= 'z' || argv[1][i] <= 'Z')))
        {
            printf("Key must only contain alphabet characters.\n");
            return 1;
        }

        int count = 0;
        for (int j = 0 ; j < argvs ; j++)
        {
            if (argv[1][j] == argv[1][i])
            {
                count++;
            }
        }
        if (count > 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }


    //getting the plaintext
    string p = get_string("plaintext: ");

    //encrypting
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //to check the index of the char
    int als = strlen(alphabet);

    //strcpy(at, from);
    //strcat(init, add);
    //strncat(dest, src, n);
    //malloc(strlen(s1) + strlen(s2) + 1); //+1 for the null-terminator
    //free(malloc's var);

    //islower(), isupper(), tolower(), toupper();


    int ts = strlen(p); //text size
    //int index; //empty var to catch the index

    //couldn't concatenate the strings in c as perfectly as i could so im just escaping it
    printf("ciphertext: ");

    for (int i = 0 ; i < ts ; i++)
    {
        //if found = false then this will print the char in p str
        bool found = false;
        for (int j = 0 ; j < als ; j++)
        {
            if (toupper(p[i]) == alphabet[j])
            {
                //index = j;
                if (islower(p[i]))
                {
                    argv[1][j] = tolower(argv[1][j]);
                }
                else
                {
                    argv[1][j] = toupper(argv[1][j]);
                }
                printf("%c", argv[1][j]);
                found = true;
                break;
            }
        }
        if (!found)
        {
            printf("%c", p[i]);
        }
    }
    //printf("ciphertext: %s\n", c);
    printf("\n");

    return 0;
}

