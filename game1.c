#include<stdio.h>
int main()
{
    int secret_number;
    int guess_number;
    secret_number = 5;
    int i;
    int guess_limit;
    guess_limit = 3;
    for(i=1;i<=guess_limit;i++){
        printf("guess number:", i);
        scanf("%d",&guess_number);
        if(guess_number==secret_number){
            printf("you won");
            break;
        }
    }
    if(guess_number!=secret_number)
    {
        printf("you lost");
    }
    return 0;
}