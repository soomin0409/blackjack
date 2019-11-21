#include "constant.h"

extern int n_hold[n_max_user+1];
extern int n_user;
extern int cardhold[n_max_user+1][n_max_card];
extern int sum[n_max_user+1];
extern int j;
extern int ans;
extern int v;
extern int game_end;
extern int end_card;
extern int dollar[n_max_user];
extern int ind;
extern int a[n_max_user+1];
void configuser(){
	do{
		printf("input player[max%d]:",n_max_user);
		scanf("%d",&n_user);
		if(n_user>n_max_user||n_user<1) printf("try again\n");
	}while(n_user>n_max_user||n_user<1);
	return ;
}							// input number of player

void calc_sum(int i,int k){

		int c; 
		c = cardhold[i][k]%13+1 ;
		if(c==11||c==12||c==13) c=10;
		else if(sum[i]<=10&&c==1) c=11;
		else if(sum[i]>10&&c==1) c=1;
		sum[i]+=c;
		if(c==11) a[i]=1;
		if(a[i]==1&&sum[i]>21){
			sum[i]-=10;
			a[i]=0;
		}                // a  is  1 or 11 
		
	return ;
}						// sum holding card of player
	
void getaction_me(){
	printf("go or stop: ");
	scanf("%d",&ans);
	if(ans==0){
		cardhold[0][j]=pullcard();
		++n_hold[0];
		++j;
	}
	else return;
}							//  decide go or stop go=0,stop=others  ver.user

void getaction_com(int i){
	
	cardhold[i][v]=pullcard();
	++n_hold[i];
	++v;
	return ;               //  decide go or stop ver.compuer
}

void keep_go(){
	int i;
	for(i=0;i<n_user;i++){
		if(dollar[i]<=0||ind>=n_card*n_set-end_card){
			game_end=1;
			break;
		}
	}
	return ;
}							// if dollar of player=0 end or number of card <=30 , game end

void initial(){
	int i,h;
	for(i=0;i<n_max_user+1;i++){
		sum[i]=0;
		n_hold[i]=0;
		a[i]=0;
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
}						// initialize some arrays and variables




	
