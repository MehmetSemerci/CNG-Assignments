#include <stdio.h>
#include <stdlib.h>
#include <time.h>
							
int roll_a_dice(void);
int first_roll(void);
int Ones(int,int,int,int,int);
int Twos(int,int,int,int,int);
int Threes(int,int,int,int,int);
int Fours(int,int,int,int,int);
int Fives(int,int,int,int,int);
int Sixes(int,int,int,int,int);
int Full_House(int,int,int,int,int);
int FourOfAKind(int,int,int,int,int);
int LittleStraight(int,int,int,int,int);
int BigStraight(int,int,int,int,int);
int Choice(int,int,int,int,int);
int Yacht(int,int,int,int,int);
int playHuman();
int playComputer();
int rulesHum(int,int,int,int,int,int);
int compStrategy(int,int,int,int,int);
int scoreSheet(int,int);

int main(){
	srand(time(NULL));
	
	printf("Welcome to the Yatch game.\n");
	printf("Lets see who is lucky!\n");
	
	int i,pla,com;
	
	if(first_roll()){
		printf("Player is the lucky one, lets get started!\n");
		for(i=1;i<13;i++){
			printf("\n\n");
			printf("Round %d\n",i);
			printf("======================================\n");
			pla=playHuman();
			printf("\n");
			com=playComputer();			
		}			
	}
	else{
		printf("Computer is the lucky one, lets get started!\n");
		for(i=1;i<13;i++){
			printf("\n\n");
			printf("Round %d\n",i);
			printf("======================================\n");
			com=playComputer();
			printf("\n");
			pla=playHuman();
		}
	}
	
	if(com>pla){
		printf("Winner is Computer\n");
	}
	else if (pla>com){													//Deciding who is the winner!
		printf("Winner is Player\n");
		
	}
	else printf("Draw");

	system("PAUSE");
	return 0;
}

int roll_a_dice(){
	return rand()%6+1;
}

int first_roll(){
	int comp,pla;
	do{
		comp=roll_a_dice();
		pla=roll_a_dice();		
	}while(pla==comp);
	printf("Player: %d - Machine: %d\n",pla,comp);
	if(pla>comp)
		return 1;
	else return 0;
}
int Ones(int d1,int d2,int d3,int d4,int d5){
	int total=0;
	if(d1==1)
		total++;
	if(d2==1)												//Pointing strategy
		total++;
	if(d3==1)				
		total++;
	if(d4==1)
		total++;
	if(d5==1)
		total++;
	return total;	
}
int Twos(int d1,int d2,int d3,int d4,int d5){
	int total=0;
	if(d1==2)
		total+=2;										//Pointing strategy
	if(d2==2)
		total+=2;
	if(d3==2)
		total+=2;
	if(d4==2)
		total+=2;
	if(d5==2)
		total+=2;
	return total;	
}
int Threes(int d1,int d2,int d3,int d4,int d5){
	int total=0;
	if(d1==3)
		total+=3;
	if(d2==3)											//Pointing strategy
		total+=3;
	if(d3==3)
		total+=3;
	if(d4==3)
		total+=3;
	if(d5==3)
		total+=3;
	return total;	
}
int Fours(int d1,int d2,int d3,int d4,int d5){
	int total=0;
	if(d1==4)													//Pointing strategy
		total+=4;
	if(d2==4)
		total+=4;
	if(d3==4)
		total+=4;
	if(d4==4)
		total+=4;
	if(d5==4)
		total+=4;
	return total;	
}
int Fives(int d1,int d2,int d3,int d4,int d5){
	int total=0;
	if(d1==5)
		total+=5;
	if(d2==5)											//Pointing strategy
		total+=5;
	if(d3==5)
		total+=5;
	if(d4==5)
		total+=5;
	if(d5==5)
		total+=5;
	return total;	
}
int Sixes(int d1,int d2,int d3,int d4,int d5){
	int total=0;
	if(d1==6)
		total+=6;
	if(d2==6)											//Pointing strategy
		total+=6;
	if(d3==6)
		total+=6;
	if(d4==6)
		total+=6;
	if(d5==6)
		total+=6;
	return total;	
}
int Full_House(int d1,int d2,int d3,int d4,int d5){
	if((d1==d2)&&(d1==d3)){
		if(d5==d4) return (d1+d2+d3+d4+d5);
		else return 0;
	}
	else if((d1==d2)&&(d1==d4)){								//Pointing strategy	
		if(d3==d5) return (d1+d2+d3+d4+d5);
		else return 0;				
	}
	else if((d1==d2)&&(d1==d5)){								//Here the program checking all the possible combinations for full house
		if(d3==d4) return (d1+d2+d3+d4+d5);
		else return 0;
	}
	else if((d2==d3)&&(d2==d4)){
		if(d1==d5) return (d1+d2+d3+d4+d5);
		else return 0;
	}
	else if((d2==d3)&&(d2==d5)){
		if(d1==d4) return (d1+d2+d3+d4+d5);
		else return 0;
	}
	else if((d2==d4)&&(d2==d5)){
		if(d1==d3) return (d1+d2+d3+d4+d5);
		else return 0;
	}
	else if((d1==d3)&&(d1==d4)){
		if(d2==d5) return (d1+d2+d3+d4+d5);
		else return 0;
	}
	else if((d1==d4)&&(d1==d5)){
		if(d2==d3) return (d1+d2+d3+d4+d5);
		else return 0;
	}
	else if((d1==d3)&&(d1==d5)){
		if(d2==d4) return (d1+d2+d3+d4+d5);
		else return 0;
	}
	else if((d3==d4)&&(d3==d5)){
		if(d2==d1) return (d1+d2+d3+d4+d5);
		else return 0;
	}
	else return 0;	
}
int FourOfAKind(int d1,int d2,int d3,int d4,int d5){
	if((d1==d2)&&(d1==d3)&&(d1==d4))
		return d1*4;
	else if((d1==d2)&&(d1==d3)&&(d1==d5))
		return d1*4;
	else if((d1==d2)&&(d1==d4)&&(d1==d5))
		return d1*4;												//Pointing strategy
	else if((d1==d3)&&(d1==d4)&&(d1==d5))
		return d1*4;
	else if((d2==d3)&&(d2==d4)&&(d2==d5))
		return d2*4;
	else return 0;	
}
int LittleStraight(int d1,int d2,int d3,int d4,int d5){
	if(((d1==1)||(d2==1)||(d3==1)||(d4==1)||(d5==1))&&
	((d1==2)||(d2==2)||(d3==2)||(d4==2)||(d5==2))&&
	((d1==3)||(d2==3)||(d3==3)||(d4==3)||(d5==3))&&							//Pointing strategy
	((d1==4)||(d2==4)||(d3==4)||(d4==4)||(d5==4))&&
	((d1==5)||(d2==5)||(d3==5)||(d4==5)||(d5==5)))
		return 30;
	else return 0;	
}
int BigStraight(int d1,int d2,int d3,int d4,int d5){
	if(((d1==6)||(d2==6)||(d3==6)||(d4==6)||(d5==6))&&
	((d1==2)||(d2==2)||(d3==2)||(d4==2)||(d5==2))&&
	((d1==3)||(d2==3)||(d3==3)||(d4==3)||(d5==3))&&						//Pointing strategy
	((d1==4)||(d2==4)||(d3==4)||(d4==4)||(d5==4))&&
	((d1==5)||(d2==5)||(d3==5)||(d4==5)||(d5==5)))
		return 30;
	else return 0;
}
int Choice(int d1,int d2,int d3,int d4,int d5){							//Pointing strategy
	return d1+d2+d3+d4+d5;
}
int Yacht(int d1,int d2,int d3,int d4,int d5){
	if((d1==d2)&&(d1==d3)&&(d1==d4)&&(d1==d5))
		return  50;
	else return 0;															//Pointing strategy
}
int playHuman(){
	int d1,d2,d3,d4,d5,i=0,rule,score,check;
	static int total=0;

	char choice;
	printf("Rolled dice for you:\n");
	printf("Dice1: %d, ",d1=roll_a_dice());
	printf("Dice2: %d, ",d2=roll_a_dice());
	printf("Dice3: %d, ",d3=roll_a_dice());
	printf("Dice4: %d, ",d4=roll_a_dice());
	printf("Dice5: %d\n",d5=roll_a_dice());
	
	do{	
		if(check==1){
			printf("Rolled dice for you:\n");
			printf("Dice1: %d, ",d1=roll_a_dice());
			printf("Dice2: %d, ",d2=roll_a_dice());
			printf("Dice3: %d, ",d3=roll_a_dice());
			printf("Dice4: %d, ",d4=roll_a_dice());						//Play human function
			printf("Dice5: %d\n",d5=roll_a_dice());
		}
		printf("Do you want roll again or not (Y/N): ");
		fflush(stdin);
		scanf("%c",&choice);
		if(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N'){
			printf("Its invalid\n");
			check=2;
		}
		else{
			if(choice=='y'||choice=='Y') check=1;
			else check=0;
			i++;
		}
	}while(check&&(i<3));
	if((i==3)&&(choice=='y'||choice=='Y')) printf("You ran out of chances!\n");
	do{
	printf("Which scoring rule you would like to use (1: ones, 2: twos, 3: threes, 4: fours, 5: fives, 6: sixes, 7: full house, 8: four_of_a_kind, 9: littlestraight, 10: big straight, 11: choice, 12: yacht):");
	fflush(stdin);
	scanf("%d",&rule);
	}while(((score=rulesHum(rule,d1,d2,d3,d4,d5))==-1));
	
	total=scoreSheet(score,total);
	return total;
	
}
int playComputer(){
	int d1,d2,d3,d4,d5,rule,score;
	static int total=0;
	printf("Rolled dice for computer:\n");
	
	printf("Dice1: %d, ",d1=roll_a_dice());
	printf("Dice2: %d, ",d2=roll_a_dice());
	printf("Dice3: %d, ",d3=roll_a_dice());
	printf("Dice4: %d, ",d4=roll_a_dice());
	printf("Dice5: %d\n",d5=roll_a_dice());
	rule = compStrategy(d1,d2,d3,d4,d5);							//Its getting a value for a strategy from comStrategy function which is to determine
	switch(rule){													//which strategy will be used and then by switch statement evaulating
		case 1:
			printf("Rule 1 (ones) is used!\n");
			score=Ones(d1,d2,d3,d4,d5);
			break;
		case 2:
			printf("Rule 2 (twos) is used!\n");
			score=Twos(d1,d2,d3,d4,d5);
			break;
		case 3:
			printf("Rule 3 (thress) is used!\n");
			score=Threes(d1,d2,d3,d4,d5);
			break;
		case 4:
			printf("Rule 4 (fours) is used!\n");
			score=Fours(d1,d2,d3,d4,d5);
			break;
		case 5:
			printf("Rule 5 (fives) is used!\n");
			score=Fives(d1,d2,d3,d4,d5);
			break;
		case 6:
			printf("Rule 6 (sixes) is used!\n");
			score=Sixes(d1,d2,d3,d4,d5);
			break;
		case 7:
			printf("Rule 7 (full house) is used!\n");
			score=Full_House(d1,d2,d3,d4,d5);
			break;
		case 8:
			printf("Rule 8 (four of a kind) is used!\n");
			score=FourOfAKind(d1,d2,d3,d4,d5);
			break;
		case 9:
			printf("Rule 9 (little straight) is used!\n");
			score=LittleStraight(d1,d2,d3,d4,d5);
			break;
		case 10:
			printf("Rule 10 (big straight) is used!\n");
			score=BigStraight(d1,d2,d3,d4,d5);
			break;
		case 11:
			printf("Rule 11 (choice) is used!\n");
			score=Choice(d1,d2,d3,d4,d5);
			break;
		case 12:
			printf("Rule 12 (yacht) is used!\n");
			score=Yacht(d1,d2,d3,d4,d5);
			break;			
	}
	total=scoreSheet(score,total);
	return total;
	
}
int rulesHum(int rule,int d1,int d2,int d3,int d4,int d5){
	static int ones,twos,threes,fours,fives,sixes,fullHouse,FourOfaKind,LStra,BStra,choice,yacht;
	
	switch(rule){
		case 1:
			if(ones==0){							
				ones++;
				return Ones(d1,d2,d3,d4,d5);
			}
			else{
				printf("You cannot use this, already used it!\n");
				return -1;
			}
			break;																		//An extra function to check whether player used the strategy before or not
		case 2:
			if(twos==0){							
				twos++;
				return Twos(d1,d2,d3,d4,d5);
			}
			else{
				printf("You cannot use this, already used it!\n");
				return -1;
			}
			break;
		case 3:
			if(threes==0){							
				threes++;
				return Threes(d1,d2,d3,d4,d5);
			}
			else{
				printf("You cannot use this, already used it!\n");
				return -1;
			}
			break;
		case 4:
			if(fours==0){							
				fours++;
				return Fours(d1,d2,d3,d4,d5);
			}
			else{
				printf("You cannot use this, already used it!\n");
				return -1;
			}
			break;
		case 5:
			if(fives==0){							
				fives++;
				return Fives(d1,d2,d3,d4,d5);
			}
			else{
				printf("You cannot use this, already used it!\n");
				return -1;
			}
			break;
		case 6:
			if(sixes==0){							
				sixes++;
				return Sixes(d1,d2,d3,d4,d5);
			}
			else{
				printf("You cannot use this, already used it!\n");
				return -1;
			}
			break;		
		case 7:
			if(fullHouse==0){							
				fullHouse++;
				return Full_House(d1,d2,d3,d4,d5);
			}
			else{
				printf("You cannot use this, already used it!\n");
				return -1;
			}
			break;
		case 8:
			if(FourOfaKind==0){							
				FourOfaKind++;
				return FourOfAKind(d1,d2,d3,d4,d5);
			}
			else{
				printf("You cannot use this, already used it!\n");
				return -1;
			}
			break;
		case 9:
			if(LStra==0){							
				LStra++;
				return LittleStraight(d1,d2,d3,d4,d5);
			}
			else{
				printf("You cannot use this, already used it!\n");
				return -1;
			}
			break;
		case 10:
			if(BStra==0){							
				BStra++;
				return BigStraight(d1,d2,d3,d4,d5);
			}
			else{
				printf("You cannot use this, already used it!\n");
				return -1;
			}
			break;
		case 11:
			if(choice==0){							
				choice++;
				return Choice(d1,d2,d3,d4,d5);
			}
			else{
				printf("You cannot use this, already used it!\n");
				return -1;
			}
			break;
		case 12:
			if(yacht==0){							
				yacht++;
				return Yacht(d1,d2,d3,d4,d5);
			}
			else{
				printf("You cannot use this, already used it!\n");
				return -1;
			}
			break;
		default:
			printf("Please enter a valid option\n");
			return -1;		
	}
}
int compStrategy(int d1,int d2,int d3,int d4,int d5){
	static int cone=0,ctwo=0,cthree=0,cfour=0,cfive=0,csix=0,cfull=0,cfouroak=0,clittle=0,cbig=0,cchoice=0,cyacht=0;
	int one = Ones(d1,d2,d3,d4,d5);
	int two = Twos(d1,d2,d3,d4,d5);
	int three = Threes(d1,d2,d3,d4,d5);
	int four = Fours(d1,d2,d3,d4,d5);
	int five = Fives(d1,d2,d3,d4,d5);
	int six = Sixes(d1,d2,d3,d4,d5);
	int full = Full_House(d1,d2,d3,d4,d5);									//here its deciding which strategy is bigger and according to this, returning a value
	int fouroak = FourOfAKind(d1,d2,d3,d4,d5);
	int little = LittleStraight(d1,d2,d3,d4,d5);
	int big = BigStraight(d1,d2,d3,d4,d5);
	int choice = Choice(d1,d2,d3,d4,d5);
	int yacht = Yacht(d1,d2,d3,d4,d5);
		
	
	if(cone!=1){
		if(((one>=two)||(ctwo==1))&&((one>=three)||(cthree==1))&&((one>=four)||(cfour==1))&&
		((one>=five)||(cfive==1))&&((one>=six)||(csix==1))&&((one>=full)||(cfull==1))&&
		((one>=fouroak)||(cfouroak==1))&&((one>=little)||(clittle==1))&&((one>=big)||(cbig==1))&&
		((one>=choice)||(cchoice==1))&&((one>=yacht)||(cyacht==1))){
			cone=1;
			return 1;}
	}
	if(ctwo!=1){
		if(((two>=one)||(cone==1))&&((two>=three)||(cthree==1))&&((two>=four)||(cfour==1))&&
		((two>=five)||(cfive==1))&&((two>=six)||(csix==1))&&((two>=full)||(cfull==1))&&
		((two>=fouroak)||(cfouroak==1))&&((two>=little)||(clittle==1))&&((two>=big)||(cbig==1))&&
		((two>=choice)||(cchoice==1))&&((two>=yacht)||(cyacht==1))){
			ctwo=1;
			return 2;}
	}
	if(cthree!=1){
		if(((three>=one)||(cone==1))&&((three>=two)||(ctwo==1))&&((three>=four)||(cfour==1))&&
		((three>=five)||(cfive==1))&&((three>=six)||(csix==1))&&((three>=full)||(cfull==1))&&
		((three>=fouroak)||(cfouroak==1))&&((three>=little)||(clittle==1))&&((three>=big)||(cbig==1))&&
		((three>=choice)||(cchoice==1))&&((three>=yacht)||(cyacht==1))){
			cthree=1;
			return 3;}
	}
	if(cfour!=1){
		if(((four>=one)||(cone==1))&&((four>=two)||(ctwo==1))&&((four>=three)||(cthree==1))&&
		((four>=five)||(cfive==1))&&((four>=six)||(csix==1))&&((four>=full)||(cfull==1))&&
		((four>=fouroak)||(cfouroak==1))&&((four>=little)||(clittle==1))&&((four>=big)||(cbig==1))&&
		((four>=choice)||(cchoice==1))&&((four>=yacht)||(cyacht==1))){
			cfour=1;
			return 4;}
	}
	if(cfive!=1){
		if(((five>=one)||(cone==1))&&((five>=two)||(ctwo==1))&&((five>=three)||(cthree==1))&&
		((five>=four)||(cfour==1))&&((five>=six)||(csix==1))&&((five>=full)||(cfull==1))&&
		((five>=fouroak)||(cfouroak==1))&&((five>=little)||(clittle==1))&&((five>=big)||(cbig==1))&&
		((five>=choice)||(cchoice==1))&&((five>=yacht)||(cyacht==1))){
			cfive=1;
			return 5;}
	}
	if(csix!=1){
		if(((six>=one)||(cone==1))&&((six>=two)||(ctwo==1))&&((six>=three)||(cthree==1))&&
		((six>=four)||(cfour==1))&&((six>=five)||(cfive==1))&&((six>=full)||(cfull==1))&&
		((six>=fouroak)||(cfouroak==1))&&((six>=little)||(clittle==1))&&((six>=big)||(cbig==1))&&
		((six>=choice)||(cchoice==1))&&((six>=yacht)||(cyacht==1))){
			csix=1;
			return 6;}
	}
	if(cfull!=1){
		if(((full>=one)||(cone==1))&&((full>=two)||(ctwo==1))&&((full>=three)||(cthree==1))&&
		((full>=four)||(cfour==1))&&((full>=five)||(cfive==1))&&((full>=six)||(csix==1))&&
		((full>=fouroak)||(cfouroak==1))&&((full>=little)||(clittle==1))&&((full>=big)||(cbig==1))&&
		((full>=choice)||(cchoice==1))&&((full>=yacht)||(cyacht==1))){
			cfull=1;
			return 7;}
	}
	if(cfouroak!=1){
		if(((fouroak>=one)||(cone==1))&&((fouroak>=two)||(ctwo==1))&&((fouroak>=three)||(cthree==1))&&
		((fouroak>=four)||(cfour==1))&&((fouroak>=five)||(cfive==1))&&((fouroak>=six)||(csix==1))&&
		((fouroak>=full)||(cfull==1))&&((fouroak>=little)||(clittle==1))&&((fouroak>=big)||(cbig==1))&&
		((fouroak>=choice)||(cchoice==1))&&((fouroak>=yacht)||(cyacht==1))){
			cfouroak=1;
			return 8;}
	}
	if(clittle!=1){
		if(((little>=one)||(cone==1))&&((little>=two)||(ctwo==1))&&((little>=three)||(cthree==1))&&
		((little>=four)||(cfour==1))&&((little>=five)||(cfive==1))&&((little>=six)||(csix==1))&&
		((little>=full)||(cfull==1))&&((little>=fouroak)||(cfouroak==1))&&((little>=big)||(cbig==1))&&
		((little>=choice)||(cchoice==1))&&((little>=yacht)||(cyacht==1))){
			clittle=1;
			return 9;}
	}
	if(cbig!=1){
		if(((big>=one)||(cone==1))&&((big>=two)||(ctwo==1))&&((big>=three)||(cthree==1))&&
		((big>=four)||(cfour==1))&&((big>=five)||(cfive==1))&&((big>=six)||(csix==1))&&
		((big>=full)||(cfull==1))&&((big>=fouroak)||(cfouroak==1))&&((big>=little)||(clittle==1))&&
		((big>=choice)||(cchoice==1))&&((big>=yacht)||(cyacht==1))){
			cbig=1;
			return 10;}
	}
	if(cchoice!=1){
		if(((choice>=one)||(cone==1))&&((choice>=two)||(ctwo==1))&&((choice>=three)||(cthree==1))&&
		((choice>=four)||(cfour==1))&&((choice>=five)||(cfive==1))&&((choice>=six)||(csix==1))&&
		((choice>=full)||(cfull==1))&&((choice>=fouroak)||(cfouroak==1))&&((choice>=little)||(clittle==1))&&
		((choice>=big)||(cbig==1))&&((choice>=yacht)||(cyacht==1))){
			cchoice=1;
			return 11;}
	}
	if(cyacht!=1){
		if(((yacht>=one)||(cone==1))&&((yacht>=two)||(ctwo==1))&&((yacht>=three)||(cthree==1))&&
		((yacht>=four)||(cfour==1))&&((yacht>=five)||(cfive==1))&&((yacht>=six)||(csix==1))&&
		((yacht>=full)||(cfull==1))&&((yacht>=fouroak)||(cfouroak==1))&&((yacht>=little)||(clittle==1))&&
		((yacht>=big)||(cbig==1))&&((yacht>=choice)||(cchoice==1))){
			cyacht=1;
			return 12;}
	}			
}
int scoreSheet(int score,int total){
	
	total+=score;
	printf("Your score is: %d and your total is: %d\n",score,total);			//scoresheet
	return total;
}//MS
