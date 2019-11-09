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
		printf("dollar of player%d : %d\n",i,dollar[i]);
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
			bet[i]=rand()%bet_max+1;
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
				if(i==n_user&&k==0){
					printf(" x ");
					continue ;
				}
				if(0<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<11) printf(" DIA%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==11) printf(" DIAJ ");
				else if(cardhold[i][k]%52+1==12) printf(" DIAK ");
				else if(cardhold[i][k]%52+1==13) printf(" DIAQ ");
				
				else if(13<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<24) printf(" HRT%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==24) printf(" HRTK ");
				else if(cardhold[i][k]%52+1==25) printf(" HRTQ ");
				else if(cardhold[i][k]%52+1==26) printf(" HRTJ ");
				
				else if(26<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<37) printf(" SPD%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==37) printf(" SPDQ ");
				else if(cardhold[i][k]%52+1==38) printf(" SPDK ");
				else if(cardhold[i][k]%52+1==39) printf(" SPDJ ");
				
				else if(39<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<50) printf(" CLV%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==50) printf(" CLVK ");
				else if(cardhold[i][k]%52+1==51) printf(" CLVJ ");
				else if(cardhold[i][k]%52+1==52) printf(" CLVQ ");
				
	
			}
			printf("\n");
	}
	return ;
}
void print_card(int i,int n){
	int k;
	for(k=0;k<n;k++){
				if(0<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<11) printf(" DIA%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==11) printf(" DIAJ ");
				else if(cardhold[i][k]%52+1==12) printf(" DIAK ");
				else if(cardhold[i][k]%52+1==13) printf(" DIAQ ");
				
				else if(13<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<24) printf(" HRT%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==24) printf(" HRTK ");
				else if(cardhold[i][k]%52+1==25) printf(" HRTQ ");
				else if(cardhold[i][k]%52+1==26) printf(" HRTJ ");
				
				else if(26<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<37) printf(" SPD%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==37) printf(" SPDQ ");
				else if(cardhold[i][k]%52+1==38) printf(" SPDK ");
				else if(cardhold[i][k]%52+1==39) printf(" SPDJ ");
				
				else if(39<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<50) printf(" CLV%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==50) printf(" CLVK ");
				else if(cardhold[i][k]%52+1==51) printf(" CLVJ ");
				else if(cardhold[i][k]%52+1==52) printf(" CLVQ ");
	}
	return ;
}
void calc_sum(int i,int k){

		int c; 
		c = cardhold[i][k]%13+1 ;
		if(c==11||c==12||c==13) c=10;
		else if(sum[i]<=10&&c==1) c=11;
		else if(sum[i]>10&&c==1) c=1;
		printf(" %d ",c);
		sum[i]+=c;
	return ;
	
	}
	
int j=2,ans;
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
int v=2;
void getaction_com(int i){
	
	cardhold[i][v]=pullcard();
	++n_hold[i];
	++v;
	return ;
}
void checkresult(){
	int i;
	for(i=0;i<n_user;i++){
		if(sum[n_user]==21&&n_hold[n_user]==2){
			if(sum[i]==21&&n_hold[i]==2){
				dollar[i]+=2*bet[i];
				printf("player%d win|| doller :%d\n",i,dollar[i]);
			}
			else {
			dollar[i]-=bet[i];
			printf("player%d lose|| doller :%d\n",i,dollar[i]);
			}
		}
		else if(sum[n_user]<21&&n_hold[n_user]>=2){
			if(sum[i]<21&&sum[i]>=sum[n_user]){
				dollar[i]+=bet[i];
				printf("player%d win|| doller :%d\n",i,dollar[i]);
			}
			if(sum[i]<sum[n_user]){
				dollar[i]-=bet[i];
				printf("player%d lose|| doller :%d\n",i,dollar[i]);
			}
		}
		else if(sum[n_user]>21){
			if(sum[i]>21){
				dollar[i]-=bet[i];
				printf("player%d lose|| doller :%d\n",i,dollar[i]);
			}
			else{
				dollar[i]+=bet[i];
				printf("player%d win|| doller :%d\n",i,dollar[i]);
			}
		}
		printf("\n");
	}
	return ;
}
int game_end=0;
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
void checkwinner(){
	int i,max=0;
	for(i=0;i<n_user;i++){
		if(dollar[i]>max) max=dollar[i];
	}
	printf("dollar of winner : %d",max);
	return ;
}



int main(int argc, char *argv[]) {
	int m,b;
	int round=1;
	srand((unsigned)time(NULL));
	configuser();
	printf("initial dollar\n");
	initial_dollar();
	mixcardtray();
	do{
		printf("round%d start----------------------------\n",round);
		bet_dollar();
		offercard();
		print_initial_card();
		for(m=0;m<n_user+1;m++){
			for(b=0;b<2;b++){
			calc_sum(m,b);
			}

		}
		
		printf("game start-------------------------------\n");
		while(sum[0]<=21&&ans==0){
		
			getaction_me();
			if(ans!=0) break;
			print_card(0,j);
			calc_sum(0,j-1);
			printf("(%d)",sum[0]);
		}		
		
		printf("\n");
		for(m=1;m<n_user+1;m++)
		{	v=2;
			while(sum[m]<17){
				
				getaction_com(m);
				calc_sum(m,ind);
			}
				
			print_card(m,ind);
				
			printf("\n");
		}
		printf("round%d result----------------------------\n",round);
		checkresult();
		keep_go();
		++round;
	}while(game_end==0);
	
	checkwinner();
	
	return 0;
}
