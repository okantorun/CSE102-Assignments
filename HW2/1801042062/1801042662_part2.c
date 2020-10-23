#include <stdio.h>
#include <math.h>
int number_length(int number){
	int sonuc;
	if(number==0){
		return 1;
	}
	else if(number>999999 || number<0){
		return 0;
	}
	else{
	sonuc=log10(number)+1;
	return sonuc;
}
}
/*My algorithm ;takes the mode of the number according to the index value 
I enter and I find the number in that digit.
I did this for each of the digits steps.
*/
int find_digit(int number, int index){
	if(number_length(number)==0){//TRY AGAİN
		return 0;
	}
	else if(number<10){
		return number;
	}
	else if(10<=number && number<100){
		if(index%2==0){
			return number%10;
		}
		else{
			return (number-number%10)/10;
		}
	}
	
	else if(100<number && number<1000){
		if(index%3==0){
			return number%10;
		}
		else if(index%3==2){
			return ((number%100)-(number%10))/10;
		}
		else if(index%3==1){
			return (number-(number%100)+(number%10))/100;
		}
	}

	 else if(1000<=number && number<10000){
		if(index%4==0){
			return number%10;
		}
		if(index%4==3){
			return ((number%100)-(number%10))/10;
		}
		else if(index%4==2){
			return ((number%1000)-(number%100))/100;
		}
		else if(index%4==1){
			return (number-(number%1000))/1000;
		}

	}
	
	else if(10000<=number && number<100000){
		if(index%5==0){
			return number%10;
		}
		else if(index%5==4){
			return ((number%100)-(number%10))/10;
		}
		else if(index%5==3){
			return ((number%1000)-(number%100))/100;
		}
		else if(index%5==2){
			return ((number%10000)-(number%1000))/1000;
		}
		else if(index%5==1){
			return (number-(number%10000))/10000;
		}

	}
	else if(100000<=number && number<1000000){
		if(index%6==0){
			return number%10;
		}
		else if(index%6==5){
			return ((number%100)-(number%10))/10;
		}
		else if(index%6==4){
			return ((number%1000)-(number%100))/100;
		}
		else if(index%6==3){
			return ((number%10000)-(number%1000))/1000;
		}
		else if(index%6==2){
			return ((number%100000)-(number%10000))/10000;
		}
		else if(index%6==1){
			return (number-(number%100000))/100000;
		}

	}
}
int main(){
	int a,i;
	printf("Enter a number(Max 6 digits)\n");
	scanf("%d",&a);
	//----- NUMBER LENGTH -----
	if(number_length(a)==0){
		printf("Please enter a maximum 6-digit number and positive number");
	}
	else if(number_length(a)==1){
		printf("your number has 1 digits");
	}
	else {
		printf("your number has %d digits",number_length(a));
	}
	//-------FİND DİGİT-------------
	if(find_digit(a,i)==0){
		printf("\nTry Again\n");
	}
	else{
	printf("\nWhen your number is written 100 times next to each other, which digit of this number would you like to see ?:\n");
	scanf("%d",&i);
	printf("\n%d.th digit of the big number sequence : %d\n",i,find_digit(a,i));
}
}
