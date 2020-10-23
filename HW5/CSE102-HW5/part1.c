#include<stdio.h>
#include<stdlib.h>
void append_file(char *file_path, char c){
	int i;
	char a;
	int counter=0;
	int counter2=0,counter3=0,counter4=0;
	FILE*fp;
	if(c=='1'){
		fp=fopen(file_path,"a+");
		while(!feof(fp)){
		a=fgetc(fp);	//I'm checking that the new is marked in the file.
		if(a=='1')
			counter++;
		}
		if(counter==0)
			fprintf(fp,"%c",c);//If it's not read, I write it in the file.
		fclose(fp);
	}
	else if(c=='2'){
		fp=fopen(file_path,"a+");
		while(!feof(fp)){
		a=fgetc(fp);
		if(a=='2')
			counter++;
		}
		if(counter==0)
			fprintf(fp,"%c",c);
		fclose(fp);
	}
	else if(c=='3'){
		fp=fopen(file_path,"a+");
		while(!feof(fp)){
		a=fgetc(fp);
		if(a=='3')
			counter++;
		}
		if(counter==0)
			fprintf(fp,"%c",c);
		fclose(fp);
	}	
	else if(c=='4'){
		fp=fopen(file_path,"a+");
		while(!feof(fp)){
		a=fgetc(fp);
		if(a=='4')
			counter++;
		}
		if(counter==0)
			fprintf(fp,"%c",c);
		fclose(fp);

	}
	else if(c=='5'){
		fp=fopen(file_path,"a+");
		while(!feof(fp)){
			a=fgetc(fp);
			if(a=='1')
				counter++;		/*	for the b part  I'm checking readed the news*/
			else if(a=='2')
				counter2++;
			else if(a=='3')
				counter3++;
			else if(a=='4')
				counter4++;
		}
		if(counter!=0)
			printf("1. new is readed\n"); // I m printing readed news 
		if(counter2!=0)
			printf("2. new is readed\n");
		if(counter3!=0)
			printf("3. new is readed\n");
		if(counter4!=0)
			printf("4. new is readed\n");

	}
	else if(c=='6'){
		fp=fopen(file_path,"a+");
		while(!feof(fp)){
			a=fgetc(fp);							/*when we want to read the news,I check if it's been read before, and I ask again,directing to the menu*/
			if(a=='1')
				counter++;
			}
		if(counter!=0){
			printf("This new is readed.Do you want to read again? Yes(1) / No(0):");
			scanf("%d",&i);
			if(i!=1){
				printf("Good Bye!");
				exit(0);
			}
		}

		fclose(fp);
	}
	else if(c=='7'){
		fp=fopen(file_path,"a+");
		while(!feof(fp)){
			a=fgetc(fp);
			if(a=='2')
				counter++;
			}
		if(counter!=0){
			printf("This new is readed.Do you want to read again? Yes(1) / No(0):");
			scanf("%d",&i);
			if(i!=1){
				printf("Good Bye!");
				exit(0);
			}

		}

		fclose(fp);
	}
	else if(c=='8'){
		fp=fopen(file_path,"a+");
		while(!feof(fp)){
			a=fgetc(fp);
			if(a=='3')
				counter++;
			}
		if(counter!=0){
			printf("This new is readed.Do you want to read again? Yes(1) / No(0):");
			scanf("%d",&i);
			if(i!=1){
				printf("Good Bye!");
				exit(0);
			}
		}

		fclose(fp);
	}
	else if(c=='9'){
		fp=fopen(file_path,"a+");
		while(!feof(fp)){
			a=fgetc(fp);
			if(a=='4')
				counter++;
			}
		if(counter!=0){
			printf("This new is readed.Do you want to read again? Yes(1) / No(0):");
			scanf("%d",&i);
			if(i!=1){
				printf("Good Bye!");
				exit(0);
			}
		}

		fclose(fp);
	}
}
void read_news(char buffer[500], char file_path[10], int is_Only_Title){
	int i=0;
	int j=0;
	FILE*fp;
	if(is_Only_Title==1){//Reading Headline 
		fp=fopen(file_path,"r");
		 while(!feof(fp)){//It reads characters until the end of the line.
		 	buffer[i]=fgetc(fp);
		 	if(buffer[i]!='\n')
		 		printf("%c",buffer[i]);
		 	else
		 		break;
		 	i++;
		}
	}	
	else if(is_Only_Title==0){
		fp=fopen(file_path,"r");
		while((buffer[j]=fgetc(fp))!=EOF){//It reads the whole text
		 	printf("%c",buffer[j]);
		 	j++;
		}

	}
	
}
double f_func(int x){
	return x*x*x-x*x+2;			/*I perform the desired operations according to function prototypes*/

}
double g_func(double f(int x), int a){
	
	return f(a)*f(a);

}
void read_magic_numbers(char buffer_magic[10], char buffer_news[500]){
	int number=0;
	int j=0;
	int y=500;
	int a=0;
	int i;
	double temp;
	double sum;
	for(i=0;i<500;i++){
		if(buffer_news[i]=='#'){
		 		y=i;
		 	}									//I put the magic numbers to the array
		 	if(i==y+1){
		 		buffer_magic[a]=buffer_news[i];
		 		a++; // Length of array
		 	}
	}
	for(i=0;i<a;i++){
		number=buffer_magic[i]-'0';//I'm changing the variable type so I can process it.
		temp=g_func(f_func,number);//I'm sending every array element to the function.
		sum+=temp;
	}
		printf("%.2lf",sum);

}

void menu(){
	char buffer_magic[10], buffer_news[500];
	int number;
	char a,b;
	char buffer[500];
	printf("******Daily Press******");
	printf("\nTitle of 1. news:");
	read_news(buffer,"CSE102-HW5/news/1.txt",1);//I'm printing a headline.
	printf("\nTitle of 2. news:");
	read_news(buffer,"CSE102-HW5/news/2.txt",1);
	printf("\nTitle of 3. news:");
	read_news(buffer,"CSE102-HW5/news/3.txt",1);
	printf("\nTitle of 4. news:");
	read_news(buffer,"CSE102-HW5/news/4.txt",1);
	
	printf("\nWhat do you want to do?\na.read a new\nb.list a readed news\nc.Get decrypted information from the news");
	while(1){
		
		scanf("%c",&a);
		switch(a){
			case 'a':
				printf("Which news do you want to read ?");
				scanf("%d",&number);
				
				if(number==1){
					append_file("CSE102-HW5/readed_news_id.txt",'6');//I check the readed texts and proceed accordingly.
					read_news(buffer,"CSE102-HW5/news/1.txt",0);//I printed the whole text
					append_file("CSE102-HW5/readed_news_id.txt",'1');//I save the reading of the text in Document 'readed_news_id.txt'.
				}
				else if(number==2){
					append_file("CSE102-HW5/readed_news_id.txt",'7');
					read_news(buffer,"CSE102-HW5/news/2.txt",0);
					append_file("CSE102-HW5/readed_news_id.txt",'2');
				}
				else if(number==3){
					append_file("CSE102-HW5/readed_news_id.txt",'8');
					read_news(buffer,"CSE102-HW5/news/3.txt",0);
					append_file("CSE102-HW5/readed_news_id.txt",'3');
				}
				else if(number==4){
					append_file("CSE102-HW5/readed_news_id.txt",'9');
					read_news(buffer,"CSE102-HW5/news/4.txt",0);
					append_file("CSE102-HW5/readed_news_id.txt",'4');
				}
				printf("\nDo you want to continue? Yes(y)/No(n)");
				scanf(" %c",&b);
				if(b=='n'){
					printf("Good Bye!");
					exit(0);
				}
				printf("******Daily Press******");
				printf("\nTitle of 1. news:");
				read_news(buffer,"CSE102-HW5/news/1.txt",1);
				printf("\nTitle of 2. news:");
				read_news(buffer,"CSE102-HW5/news/2.txt",1);
				printf("\nTitle of 3. news:");
				read_news(buffer,"CSE102-HW5/news/3.txt",1);
				printf("\nTitle of 4. news:");
				read_news(buffer,"CSE102-HW5/news/4.txt",1);
				printf("\nWhat do you want to do?\na.read a new\nb.list a readed news\nc.Get decrypted information from the news");
				break;
			case 'b' :
				printf("\n\nReaded news are listed below:\n");
				append_file("CSE102-HW5/readed_news_id.txt",'5');
				printf("\nDo you want to continue? Yes(y)/No(n)");
				scanf(" %c",&b);
				if(b=='n'){
					printf("Good Bye!");
					exit(0);
				}
				printf("******Daily Press******");
				printf("\nTitle of 1. news:");
				read_news(buffer,"CSE102-HW5/news/1.txt",1);
				printf("\nTitle of 2. news:");
				read_news(buffer,"CSE102-HW5/news/2.txt",1);
				printf("\nTitle of 3. news:");
				read_news(buffer,"CSE102-HW5/news/3.txt",1);
				printf("\nTitle of 4. news:");
				read_news(buffer,"CSE102-HW5/news/4.txt",1);
				printf("\nWhat do you want to do?\na.read a new\nb.list a readed news\nc.Get decrypted information from the news");
				break;

			case 'c' :
				printf("\nWhich news would you like to decrypt ?:");
				scanf("%d",&number);
				if(number==1){
					read_news(buffer,"CSE102-HW5/news/1.txt",0);//I'm printing the text firstly.
					printf("\nnumber of tests performed=");
					read_magic_numbers(buffer_magic,buffer);//I printing the result

				}
				else if(number==2){
					read_news(buffer,"CSE102-HW5/news/2.txt",0);
					printf("\nnumber of sick people=");
					read_magic_numbers(buffer_magic,buffer);
				}
				else if(number==3){
					read_news(buffer,"CSE102-HW5/news/3.txt",0);
					printf("\nnumber of deaths=");
					read_magic_numbers(buffer_magic,buffer);
				}
				else if(number==4){
					read_news(buffer,"CSE102-HW5/news/4.txt",0);
					printf("\nexpected number of sick people=");
					read_magic_numbers(buffer_magic,buffer);
				}
				printf("\nDo you want to continue? Yes(y)/No(n)");
				scanf(" %c",&b);
				if(b=='n'){
					printf("Good Bye!");
					exit(0);
				}
				printf("******Daily Press******");
				printf("\nTitle of 1. news:");
				read_news(buffer,"CSE102-HW5/news/1.txt",1);
				printf("\nTitle of 2. news:");
				read_news(buffer,"CSE102-HW5/news/2.txt",1);
				printf("\nTitle of 3. news:");
				read_news(buffer,"CSE102-HW5/news/3.txt",1);
				printf("\nTitle of 4. news:");
				read_news(buffer,"CSE102-HW5/news/4.txt",1);
				printf("\nWhat do you want to do?\na.read a new\nb.list a readed news\nc.Get decrypted information from the news");
				break;

			default:
				break;

		}
	}
}
int main(){
	
	
	menu();

}