/****
 * 147 - Dollars
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 30000
long long int DP[MAX/5+1];
int L[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};

int main()
{
    int money;
    int in0, in1;
    int i, j;

    DP[0] = 1;
    for (i = 1; i <= MAX/5; i+=1)
        DP[i] = 0;

    for (i = 0; i < 11; i += 1)
    {
        for (j = L[i]; j <= MAX/5; j += 1)
        {
            DP[j] += DP[j - L[i]];
        }
    }

    while(scanf("%d.%d", &in0, &in1) != EOF)
    {
        if (in0 == 0 && in1 == 0)
            break;
        money = in0 * 20 + in1 / 5;
        printf("%3d.%02d%17lld\n", in0, in1, DP[money]);
    }

    return 0;
}
