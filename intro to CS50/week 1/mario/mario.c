#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //declaring H
    int H;
    //checking the cond
    do
    {
        //user input
        H = get_int("Height: ");
    }
    while (H < 1 || H > 8);

    //drawing the shape
    // r for ROW
    for (int r = 1 ; r <= H ; r++)
    {
        // s for SPACE
        for (int s = H - r ; s >= 1 ; s--)
        {
            printf(" ");
        }
        // cl for col left
        for (int cl = 0 ; cl < r ; cl++)
        {
            printf("#");
        }

        //printing the fixed space
        printf("  ");

        // cr for col right
        for (int cr = 0 ; cr < r ; cr++)
        {
            printf("#");
        }
        //moving to the next row
        printf("\n");
    }

}