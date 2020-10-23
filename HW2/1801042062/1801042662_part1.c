#include <stdio.h>
#include <math.h>

int draw_triangle(int side1,int side2, int side3){

if(side1+side2>side3 && side1+side3>side2 && side2+side3>side1 ){
	//printf("According to the triangle inequality theorem, this triangle can be drawn.\n");
	return 1;
}
else{
	//printf("According to the triangle inequality theorem, this triangle cannot be drawn. \n");
	return 0;
}

}
void type_triangle(int side1,int side2, int side3){
	if(draw_triangle(side1,side2,side3)==0){//İf the Triangle cannot be drawn
		printf("The triangle type could not be found because the Triangle could not be drawn.\n");
	}
	else if(side1==side2 && side1==side3 && side2==side3){
		printf("İt is a Equilateral Triangle\n");
	}
	else if(side1==side2 && side3!=side1 && side3!=side2|| side1==side3 && side2!=side1 && side2!=side3|| side2==side3 && side1!=side3 && side1!=side2){

		printf("İt is a İsosceles Triangle\n");
	}
	else{

		printf("İt is a Scalane Triangle\n");
	}
	
}
int perimeter_triangle(int side1,int side2, int side3){
	int perimeter;
	perimeter=side1+side2+side3;
	if(draw_triangle(side1,side2,side3)==0){//The perimeter could not be calculated because the triangle could not be drawn
		return 0;
	}
	else{
	return perimeter;
}
}
double area_triangle(int side1,int side2, int side3,int perimeter){
	double area;
	double p=perimeter/2.0;
	area=sqrt(p*(p-side1)*(p-side2)*(p-side3));
	if(draw_triangle(side1,side2,side3)==0){//İf the Triangle can't be drawn, it doesn't calculate the area.
		return 1;
	}
	else {
		return area;
	}
}

int main(){
int a,b,c,d;
printf("The length of first side:");
scanf("%d",&a);
printf("\nThe length of second side:");
scanf("%d",&b);
printf("\nThe length of third side:");
scanf("%d",&c);
if(draw_triangle(a,b,c)==1){
	printf("According to the triangle inequality theorem, this triangle can be drawn.\n");
}
else if(draw_triangle(a,b,c)==0){
	printf("According to the triangle inequality theorem, this triangle cannot be drawn. \n");
}
type_triangle(a,b,c);
if(perimeter_triangle(a,b,c)==0){
printf("The perimeter could not be calculated because the triangle could not be drawn\n");
}
else{
	printf("The perimeter of the triangle:%d\n",perimeter_triangle(a,b,c));

}
d=perimeter_triangle(a,b,c);
if(area_triangle(a,b,c,d)==1){
	printf("The area could not be calculated because the triangle could not be drawn\n");
}
else {
	printf("The area of the triangle:%lf\n",area_triangle(a,b,c,d));
}




}