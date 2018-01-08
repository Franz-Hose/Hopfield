#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int train_pattern[10][20][10];
int test_pattern[10][20][10];
char temp_input = 0;
char temp_last = 0;
int start = 0;

void make_train_bipolar()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j= 0; j < 20; j++)
        {
            for(int k = 0; k<10; k++)
            {
                if(train_pattern[i][j][k] == 42)
                {
                    train_pattern[i][j][k] = 1;
                }
                else if(train_pattern[i][j][k] == 46)
                {
                    train_pattern[i][j][k] = -1;
                }
            }

        }
    }
}

void make_test_bipolar()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j= 0; j < 20; j++)
        {
            for(int k = 0; k<10; k++)
            {
                if(test_pattern[i][j][k] == 42)
                {
                    test_pattern[i][j][k] = 1;
                }
                else if(test_pattern[i][j][k] == 46)
                {
                    test_pattern[i][j][k] = -1;
                }
            }

        }
    }
}

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
    make_train_bipolar();
//  //PRINT A PATTERN
//    for(int j= 0; j<10; j++)
//    {
//        for(int k = 0; k<20; k++)
//        {
//            printf("%c", train_pattern[0][k][j]);
//        }
//        printf("\n");
//    }


    /*test input with new patterns*/
    while(scanf("%c", &temp_input) != EOF)
    {
        scanf("%c", &temp_input);


        if(temp_input == '-' && temp_last != '-')
        {
            i++;
            j = 0;
            k = 0;
        }
        else if(temp_input == '.' || temp_input == '*')
        {
            test_pattern[i][j][k] = temp_input;
            j++;
        }
        else if(temp_input == '\n')
        {
            k++;
            j = 0;
        }

        temp_last = temp_input;
    }
    make_test_bipolar();

}
