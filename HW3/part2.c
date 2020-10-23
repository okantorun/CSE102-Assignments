#include<stdio.h>
#include<math.h>
int isprime (int a){
	int i,j;
	int answer=0;
	for(i=2;i<=sqrt(a);i++){
			if(a%i==0){
			answer=i;//smallest divisor
			i=a;//to get out of the loop
		}
	}
	return answer;
	
}
int main(){
	int number,i;
	printf("Please enter a integer:\n");
	scanf("%d",&number);
	for(i=2;i<number;i++){
		if(isprime(i)==0){	
			printf("\n%d is prime number\n",i);
		}
		else {			
			printf("\n%d is not a prime number,it is divedible by %d\n",i,isprime(i));
		}
	}
}