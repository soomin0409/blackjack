#include "constant.h"
extern int n_user;
extern int n_hold[n_max_user+1];
extern int sum[n_max_user+1];
extern int bet[n_max_user];
extern int dollar[n_max_user];

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
		else if(sum[n_user]==21&&n_hold[n_user]>2){
			if(sum[i]==21&&n_hold[i]==2){
				dollar[i]+=bet[i]*2;
				printf("player%d win|| doller :%d\n",i,dollar[i]);
			}
			else if(sum[i]==21&&n_hold[i]>2){
				dollar[i]+=bet[i];
				printf("player%d win|| doller :%d\n",i,dollar[i]);
			}
			else {
				dollar[i]-=bet[i];
				printf("player%d lose|| doller :%d\n",i,dollar[i]);
				
			}
		}
		else if(sum[n_user]<21&&n_hold[n_user]==2)
		{
			if(sum[i]==21&&n_hold[i]==2){
				dollar[i]+=bet[i]*2;
				printf("player%d win|| doller :%d\n",i,dollar[i]);
			}
			else if(sum[i]==21&&n_hold[i]>2){
				dollar[i]+=bet[i];
				printf("player%d win|| doller :%d\n",i,dollar[i]);
			}
			else if(sum[i]<21&&sum[i]>=sum[n_user]){
				dollar[i]+=bet[i];
				printf("player%d win|| doller :%d\n",i,dollar[i]);
			}
			else {
				dollar[i]-=bet[i];
				printf("player%d lose|| doller :%d\n",i,dollar[i]);
			}
			
			
		}
		else if(sum[n_user]<=21&&n_hold[n_user]>2){
			if(sum[i]<21&&sum[i]>=sum[n_user]){
				dollar[i]+=bet[i];
				printf("player%d win|| doller :%d\n",i,dollar[i]);
			}
			else if(sum[i]==21&&n_hold[i]==2){
				dollar[i]+=bet[i]*2;
				printf("player%d win|| doller :%d\n",i,dollar[i]);
			}
			else if(sum[i]==21&&n_hold[i]>2){
				dollar[i]+=bet[i];
				printf("player%d win|| doller :%d\n",i,dollar[i]);
			}
			else {
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
