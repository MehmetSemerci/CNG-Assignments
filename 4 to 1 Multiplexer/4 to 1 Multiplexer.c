#include <stdio.h>																
int main(){																		/*In this code I m working on decimals */
																				/*just for hexadecimals I m using char*/
	int menuindex=1;															/*and I could not handle the error if you enter chararater*/
																				/*while the code asks decimals the code will collapse as I m working on decimals*/
	while (menuindex==1){
		int selectlines,base,dataline,remainder,binary=0,i=1,cont=0;
		char dl16,con;
		
		printf("Welcome to 4 to 1 multiplexer!\n");
		
		printf("(1) Compute and Display the Output\n");
		printf("(2) Quit\n");
		
		printf("You choose: ");
		fflush(stdin);	
		scanf("%d",&menuindex);                                    /* it gets menu index and if it is not equal to 1*/
																   /* or 2 give error and ask again until menuindex*/
		while(menuindex!=1 && menuindex!=2){                       /* equals to 1 or 2*/
			printf("!!!You have choosen wrong option!!\n");
			printf("!!!Please select from list\n");
			
			printf("(1) Compute and Display the Output\n");
			printf("(2) Quit\n");
			
			printf("You choose: ");			
			scanf("%d",&menuindex);
		}
		if(menuindex==1){																				/*If menuindex equals to 1*/
			printf("You have chosen option 1\n");														/*it asks selectlines*/
			
			printf("Please enter select lines: ");			
			scanf("%d",&selectlines);
			
			while(selectlines!=00 && selectlines!=01 && selectlines!=10 && selectlines!=11){			/*If selectlines not two digits binary*/
				printf("It is not a 2-digit binary number for the select lines. Please try again!\n");	/*it gives error again*/
				printf("Please enter select lines: ");				
				scanf("%d",&selectlines);
			}
			printf("Which base will you use to enter data lines (base 16/10/2)? ");						/*If selectlines valid is asks base*/
			fflush(stdin);
			scanf("%d",&base);																			/*and again if input is not valid code */
			while(base!=2 && base!=10 && base!=16){														/*ask it again until it is valid*/
				printf("%d is not valid base. Please try again\n",base);												
				printf("Which base will you use to enter data lines (base 16/10/2)? ");
				scanf(" %d",&base);
			}
			switch(base){																				/*I m using switch here according to base*/
				case 2:
					printf("Please enter the data lines to decode: ");
					scanf(" %d",&dataline);																/*As there are limited valid input*/
					while(dataline!= 0 && dataline!=1 &&dataline!= 10 && dataline!=11&&					/*Code checks them one by one(Not proper way)*/
					dataline!= 100 && dataline!=101 && dataline!= 111 && dataline!=1000&&
					dataline!= 1001 && dataline!=1010 && dataline!= 1011 && dataline!=1100&&
					dataline!= 1101 && dataline!=1110 && dataline!= 1111 && dataline!=110){
						
						printf("%d is not 4-digit binary number. Please try again\n",dataline);						
						
						printf("Please enter the data lines to decode: ");
						scanf(" %d",&dataline);
					}
					switch(selectlines){												/*According to selectlines its divide the dataline by ten or its powers*/
						case 00:														/*and gives input	*/	
							printf("Output is: %d\n\n",dataline%10);
							break;
						case 01:
							dataline/=10;
							printf("Output is: %d\n\n",dataline%10);
							break;
						case 10:
							dataline/=100;
							printf("Output is: %d\n\n",dataline%10);
							break;
						case 11:
							dataline/=1000;
							printf("Output is: %d\n\n",dataline%10);
							break;
					
					}
					break;
				case 10:
					printf("Please enter the data lines to decode: ");
					scanf(" %d",&dataline);
					while(dataline > 15 || dataline < 0){																	/*gets dataline in base 10 and if*/
						printf("It is not possible to convert decimal %d to 4-digit binary number. Please try\n",dataline);	/*it is bigger than 15 (1111) give error*/
						printf("again!\n");						
						
						printf("Please enter the data lines to decode: ");
						scanf(" %d",&dataline);
					}
					
					while(dataline != 0) {        
       					remainder=dataline%2;
        				dataline=dataline/2;
        				binary=binary+(remainder*i);
        				i=i*10;
    				}
    				dataline=binary;         /*it converts dataline to binary here*/
    				
    				switch(selectlines){													/*According to selectlines its divide the dataline by ten or its powers*/
						case 00:															/*and gives input*/
							printf("Output is: %d\n\n",dataline%10);
							break;
						case 01:
							dataline/=10;
							printf("Output is: %d\n\n",dataline%10);
							break;
						case 10:
							dataline/=100;
							printf("Output is: %d\n\n",dataline%10);
							break;
						case 11:
							dataline/=1000;
							printf("Output is: %d\n\n",dataline%10);
							break;
					
					}
					break;
				case 16:																/*Here it gets input in char and in switch case according to char*/
					printf("Please enter the data lines to decode: ");					/*it gives dataline its real value*/
					fflush(stdin);
					scanf("%c%c",&dl16,&con);
					
					
					switch(dl16){
						case '0':
							dataline=0;
							break;
						case '1':
							dataline=1;
							break;
						case '2':
							dataline=2;
							break;
						case '3':
							dataline=3;
							break;
						case '4':
							dataline=4;
							break;
						case '5':
							dataline=5;
							break;
						case '6':
							dataline=6;							
							break;
						case '7':
							dataline=7;							
							break;
						case '8':
							dataline=8;							
							break;
						case '9':
							dataline=9;							
							break;
						case 'a':case 'A':
							dataline=10;
							break;
						case 'b':case 'B':
							dataline=11;
							break;
						case 'c':case 'C':
							dataline=12;
							break;
						case 'd':case 'D':
							dataline=13;
							break;
						case 'e':case 'E':
							dataline=14;
							break;
						case 'f':case 'F':
							dataline=15;
							break;
						default:
							cont=1;	  												/*cont is controller variable here*/
					}
					if(con!=10){
							cont=1;
					}
					else;
					
					while(cont==1){													/*if cont equals to 1 it gives error and do the same thing until*/
						printf("It is not valid. Please try again\n");				/*it gets valid input*/
											
						cont=0;
						printf("Please enter the data lines to decode: ");
						fflush(stdin);
						scanf("%c%c",&dl16,&con);
						
						switch(dl16){
							case '0':
								dataline=0;
								break;
							case '1':
								dataline=1;
								break;
							case '2':
								dataline=2;
								break;
							case '3':
								dataline=3;
								break;
							case '4':
								dataline=4;
								break;
							case '5':
								dataline=5;
								break;
							case '6':
								dataline=6;
								break;
							case '7':
								dataline=7;
								break;
							case '8':
								dataline=8;
								break;
							case '9':
								dataline=9;
								break;
							case 'a':case 'A':
								dataline=10;
								break;
							case 'b':case 'B':
								dataline=11;
								break;
							case 'c':case 'C':
								dataline=12;
								break;
							case 'd':case 'D':
								dataline=13;
								break;
							case 'e':case 'E':
								dataline=14;
								break;
							case 'f':case 'F':
								dataline=15;
								break;
							default:
								cont=1;	
						}
						if(con!=10){
							cont=1;
						}
						else;
					}
					
					while(dataline != 0) {
       					remainder=dataline%2;
        				dataline=dataline/2;
        				binary=binary+(remainder*i);
        				i=i*10;
    				}
    				dataline=binary;			/*it converts dataline to binary here*/
    				
					switch(selectlines){
						case 00:													/*According to selectlines its divide the dataline by ten or its powers*/
							printf("Output is: %d\n\n",dataline%10);				/*and gives input*/
							break;										
						case 01:
							dataline/=10;
							printf("Output is: %d\n\n",dataline%10);
							break;
						case 10:
							dataline/=100;
							printf("Output is: %d\n\n",dataline%10);
							break;
						case 11:
							dataline/=1000;
							printf("Output is: %d\n\n",dataline%10);
							break;
					
					}
					break;	
			}
		}
		
		else if(menuindex==2){                      /*BYE*/
			printf("You have chosen option 2\n");
			printf("Byee!!");
		}
	}

	
	
	
	
	return 0;
}//MS
