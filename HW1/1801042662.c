//***OKAN TORUN 1801042662
#include <stdio.h>
#include <math.h>
//***İMPORTANT***When compiling, you need to compile it as "gcc 1801042662.c -o 1801042662 -lm",  because of " math.h " library.
  void find_root(){
  double a,b,c;
  double delta;
  double root1,root2;
  printf("Please Enter the first coefficient:");
  scanf("%lf",&a);
  printf("\nPlease Enter the second coefficient:");
  scanf("%lf",&b);
  printf("\nPlease Enter the third coefficient:");
  scanf("%lf",&c);
  delta=b*b-4*a*c;
  

  if(delta>0){   
    root1=(-b+sqrt(delta))/(2*a);
    root2=(-b-sqrt(delta))/(2*a);
    printf("Output> Your equation %.0lfx^2 + %.0lfx + %.0lf have real roots:{%.2lf,%.2lf}\n",a,b,c,root1,root2);
  }
  else if(delta==0){ 

    root1=(-b/2*a); 
    printf("root1 = root2 = %.2lf\n", root1);
  }
  else{ 
    printf("Output> Your equation %.0lfx^2 + %.0lfx + %.0lf does not have any real roots.\n",a,b,c);
  }

}
void find_newtonian_root(){

  double a,b,c,x0,x1,x2,x3,x4,x5,f1,f2,f3,f4,f5,d1,d2,d3,d4,d5;
  printf("Please Enter the first coefficient:");
  scanf("%lf",&a);
  printf("\nPlease Enter the second coefficient:");
  scanf("%lf",&b);
  printf("\nPlease Enter the third coefficient:");
  scanf("%lf",&c);
  printf("\nPlease Enter the initial:");
  scanf("%lf",&x0);
  x1=x0-((a*x0*x0+b*x0+c)/(2*a*x0+b));//Xn=(Xn-1)-((f(X0)/f'(X0)) Newton's Algorithm formula
  x2=x1-((a*x1*x1+b*x1+c)/(2*a*x1+b));
  x3=x2-((a*x2*x2+b*x2+c)/(2*a*x2+b));
  x4=x3-((a*x3*x3+b*x3+c)/(2*a*x3+b));
  x5=x4-((a*x4*x4+b*x4+c)/(2*a*x4+b));
  f1=a*x1*x1+b*x1+c;//f(x)
  f2=a*x2*x2+b*x2+c;
  f3=a*x3*x3+b*x3+c;
  f4=a*x4*x4+b*x4+c;
  f5=a*x5*x5+b*x5+c;
  d1=fabs(x5-x1);//Different,"Fabs" allows us to get the absolute value of the number.
  d2=fabs(x5-x2);
  d3=fabs(x5-x3);
  d4=fabs(x5-x4);
  d5=fabs(x5-x5);
  printf("Step\tx\tf(x)\tDifference\n");
  printf("x1\t%.4lf\t%.4lf\t%.4lf\n",x1,f1,d1);
  printf("x2\t%.4lf\t%.4lf\t%.4lf\n",x2,f2,d2);
  printf("x3\t%.4lf\t%.4lf\t%.4lf\n",x3,f3,d3);
  printf("x4\t%.4lf\t%.4lf\t%.4lf\n",x4,f4,d4);
  printf("x5\t%.4lf\t%.4lf\t%.4lf\n",x5,f5,d5);


}
int find_multiple_closest(int a, int b){
  int sonuc;

  sonuc=a/b;

  if(a>b){
    /*I multiplied the result from the division of the big number into the small number by the small number.
    I added one to the same result, multiplied it again, and compared the differences between the two multipliers.*/
    if(a-b*sonuc==0){
      return a;


    }
    else if((a-b*sonuc)<b*(sonuc+1)-a){
      return (sonuc*b);
    
    }
    else if((a-b*sonuc)>b*(sonuc+1)-a){
      return (b*(sonuc+1));
    }
    else if((a-b*sonuc)==b*(sonuc+1)-a){//if the numbers are equidistant, it chooses the big one.

      return (b*(sonuc+1));
    }

    
 } 

 }


int main(void){
  find_root();
  find_newtonian_root();
  int sayi1,sayi2;
  printf("Enter the first integer:");
  scanf("%d",&sayi1);
  printf("\nEnter the second integer:");
  scanf("%d",&sayi2);
  find_multiple_closest(sayi1,sayi2);
  printf("Closest number to %d that is multiple of %d is %d",sayi1,sayi2,find_multiple_closest(sayi1,sayi2));
  

}