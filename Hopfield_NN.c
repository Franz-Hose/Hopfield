#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int pattern[10][20][10];
int temp_input = 0;
int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(scanf("%i%i%i\n") !="---")
    while(scanf(" %i\n") != "-")
    {
        while(scanf(" %i", &temp_input) !="\n")
        {
            pattern[i][j][k] = temp_input;
            j++;
        }
        k++;
    }
    i++;

}
