#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>


int numPathsHome(int street, int avenue){
  int x;

  if(avenue==0){
    x=1;
  }
  else{
     x= (street+avenue)*numPathsHome(street,avenue-1)/avenue;   //I calculate by taking permitation by avenue and street with recursion.
  }                                                             // ((street+avenue)!/(street!+avenue!)) with formula
  
  return x;
 
}
struct card {

  const char *face;
  const char *suit;

};
void card_shuffle(){
  int array[13][4];
  char face[4][10]={"Hearts", "Diamonds", "Clubs", "Spades"};
  char suit[13][10]={"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  int count=0;
  int i;
  int r,z;
  struct card f1;

  srand(time(NULL));
  for(i=0;i<52;i++){
    do{               
     r = rand()%13;   //new random value if the previously selected card is selected again.
     z = rand()%4;
    }while(array[r][z]==1) ;
      array[r][z]=1; //to check the selected cards
     f1.face=face[z];
     f1.suit=suit[r];
     if(count%2==0)
      printf("\n");
     printf("%s of ",f1.face );   //I'm printing the information I put into structure.
     printf("%-15s",f1.suit );
     count++;
  }

}

struct Hospital{

  char* name;
  char citiesServed[3];

};


int canOfferCovidCoverage(char _cities[6], char _locations[4][3], int _numHospitals, struct Hospital results[4]){
char a;
  if(_numHospitals==0){
     strcpy(results[_numHospitals].citiesServed,_locations[_numHospitals]); //I copy the values in the locations index into the struct result citiesServed.
     results[_numHospitals].citiesServed[3]='\0';                   //I put null to avoid printing meaningless characters after the last value.
     a=_numHospitals-'0';
    results[_numHospitals].name=_numHospitals-"0";
  }
  else{
    strcpy(results[_numHospitals].citiesServed,_locations[_numHospitals]);
    results[_numHospitals].citiesServed[3]='\0';
    a=_numHospitals-'0';
    results[_numHospitals].name=_numHospitals-"0";
    canOfferCovidCoverage(_cities,_locations,_numHospitals-1,results);//With recursion, I go to the previous index and continue copying.
  }                                                                   // until '_numhospital' is 0.
  return _numHospitals+1; //finally, I return the number of hospitals the user has entered.

}

void canOfferCovidCoverage_result(){
  char _cities[6]= { 'A', 'B', 'C', 'D', 'E', 'F' };
  char  _locations[4][3]={{'A', 'C', 'D'}, {'B', 'F'}, {'C', 'E', 'F'},{'A', 'B', 'C'}};
  int _numHospitals;
  struct Hospital results1[4];

  printf("\nEnter the maximum number of hospital that can be constructed:");
  scanf("%d",&_numHospitals);
  
 
  if(_numHospitals==0 || _numHospitals>4)
       printf("İnvalid Value\n");
  
  else{
    if(canOfferCovidCoverage(_cities,_locations,_numHospitals-1,results1)>2){
      printf("\n\nYes,can offer health care to all.\n\n");        //if the number of hospitals is more than 2, I'm printing the information on structer.
      for(int i=0;i<_numHospitals;i++)
        printf("Hospital - %s\nHospital locations: %s\n",results1[i].name,results1[i].citiesServed );

    }
    else
      printf("No,some cities are not covered.\n");    //if the number of hospitals is 2 and less
  }
}

void menu(){
  int number;
  int street,avenue;
    printf("\n\nWelcome to Homework 9,please choose one of the parts to continue\n------------\n");
    printf("\n1)Part 1\n2)Part 2\n3)Part 3\n4)Exit\n");
    scanf("%d",&number);
    switch(number){
      case 1:
        printf("\nEnter the street number:");
        scanf("%d",&street);
        printf("street:%d\n",street);
        printf("Enter the avenue number:");
        scanf("%d",&avenue);
        printf("avenue:%d\n",avenue);
        printf("Number of optimal packs to take back home:%d\n\n\n",numPathsHome(street-1,avenue-1));
        break;

      case 2:
        card_shuffle();
        break;
      case 3:
        canOfferCovidCoverage_result();
        break;
      case 4:
        exit(number);
        break;
    }
  }





int main(){

  menu();
   
}


