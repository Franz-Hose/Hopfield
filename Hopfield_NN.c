#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int train_pattern[10][20][10];
char temp_input = 0;
char temp_last = 0;
int start = 0;
int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    /* Training input*/
    while(start == 0)
    {
        scanf("%c", &temp_input);


        if(temp_input == '-' && temp_last != '-')
        {
            i++;
            j = 0;
            k = 0;
        }
        else if(temp_last == '-' && temp_input == '-')
        {
            break;
        }
        else if(temp_input == '.' || temp_input == '*')
        {
            train_pattern[i][j][k] = temp_input;
            j++;
        }
        else if(temp_input == '\n')
        {
            k++;
            j = 0;
        }

        temp_last = temp_input;
    }

    for(int j= 0; j<10; j++)
    {
        for(int k = 0; k<20; k++)
        {
            printf("%c", pattern[0][k][j]);
        }
        printf("\n");
    }

    /*test the new patterns*/
    while(scanf("%c", &temp_input) != EOF)
    {

    }


    return 0;
}


