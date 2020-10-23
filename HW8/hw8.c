#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#define MAX_LENGTH 500

void generate_hofstadters_sequence(int *arr,int n) {
   int j;
   
   for(j=n;j<500;j++){	
       arr[j]=0;
    }
  
   if(n!=1){
      generate_hofstadters_sequence(arr,n-1);
      arr[n] = arr[n - arr[n - 1]] + arr[n - arr[n - 2]]; 	//I'm filling in the array index with recursion.
     // printf("%d\n",arr[n-1] );
    }
    else{
     
      arr[0]=1;
      arr[1]=1;
    }  
}


int find_max(int arr[], int index, int max_value){
  
  int i=0;
  int temp,j,max_index;
  arr[0]=1;
  arr[1]=1;
   if(index>=0){								//I compare it to the previous value of the array and find the max number.
        if(max_value<arr[index])
            max_value = arr[index];
  
      return find_max(arr, index-1, max_value);
    }
     
    return max_value;
}

int sum_array (int arr[]){
  int i;
  int b;
  if(arr[1]<MAX_LENGTH){
    arr[0]+=arr[arr[1]];		//I used' arr[0] ' as a sum.
    arr[1]++;					//I used' arr[1] ' as a counter.
    return  sum_array(arr); 	
  }
  else {
    arr[1]=1;	//I changed arr[0] and arr[1] to their old values.
    b=arr[0];	
    arr[0]=1;
    return b;
  }

}
double std_array (int arr[], double *mean, int n, int index){
  int a;
  int b;
  if(arr[1]<n && index==n-1){
    arr[0]+=arr[arr[1]];						//I used arr[0] as a sum again .
    arr[1]++;									//I used' arr[1] ' as a counter again.	
    return  std_array(arr,mean,n,index);

  }

  else if(arr[1] >= n && index==n-1){    
    *mean=(double)arr[0]/n;
    arr[0]=1;
    arr[1]=1;

  }

  if(index>=1){
    arr[0]+=pow(arr[index]-*mean,2);			//I used  index and n in condition expressions.

    return  std_array(arr,mean,n,index-1);
  }

  else{
    b=arr[0]+pow(1-*mean,2);
    arr[0]=1;
    arr[1]=1;
    return sqrt(b/(n-1));
  }

}
char* remove_duplicates (char* str){

  int j;
   
  if(*(str+1)=='\0'){		//I asked the string to return the next element if it was empty and I terminated the program.
    return str;
  }
 
  else if(*str==*(str+1)){
    for(j=2;j<20;j++){				//I compare the array element to the next element,and if it's the same, I shift it to the left.
      if(str[j]!='\0')
        str[j-1]=str[j];
      else{
        str[j-1]='\0';
      }
    }
    if(*str==*(str+1))
      return remove_duplicates(str);	//this recursion comes into play when there are more than one letter side by side.
  										//it repeats until I deleted it all.
  }

  str++;								//I'm going to move on to the next Index and keep checking.
  return remove_duplicates((str));
 
}



void menu(){
	int number,number2,n,array[MAX_LENGTH],max_value1,i;
	char arr[MAX_LENGTH];
	double ort;
	while(1){
		printf("Welcome to Homework 8,please choose one of the parts to continue\n------------\n");
		printf("\n1)Execute Part 1\n2)Execute Part 2\n3)Execute Part 3\n4)Exit\n");
		scanf("%d",&number);
		switch(number){
			case 1:
				while(1){
					printf("\nPlease make your choice:\n--------");
					printf("\n1)Fill Array\n2)Find Biggest Number\n3)Calculate Sum\n4)Calculate Standart Devision\n5)Exit\n");
					scanf("%d",&number2);
					switch(number2){
							case 1:
								printf("Entered a value:");
								scanf("%d",&n);
								generate_hofstadters_sequence(array,n-1);
								break;
							case 2:
								printf("\nBiggest number:%d\n\n",find_max(array,n,max_value1));
								break;
							case 3:
								printf("\nTotal is %d\n\n",sum_array(array));
								break;
							case 4:
								printf("\n\nStandard Deviation-->%.2lf\n",std_array(array,&ort,n,n-1));
								printf("Mean-->%.2lf\n\n",ort);
								break;
							case 5:
								exit(number2);
								break;
					}
				}
				break;
			case 3:
				printf("Please enter the string:");
				scanf(" %[^\t\n]s",arr);
				remove_duplicates(arr);
				printf("\nCorrect Sentence:----%s\n\n\n",arr);
				break;
			case 4:
				exit(number);


		}
	}
}

int main(){
		
	menu();

}


