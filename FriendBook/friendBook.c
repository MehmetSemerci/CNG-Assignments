#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

struct Node{
	char name[15];
	char surname[15];
	char gender[4];
	char birth[10];
	struct Node *next;
};

struct Node* insertFriend(struct Node *friendList);
struct Node* initialiseFriendBook(char file[]);
int printFriendList(struct Node *list);
void insertNode(struct Node *list, struct Node *newNode);
int findPos(struct Node *friendList, struct Node *newFriend);
int searchFriend(struct Node *list);
struct Node* blockFriend(struct Node *blocked,struct Node *list);
int printBlockedFriends(struct Node* list);


int main(){
	
	struct Node *myFriendList,*blocked;
	
	blocked = (struct Node *) malloc(sizeof(struct Node));
	blocked->next=(struct Node *) malloc(sizeof(struct Node));
	blocked->next->next=NULL;
	strcpy(blocked->name, "Aaa");
	strcpy(blocked->next->name, "Zzz");
	
	char file[20];
	int choice;
	int exit = FALSE;
	printf("Please enter your file name:");
	gets(file);	
	myFriendList=initialiseFriendBook(file);
	
	while(exit!=TRUE){
			
		do{
		
			printf("(1) Insert a new friend\n");
			printf("(2) Print your friends\n");
			printf("(3) Search for your friend\n");
			printf("(4) Block your friend\n");
			printf("(5) Print your blocked friend\n");
			printf("(6) Exit\n");
			printf("Enter your option:");
			scanf("%d",&choice);
			
			if(choice<0||choice>6){
				printf("Wrong choice!\n");
			}
			
		}while(choice<0||choice>6);
		
		switch(choice){
			
			case 1:
				insertFriend(myFriendList);
				break;
			case 2:
				printFriendList(myFriendList);
				break;
			case 3:
				searchFriend(myFriendList);
				break;
			case 4:
				myFriendList=blockFriend(blocked,myFriendList);
				break;
			case 5:
				printBlockedFriends(blocked);
				break;
			case 6:
				printf("BYE!");
				exit=TRUE;			
		}
	}
	

	return 0;
}

struct Node* initialiseFriendBook(char file[]){
	
	
	FILE *friends;
	
	friends = fopen(file,"r");
	
	char c[2];							//This part is mainly about
	fgets(c,2,friends);					//whether the file is empty 
	if(strcoll(c,"Aaa")>0){				//or not.			           
		rewind(friends);				//
	}
	
	
	
	if(friends==NULL){
		printf("We cannot open your friend list :(\n");
		exit(1);
	}
	else
		printf("Your FriendBook has been created.\n");
	
	struct Node *myFriendList,*temp,*newFriend,*head,*nef;
	
	newFriend =	(struct Node *) malloc(sizeof(struct Node));
	newFriend->next=NULL;
	
	myFriendList = (struct Node *) malloc(sizeof(struct Node));			//To understand where to start and
	myFriendList->next=(struct Node *) malloc(sizeof(struct Node));		//stop I created empty nodes
	myFriendList->next->next=NULL;										//their name values are "Aaa" and "Zzz"
	strcpy(myFriendList->name, "Aaa");									//which are the upperLimits for names
	strcpy(myFriendList->next->name, "Zzz");							//
	
	head = myFriendList;
	
	int counter=0;
	char string[80];
	char s[2]=";";
	char *token;
	
	while(!feof(friends)){		
		head=myFriendList;
		
		fgets(string,80,friends);
		token = strtok(string, s);						//Here I m dividing my string
														// and copying them to newFriend
					  	
		strcpy(newFriend->name, token);
		
		token = strtok(NULL, s);
		strcpy(newFriend->surname, token);
		
		token = strtok(NULL, s);
		strcpy(newFriend->gender, token);
	  	
		token = strtok(NULL, s);
		strcpy(newFriend->birth, token);					  	
							
		token=NULL;
			
		insertNode(head,newFriend);		
	}
	fclose(friends);
	
	return myFriendList;		
	
}

void insertNode(struct Node *list, struct Node *newNode){
	
	struct Node *neww;
	neww=(struct Node *) malloc(sizeof(struct Node));
	neww->next=NULL;
	
	strcpy(neww->name,newNode->name);					//Here I m copying my newNode to
	strcpy(neww->surname,newNode->surname);				//another node to avoid some errors
	strcpy(neww->gender,newNode->gender);				//
	strcpy(neww->birth,newNode->birth);
	
	int i=0;
	int n=findPos(list,neww);
	
	while(i<n){		
		list=list->next;
		i++;		
	}
	
	neww->next=list->next;
	list->next=neww;
	
}
struct Node* insertFriend(struct Node *friendList){
	
	struct Node *newFriend=(struct Node *) malloc(sizeof(struct Node));
	
	printf("Enter the details of your friend to insert.\n");
	
	printf("First name:");
	fflush(stdin);
	gets(newFriend->name);
	while(strcoll("",newFriend->name)==0){                  
		printf("Please enter valid information!\n");		//Error checking
		printf("First name:");								//
		fflush(stdin);
		gets(newFriend->name);
	}
	
	printf("Second name:");
	fflush(stdin);
	gets(newFriend->surname);
	while(strcoll("",newFriend->surname)==0){				//Error checking
		printf("Please enter valid information!\n");
		printf("Second name:");
		fflush(stdin);
		gets(newFriend->surname);
	}
	
	printf("Gender:");
	fflush(stdin);
	gets(newFriend->gender);
	while(strcoll("",newFriend->gender)==0){				//Error checking
		printf("Please enter valid information!\n");
		printf("Gender:");
		fflush(stdin);
		gets(newFriend->gender);
	}
	
	printf("Birth Date:");
	fflush(stdin);
	gets(newFriend->birth);
	while(strcoll("",newFriend->birth)==0){					//Error checking
		printf("Please enter valid information!\n");
		printf("Birth Date:");
		fflush(stdin);
		gets(newFriend->birth);
	}
	
	insertNode(friendList,newFriend);
	printf("%s added to your friend list\n",newFriend->name);
	
	
	return friendList;
}

int findPos(struct Node *friendList, struct Node *newFriend){
	
	int counter=0;
	

	while(strcoll(friendList->name,"Zzz")!=0){					//reads until my last node
		
		int n=strcoll(friendList->name,newFriend->name);
						
		if(n<0){
			counter++;											//compares mylast name and new name
		}	
																
		friendList=friendList->next;			
	}
	return counter-1;
	
}

int printFriendList(struct Node *list){
	
	if(strcoll(list->name,"Aaa")==0&&strcoll(list->next->name,"Zzz")==0){
		printf("You don't have any friends in your list.\n");
		return 0;
	}
	
	printf("Name      Surname        Gender    Birth Date\n");
	//printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	while(list!=NULL){
		
		if(strcoll(list->name,"Aaa")!=0&&strcoll(list->name,"Zzz")!=0){		
			printf("%-10s%-17s%-8s%-10s\n",list->name,list->surname,list->gender,list->birth);						
		}
		
		list=list->next;
	}
	printf("\n");
	
}

int searchFriend(struct Node *list){
	
	if(strcoll(list->name,"Aaa")==0&&strcoll(list->next->name,"Zzz")==0){
		printf("You don't have any friends in your list.\n\a");
		return 0;
	}
	
	char name[20];															//In order to have O(logn)
																			//search algorithm like binary search, we should
	printf("Enter the first name of your friend to search.\n");				//know both next and previous element
	printf("First name:");													//but here we are using linked list
	fflush(stdin);															//so it is a bit hard to use O(logn) algorithm
	gets(name);
	
	while(strcoll(list->name,name)!=0){
		list=list->next;
		if(list==NULL){
			printf("We could not find a friend named \"%s\"\n",name);
			return 0;
		}		
	}
	printf("Your friend is in your friend list.\n");
	printf("Name      Surname        Gender    Birth Date\n");
	//printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%-10s%-17s%-8s%-10s\n\n",list->name,list->surname,list->gender,list->birth);
		
}

struct Node* blockFriend(struct Node *blocked,struct Node *list){
	
	if(strcoll(list->name,"Aaa")==0&&strcoll(list->next->name,"Zzz")==0){
		printf("You don't have any friends to block.\n\a");
		return list;
	}
	
	
	struct Node *toBlock,*temp;
	temp=list;
	toBlock=(struct Node *) malloc(sizeof(struct Node));
	toBlock->next=NULL;
	
	char name[20];
	printf("Enter the first name of your friend to block.\n");
	printf("First name:");
	fflush(stdin);
	gets(name);
	
	
	while(strcoll(temp->next->name,name)!=0){
		temp=temp->next;
		if(strcoll(temp->next->name,"Zzz")==0){
			printf("We could not find friend named \"%s\"\n",name);
			return list;
		}
	}
	strcpy(toBlock->name,temp->next->name);
	strcpy(toBlock->surname,temp->next->surname);
	strcpy(toBlock->gender,temp->next->gender);
	strcpy(toBlock->birth,temp->next->birth);
	insertNode(blocked,toBlock);
	printf("%s added to your blocked friend list\n\a",toBlock->name);
	
	temp->next=temp->next->next;
	
	return list;
}
int printBlockedFriends(struct Node* list){
	
	if(strcoll(list->name,"Aaa")==0&&strcoll(list->next->name,"Zzz")==0){
		printf("You don't have any blocked friends in your list.\n");
		return 0;
	}
	
	printf("Your blocked friends are listed below.\n");
	printf("Name      Surname        Gender    Birth Date\n");
	//printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	while(list!=NULL){
		
		if(strcoll(list->name,"Aaa")!=0&&strcoll(list->name,"Zzz")!=0){		
			printf("%-10s%-17s%-8s%-10s\n",list->name,list->surname,list->gender,list->birth);						
		}
		
		list=list->next;
	}
	printf("\n");
}






