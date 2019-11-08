#include <stdio.h>
#include <stdlib.h>
#define n_user_max 
#define n_dollar
#define n_card 52
#define n_set 
#define bet_max
#define n_max_card
int n_user;
int dollar[n_user];//player's dollar 
int cardtray[n_card*n_set];
int bet[n_user];
int j=0; // card index
int cardhold[n_user+1][n_max_card];
int sum[n_user+1];
int game_end=0;
int n_hold[n_user+1]={0};//number of holding card 

void configuser(){
	do{
	
	printf("input user: ");
	scanf("%d",&n_user);
	if(n_user>n_max_use) printf("try again\n");
	
	}while(n_user>n_max_user);
	
	return ;
}

void initial_dollar(){
	int i;
	for(i=0;i<n_user;i++)
	{
		dollar[i]=n_dollar;
		printf("dollar of player[%d] : %d\n",i,dollar[i]);
	}
	return ;
}

void mixcardtray(){
	int i;
	int temp, x, y;
	for (i=0;i<card_num*cardset;i++){
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

void bet_dollar(){
	int i;
	do{
	printf("bet dollar:");
	scanf("%d",&bet[0]);
	}while(bet[0]>dollar[0]);
	printf("betting of player[0]: %d\n",bet[i]);
	
	for(i=1;i<n_user;i++)
	{	do{
		bet[i]=rand()%(bet_max+1);
		}while(bet[i]>dollar[i]);
		printf("betting of player[%d]: %d\n",i,bet[i]);
	}
	return ;
}
int pull_card(){
	int i;
	i=j;
	++j;
	return cardtray[i];
}
void offercard(){
	int i;
	for(i=0;i<n_user+1;i++)
	{
		cardhold[i][0]=pull_card();
		++n_hold[i];
	 } 
	for(i=0;i<n_user+1;i++)
	{
		cardhold[i][1]=pull_card();
		++n_hold[i];
	}
	return ;
}

void print_initial_card(){

	for(i=0;i<n_user+1;i++){
		printf("cards of player[%d]: ",i);
		for(k=0;k<2;k++){
		if(i==n_user&&k==0) printf("x"); 
		
		if(0<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<11) printf(" %s%d ",'DIA',cardhold[i][k]);
		if(cardhold[i][k]%52+1==11) printf("DIAJ");
		if(cardhold[i][k]%52+1==12) printf("DIAQ");
		if(cardhold[i][k]%52+1==13) printf("DIAK");
		
		if(13<cardhold[i][k]%52+1&&cardhold[i][k%52+1]<24) printf(" %s%d ",'HRT',cardhold[i][k]);
		if(cardhold[i][k]%52+1==24) printf("HRTJ");
		if(cardhold[i][k]%52+1==25) printf("HRTQ");
		if(cardhold[i][k]%52+1==26) printf("HRTK");
		
		if(26<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<37) printf(" %s%d ",'SPD',cardhold[i][k]);
		if(cardhold[i][k]%52+1==37) printf("SPDJ");
		if(cardhold[i][k]%52+1==38) printf("SPDQ");
		if(cardhold[i][k]%52+1==39) printf("SPDK");
		
		if(39<cardhold[i][k]%52+1&&cardhold[i][k%52+1]<50) printf(" %s%d ",'CLV',cardhold[i][k]);
		if(cardhold[i][k]%52+1==50) printf("CLVJ");
		if(cardhold[i][k]%52+1==51) printf("CLVQ");
		if(cardhold[i][k]%52+1==52) printf("CLVK");
		}
		printf("\n");
	}
	
}


void print_card(int i){
	int k;
	for(k=0;k<j;k++){
		
		if(0<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<11) printf(" %s%d ",'DIA',cardhold[i][k]);
		if(cardhold[i][k]%52+1==11) printf("DIAJ");
		if(cardhold[i][k]%52+1==12) printf("DIAQ");
		if(cardhold[i][k]%52+1==13) printf("DIAK");
		
		if(13<cardhold[i][k]%52+1&&cardhold[i][k%52+1]<24) printf(" %s%d ",'HRT',cardhold[i][k]);
		if(cardhold[i][k]%52+1==24) printf("HRTJ");
		if(cardhold[i][k]%52+1==25) printf("HRTQ");
		if(cardhold[i][k]%52+1==26) printf("HRTK");
		
		if(26<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<37) printf(" %s%d ",'SPD',cardhold[i][k]);
		if(cardhold[i][k]%52+1==37) printf("SPDJ");
		if(cardhold[i][k]%52+1==38) printf("SPDQ");
		if(cardhold[i][k]%52+1==39) printf("SPDK");
		
		if(39<cardhold[i][k]%52+1&&cardhold[i][k%52+1]<50) printf(" %s%d ",'CLV',cardhold[i][k]);
		if(cardhold[i][k]%52+1==50) printf("CLVJ");
		if(cardhold[i][k]%52+1==51) printf("CLVQ");
		if(cardhold[i][k]%52+1==52) printf("CLVK");
		
	}
	return ;	
}

void calc_sum(int i){
	int k;
	for(k=0;k<j;k++){
		if(sum[i]<=10&&cardhold[i][k]%13+1==1) cardhold[i][k]=11;
		if(sum[i]>10&&cardhold[i][k]%13+1)==1) cardhold[i][k]=11;
		sum[i]+=cardhold%13+1;	
		}
	return ;
}

void getaction_me(){
	printf("go or stop");
	scanf("%d",&ans);
	if(ans==0) {
	cardhold[i][k]=pull_card;
	++n_hold[i];
	++k;}
	else return ;
} 

void getaction_com(int i){
	
	cardhold[i][k]=pull_card;
	++n_hold[i];
	
}

void checkresult(){
	for(i=0;i<n_user;i++){
	if(sum[n_user+1]==21&&n_hold[n_user+1]==2){
		if(sum[i]==21&&n_hold[i]==2){
			dollar[i]+=2*bet[i];
			printf("player[%d]:win//dollar:%d\n",i,dollar[i]);
		}
		else 
		doller[i]-=bet[i];
		printf("player[%d]:lose//dollar:%d\n",i,dollar[i]);
	} 
	if(sum[n_user+1]<21&&n_hold[n_user+1]>=2){
		if(sum[i]<21&&sum[i]>=sum[n_user+1]){
			dollar[i]+=bet[i];
			printf("player[%d]:win//dollar:%d",i,dollar[i]);
		}
		if(sum[i]<sum[n_user+1]){
			dollar-=bet[i];
			printf("player[%d]:lose//dollar:%d",i,dollar[i]);
		}
		
	}
	if(sum[n_user+1]>21){
		if(sum[i]>21){
			dollar[i]-=bet[i];
			printf("player[%d]:lose//dollar:%d",i,dollar[i]);
		}
		else {
			doller[i]+=bet[i];
			printf("player[%d]:win//dollar:%d",i,dollar[i]);
		}
	}
		
	}
	return ;
}
void keep_go(){
	int i;
	for(i=0;i<n_user;i++);
	{	if(dollar[i]<0||j>=(n_card)*(n_set)-30)
		game_end=1;
	}
	return ;
}
void checkwinner(){
	int max=0
	for (i=0;i<n_user;i++){
		if (dollar[i]>=max) max=dollar[i];
	}
	printf("dollar of winner : %d",max);
}









