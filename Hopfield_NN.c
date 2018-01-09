#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N_patt 10
#define columns 20
#define lines 10

#define n_neurons columns * lines
#define max_iter 2000

int train_pattern[N_patt][n_neurons];
int test_pattern[N_patt][n_neurons];
char temp_input = 0;
char temp_last = 0;
int start = 0;
double WEIGHTS[n_neurons][n_neurons] = {{0}};
double out[n_neurons] = {0};
int bipolarOut[n_neurons] = {0};

void make_train_bipolar()
{
    for(int i = 0; i < N_patt; i++)
    {
        for(int j= 0; j < n_neurons; j++)
        {
            if(train_pattern[i][j]== 42)
            {
                train_pattern[i][j] = 1;
            }
            else if(train_pattern[i][j] == 46)
            {
                train_pattern[i][j] = -1;
            }

        }
    }
}

void make_test_bipolar()
{
    for(int i = 0; i < N_patt; i++)
    {
        for(int j= 0; j < n_neurons; j++)
        {
            if(test_pattern[i][j]== 42)
            {
                test_pattern[i][j] = 1;
            }
            else if(test_pattern[i][j] == 46)
            {
                test_pattern[i][j] = -1;
            }

        }
    }
}

void trainingphase()
{
    for(int pattern = 0; pattern < N_patt; pattern++)
    {
        for(int i = 0; i < n_neurons; i++)
        {
            for(int j = 0; j < n_neurons; j++)
            {
                if(i == j)
                {
                    WEIGHTS[i][j] = 0;
                }
                else
                {

                    WEIGHTS[i][j] += train_pattern[pattern][i] * train_pattern[pattern][j];
                }
            }
        }
    }
}

void recovery_phase()
{
    for(int pattern = 0; pattern < N_patt; pattern++)
    {
        for(int iteration = 0; iteration < max_iter; iteration++)
        {
            int true_count = 0;
            for(int n1 = 0; n1 < n_neurons; n1++)
            {
                out[n1] = 0.0;

                for(int n2 = 0; n2 < n_neurons; n2++)
                {
                    out[n1] += WEIGHTS[n1][n2] * test_pattern[pattern][n2];

                }

                if(out[n1] >= 0)
                    bipolarOut[n1] = 1;
                else
                    bipolarOut[n1] = -1;

                if(bipolarOut[n1] == test_pattern[pattern][n1])
                    true_count++;
            }

            if(true_count == n_neurons)
                break;
            else
                for(int neuron = 0; neuron < n_neurons; neuron++)
                {
                    test_pattern[pattern][neuron] = bipolarOut[neuron];

                }
        }
    }
}

void backtransform_testset()
{
    for(int i = 0; i < N_patt; i++)
    {
        for(int j= 0; j < n_neurons; j++)
        {
            if(test_pattern[i][j] == 1)
            {
                test_pattern[i][j] = 42;
            }
            else if(test_pattern[i][j] ==-1)
            {
                test_pattern[i][j] = 46;
            }

        }
    }
}

int main()
{

    int i = 0;
    int j = 0;

    /* Training input*/
    while(start == 0)
    {
        scanf("%c", &temp_input);


        if(temp_input == '-' && temp_last != '-')
        {
            i++;
            j = 0;
        }
        else if(temp_last == '-' && temp_input == '-')
        {
            break;
        }
        else if(temp_input == '.' || temp_input == '*')
        {
            train_pattern[i][j] = temp_input;
            j++;
        }

        temp_last = temp_input;
    }
    make_train_bipolar();


    int patterncounter = 0;
    i = 0;
    j = 0;
    /*test input with new patterns*/
    while(scanf("%c", &temp_input) != EOF)
    {
        if(temp_input == '.' || temp_input == '*')
        {
            test_pattern[i][j] = temp_input;
            j++;
//            if(j == n_neurons) // Auskommentieren für test daheim
//            {
//                break;
//            }


        }
        else if(temp_input == '-' && temp_last != '-')
        {
            i++;
            j = 0;
            patterncounter++;

        }


        temp_last = temp_input;
    }
    make_test_bipolar();

    /* trainiere die Gewichte*/
    trainingphase();

    /* recover ein schlechtes pattern*/
    recovery_phase();

    backtransform_testset();

    //PRINT A PATTERN
    int columncounter = 0;
    j = 0;
    for(int i = 0; i < N_patt; i++)
    {
        for(int j = 0; j < n_neurons; j++)
        {
            printf("%c", test_pattern[i][j]);
            columncounter++;
            if(columncounter == columns)
            {
                columncounter = 0;
                printf("\n");
            }
        }
        if(i == patterncounter)
        {
            break;
        }
        printf("-\n");
    }

}
