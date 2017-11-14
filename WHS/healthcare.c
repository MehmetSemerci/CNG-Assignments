#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct data{
		char name[30];
		char surname[30];
		char gender;
		int day;
		int month;
		int year;
		int waist;
		int hip;
	};

int Load_Healthcare_Table(char [],struct data [],int);
int lineCounter(char []);
void Display_Healthcare_Table(char [],struct data [],int);
int search(struct data[],int ,char [],char []);
void WHR_Interpreter(struct data [],int, int);

int main(){
	
	char inpFile[30];
	
	int lineNum;
	printf("Please enter the file name:");
	gets(inpFile);
	lineNum=lineCounter(inpFile);
	struct data patients[lineNum];
	Load_Healthcare_Table(inpFile,patients,lineNum);
	Display_Healthcare_Table(inpFile,patients,lineNum);
	char name[20],surname[20],string;
	char er[2]="X";
	
	int result;
	do{
		printf("Enter the name and surname for WHR calculation (Exit - X X):");
		fflush(stdin);
		scanf("%s %s",name,surname);
		if(strcmp(name,er)){
			result=search(patients,lineNum,name,surname);
			if(result==-1)
				printf("We don t know their details! Please try again!\n");
			else
				WHR_Interpreter(patients,lineNum,result);				
		}
		
	}while(strcmp(name,er));
	
	return 0;
}

int Load_Healthcare_Table(char file[],struct data patients[],int Lines){
	FILE *record;
	
	record=fopen(file,"r");
	if(record==NULL){
		printf("We cannot open the file :(");
		exit(1);
	}
	else
		printf("Healthcare records file has been successfully loaded!\n");
	
	int i;
	for(i=0;i<Lines;i++){
		fscanf(record,"%s %s %c %d/%d/%d %d %d",patients[i].name,patients[i].surname,&patients[i].gender,&patients[i].day,&patients[i].month,&patients[i].year,&patients[i].waist,&patients[i].hip);
	}
	fclose(record);
	return Lines;
}

void Display_Healthcare_Table(char file[],struct data patients[],int lineNum){
	printf("Following records have been loaded:\n");
	printf("Firstname    Lastname    Gender    DOB    Waist(cm)    Hip(cm)\n");
	int i;
	for(i=0;i<lineNum;i++){
		printf("%-12s %-12s %2c     %d/%d/%d %5d %10d\n",patients[i].name,patients[i].surname,patients[i].gender,patients[i].day,patients[i].month,patients[i].year,patients[i].waist,patients[i].hip);
	}
}

int search(struct data patients[],int lineNum,char name[],char surname[]){
	int i;
	for(i=0;i<lineNum;i++){
		if(!strcmp(patients[i].name,name) && !strcmp(patients[i].surname,surname)){
			return i;		
		}
	}
	return -1;
}

void WHR_Interpreter(struct data patients[],int lineNum, int position){
	float result;
	patients[position].waist+=0.0;
	float waist = patients[position].waist;
	patients[position].hip+=0.0;	
	float hip = patients[position].hip;
	result=waist/hip;
	
	printf("%s %s has WHR %.2f and classified as ",patients[position].name,patients[position].surname,result);
	if(patients[position].gender=='M'){
		if(result>1.00)
			printf("extreme\n");
		else if(result > 0.95 && result<=1.00)
			printf("high\n");
		else if(result > 0.90 && result<=0.95)
			printf("average\n");
		else if(result > 0.85 && result<=0.90)
			printf("good");
		else 
			printf("excellent\n");
	}
			
	else{
		if(result>0.90)
			printf("extreme\n");
		else if(result > 0.85 && result<=0.90)
			printf("high\n");
		else if(result > 0.80 && result<=0.85)
			printf("average\n");
		else if(result > 0.75 && result<=0.80)
			printf("good\n");
		else 
			printf("excellent\n");
	}
}

int lineCounter(char file[]){
	FILE *record;
	char c;
	record=fopen(file,"a+");
	if(record==NULL){
		printf("We cannot open the file :(");
		exit(1);
	}		
	int count=1;
	while(fscanf(record,"%c",&c)!=EOF){		
		if(c=='\n')
			count++;
	}
	fclose(record);	
	return count;	
}//MS


