#include <stdio.h>
#include <stdlib.h>
 #include <string.h>
char nb1[] ;
char nb2[] ;
int b1,b2 ;

int toDeci(char *str, int base);
char* fromDeci(int nb , int base) ;


void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}
void set_nb(char *nb,int base){
    printf("please enter the number");
    scanf("%c",&nb);
    printf("please enter his base between 2 and 10 ");
    do {
    scanf("%d",&base);
    }while(!(base >=2 || base <=10 ));
}


int main()
{
    set_nb(nb1,b1) ;
    printf("please enter the second base");
    do {

    scanf("%d",&b2);

    }while(!(b2 >=2 || b2 <=10 ));

    if(b1 == b2){
        printf("result : %c",&nb1) ;
    }else if(b2 == 10) {
        printf("result : %d",toDeci(nb1,b1));

    }else {
       int dec = toDeci(nb1,b1) ;
       printf("result : %c",fromDeci(nb1,b1));
    }


    return 0;
}
int toDeci(char *str, int base)
{
    int len = strlen(str);
    int power = 1; // Initialize power of base
    int num = 0;  // Initialize result
    int i;

    // Decimal equivalent is str[len-1]*1 +
    // str[len-1]*base + str[len-1]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        // A digit in input number must be
        // less than number's base
        if ( (int)(str[i]) >= base)
        {
           printf("Invalid Number");
           return -1;
        }

        num += (int)(str[i]) * power;
        power = power * base;
    }

    return num;
}

// Function to convert a given decimal number
// to a base 'base' and
char* fromDeci(int nb , int base)
{
    int index = 0;  // Initialize index of result
    char *res ;
    // Convert input number is given base by repeatedly
    // dividing it by base and taking remainder
    while (nb > 0)
    {
        res[index++] = (char)(nb % base);
        nb /= base;
    }
    res[index] = '\0';

    // Reverse the result
    strev(res);

    return res;
}
