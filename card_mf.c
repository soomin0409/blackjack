#include "constant.h"

extern int cardtray[n_card*n_set];
extern int ind;
extern int cardhold[n_max_user+1][n_max_card];
extern int n_user;
extern int n_hold[n_max_user+1];

void mixcardtray(){
	int i;
	int temp, x, y;
	for(i=0;i<n_card*n_set;i++){
		cardtray[i]=i+1;
	}
	for(i=0;i<n_card*n_set;i++){
		x=rand()%(n_card*n_set);
		y=rand()%(n_card*n_set);
		if(x!=y){
			temp=cardtray[x];
			cardtray[x]=cardtray[y];
			cardtray[y]=temp;
		}
	}
	return ;
}
int pullcard(){
	int i;
	i=ind;
	++ind;
	return cardtray[i];
}
void offercard(){
	int i;
		cardhold[n_user][0]=pullcard();
		++n_hold[n_user];
	for(i=0;i<n_user;i++){
		cardhold[i][0]=pullcard();
		++n_hold[i];
	}
		cardhold[n_user][1]=pullcard();
		++n_hold[n_user];
	for(i=0;i<n_user;i++){
		cardhold[i][1]=pullcard();
		++n_hold[i];
	}
	return ;
	
}

