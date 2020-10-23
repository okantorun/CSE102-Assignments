#include <stdio.h>
int main(){
  double amount,amount2;
  int select;
  printf("***** Welcome to ABC Exchange Office *****\n");
  printf("Enter your amount:\n");
  scanf("%lf",&amount);
  if(amount<0){
    printf("Please enter positive value \n" );
  }
  else{
  printf("\nPlease select your currency\n1. Turkish Lira\n2. Euro\n3. Dollar\n\n");
  scanf("%d",&select);
  switch(select){
    case 1:
    printf("You have %lf Turkish Liras\n",amount);
    printf("Choose which currency you want to convert\n");
    scanf("%lf",&amount2);
    if(amount2==1){
      printf("You have %lf Turkish Liras",amount);
    }
    else if(amount2==2){
      printf("You have %lf Euro",amount/6.69);
    }
    else if(amount2==3){
      printf("You have %lf Dollar",amount/6.14);
    }
    else{
      printf("Your selection is invalid");
    }
    break;
    case 2:
    printf("You have %lf Euro\n",amount);
    printf("Choose which currency you want to convert\n");
    scanf("%lf",&amount2);
    if(amount2==1){
      printf("You have %lf Turkish Liras",amount*6.69);
    }
    else if(amount2==2){
      printf("You have %lf Euro",amount);
    }
    else if(amount2==3){
      printf("You have %lf Dollar",amount*1.08);
    }
    else{
      printf("Your selection is invalid");
    }
    break;
    case 3:
    printf("You have %lf Dollar\n",amount);
    printf("Choose which currency you want to convert\n");
    scanf("%lf",&amount2);
    if(amount2==1){
      printf("You have %lf Turkish Liras",amount*6.14);
    }
    else if(amount2==2){
      printf("You have %lf Euro",amount*0.9);
    }
    else if(amount2==3){
      printf("You have %lf Dollar",amount);
    }
    else{
      printf("Your selection is invalid");
    }
    break;
    default:
    printf("Your selection is invalid");
  }
}

}