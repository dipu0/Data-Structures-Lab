#include<stdio.h>
#include<time.h>

int main()
{
    unsigned long int n;
    unsigned long int i,j,count=0;
    printf("Enter: ");
    scanf("%lu",&n);

    int Prime_List[n];

    clock_t start = clock();
    for(i = 2; i<=n+1; i++)

        Prime_List[i] = i;

    for(i=2; i*i<=n; i++)
    {
        if (Prime_List[i] != 0)
        {
            for(j=i; j<n; j++)
            {
                if (Prime_List[i]*j > n)
                    break;
                else
                    Prime_List[i*j]=0;
            }
        }
    }
    clock_t end = clock();

    for(i = 2; i<=n; i++)
    {

        if (Prime_List[i]!=0)
            count++;
    }

    printf("Number of primes %lu \n",count);
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.5f",seconds);

    return 0;


}
