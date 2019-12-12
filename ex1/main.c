#include <stdio.h>
#include <stdlib.h>

int current_up_nb = 200 ;
int current_low_nb = 1;
int saved_nb,predicted_nb ;
int game_mode ;
char current_action ;

int RandomInterval(int lower, int upper);
void ShowMenu(){
     printf("please shoose an option\n");
     printf("1 => play with computer\n");
     printf("2 => play with your peer\n");
     printf("+ => increate the predicted number \n");
     printf("- => decreate the predicted number\n");
     printf("= => congratulation you won\n");
}


int main()
{

    ShowMenu();

    scanf("%d",&game_mode);
    if (game_mode == 1){
    printf("please put a number in your mind and i will try to predict it \n");
    do {
        // make prediction
        predicted_nb = RandomInterval(current_low_nb,current_up_nb);
        printf("my prediction is %d \n",predicted_nb) ;

        // give a hint
        printf("give me a hint \n");
        scanf("%c",&current_action) ;

        // adjust for next prediction
        if(current_action == "+"){
            current_low_nb = predicted_nb ;
         }
        else if(current_action == "-"){
            current_up_nb = predicted_nb ;
        }

    }
    while(current_action != "=");
    }
    else if(game_mode == 2){
       printf("please enter the number that you wanna you peer to predict it");
       scanf("%d",&saved_nb);
        do {
        // make a prediction
        printf("please give me a prediction \n");
        scanf("%c",&predicted_nb) ;

        // adjust for next prediction
        if(predicted_nb > saved_nb ){
            current_action = "+" ;
         }
        else if(predicted_nb < saved_nb){
            current_action = "-" ;
        }
        printf("%c",current_action);
        if(predicted_nb == saved_nb){
            current_action = "=" ;
        }
    }
    while(current_action != "=");

    }
    printf("congratualtion you won")



}
int RandomInterval(int lower, int upper)
{
     int num = (rand() % (upper - lower + 1)) + lower ;
     return num ;
}
