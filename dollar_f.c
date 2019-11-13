#include "constant.h"
extern int dollar[n_max_user];
extern int bet[n_max_user];
extern int n_user;


void initial_dollar(){
	int i;
	for(i=0;i<n_user;i++)
	{
		dollar[i]=n_dollar;
		printf("dollar of player%d : %d\n",i,dollar[i]);
	}
	return ;
}											//  initial dollar of palyer

void bet_dollar(){
	int i;
	do{
		printf("bet dollar:");
		scanf("%d",&bet[0]);
		if(bet[0]>dollar[0]) printf("try again\n");
	}while(bet[0]>dollar[0]);
	printf("betting of player0 : %d\n",bet[0]);
	for (i=1;i<n_user;i++){
		do{
			bet[i]=rand()%bet_max+1;
		}while(bet[i]>dollar[i]);
		printf("betting of player%d : %d\n",i,bet[i]);
	}
	return ;
	
}										// betting dollar of player
