#include <stdio.h>
#include <stdlib.h>
#include "constant.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int n_user;  // number of player 
int dollar[n_max_user]; // current dollar
int cardtray[n_card*n_set]; // number of cards in cardtray
int bet[n_max_user]; // betting dollar
int ind=0;// card index 
int cardhold[n_max_user+1][n_max_card]; // current card of player
int n_hold[n_max_user+1]={ 0, }; // number of player holding card
int sum[n_max_user+1]={ 0, }; // sum of card
int j=2; // variable in printcard(), calc_sum()
int ans; // go or stop answer in getaction_me()
int v=2; // variable in printcard() , calc_sum()
int game_end=0; // deciding to keep game 
int end_card=30; // min card in cardtray


int main(int argc, char *argv[]) {
	int m,b,w; // various in print_initial_card(), print_card()
	int round=1; // index of round
	
	srand((unsigned)time(NULL));
	
	printf("BLACK JACK      (((*******press only numbers*******)))\n\n");
	configuser();
	printf("user = player0  server = player%d \n",n_user);
	printf("\n");
	printf("initial dollar\n");
	initial_dollar();

	mixcardtray();
	do{	printf("\n");
		printf("-------------[round%d start//(card index %d)]--------------\n",round,ind);
		printf("\n");
		bet_dollar();
		printf("\n");
		offercard();
		print_initial_card();
		for(m=0;m<n_user+1;m++){
			for(b=0;b<2;b++){
			calc_sum(m,b);
			}

		}
		
		printf("\n");
		printf("game start---------------------------\n");
		printf("< go = 0 , stop = others >   (((*******press only numbers*******)))\n");
		
		
		while(sum[0]<=21&&ans==0){
			
			if(sum[0]==21&&n_hold[0]==2){
				printf("palyer0:");
				print_card(0,j);
				printf("(%d)",sum[0]);
				printf("...............black jack// dollar: %d ",dollar[0]+2*bet[0]);
				break;
			}
			
			getaction_me();
			
			if(ans!=0) {
				printf("player0:");
				print_card(0,j); 
				printf("(%d)",sum[0]);
				break;
			}
			
			
			printf("palyer0:");
			print_card(0,j);
			calc_sum(0,j-1);
			printf("(%d)",sum[0]);
			if (sum[0]>21){
				printf("...............over flow// dollar: %d ",dollar[0]-bet[0]);
			}
		}		
		
		printf("\n");
		
	
		
			for(m=1;m<n_user+1;m++)
			{	v=2;
				while(sum[m]<17){
				
					getaction_com(m);
					calc_sum(m,v-1);
				}
				printf("player%d:",m);	
				print_card(m,v);
				printf("(%d)",sum[m]);
				if(m!=n_user&&sum[m]==21&&n_hold[m]==2) printf("...............black jack// dollar: %d ",dollar[m]+2*bet[m]);
				else if(m!=n_user&&sum[m]>21) printf("...............over flow// dollar: %d ",dollar[m]-bet[m]);
				if(m==n_user&&sum[m]==21&&n_hold[m]==2) printf("...............black jack");
				else if(m==n_user&&sum[m]>21) printf("...............over flow");
				printf("\n");
			}				
		
				
		
		printf("\n");
		printf("round%d result--------------------------\n",round);
		checkresult();
		keep_go();
		++round;
		initial(); 

	}while(game_end==0);
	
	printf("\n");
	printf("-------------------------------<<**winner**>>-------------------------------\n\n\n");
	checkwinner();
	printf("\n\n\n");
	printf("----------------------------------------------------------------------------\n");
	printf("press enter . . . \n\n");
	getchar();
	getchar(); //  preventing automatic shutdown 
	return 0;
}
