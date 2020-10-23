#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct llnodes {
	int x;
	struct llnodes * next; 
} llnode;



llnode *read_linkedlist(llnode *iter,char *filename){
	int i=0,j=0;
	int d;
	char a;
	char *str;
	char *word;
	int *deneme;
	
	llnode *l;
	
	l=(llnode*)malloc(sizeof(llnode));

	FILE*fp;
	fp=fopen(filename,"r");
	word = (char*)malloc(sizeof(char));		
	while(!(feof(fp))){							
		a=fgetc(fp);							//I'm putting the characters in the file into a dynamic array of characters.
		if(a==',')
			j++;
		word = (char*)realloc(word,(i+1)* sizeof(char));	//every time I increase the size of the array with realloc.
		*(word+i)=a;
		i++;

	}
	
	str = strtok(word,",");
	l->x=atoi(str);
	iter=l;					//I'm putting a new pointer on the head of the node.
	while(j>1){
		str = strtok(NULL,",");
		l->next=(llnode*)malloc(sizeof(llnode));	//I put the numbers in order on the next X element of the node.
		l->next->x=atoi(str);
		l=l->next;
		j--;
	
	}
	l->next=NULL;		
	
	return iter;
	


}
float * stats_linkedlist(float *store_linkedlist){
	int i=0,j=0;
	int *str_int;
	float max_value;
	float min_value;
	float mean;
	float std=0; 
	int byte=0;
	float total=0;
	llnode *okan;
	llnode *p;
	okan=read_linkedlist(okan,"list.txt");
	p=okan;		//pointer for standard deviation

	store_linkedlist=(float*)calloc(5, sizeof(float));
		
	max_value=okan->x;
	min_value=okan->x;

	while(okan!=NULL){

		if(okan->x>max_value)
			max_value=okan->x;		//MAX value
		if(okan->x<min_value)
			min_value=okan->x;		//MİN value
		total=total+okan->x;
		i++;
		okan=okan->next;
		byte=byte+sizeof(int)*4;	//pointer and int size at each node
	}
	
	//store_linkedlist[1]=okan->x;
	total=total/i;
	store_linkedlist[0]=max_value;
	store_linkedlist[1]=min_value;
	store_linkedlist[2]=total;
	store_linkedlist[4]=byte;

	i=0;
	while(p!=NULL){								//calculating standard deviation
		std=std+(p->x-total)*(p->x-total);			
		i++;
		p=p->next;
	}
	std=sqrt(std/i);
	store_linkedlist[3]=std;

	return store_linkedlist;

}


int *read_array(char *filename,int *store_int){			
	int i=0,j=0,k=0;
	char a;
	char *str;
	char *word;
	int total_number;
	int convert;						//unlike the linked list, we save numbers in a dynamic array.

	
	FILE*fp;
	fp=fopen(filename,"r");
	word = (char*)malloc(sizeof(char));
	while(!(feof(fp))){
		a=fgetc(fp);
		if(a==',')
			j++;
		word = (char*)realloc(word,(i+1)* sizeof(char));
		*(word+i)=a;
		i++;

	}
	total_number=j;
	store_int = (int*)calloc(j+1, sizeof(int));

	str = strtok(word,",");
	while(j>0){
		
		store_int[k]=atoi(str);
		j--;
		k++;
		str = strtok(NULL,",");

	}
	store_int[k]=-1;
	
	fclose(fp);
	return store_int;
}
float * stats_array(float *stored_result){
	int i=0,j=0;
	int *str_int;
	float max_value;
	float min_value;
	float mean;
	float std=0; 
	int byte=0;
	float total=0;

	stored_result=(float*)calloc(5, sizeof(float));

	str_int=read_array("list.txt",str_int);
	max_value=str_int[0];
	min_value=str_int[0];
	while(str_int[i]!=-1){
		if(str_int[i]>max_value)
			max_value=str_int[i];			//MAX value
		if(str_int[i]<min_value)
			min_value=str_int[i];			//MİN value
		total=total+str_int[i];
		i++;
		byte=byte+sizeof(str_int[i]);		//Byte
		
	}
	total=total/i;
	stored_result[0]=max_value;
	stored_result[1]=min_value;
	stored_result[2]=total;
	stored_result[4]=byte;


	i=0;
	while(str_int[i]!=-1){
		std=std+(str_int[i]-total)*(str_int[i]-total);
		i++;
	}
	std=sqrt(std/i);
	stored_result[3]=std;

	return stored_result;

}


typedef struct compare{			//-------------PART_2----------------------
  int n1;
  int n2;

}compare_s;

typedef struct node {
  int x;
  struct node *next;
}nodes;


compare_s *part2(nodes *root,int *dynamic,int *counter_cpy){
  int i=0,j=0,k=0,counter=0;
  int ent_d;
  int ent_l;
  nodes *root_back;
  compare_s *host;
  dynamic=(int*)malloc(sizeof(int));
  printf("Please fill the dynamic array into you enter '-1':\n");
  while(1){

    scanf("%d",&ent_d);
    
    if(ent_d==-1)
      break;

    dynamic=(int*)realloc(dynamic,(i+1)*sizeof(int));	//I put the numbers I get from the user into the dynamic array in order.
    *(dynamic+i)=ent_d;
    i++;

  }
  
  root=(nodes*)malloc(sizeof(nodes));
  root_back=root;
  printf("Please fill the linked list into you enter '-1':\n");
  while(1){

     scanf("%d",&ent_l);
      if(ent_l==-1)
        break;
      if(j==0)
        root->x=ent_l;
      else{
        root->next=(nodes*)malloc(sizeof(nodes));	//I put the numbers I get from the user on a linked list.
        root->next->x=ent_l;
        root=root->next;
      }
      j++;

  }
  host=(compare_s*)malloc(sizeof(compare_s));
  for(k=0;k<i;k++){
    if(*(dynamic+k)!=root_back->x){								//I'm comparing the numbers in the index of the two arguments.
      host=(compare_s*)realloc(host,(counter+1)*sizeof(compare_s));
      host[counter].n1=*(dynamic+k);		//I'm putting the numbers into the hold structure.
      host[counter].n2=root_back->x;
      counter++;							//the counter is size of host structure array.
    }
    root_back=root_back->next;
   
  }
  *counter_cpy=counter;
  
  return host;						//I'm returning the structure where I put the wrong numbers.
 
}



int main(){
	float *array_linked;
	float *array_dynamic;
	int i;
	int *d1;
	int count;
	float cpu_time_used ;
	float time_taken;
	clock_t time1,time2,time3,time4; 
	
	time1 = clock(); 
	
	array_dynamic=stats_array(array_dynamic);
	
	printf("--------------DYNAMİC\n" );
	printf("MAX->%.2f\n",array_dynamic[0] );
	printf("MİN->%.2f\n",array_dynamic[1] );
	printf("MEAN->%.2f\n",array_dynamic[2] );
	printf("STD->%.2f\n",array_dynamic[3] );
	printf("Number of Byte Used->%.2f\n",array_dynamic[4] );
	time2 = clock();
    time_taken = ((float)(time2-time1))/CLOCKS_PER_SEC; // Dynamic
    printf("read_array() and stats_array() took %f seconds to execute \n", time_taken); 

    time3 = clock();
    array_linked=stats_linkedlist(array_linked);
    printf("\n--------------LİNKED_LİST\n");
	printf("MAX->%.2f\n",array_linked[0] );
	printf("MİN->%.2f\n",array_linked[1] );
	printf("MEAN->%.2f\n",array_linked[2] );
	printf("STD->%.2f\n",array_linked[3] );
	printf("Number of Byte Used->%.2f\n",array_linked[4] );
	printf("---------------------------------\n");
    time4 = clock();
    cpu_time_used = ((float)(time4-time3))/CLOCKS_PER_SEC; // LİNKED_LİST
  
    printf("read_linkedlist() and stats_linkedlist() took %f seconds to execute \n", cpu_time_used); 
    printf("\n---------------------\n");

    nodes *first_struct;
  	compare_s *second_struct;
    second_struct=part2(first_struct,d1,&count);
  	printf("------------------\n");
  	for(i=0;i<count;i++)
    	printf("-->%d,%d\n",second_struct[i].n1,second_struct[i].n2 );


	
}
