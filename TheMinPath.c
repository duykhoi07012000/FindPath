#include <stdio.h>
#include <string.h>
#define MAX 1000

int arr_path[MAX][MAX] = {0};
int arr_2_factor[MAX][MAX] = {0};
int arr_min_2_factor[MAX][MAX] = {0};
int arr_5_factor[MAX][MAX] = {0};
int arr_min_5_factor[MAX][MAX] = {0};

int two_factor(int n)
{   
    int twocount = 0;
    if(n == 0)
    {
        return -1;
    }
    while (n % 2 == 0)
    {
        twocount++;
        n = n / 2;
    }
    return twocount;
}
 
int five_factor(int n)
{
    int fivecount = 0;
    if(n == 0)
    {
        return -1;
    }
    while (n % 5 == 0)
    {
        fivecount++;
        n = n / 5;
    }
    return fivecount;
}

int min(int a, int b)
{
    if(a == -1)
    {
        return b;
    }
    else if(b == -1)
    {
        return a;
    }
    else if( a <= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main(void)
{
    int T, TestCase , N, min_2_factor, min_5_factor, result;
    scanf("%d", &T);
    for(TestCase = 1; TestCase <= T; ++TestCase)
    {
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &arr_path[i][j]);
                arr_2_factor[i][j] = two_factor(arr_path[i][j]);
                arr_5_factor[i][j] = five_factor(arr_path[i][j]);
            }
        }

        // Min path 2 factor and 5 factor:
        for(int i = N - 1; i >=0; i--)
        {
            for(int j = N - 1; j >= 0; j--)
            {
                if(i == (N - 1) && j != (N -1))
                {
                    if(arr_2_factor[i][j] != -1)
                    {
                        if(arr_min_2_factor[i][j+1] != -1)
                        {
                            arr_min_2_factor[i][j] = arr_2_factor[i][j] + arr_min_2_factor[i][j+1];
                        }
                        else
                        {
                            arr_min_2_factor[i][j] = arr_2_factor[i][j];
                        }
                    }
                    else
                    {
                        arr_min_2_factor[i][j] = -1;
                    }
                    if(arr_5_factor[i][j] != -1)
                    {
                        if(arr_min_5_factor[i][j+1] != -1)
                        {
                            arr_min_5_factor[i][j] = arr_5_factor[i][j] + arr_min_5_factor[i][j+1];
                        }
                        else
                        {
                            arr_min_5_factor[i][j] = arr_5_factor[i][j];
                        }
                    }
                    else
                    {
                        arr_min_5_factor[i][j] = -1;
                    }   
                }
                else if(i != (N -1) && j == (N-1))
                {
                    if(arr_2_factor[i][j] != -1)
                    {
                        if(arr_min_2_factor[i+1][j] != -1)
                        {
                            arr_min_2_factor[i][j] = arr_2_factor[i][j] + arr_min_2_factor[i+1][j];
                        }
                        else
                        {
                            arr_min_2_factor[i][j] = arr_2_factor[i][j];
                        }
                    }
                    else
                    {
                        arr_min_2_factor[i][j] = -1;
                    }
                    if(arr_5_factor[i][j] != -1)
                    {
                        if( arr_min_5_factor[i+1][j] != -1)
                        {
                            arr_min_5_factor[i][j] = arr_5_factor[i][j] + arr_min_5_factor[i+1][j];
                        }
                        else
                        {
                           arr_min_5_factor[i][j] = arr_2_factor[i][j]; 
                        }
                    }
                    else
                    {
                        arr_min_5_factor[i][j] = -1;
                    }   
                }
                else if(i != (N - 1) && j != (N - 1))
                {
                    if(arr_2_factor[i][j] != -1)
                    {
                        arr_min_2_factor[i][j] = arr_2_factor[i][j] + min(arr_min_2_factor[i][j+1], arr_min_2_factor[i+1][j]);
                    }
                    else
                    {
                        arr_min_2_factor[i][j] = -1;
                    }
                    if(arr_5_factor[i][j] != -1)
                    {
                         arr_min_5_factor[i][j] = arr_5_factor[i][j] + min(arr_min_5_factor[i][j+1], arr_min_5_factor[i+1][j]);
                    }
                    else
                    {
                         arr_min_5_factor[i][j] = -1;
                    }
                }
                else
                {
                    arr_min_2_factor[i][j] = arr_2_factor[i][j];
                    arr_min_5_factor[i][j] = arr_5_factor[i][j];
                }
            }
        }
        // Find the min path:
        min_2_factor = arr_min_2_factor[0][0];
        min_5_factor = arr_min_5_factor[0][0];
        result = min(min_2_factor, min_5_factor);
        printf("#%d %d\n", TestCase, result);
        memset(arr_path, 0, sizeof(arr_path));
        memset(arr_2_factor, 0, sizeof(arr_2_factor));
        memset(arr_min_2_factor, 0, sizeof(arr_min_2_factor));
        memset(arr_5_factor, 0, sizeof(arr_5_factor));
        memset(arr_min_5_factor, 0, sizeof(arr_min_5_factor));
    }
    return 0;
}