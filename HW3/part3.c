#include<stdio.h>
int us(int number,int us){//exponent finding function
	int i, answer = 1;
    for (i = 0; i < us; i++)
        answer = answer * number; 
    return answer;
}
int different(int a,int b){//finding a non-binary number
	int count1=0;
    int count2 =0;
    while (a != 0) {//when we get the number's mode, the counter is incremented if the remainder is not 1 or 0 .      
        if(a%10==1 || a%10==0){
            a/=10;
        }
        else{
            count1++;
            a /= 10;
        }     
    }
    while (b != 0) {
        if(b%10==1 || b%10==0){
            b/=10;
        }
        else{
            count2++;
            b /= 10;
        }           
    }
    if(count1!=0 || count2!=0){//returns an error if one of the two numbers has a number other than 1 or 0.
        return 0;  //printf("try again");
    }
    else{
        return 1;  //printf("true");
    }    
}
int length(int a,int b){
	int count1=0;
    int count2 =0;
    while (a != 0) {//we divide and find the number of digits until the number is 0.
        a /= 10;    
        ++count1;
    }
    while (b != 0) {
        b /= 10;     
        ++count2;
    }
    if(count1!=count2){//if the counter of two numbers is not equal, they are of different length.
    	return 0;
    }
    else{
    	return 1;
    }
}
int andop (int a, int b){
	int counter,temp,sum;
	int answer=0;
	int digit=0;
	counter=a;
	while (counter != 0) {//I found the number of digits.
        counter /= 10;     
        ++digit;
    }
	while(digit != 0){
		sum=a+b;
		temp = (sum/us(10,digit-1))%10;//starting with the first digit of the 2 numbers we collect, I examine each digit.
		if(temp==2)
			answer=answer+us(10,digit-1);//if there is 2 in the Digit we examined,we add the exponent of 10 to the result.
		digit--;
	}
	return answer;
}
int main(){
	int number1,number2;
	printf("Enter first integer:");
	scanf("%d",&number1);
	printf("Enter second integer:");
	scanf("%d",&number2);
	while(length(number1,number2)==0){
		printf("Integers should be same length,please enter 2 new integers.\n");
		printf("Enter first integer:");
		scanf("%d",&number1);
		printf("Enter second integer:");
		scanf("%d",&number2);
	}
	while(different(number1,number2)==0){
		printf("Integers should be binary,please enter 2 new integers.\n");
		printf("Enter first integer:");
		scanf("%d",&number1);
		printf("Enter second integer:");
		scanf("%d",&number2);
	}
	printf("%d AND %d = %d",number1,number2,andop(number1,number2));	
}
