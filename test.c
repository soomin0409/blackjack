#include <stdio.h>
#include <stdlib.h>

//player0=me,player6=dealer

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int m;// to for
	
	configuser();// number of user
	
	printf("initial dollar\n"); 
	intial_dollar();// initial dollar of players
	
	mixcardtray();
	do{
		printf("round%d start");//star round
		bet_dollar();//betting
		offercard();//offer 2 cards
		print_initial_card();// print 2 cards dealer+others 
		calc_sum();// calculate card sum
		
		printf("game start");
		while(sum[0]<=21){
		getaction_me(0);// go stop - pullcard
		print_card(0);
		calc_sum(0);}
		for(m=1;m<n_user+1;m++){
		while(sum[m]<17){
		getaction_com(m);//pullcard
		print_card(m);
		calc_sum(m);}
		}
		printf("round %d result");
		checkresult();
		keep_go();// keep go or not
	}while(game_end==0)
		
		check_winner();
	
	return 0;
	
}
