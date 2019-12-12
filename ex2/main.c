#include <stdio.h>
#include <stdlib.h>
int A , B , n ;
int factorial(int n);
float binomial(int A, int B, int n) ;

int main()
{
    printf("please enter A : \n");
    scanf("%d",&A);
    printf("please enter B : \n");
    scanf("%d",&B);
    printf("please enter n : \n");
    scanf("%d",&n);
    printf("%f",binomial(A, B, n));
    return 0;
}
int factorial(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
float binomial(int A, int B, int n)
{
    int nFact = factorial(n);
    float sum = 0 ;


    for (int i = 0; i < n + 1; i++) {


        int niFact = factorial(n - i);
        int iFact = factorial(i);

        int aPow = pow(A, n - i);
        int bPow = pow(B, i);


        sum += (nFact * aPow * bPow) / (niFact * iFact) ;
    }
    return sum ;
}
