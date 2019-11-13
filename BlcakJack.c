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
	int m,b; // various in print_initial_card()
	int round=1; // index of round
	
	srand((unsigned)time(NULL));
	
	printf("BLACK JACK (press only numbers)\n\n");
	configuser();
	printf("user = player0  server = player%d \n",n_user);
	printf("\n");
	printf("initial dollar\n");
	initial_dollar();

	mixcardtray();
	do{	printf("\n");
		printf("-------------[round%d start]--------------\n",round);
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
		printf("*/press only numbers/*( go = 0 , stop = others )\n");
		while(sum[0]<=21&&ans==0){
		
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
	printf("winner--------------------------------------\n");
	checkwinner();
	
	return 0;
}
