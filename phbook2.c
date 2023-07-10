#include<stdio.h>
int main(){
    char str[50];
    int a;
    int b;
    int d;
    char add[50];

    char strn[50];
    int ad;
    int bf;
    int dh;
    char addn[50];

    printf("welcome to phone book\n");
    printf("MENU\n");
    printf("press 1 to add new contact\n\n");
    int x;
    printf("Enter\n");
    scanf("%d",&x);
    if(x==1){
        int y;
        printf("enter the number of the contact to be added:");
        scanf("%d",&y);
        if(y==1){
            printf("------------------------------------------\n");
            printf("Name:");
            scanf("%s",&str);
            printf("Age:");
            scanf("%d",&a);
            printf("phone number:");
            scanf("%d",&b);
            printf("date of birth: using dd/mm/yyyy");
            scanf("%d",&d);
            printf("Adress:");
            scanf("%s",&add);
        }
        else if(y==2){
            printf("------------------------------------------\n");
            printf("Name:");
            scanf("%s",&str);
            printf("Age:");
            scanf("%d",&a);
            printf("phone number:");
            scanf("%d",&b);
            printf("date of birth:");
            scanf("%d",&d);
            printf("Adress:");
            scanf("%s",&add);

            printf("Name:");
            scanf("%s",&strn);
            printf("Age:");
            scanf("%d",&ad);
            printf("phone number:");
            scanf("%d",&bf);
            printf("date of birth:");
            scanf("%d",&dh);
            printf("Adress:");
            scanf("%s",&addn);
        }
        printf("press 2 to see the entered contacts:");
        printf("press 3 to exit the phone book:");
        int z;
        printf("Enter:");
        scanf("%d",&z);
        if(z==2)
        {
            int num;
            printf("enter the number of contact to be viewd:");
            scanf("%d",&num);
            if(num==1)
            {
            printf("------------------------------------------\n");
            printf("Name:");
            printf("%s",str);
            printf("Age:");
            printf("%d",a);
            printf("phone number:");
            printf("%d",b);
            printf("date of birth:");
            printf("%d",d);
            printf("Adress:");
            printf("%s",add);
            }
            else if(num==2)
           {
            printf("------------------------------------------\n");
            printf("Name:");
            printf("%s",str);
            printf("Age:");
            printf("%d",a);
            printf("phone number:");
            printf("%d",b);
            printf("date of birth:");
            printf("%d",d);
            printf("Adress:");
            printf("%s",add);

            printf("Name:");
            printf("%s",strn);
            printf("Age:");
            printf("%d",ad);
            printf("phone number:");
            printf("%d",bf);
            printf("date of birth:");
            printf("%d",dh);
            printf("Adress:");
            printf("%s",addn);
            }
        }
        else if(z==3)
        {
            printf("Are you sure you want to close the phone book\n");
            printf("press 1 for yes\n");
            printf("press 2 for no\n");
            int ans;
            printf("enter \n");
            printf("%d",&ans);
            if(ans==1){
                printf("the phone book has closed:");
                printf("Have a good day\n");
            }
            else if(ans==2){
                printf("the phone book has not closed\n");
                printf("you are continue\n");
            }
        } 
    }
    else{
        printf("in valid");
    }
    return 0;
}