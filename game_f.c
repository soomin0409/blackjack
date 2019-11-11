#include "constant.h"

extern int n_hold[n_max_user+1];
extern int n_user;
extern int cardhold[n_max_user+1][n_max_card];
extern int sum[n_max_user+1];
extern int j;
extern int ans;
extern int v;
extern int game_end;
extern int dollar[n_max_user];
extern int ind;

void configuser(){
	do{
		printf("input player:");
		scanf("%d",&n_user);
		if(n_user>n_max_user) printf("try again\n");
	}while(n_user>n_max_user);
	return ;
}

void calc_sum(int i,int k){

		int c; 
		c = cardhold[i][k]%13+1 ;
		if(c==11||c==12||c==13) c=10;
		else if(sum[i]<=10&&c==1) c=11;
		else if(sum[i]>10&&c==1) c=1;
	
		sum[i]+=c;
	return ;
}
	
void getaction_me(){
	printf("go or stop: ");
	scanf("%d",&ans);
	if(ans==0){
		cardhold[0][j]=pullcard();
		++n_hold[0];
		++j;
	}
	else return;
}

void getaction_com(int i){
	
	cardhold[i][v]=pullcard();
	++n_hold[i];
	++v;
	return ;
}

void keep_go(){
	int i;
	for(i=0;i<n_user;i++){
		if(dollar[i]<=0||ind>=n_card*n_set-30){
			game_end=1;
			break;
		}
	}
	return ;
}

void initial(){
	int i,h;
	for(i=0;i<n_max_user+1;i++){
		sum[i]=0;
		n_hold[i]=0;
	}
	for(i=0;i<n_max_user+1;i++){
		for(h=0;h<n_max_card;h++)
		{
		 	cardhold[i][h]=0;
		}
	}
	ans=0;
	v=2;
	j=2;
	return ;
}




	
