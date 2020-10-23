#include<stdio.h>
#include <stdlib.h>//These three libraries. I used it for the random values.
#include <time.h>
#include<string.h>
#define ROW 20
#define COL 20 
						
										//the Final words are less likely to collide.

void direction1(char array[ROW][COL],char kelime[COL],int z,int b,int y,int l,int n[10]){
	int i;
	int counter=0;

	while(counter==0){
		l = rand()%8;	   				//I'm picking up random numbers and setting directions.
		if(l==0 && (20-b)<z){			// word might overflow out of the table, I'll get another random number and find another direction.
				n[0]=l;					//to convert the uppercase, I put the random number to the 'n' array.
				for(i=0;i<z;i++){
					array[b][y]=kelime[i];
					b--;					//if conditions are allow, I increase the counter and exit the loop.
				}
				counter++;
			
		}	
		else if(l==1 && (20-b)>z){
			
				n[0]=l;							//I put the letters in the array according to the directions.
				for(i=0;i<z;i++){
					array[b][y]=kelime[i];		
					b++;
				}
				counter++;
	
		}
		else if(l==2 && (20-y)>z){
		
				n[0]=l;
				for(i=0;i<z;i++){
					array[b][y]=kelime[i];
					y++;
				}
				counter++;
			
			
		}
		else if(l==3 && (20-y)<z){
			
				n[0]=l;
				for(i=0;i<z;i++){
					array[b][y]=kelime[i];
					y--;
				}
				counter++;
			
			
		}
		else if(l==4 && ((20-b)>z && (20-y)>z)){
			
				n[0]=l;
				for(i=0;i<z;i++){
					array[b][y]=kelime[i];
					b++;
					y++;
				}
				counter++;
			
			
		}
		else if(l==5 && ((20-b)>z && (20-y)<z)){
			
				n[0]=l;
				for(i=0;i<z;i++){
					array[b][y]=kelime[i];
					b++;
					y--;
				}
				counter++;
			
			
		}
		else if(l==6 && ((20-b)<z && (20-y)>z)){
			
				n[0]=l;
				for(i=0;i<z;i++){
					array[b][y]=kelime[i];
					b--;
					y++;
				}
				counter++;
			
		}
		else if(l==7 && ((20-b)<z && (20-y)<z)){
			
				n[0]=l;
				for(i=0;i<z;i++){
					array[b][y]=kelime[i];
					b--;
					y--;
				}
				counter++;	
		}
		
	}
}


void direction2(char array[ROW][COL],int z,int h,int k,int n[10]){
	int i;
	if(n[0]==0){
		for(i=0;i<z;i++){			//I'm sending 'direction1' here.
			array[h][k]-=32;		//I find letters's direction and I'm converting uppercase one by one.  
			h--;					// 'z' is length of word.I put the letters of the word in the random line into the array.
		}
	}
	else if(n[0]==1){
		for(i=0;i<z;i++){
			array[h][k]-=32;
			h++;
		}

	}
	else if(n[0]==2){
		for(i=0;i<z;i++){
			array[h][k]-=32;
			k++;
		}

	}
	else if(n[0]==3){
		for(i=0;i<z;i++){
			array[h][k]-=32;
			k--;
		}

	}
	else if(n[0]==4){
		for(i=0;i<z;i++){
			array[h][k]-=32;
			h++;
			k++;
		}

	}
	else if(n[0]==5){
		for(i=0;i<z;i++){
			array[h][k]-=32;
			h++;
			k--;
		}

	}
	else if(n[0]==6){
		for(i=0;i<z;i++){
			array[h][k]-=32;
			h--;
			k++;
		}

	}
	else if(n[0]==7){
		for(i=0;i<z;i++){
			array[h][k]-=32;
			h--;
			k--;
		}
	}

}
void reading(char letter[COL]){
	int k;
	int i,x;
	char a;
	FILE*fp;
	fp=fopen("words.txt","r");		
	x = 1+rand()%100;
	for(i=0;i<1000;i++){
		
		a=fgetc(fp);	//I take random numbers and put the word on that line into array.
		if(a=='\n'){
			x--;
		}
		if(x==0){
			for (k=0;k<100;k++)
			{
				a=fgetc(fp);	//I put the letters of the word in the random line into the array.
				if(a=='\n')
					break;
				letter[k]=a;
				printf("%c\n",letter[k]);
			}
		}
		if(x==0)
			break;
		
	}
	fclose(fp);
}
int main(){
	char str[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char array[ROW][COL];
	char letter[COL];
	char deneme[20];
	char s[10][20];
	int n1[10],n2[10],n3[10],n4[10],n5[10],n6[10],n7[10],n8[10],n9[10],n10[10];
	char cr;
	int i,j,h,counter=0;
	int x,y,z,b,k,l;
	char a;
	srand(time(NULL));
	for(i=0;i<10;i++){
		reading(letter);		
		z=strlen(letter);			//I take random 10 words in the loop and determine the directions and positions of the words with function.
		b = rand()%20;		//b and y are numerical values of the initial coordinate.
		y = rand()%20;
		printf("%d,%d\n",b,y);
		if(i==0){
			strcpy(s[0],letter);	//I'm copying it to a different array to compare with the user entered word.
			direction1(array,letter,z,b,y,l,n1);
		}
		else if(i==1){
			strcpy(s[1],letter);	
			direction1(array,letter,z,b,y,l,n2);
		}
		else if(i==2){
			strcpy(s[2],letter);	
			direction1(array,letter,z,b,y,l,n3);
		}
		else if(i==3){
			strcpy(s[3],letter);	
			direction1(array,letter,z,b,y,l,n4);
		}
		else if(i==4){
			strcpy(s[4],letter);	
			direction1(array,letter,z,b,y,l,n5);
		}
		else if(i==5){
			strcpy(s[5],letter);	
			direction1(array,letter,z,b,y,l,n6);
		}
		else if(i==6){
			strcpy(s[6],letter);	
			direction1(array,letter,z,b,y,l,n7);
		}
		else if(i==7){
			strcpy(s[7],letter);	
			direction1(array,letter,z,b,y,l,n8);
		}
		else if(i==8){
			strcpy(s[8],letter);	
			direction1(array,letter,z,b,y,l,n9);
		}
		else if(i==9){
			strcpy(s[9],letter);	
			direction1(array,letter,z,b,y,l,n10);
		}

	}
	printf("\n\t  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19\n\n");
	for(i=0;i<20;i++){
		a=i+17+'0';					//I'm printing the location letters next to matrix.
		printf("    %c-    ", a);
		for(j=0;j<20;j++){
			if(array[i][j]>= 'a' && array[i][j]<= 'z')	//if there are characters in the array,it prints.
				printf("%c ",array[i][j]);

			else {
				x = rand()%26;			//if the index of the array is empty, I take a random letter and print it.
				array[i][j]=str[x];
				printf("%c ",array[i][j]);
			}
		}
		if(i==0)printf("\t\t%s", s[0]);
		else if(i==1)printf("\t\t%s",s[1]);		//I write the words we'll look for in the table next to matrix.
		else if(i==2)printf("\t\t%s",s[2]);		//I have the words to search on the right side.
		else if(i==3)printf("\t\t%s",s[3]);		//so there were meaningless overflows on the left side of the Matrix.
		else if(i==4)printf("\t\t%s",s[4]);		//I couldn't find a solution to that.
		else if(i==5)printf("\t\t%s",s[5]);
		else if(i==6)printf("\t\t%s",s[6]);
		else if(i==7)printf("\t\t%s",s[7]);
		else if(i==8)printf("\t\t%s",s[8]);
		else if(i==9)printf("\t\t%s",s[9]);
		printf("\n");
	}
	
	while(counter!=10){
		printf("\nPlease enter the coordinate and the word:");
		scanf("%c%d %s",&cr,&k,deneme);
		if(strcmp(deneme,"exit")==0)	//*******İf you want to exit,write a random coordinate and then space and write exit.********
			exit(0);
		printf("\n");
		h=cr-'A';		//I'm converting the letter part of the coordinate to int.
		z=strlen(deneme);
		if(array[h][k]==deneme[0]){  //I'm checking the coordinates the user entered.
			if(strncmp(s[0],deneme,z)==0){//I'm comparing the word in the array with the word the user entered with each statement.if it's not true, there's no change.
				direction2(array,z,h,k,n1);//İf it is true,I'm converting uppercase letters in the array.
				for(i=0;i<z;i++)
					s[0][i]-=32;
				counter++;
			}
			else if(strncmp(s[1],deneme,z)==0){//Every correctly known word counter is increasing.
				direction2(array,z,h,k,n2);		//All the words are known, the loop ends.
				for(i=0;i<z;i++)
					s[1][i]-=32;
				counter++;
			}
			else if(strncmp(s[2],deneme,z)==0){
				direction2(array,z,h,k,n3);
				for(i=0;i<z;i++)
					s[2][i]-=32;
				counter++;
			}
			else if(strncmp(s[3],deneme,z)==0){
				direction2(array,z,h,k,n4);
				for(i=0;i<z;i++)
					s[3][i]-=32;
				counter++;
			}
			else if(strncmp(s[4],deneme,z)==0){
				direction2(array,z,h,k,n5);
				for(i=0;i<z;i++)
					s[4][i]-=32;
				counter++;
			}
			else if(strncmp(s[5],deneme,z)==0){
				direction2(array,z,h,k,n6);
				for(i=0;i<z;i++)
					s[5][i]-=32;
				counter++;
			}
			else if(strncmp(s[6],deneme,z)==0){
				direction2(array,z,h,k,n7);
				for(i=0;i<z;i++)
					s[6][i]-=32;
				counter++;
			}
			else if(strncmp(s[7],deneme,z)==0){
				direction2(array,z,h,k,n8);
				for(i=0;i<z;i++)
					s[7][i]-=32;
				counter++;
			}
			else if(strncmp(s[8],deneme,z)==0){
				direction2(array,z,h,k,n9);
				for(i=0;i<z;i++)
					s[8][i]-=32;
				counter++;
			}
			else if(strncmp(s[9],deneme,z)==0){
				direction2(array,z,h,k,n10);
				for(i=0;i<z;i++)
					s[9][i]-=32;
				counter++;
			}
		}
		printf("\t  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19\n\n");
		for(i=0;i<20;i++){
			a=i+17+'0';
			printf("    %c-    ",a);			//After each prediction, the new matrix is printed.
			for(j=0;j<20;j++){
				printf("%c ",array[i][j]);
			}
			if(i==0)printf("\t\t%s", s[0]);
			else if(i==1)printf("\t\t%s",s[1]);
			else if(i==2)printf("\t\t%s",s[2]);
			else if(i==3)printf("\t\t%s",s[3]);
			else if(i==4)printf("\t\t%s",s[4]);
			else if(i==5)printf("\t\t%s",s[5]);
			else if(i==6)printf("\t\t%s",s[6]);
			else if(i==7)printf("\t\t%s",s[7]);
			else if(i==8)printf("\t\t%s",s[8]);
			else if(i==9)printf("\t\t%s",s[9]);
			printf("\n");
		}
	}
	printf("Congratulations, You found them all.\n");
			
}