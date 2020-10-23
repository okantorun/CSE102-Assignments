#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void refresh_position (int *x, int *y,double *d,double *r){
	int temp1,temp2;
    temp1=*y;
    temp2=*x;			
	srand(time(NULL));
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
			    while((x==0 || y==0) || y==12){
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
				printf("Error! operator is not correct\n");
				printf("Command waiting...:");
				break;

		}	
}

}

int main(){

	track_machine();
	

}