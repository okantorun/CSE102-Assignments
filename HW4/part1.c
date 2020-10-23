#include<stdio.h>
#include<stdlib.h>
char decrypt_numbers(int number){
    
 
        switch(number){
           // case '\n':
              //  return '\n'; 
                
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
            default:
                return '\n';
            
        }
       
    
}
void deep_decrypt_and_print(char* file_path){
    char a;
    int z;
    FILE *fp=fopen(file_path,"r");
    while(!feof(fp)){
        a= fgetc(fp);
        z = a - '0';
        //if(z== -38){
         //   printf("\n");
       // }
       // else{
            printf("%c",decrypt_numbers(z));
      //  }
    }
    fclose(fp);
    

}

int main() {


    deep_decrypt_and_print("encrypted_p1.img");
   

     /*while(1)
     {
        c = fgetc(fp);
        if(c==EOF)
            break;
        else
            if(c=='\n'){
               printf("\n"); 
            }
            else if(c=='0'){
                printf(" ");
            }
            else if(c=='1'){
                printf("-");
            }
             else if(c=='2'){
                printf("_");
            }
             else if(c=='3'){
                printf("|");
            }
             else if(c=='4'){
                printf("/");
            }
            else if(c=='5'){
                printf("\\");
            }
            else if(c=='6'){
                printf("O");
            }
            
     }*/
    //fclose(fp);
}