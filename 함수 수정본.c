#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define n_max_user 5
#define n_dollar 50
#define n_card 52
#define n_set 4
#define bet_max 5
#define n_max_card 10
int n_user;
int dollar[n_max_user];
int cardtray[n_card*n_set];
int bet[n_max_user];
int ind=0;// card index 
int cardhold[n_max_user+1][n_max_card];
int n_hold[n_max_user+1]={ 0, };
int sum[n_max_user+1]={ 0, };
void configuser(){
	do{
		printf("input player:");
		scanf("%d",&n_user);
		if(n_user>n_max_user) printf("try again\n");
	}while(n_user>n_max_user);
	return ;
}
void initial_dollar(){
	int i;
	for(i=0;i<n_user;i++)
	{
		dollar[i]=n_dollar;
		printf("dollar of player%d : %d",i,dollar[i]);
	}
	return ;
}
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
void bet_dollar(){
	int i;
	do{
		printf("bet dollar:");
		scanf("%d",&bet[0]);
		if(bet[0]>dollar[0]) printf("try again");
	}while(bet[0]>dollar[0]);
	printf("betting of player0 : %d\n",bet[0]);
	for (i=1;i<n_user;i++){
		do{
			bet[i]=rand()%(bet_max+1);
		}while(bet[i]>dollar[i]);
		printf("betting of player%d : %d\n",i,bet[i]);
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
void print_initial_card(){
	int i,k;
	for(i=0;i<n_user+1;i++){
		printf("cards of player%d : ",i);
			for(k=0;k<2;k++){
				if(i==n_user&&k==0) printf("X");
				continue;
				if(0<cardhold[i][k]%52+1<11) printf("DIA%d",cardhold[i][k]%13+1);
				if(cardhold[i][k]%52+1==11) printf("DIAJ");
				if(cardhold[i][k]%52+1==12) printf("DIAK");
				if(cardhold[i][k]%52+1==13) printf("DIAQ");
				
				if(13<cardhold[i][k]%52+1<24) printf("HRT%d",cardhold[i][k]%13+1);
				if(cardhold[i][k]%52+1==24) printf("HRTK");
				if(cardhold[i][k]%52+1==25) printf("HRTQ");
				if(cardhold[i][k]%52+1==26) printf("HRTJ");
				
				if(26<cardhold[i][k]%52+1<37) printf("SPD%d",cardhold[i][k]%13+1);
				if(cardhold[i][k]%52+1==37) printf("SPDQ");
				if(cardhold[i][k]%52+1==38) printf("SPDK");
				if(cardhold[i][k]%52+1==39) printf("SPDJ");
				
				if(39<cardhold[i][k]%52+1<50) printf("CLV%d",cardhold[i][k]%13+1);
				if(cardhold[i][k]%52+1==50) printf("CLVK");
				if(cardhold[i][k]%52+1==51) printf("CLVJ");
				if(cardhold[i][k]%52+1==52) printf("CLVQ");
				
	
			}
			printf("\n");
	}
}
void print_card(int i){
	int k;
	for(k=0;k<ind;k++){
		if(0<cardhold[i][k]%52+1<11) printf("DIA%d",cardhold[i][k]%13+1);
				if(cardhold[i][k]%52+1==11) printf("DIAJ");
				if(cardhold[i][k]%52+1==12) printf("DIAK");
				if(cardhold[i][k]%52+1==13) printf("DIAQ");
				
				if(13<cardhold[i][k]%52+1<24) printf("HRT%d",cardhold[i][k]%13+1);
				if(cardhold[i][k]%52+1==24) printf("HRTK");
				if(cardhold[i][k]%52+1==25) printf("HRTQ");
				if(cardhold[i][k]%52+1==26) printf("HRTJ");
				
				if(26<cardhold[i][k]%52+1<37) printf("SPD%d",cardhold[i][k]%13+1);
				if(cardhold[i][k]%52+1==37) printf("SPDQ");
				if(cardhold[i][k]%52+1==38) printf("SPDK");
				if(cardhold[i][k]%52+1==39) printf("SPDJ");
				
				if(39<cardhold[i][k]%52+1<50) printf("CLV%d",cardhold[i][k]%13+1);
				if(cardhold[i][k]%52+1==50) printf("CLVK");
				if(cardhold[i][k]%52+1==51) printf("CLVJ");
				if(cardhold[i][k]%52+1==52) printf("CLVQ");
	}
	return ;
}
void calc_sum(int i){
	int k;
	for(k=0;k<ind;k++){
		int c = cardhold[i][k]%13+1 ;
		if(c==11||c==12||c==13) c=10;
		if(sum[i]<=10&&cardhold[i][k]%13+1==1) c=1;
		if(sum[i]>10&&cardhold[i][k]%13+1==1) c=11;
		sum[i]+=c;
	}
}
int j=3;
void getaction_me(){
	int ans;
	printf("go or stop");
	scanf("%d",&ans);
	if(ans==0){
		cardhold[0][j]=pullcard();
		++n_hold[0];
		++j;
	}
	else return;
}
void getaction_com(int i){
	int k=3;
	while(sum[i]<17){
	cardhold[i][k]=pullcard();
	++n_hold[i];
	++k;}
	return ;
}
void checkresult(){
	int i;
	for(i=0;i<n_user;i++){
		if(sum[n_user]==21&&n_hold[n_user]==2){
			if(sum[i]==21&&n_hold[i]==2){
				dollar[i]+=2*bet[i];
				printf("player%d win|| doller :%d",i,dollar[i]);
			}
			else {
			dollar[i]-=bet[i];
			printf("player%d lose|| doller :%d",i,dollar[i]);
			}
		}
		if(sum[n_user]<21&&n_hold[n_user]>=2){
			if(sum[i]<21&&sum[i]>=sum[n_user]){
				dollar[i]+=bet[i];
				printf("player%d win|| doller :%d",i,dollar[i]);
			}
			if(sum[i]<sum[n_user]){
				dollar[i]-=bet[i];
				printf("player%d lose|| doller :%d",i,dollar[i]);
			}
		}
		if(sum[n_user]>21){
			if(sum[i]>21){
				dollar[i]-=bet[i];
				printf("player%d lose|| doller :%d",i,dollar[i]);
			}
			else{
				dollar[i]+=bet[i];
				printf("player%d win|| doller :%d",i,dollar[i]);
			}
		}
	}
	return ;
}
int game_end=0;
void keep_go(){
	int i;
	for(i=0;i<n_user;i++){
		if(dollar[i]<0||ind>=n_card*n_set-30){
			game_end=1;
			break;
		}
	}
	return ;
}
void cheackwinner(){
	int i,max;
	for(i=0;i<n_user;i++){
		if(dollar[i]>=max) max=dollar[i];
	}
	printf("dollar of winner : %d",dollar[i]);
	return ;
}



int main(int argc, char *argv[]) {
	configuser();
	return 0;
}
