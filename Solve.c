#include <stdio.h>
#define MAX 1000000
int arr_height[MAX] = {0};

int main(void)
{
    int T, test_case, N, M, min, max, count, is_true;
    int h = 0;
    scanf("%d", &T);
    for(test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %d", &N, &M);

        for(int i = 0; i < N; i++)
        {
            scanf("%d", &arr_height[i]);
        }
        min = 0;
        // Find max height:
        max = arr_height[0];
        for(int i = 0; i < N; i++)
        {
            if(max < arr_height[i])
            {
                max = arr_height[i];
            }
        }
        // Find the height for cutting down:
        h = (min + max)/2;
        is_true = 1;
        while(is_true)
        {
            count = 0;
            for(int i = 0; i < N; i++)
            {
                if(arr_height[i] >= h)
                {
                    count += (arr_height[i] - h);
                }
            }
            if(count == M || count == 0 || ((h == min)&&(count != M)) || ((h == max)&&(count != M)))
            {
                if(count == 0 || ((h == min)&&(count != M)) || ((h == max)&&(count != M)))
                {
                    h = 0;
                }
                break;
            }
            else
            {
                if(count < M)
                {
                    h = (h + min)/2;
                }
                else
                {
                    h = (h + max)/2;
                    if(h == max-1)
                    {
                        break;
                    }
                }
                    
            }
        }
        printf("#%d %d\n", test_case, h);
    }
    return 0;
}