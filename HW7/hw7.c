#include<stdio.h>
#include <stdlib.h>//These three libraries. I used it for the random values.
#include <time.h>
#include<string.h>
#define max_value 2001			//total number of games
void line(char text[max_value][200]){			//I read the text in the file into the array.
	int i=0,j=0;
	char a;
	FILE*fp;
	fp=fopen("Video_Games.txt","r");
	while(i<2001){
		fgets(text[i],200,fp);
		i++;
	}
	
	fclose(fp);
}
void names(char array_n[max_value][100]){
	char text_copy[max_value][200];
	int i=1;
	int j=0;
	int counter=0;
	char *str_genres;
	
	line(text_copy);
	while(counter<2000){
 		 str_genres = strtok(text_copy[i],",");  	//I put 'str_genres' the part(name) up to the comma with strtok.
 		 strcpy(array_n[j],str_genres);				//I copied it to another array every time.
	 	j++;
	 	i++;
	 	counter++;

	}

}

void genres(char arr_g[max_value][20]){
	char text_copy[max_value][200];
	char array_1[max_value][20];
	int i=1;
	int j=0;
	int k=0;
	int counter=0;
	char *str_genres;
	line(text_copy);
	while(counter<max_value-1){
 		 str_genres = strtok(text_copy[i],",");//I started with the second line and started to put genres into the array.
 		 str_genres = strtok(NULL,",");
 		 strcpy(array_1[j],str_genres);
 		 if(j>0){
		 	 for(k=0;k<j;k++){								//I compare the index of the array to the previous indexes
		 		if(strcmp(array_1[j],array_1[k])==0){		//if I find the same string, a decrease index and  put there new string again.
		 		 	j--;
		 		 	break;
		 		 }
		 	}
	 	}
	 	j++;
	 	i++;
	 	counter++;

	}
	for(i=0;i<12;i++)
		strcpy(arr_g[i],array_1[i]);
}
	
void platforms(char arr_p[max_value][20]){
	char text_copy[max_value][200];
	int i=1;
	int j=0;
	int k=0;
	int counter=0;
	char result_genres[max_value][20];			//I'm doing the same process here.
	char *str_platforms;
	char array[max_value][20];
	line(text_copy);
	while(counter<max_value-1){
 		 str_platforms = strtok(text_copy[i],",");
 		 str_platforms = strtok(NULL,",");
 		 str_platforms = strtok(NULL,",");
 		 strcpy(array[j],str_platforms);
 		 if(j>0){
		 	 for(k=0;k<j;k++){
		 		if(strcmp(array[j],array[k])==0){
		 		 	j--;
		 		 	break;
		 		 }
		 	}
	 	}
	 	j++;
	 	i++;
	 	counter++;

	}
	for(i=0;i<10;i++)
		strcpy(arr_p[i],array[i]);

}
void result_genres(){
	char result1[max_value][20];
	int i;
	genres(result1);						//to print the genres to the screen
	for(i=0;i<12;i++)
		printf("%s\n",result1[i]);
	
}
void result_platform(){
	char result2[max_value][20];
	int i;
	platforms(result2);						//to platform the genre to the screen
	for(i=0;i<10;i++)
		printf("%s\n",result2[i]);

}

void float_stored(float info[2001][10]){
	char name[100];
	char text_copy_stored[max_value][200];
	int count=0;
	float k1,k2;
	int i=1;
	int j=0,k=0;
	int x,y;
	int m;
	char *str_stored;
	char array_p[2001][20];
	char array_g[2001][20];
	char array_n[2001][100];


	line(text_copy_stored);
	genres(array_g);
	platforms(array_p);

	while(count<2000){
		k=0;
		str_stored = strtok(text_copy_stored[i],",");
 		str_stored = strtok(NULL,",");
 		for(m=0;m<12;m++){
 			if(strcmp(str_stored,array_g[m])==0){
 														//I'm putting the index values of genres on the float array.
 				k1=1.0*m;
 				info[j][k]=k1;
 				k++;
 				break;
 			}
 		}
 		str_stored = strtok(NULL,",");
 		for(m=0;m<10;m++){								//I'm putting the index values of platforms on the float array.
 			if(strcmp(str_stored,array_p[m])==0){
 				k2=1.0*m;
 				info[j][k]=k2;
 				k++;
 				break;
 			}
 		}

 		str_stored = strtok(NULL,",");					//I'm converting the year character to float.
 		info[j][k]=atof(str_stored);
 		k++;
 		str_stored = strtok(NULL,",");					//I'm converting the na_sales character to float.
 		info[j][k]=atof(str_stored);
 		k++;
 		str_stored = strtok(NULL,",");					//I'm converting the eu_sales character to float.
 		info[j][k]=atof(str_stored);
 		k++;
 		str_stored = strtok(NULL,",");					//I'm converting the global_sales character to float.
 		info[j][k]=atof(str_stored);					//if global sales is 'Not Available',it automatically prints zero.
 		k++;
 		str_stored = strtok(NULL,",");					//I'm converting the Score character to float.
 		info[j][k]=atof(str_stored);
 		j++;
 		i++;	
 		count++;

	}

}
void result_stored(){
	int x,y,i;
	float info_2[max_value][10];				//***All information of the single game***
	char name_2[max_value][100];
	char name[100];
	char array_p2[max_value][20];
	char array_g2[max_value][20];

	names(name_2);
	float_stored(info_2);
	platforms(array_p2);
	genres(array_g2);
	printf("Please enter the name of the game:");
	scanf("%s",name);
	for(i=0;i<max_value;i++){
		if(strcmp(name,name_2[i])==0){		//I'm comparing the value the user entered with the value in the name array.
			x=	info_2[i][0];				//I take the platform and genres values in that line and call the values in their own functions.
			y= 	info_2[i][1];
			if(info_2[i][5]==0)				//if global sales is zero, I print' Not Available'.
				printf("\n\nName:\t\t%s\nGenre:\t\t%s\nPlatform:\t%s\nYear:\t\t%0.f\nSales In Na:\t%f\nSales In Eu:\t%f\nTotal Sales:\t%s\nUser Score:\t%f\n",name,array_g2[x],array_p2[y],info_2[i][2],info_2[i][3],info_2[i][4],"Not Available",info_2[i][6]);
			else
				printf("\n\nName:\t\t%s\nGenre:\t\t%s\nPlatform:\t%s\nYear:\t\t%0.f\nSales In Na:\t%f\nSales In Eu:\t%f\nTotal Sales:\t%f\nUser Score:\t%f\n",name,array_g2[x],array_p2[y],info_2[i][2],info_2[i][3],info_2[i][4],info_2[i][5],info_2[i][6]);		
			break;
		}
	}
}
void Games_Through_Years(){

	float info_3[max_value][10];
	char str[max_value][100];
	int year,selection;
	int counter=0;
	int i;
	
	float_stored(info_3);
	names(str);
	while(counter==0){
		printf("Enter a year:");
		scanf("%d",&year);
		printf("Until (0) or Since (1) %d:",year);
		scanf("%d",&selection);
		if(selection==0){
			printf("\n\n");
			for(i=0;i<max_value-1;i++){			//Compares the value entered by the user to all of the year index in the array.
				if(year>info_3[i][2]){
					printf("%s\n",str[i]);
					counter++;					//if the counter is zero ,program want the new value.
				}
			}
		}
		else if(selection==1){					
			printf("\n\n");
			for(i=0;i<max_value-1;i++){
				if(year<info_3[i][2]){
					printf("%s\n",str[i]);
					counter++;
				}
			}
		}
		if(counter!=0)
				break;

		printf("Try Again\n");	

	}
}
void Average_Stored(){
	float info_4[max_value][10];
	int i;
	float total=0;
	float_stored(info_4);
	for(i=0;i<max_value;i++){		//I'm summing all the values in the 6. index.
		total=total+info_4[i][6];
	}
	printf("\n\nAverage=%f\n",total/(max_value-1) );

}
void Georographical_Information(){

	float info_5[max_value][10];
	char str_n[max_value][100];
	int i;
	char name_5[100];
	int num;
	int counter=0;


	float_stored(info_5);
	names(str_n);
	while(counter==0){
		printf("Please enter the name of the game:");
		scanf("%s",name_5);									//I compare NA and EU and print it.
		for(i=0;i<max_value;i++){
			if(strcmp(name_5,str_n[i])==0){
				if(info_5[i][3]>info_5[i][4]){
					printf("\n\nThis game was more popular in North America.\n");
					counter++;
					break;
				}
				else if(info_5[i][3]<info_5[i][4]){
					printf("\n\nThis game was more popular in Europe.\n");
					counter++;
					break;
				}
			}
		}
		if(counter!=0)
			break;
		printf("Try Again\n");
	}


}
void frequence_platforms(){
	char str_platform_5[max_value][20];
	int i;
	int m;
	int number_stored[10][10];
	float info_6[max_value][10];


	platforms(str_platform_5);
	float_stored(info_6);
	
	for(i=0;i<10;i++){
		number_stored[i][0]=0; 		//I reset the result summing indexes every time
	}
	for(i=0;i<max_value-1;i++){
		m=1*info_6[i][1];			//based on every information I get from the float array, I'll increase the element of another array by one.
		number_stored[m][0]+=1;
	}
	printf("\n\n");
	for(i=0;i<10;i++)
		printf("%s\t\t%d\n",str_platform_5[i],number_stored[i][0]);		//I'm printing the results.

}
void frequence_genres(char str_genres_7[max_value][20]){
	
	int i;
	int m;
	int number_stored_7[20][10];
	float info_7[max_value][10];
	
	genres(str_genres_7);
	float_stored(info_7);

	for(i=0;i<12;i++){
		number_stored_7[i][0]=0;
	}
	
	for(i=0;i<max_value-1;i++){
		m=1*info_7[i][0];
		number_stored_7[m][0]+=1;
	}
	printf("\n\n");
	for(i=0;i<12;i++){
		printf("%-15s \t\t%d\n",str_genres_7[i],number_stored_7[i][0]);
	}
	
}


void menu(){
	
	int number;
	char str_g[max_value][20];

	while(1){
		printf("\n0: List of the Genres\n1: List of the platforms\n2: List of the Game Through the Years\n3: All informations of a Single Game\n4: Average of the user scores\n5: Georograpical information of a single game\n6: Frequence of the Genres\n7: Frequence of the platforms\n8: Exit");
		printf("\n\nPlease select an operation:");
		scanf("%d",&number);
		switch(number){
			case 0:
				result_genres();
				break;
			case 1:
				result_platform();
				break;
			case 2:
				Games_Through_Years();
				break;
			case 3:
				result_stored();
				break;
			case 4:
				Average_Stored();
				break;
			case 5:
				Georographical_Information();
				break;
			case 6:
				frequence_genres(str_g);
				break;
			case 7:
				frequence_platforms();
				break;
			case 8:
				exit(number);
				break;
			default :
				printf("\nTRY AGAIN\n");

		}
	}
}

int main(){
	
	menu();

}