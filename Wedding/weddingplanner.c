#include <stdio.h>


void menu(void);
int choice(void);
int guestnum();
int invi(int);
int table(int);
int drinks(int , int * ,int * );
int invicost(int);
int drinkscost(int,int);
void all(int,int,int,int,int);

int main(){
	
	printf("The Wedding Planning Assistant is pleased to be at your service!\n");
	int cho=1,numguest=-1,numinvi=-1,numcoke=-1,numwater=-1,costinv,costdrink;
	int numt=-1;
	
	do{
	menu();
	cho=choice();
	switch(cho){
		case 1:
			numguest=guestnum();
			numinvi=-1;
			break;
		case 2:
			numinvi=invi(numguest);
			break;
		case 3:
			numt=table(numguest);
			break;
		case 4:
			drinks(numguest,&numcoke,&numwater);
			break;
		case 5:
			costinv=invicost(numinvi);
			break;
		case 6:
			drinkscost(numcoke,numwater);
			break;
		case 7:
			all(numguest,numt,numinvi,numcoke,numwater);
			break;
		case 8:
			printf("BYE!");			
		}
	}while(cho!=8);
		
	return 0;
}
void menu(void){
		printf("1. Enter number of invited guests. \n");
		printf("2. Determine the number of invitation cards and sweets. \n");
		printf("3. Determine the number of tables needed. \n");
		printf("4. Determine drinks order. \n");
		printf("5. Cost of invitation cards. \n");
		printf("6. Cost of drinks. \n");
		printf("7. Display all information. \n");
		printf("8. Quit. \n");
}
int choice(){
	int c;
	printf("Choice: ");
	scanf("%d",&c);
	while(c>8 || c<1){
		printf("Its invalid, try again!\n");
		printf("Choice: ");
		scanf("%d",&c);
	}
	return c;
}
int guestnum(void){
	int num;
	printf("Enter the number of guests: ");
	scanf("%d",&num);
	while(num<1){
		printf("!!!Please enter a positive number!: ");
		scanf("%d",&num);
	}
	return num;
}
int invi(int num){
	int invinum=-1;
	if(num==-1)
		printf("You should select 1st option before choose this option.\n");
	else {
		if(num%2)
			invinum = num/2+1;
		else 
			invinum =num/2;
		printf("You need %d invitation cards and %.0f sweets.\n",invinum,num*1.2);
		
	}	
	return invinum;
	
}
int table(int num){
	if(num==-1)
		printf("You should select 1st option before choose this option.\n");
	else{	
		if(num%6){
			printf("You need %d tables.\n",num/6+1);
			return num/6+1;}
		else{
			printf("You need %d tables.\n",num/6);
			return num/6;}
	}
}
int drinks(int num, int *numcokep, int *numwaterp){
	if(num==-1)
		printf("You should select 1st option before choose this option.\n");
	else{
		*numcokep=num/6;
		if(num%2)
			*numwaterp=num/2+1;
		else
			*numwaterp=num/2;
		printf("You need %d cases of coke and %d cases of water.\n",*numcokep,*numwaterp);		
		
	}		
}

int invicost(num){
	if(num==-1)
		printf("You should select 1st and 2nd options before choose this option!\n");
	else{
		printf("Cost of invitation card: %d TL\n",num*10);
		return num*10;
	}
}
int drinkscost(coke,water){
	if(coke==-1)
		printf("You should select 1st and 4th options before choose this option!\n");
	else{
		printf("Cost of drinks: %d TL for coke and %d TL for water with a total of %d TL.\n",coke*5,water*3,coke*5+water*3);			
	}	
}
void all(numguest,numt,numinvi,numcoke,numwater){
	if(numinvi==-1||numwater==-1||numt==-1)
		printf("You should choose 1st, 2nd, 3rd and 4th options first!\n");
	else{
		invi(numguest);
		table(numguest);
		drinks(numguest,&numcoke,&numwater);
		invicost(numinvi);
		drinkscost(numcoke,numwater);		
	}
}//MS

