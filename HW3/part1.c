#include<stdio.h>
int sum (int n ,int flag){
	int i;
	int count=0;
	if(flag==1){
		for(i=1;i<=n;i++){
			if(i%2==1){
				count=count+i;
			}
		}
		return count;
	}
	else if(flag==0){
		for(i=1;i<=n;i++){
			if(i%2==0){
				count=count+i;
			}
	    }
		return count;

	}
	else{
		return 2;
	}
}
int mult (int n,int flag){
	int i;
	int count=1;
	if(flag==1){
		for(i=1;i<=n;i++){
			if(i%2==1){
				count=count*i;
			}
		}
		return count;
	}
	else if(flag==0){
		for(i=1;i<=n;i++){
			if(i%2==0){
				count=count*i;
			}
		}
		return count;
	}
	else{
		return 2;
	}



 }

int main(){
	int number,number1,number2;
	int j=0;
	printf("Please enter a integer:\n");
	scanf("%d",&number);
	printf("\nPlease enter '0' for sum,'1' for multiplication:");
	scanf("%d",&number1);
	printf("\nPlease enter '0' to work on even numbers,'1' to work on odd numbers:");
	scanf("%d",&number2);
	switch(number1){
		case 0:
			if(number2==0){
				for(j=1;j<=number;j++){
					if(j%2==0 && (j==number-1))//I made a condition not to put an operator after the last number.
						printf("%d",j);	
					else if(j==number && j%2==0)
						printf("%d",j);	
					else if(j%2==0)
						printf("%d +",j);
				}
				printf(" = %d",sum(number,number2));
			}	
			else if(number2==1){
				for(j=1;j<=number;j++){
					if(j%2==1 && (j==number-1))
						printf("%d",j);	
					else if(j==number && j%2==1)
						printf("%d",j);	
					else if(j%2==1)
						printf("%d +",j);
			  	}
				printf(" = %d",sum(number,number2));
			}
			else{
				printf("İnvalid value for odd/even selection.\n");
			}
			break;

		case 1:
			if(number2==0){
				for(j=1;j<=number;j++){
					if(j%2==0 && (j==number-1))
						printf("%d",j);	
					else if(j==number && j%2==0)
						printf("%d",j);	
					else if(j%2==0)
			    		printf("%d *",j); 
		   		}
		   		printf(" = %d",mult(number,number2));
		 	}
		    else if(number2==1){
				for(j=1;j<=number;j++){
					if(j%2==1 && (j==number-1))
						printf("%d",j);
					else if(j==number && j%2==1)
						printf("%d",j);	
					else if(j%2==1)
				    	printf("%d *",j);
				}
			 	printf(" = %d",mult(number,number2));
			}
			else{
				printf("İnvalid value for odd/even selection.\n");
			}

			break;
		default :
			printf("Unsported operation");
	}
}