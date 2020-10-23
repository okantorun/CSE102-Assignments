#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_LENGTH 250
const double PI =  3.1415926;

void text(char word[MAX_LENGTH][200]){			//I read the text in the file into the array.
	int i=0,j=0;
	char a;
	FILE*fp;
	fp=fopen("commands.txt","r");
	while(i<250){
		fgets(word[i],200,fp);
		i++;
	}

	fclose(fp);
}


struct point{

	char name_p[5];
	float x;			
	float y;


};
struct line{

	char name_l[5];
	struct point find_line_1;		//first point of line
	struct point find_line_2;  		//second point of line


	
};

struct  polygon{

	char name_polygon_p[10];
	char name_polygon_l[10];
	struct line polygon_line;
	struct point polygon_point;
 	
};

void data(struct line data_line[25],struct point data_point[25],struct polygon data_polygon[25]){
	char arr_data[MAX_LENGTH][200];
	int number;
	char a; 
	int count=0;
	char *str;
	int i;
	text(arr_data);
	number=atoi(arr_data[1]);			// total number of data
	for(i=2;i<(number-2)/2+2;i++){		//the loop is processing based on the number of data.
		str = strtok(arr_data[i]," ");
		data_point[i-2].x=atof(str);		//I keep coordinates and Point Names in the structure
		str = strtok(NULL," ");
		data_point[i-2].y=atof(str);
		str = strtok(NULL,"/");
		strcpy(data_point[i-2].name_p,str);
	}
	for(i=(number-2)/2+2;i<number;i++){
		str = strtok(arr_data[i]," ");
		strcpy(data_line[count].find_line_1.name_p,str);
		data_line[count].find_line_1.x=data_point[count].x;		//I keep the point name of line and the line name in the structure.
		data_line[count].find_line_1.y=data_point[count].y;
		str = strtok(NULL," ");
		strcpy(data_line[count].find_line_2.name_p,str);
		data_line[count].find_line_2.x=data_point[count+1].x;
		data_line[count].find_line_2.y=data_point[count+1].y;
		str = strtok(NULL,"/");
		strcpy(data_line[count].name_l,str);
		count++;
	}
	data_line[count-1].find_line_2.x=data_point[0].x;	// This line that combines the last point with the first point
	data_line[count-1].find_line_2.y=data_point[0].y;

	count =0;
	for(i=0;i<=(number-2)/2;i++){
		if(i==(number-2)/2){
			str = strtok(NULL," ");
			strcpy(data_polygon[0].name_polygon_p,str);		//I keep the point names of the Polygon.
			break;
		}
		if(i==0){
			str = strtok(arr_data[number]," ");
			strcpy(data_polygon[i].polygon_point.name_p,str);
		}
		else {
			str = strtok(NULL," ");
			strcpy(data_polygon[i].polygon_point.name_p,str);
		}
	

	}
	for(i=0;i<=(number-2)/2;i++){
		if(i==(number-2)/2){
			str = strtok(NULL," ");
			strcpy(data_polygon[0].name_polygon_l,str);			//I keep the line names of the Polygon.
			break;
		}
		if(i==0){
			str = strtok(arr_data[number+1]," ");
			strcpy(data_polygon[i].polygon_line.name_l,str);
		}
		else {
			str = strtok(NULL," ");
			strcpy(data_polygon[i].polygon_line.name_l,str);
		}
	

	}

}
void actions(){
	int i,j,k;
	int z;
	float total=0;
	float tangent;
	int number_data;
	int number_actions;
	char file_address[20];
	char *str;
	char *str1;
	char *str2;
	int index1,index2;
	float length1,length2;
	float result;
	float result2;
	float result3;
	float arccos;
	char arr_actions[MAX_LENGTH][200];
	struct line actions_line[25];
	struct point actions_point[25];
	struct polygon actions_polygon[25];

	text(arr_actions);
	data(actions_line,actions_point,actions_polygon);

	number_data=atoi(arr_actions[1]);
	str1 = strtok(arr_actions[number_data+4],"\n");		//  OUTPUT ADRESS
	strcpy(file_address,str1);

	FILE *write=fopen(file_address,"w");
	number_actions=atoi(arr_actions[number_data+5]);	//Total number of actions
	
	for(i=0;i<number_actions;i++){
		result=0;
		result2=0;
		result3=0;
		str = strtok(arr_actions[number_data+6+i]," ");
	
		if(strcmp(str,"Distance")==0){
			str1 = strtok(NULL," ");
			

			str2 = strtok(NULL," ");

			if(str1[0]=='L' || str2[0]=='L'){		//First condition: to find the distance between the point and the line

				if(str1[0]=='L'){
					for(j=0;j<20;j++){
						if(j<10){
							if(strncmp(actions_line[j].name_l,str1,3)==0)	//I'm comparing the strings I read with the strings in the structure.
								index1=j;									//and I take the index number
							if(strncmp(actions_point[j].name_p,str2,2)==0)	//I'm processing with the numbers in this index.
								index2=j;
						}
						else{
							if(strncmp(actions_line[j].name_l,str1,5)==0)
								index1=j;
							if(strncmp(actions_point[j].name_p,str2,3)==0)
								index2=j;
						}
					}
					//the distance formula between point and line
					tangent=fabs((actions_line[index1].find_line_1.y-actions_line[index1].find_line_2.y)/(actions_line[index1].find_line_1.x-actions_line[index1].find_line_2.x));
					result=fabs(tangent*(actions_point[index2].x-actions_line[index1].find_line_1.x)-(actions_point[index2].y-actions_line[index1].find_line_1.y))/sqrt(tangent*tangent+1);
					printf("%s (%s,%s)=%.1f\n",str,actions_polygon[index1].polygon_line.name_l,actions_polygon[index2].polygon_point.name_p,result);
					fprintf(write,"%s (%s,%s)=%.1f\n",str,actions_polygon[index1].polygon_line.name_l,actions_polygon[index2].polygon_point.name_p,result);

				}
				else if(str2[0]=='L'){
					for(j=0;j<20;j++){
						if(j<10){
							if(strncmp(actions_line[j].name_l,str2,3)==0)
								index1=j;
							if(strncmp(actions_point[j].name_p,str1,2)==0)
								index2=j;
						}
						else{
							if(strncmp(actions_line[j].name_l,str2,5)==0)
								index1=j;
							if(strncmp(actions_point[j].name_p,str1,3)==0)
								index2=j;
						}
					}
					tangent=fabs((actions_line[index1].find_line_1.y-actions_line[index1].find_line_2.y)/(actions_line[index1].find_line_1.x-actions_line[index1].find_line_2.x));
					result=fabs(tangent*(actions_point[index2].x-actions_line[index1].find_line_1.x)-(actions_point[index2].y-actions_line[index1].find_line_1.y))/sqrt(tangent*tangent+1);
					printf("%s (%s,%s)=%.1f\n",str,actions_polygon[index2].polygon_point.name_p,actions_polygon[index1].polygon_line.name_l,result);
					fprintf(write,"%s (%s,%s)=%.1f\n",str,actions_polygon[index1].polygon_line.name_l,actions_polygon[index2].polygon_point.name_p,result);

				}


			}

			

			else{						//This condition: to find the distance between the point and the point
				for(j=0;j<20;j++){
					
					if(j<9){
				
						if(strncmp(actions_point[j].name_p,str1,2)==0)
							index1=j;
						if(strncmp(actions_point[j].name_p,str2,2)==0)
							index2=j;
					}
					else{
						if(strncmp(actions_point[j].name_p,str1,3)==0)
							index1=j;
						if(strncmp(actions_point[j].name_p,str2,3)==0)
							index2=j;

					}

				}
				result=sqrt(pow((actions_point[index1].x-actions_point[index2].x),2)+pow((actions_point[index1].y-actions_point[index2].y),2));
				printf("%s (%s,%s)=%.1f\n",str,actions_polygon[index1].polygon_point.name_p,actions_polygon[index2].polygon_point.name_p,result);
				fprintf(write,"%s (%s,%s)=%.1f\n",str,actions_polygon[index1].polygon_point.name_p,actions_polygon[index2].polygon_point.name_p,result);
			}
			
			
			
			
		}
		else if (strcmp(str,"Length")==0){			//finding the Polygon's circumference or length of line
			str1 = strtok(NULL," ");
			for(j=0;j<20;j++){						
				if(strncmp(actions_polygon[0].name_polygon_p,str1,3)==0){		//Polygon's circumference 
					for(k=0;k<(number_data-2)/2;k++){
						if(k==(number_data-2)/2-1){
							result=result+sqrt(pow((actions_point[0].x-actions_point[k].x),2)+pow((actions_point[0].y-actions_point[k].y),2));
							printf("%s (%s)=%.1f\n",str,actions_polygon[0].name_polygon_p,result);
							fprintf(write,"%s (%s)=%.1f\n",str,actions_polygon[0].name_polygon_p,result);
							break;
						}
					
						result=result+sqrt(pow((actions_point[k].x-actions_point[k+1].x),2)+pow((actions_point[k].y-actions_point[k+1].y),2));
						
					}
					
					break;

				}
				else if(strncmp(actions_line[j].name_l,str1,3)==0){		//Length of line
					if(j==(number_data-2)/2-1){
						result=sqrt(pow((actions_point[j].x-actions_point[0].x),2)+pow((actions_point[j].y-actions_point[0].y),2));
						printf("%s (%s)=%.1f\n",str,actions_polygon[j].polygon_line.name_l,result);
						fprintf(write,"%s (%s)=%.1f\n",str,actions_polygon[j].polygon_line.name_l,result);
						break;

					}
					result=sqrt(pow((actions_point[j].x-actions_point[j+1].x),2)+pow((actions_point[j].y-actions_point[j+1].y),2));
					printf("%s (%s)=%.1f\n",str,actions_polygon[j].polygon_line.name_l,result);
					fprintf(write,"%s (%s)=%.1f\n",str,actions_polygon[j].polygon_line.name_l,result);

				}
				
			}
			

		}
		else if(strcmp(str,"Area")==0){
			for(k=0;k<(number_data-2)/2;k++){			
				if(k==(number_data-2)/2-1){			//formula for finding the area of the Polygon
					result=fabs(result+(actions_point[k].x*actions_point[0].y-actions_point[0].x*actions_point[k].y));
					break;
				}	
				result=result+(actions_point[k].x*actions_point[k+1].y-actions_point[k+1].x*actions_point[k].y);
			}
			printf("%s (%s)=%.1f\n",str,actions_polygon[0].name_polygon_p,result/2);
			fprintf(write,"%s (%s)=%.1f\n",str,actions_polygon[0].name_polygon_p,result/2);
		}
		else if(strcmp(str,"Angle")==0){
			str1 = strtok(NULL," ");
			str2 = strtok(NULL," ");
			for(j=0;j<20;j++){
				if(j<10){
					if(strncmp(actions_line[j].name_l,str1,3)==0)
						index1=j;
					if(strncmp(actions_line[j].name_l,str2,3)==0)
						index2=j;
				}
				else{
					if(strncmp(actions_line[j].name_l,str1,5)==0)
						index1=j;
					if(strncmp(actions_line[j].name_l,str2,5)==0)
						index2=j;
				}
			}		
			//I calculate the angle between two lines with the cosine formula

			length1=sqrt(pow((actions_line[index1].find_line_1.x-actions_line[index1].find_line_2.x),2)+pow((actions_line[index1].find_line_1.y-actions_line[index1].find_line_2.y),2));
			length2=sqrt(pow((actions_line[index2].find_line_1.x-actions_line[index2].find_line_2.x),2)+pow((actions_line[index2].find_line_1.y-actions_line[index2].find_line_2.y),2));
			result=fabs(((actions_line[index1].find_line_1.x)-(actions_line[index1].find_line_2.x))*((actions_line[index2].find_line_1.x)-(actions_line[index2].find_line_2.x)));
			result2=fabs(((actions_line[index1].find_line_1.y)-(actions_line[index1].find_line_2.y))*((actions_line[index2].find_line_1.y)-(actions_line[index2].find_line_2.y)));
			result3=(result+result2)/(length1*length2);
			arccos= acosf(result3)*180/PI;
			
			printf("%s (%s,%s)=%.1f\n",str,actions_polygon[index1].polygon_line.name_l,actions_polygon[index2].polygon_line.name_l,arccos);
			fprintf(write,"%s (%s,%s)=%.1f\n",str,actions_polygon[index1].polygon_line.name_l,actions_polygon[index2].polygon_line.name_l,arccos);
		}
	}
}


int main(){
	struct line data_line[20];
	struct point data_point[20];
	struct polygon data_polygon[20];
	int i;
	float c;
	char array[MAX_LENGTH][200];
	char text_copy[MAX_LENGTH][20];
	//text(array);
	char *str_genres;
	actions();
	//data(data_line,data_point,data_polygon);
	
	
	
	

}