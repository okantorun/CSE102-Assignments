#include<stdio.h>
char decrypt_numbers(int number){
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
           
           // default:
              //  printf("\n");
            
        }
       
    
}
      
int main(){
    int i,counter,total,a,d;
    char n;
    counter=0;
    FILE *fp=fopen("encrypted_p2.img","r");
    while(!feof(fp)){
        total=0;
        fseek(fp,counter,SEEK_SET);
        for(i=0;i<3;i++){
            n= fgetc(fp);
            d=n-'0';
            if(d==-38){
                printf("\n");
                counter+=3;
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

