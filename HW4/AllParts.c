#include <stdio.h>
#include <stdlib.h>//These three libraries. I used it for the random values in third  part.
#include <time.h>
#include <math.h>
char decrypt_numbers(int number){//Part1-Part2
        switch(number){
            case 0:
                return ' ';
                
            case 1: 
                return '-';
                
            case 2:
                return '_';
                
            case 3:
                return '|';
                
            case 4:
                return '/';
                
            case 5:
                return '\\';
                
            case 6:
                return 'O';
            
        }   
}
char decrypt_p4(char number){//Part4
        switch(number){
            case ' ':
                return '0';
                
            case '-': 
                return '1';
                
            case '_':
                return '2';
                
            case '|':
                return '3';
                
            case '/':
                return '4';
                
            case '\\':
                return '5';
                
            case 'O':
                return '6';          
            
        }    
}

void decrypt_and_print(char* file_path){
    char a;
    int z;
    FILE *fp=fopen(file_path,"r");
    while(!feof(fp)){
        a= fgetc(fp);//After receiving the character as "char", I converted it to" int " for processing.
        z = a - '0';
        if(z== -38){//the" end of line " character is '-38' in ASCII 
           printf("\n");
        }
        else{
            printf("%c",decrypt_numbers(z));
        }
    }
    fclose(fp);

}
void deep_decrypt_and_print (char* file_path){
    int i,counter,total,d;
    char n;
    counter=0;
    FILE *fp=fopen(file_path,"r");
    while(!feof(fp)){
        total=0;
        fseek(fp,counter,SEEK_SET);//when the loop ended, I used "fseek" to start with the next character.
        for(i=0;i<3;i++){
            n= fgetc(fp);
            d=n-'0';
            if(d==-38){
                printf("\n");
                counter+=3;//I used it to reduce the space between the lines.
                break;
            }               
            else
                total+=d;
        }
        counter++;
        total=total%7;
        printf("%c",decrypt_numbers(total));
        
    }
    fclose(fp);
}
void refresh_position (int *x, int *y,double *d,double *r){
    int temp1,temp2;
    temp1=*y;//I used "temp" to compare the enemy's position with the previous one each time.
    temp2=*x;           
    srand(time(NULL));//Random Value
    *x = rand()%11;
    srand(time(NULL));
    *y = rand()%12;
    *r=sqrt((temp1-*y)*(temp1-*y)+(temp2-*x)*(temp2-*x));
    *d=sqrt((6-*y)*(6-*y)+(6-*x)*(6-*x));             
}
void track_machine(){
    int i,j,x,y,temp1,temp2;
    double d,r;
    char number;
    y=1;
    x=1;
    for(i=1;i<12;i++){//Y-axis
        for(j=1;j<12;j++){//X-axis
            if(i==6 && j==6)
                printf("O");
            else if(i==1 && j==1)
                printf("E");
            else
                printf(".");
            printf("\t");
        }
        printf("\n");
    }
    printf("Enemies X position: 1, Y position: 1, Displacement: 0, Distance to our camp: 7.07 \n");
    printf("Command waiting...:");
    while(1){
        scanf("%c",&number);
        switch(number){
            case 'R':
                system("clear");
                refresh_position(&x,&y,&d,&r);
                while((x==0 || y==0) || y==12){//To avoid going outside the matrix area
                    refresh_position(&x,&y,&d,&r);
                }
                for(i=1;i<12;i++){//Y-axis
                    for(j=1;j<12;j++){//X-axis
                        if(i==6 && j==6)
                            printf("O");
                        else if(i==y && j==x)
                            printf("E");
                        else
                            printf(".");
                        printf("\t");
                    }
                    printf("\n");
                }
                printf("\n Enemies X position: %d, Y position: %d, Displacement: %.2lf ,Distance to our camp: %.2lf\n",x,y,r,d);
                printf("Command waiting...:");
                break;
            case 'E':
                exit(number);
                break;
            default:
                printf("Incorrect entry\n");
                printf("Command waiting...:");
                break;
        }   
    }

}
void encrypt_messages (char* file_path){
    int i,counter,total,a,d,temp,flag;
    char n;
    flag=0;
    temp=0;
    counter=0;
    FILE *fp=fopen(file_path,"r");
    FILE *write=fopen("encrypted_p4.img","w");
    while(!feof(fp)){
        total=0;
        fseek(fp,counter,SEEK_SET);
        for(i=0;i<3;i++){
            n= fgetc(fp);
            d=decrypt_p4(n)-'0';
            if(counter==0 && i==0 || counter==0 && i==1){
                total+=d;
                printf("%d",total%7);
                fprintf(write,"%d",total);
                total=0;

            }    
            else  if(d==-38){
                if(flag==4){
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    fprintf(write,"\n\n\n");
                    flag=5;
                    counter+=6;
                    i=3;
                    total=0;
                    break;
                }
                else{
                    printf("\n");
                    fprintf(write,"\n");
                    flag++;
                    total=0;
                    counter+=3;
                    i=3;
                    break;
                }
            }               
            else
                total+=d;
        }
        if(d==-38 && flag==5){//To adjust the space between two paragraphs
            for(i=0;i<3;i++){
                fseek(fp,counter,SEEK_SET);
                n= fgetc(fp);
                d=decrypt_p4(n)-'0';
                temp+=d;
                total=temp%7;
                printf("%d",total);
                fprintf(write,"%d",total);
            }
            temp=0;
        }
        else if(flag==10){
            break;
        }
       else if(d==-38){
            for(i=0;i<2;i++){
                n= fgetc(fp);
                d=decrypt_p4(n)-'0';
                temp+=d;
                total=temp%7;
                printf("%d",total);
                fprintf(write,"%d",total);
            }
            temp=0;
        }
        else{
            counter++;
            total=total%7;
            printf("%d",total);
            fprintf(write,"%d",total);

        }
    }
    fclose(fp);
    fclose(write);

}
void menu (){
    int number;
    while(1){
        printf("Please make your choice:");
        scanf("%d",&number);
        switch(number){
            case 1:
                decrypt_and_print("encrypted_p1.img");
                break;
            case 2:
                deep_decrypt_and_print("encrypted_p2.img");
                break;
            case 3:
                track_machine();
                break;
            case 4:
                encrypt_messages("decrypted_p4.img");
                break;
            case 5:
                exit(number);
        }
    }
}


int main() {

    menu();
     
}