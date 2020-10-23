#include<stdio.h>
char decrypt(int number){
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
int main(){
	int i,counter,total,a,d,temp,flag;
    char n;
    flag=0;
    temp=0;
    counter=0;
    FILE *fp=fopen("decrypted_p4.img","r");
    FILE *write=fopen("encrypted_p4.img","w");
    while(!feof(fp)){
        total=0;
        fseek(fp,counter,SEEK_SET);
        for(i=0;i<3;i++){
            n= fgetc(fp);
            d=decrypt(n)-'0';
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
        if(d==-38 && flag==5){
        	for(i=0;i<3;i++){
        		fseek(fp,counter,SEEK_SET);
        		n= fgetc(fp);
            	d=decrypt(n)-'0';
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
            	d=decrypt(n)-'0';
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