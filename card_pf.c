#include "constant.h"
extern int cardhold[n_max_user+1][n_max_card];
extern int n_user;



void print_initial_card(){
	int i,k;
	for(i=0;i<n_user+1;i++){
		printf("cards of player%d : ",i);
			for(k=0;k<2;k++){
				if(i==n_user&&k==0){
					printf(" x ");
					continue ;
				}
				if(cardhold[i][k]%52+1==1) printf(" DIAA ");
				else if(1<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<11) printf(" DIA%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==11) printf(" DIAJ ");
				else if(cardhold[i][k]%52+1==12) printf(" DIAK ");
				else if(cardhold[i][k]%52+1==13) printf(" DIAQ ");
				
				else if(cardhold[i][k]%52+1==14) printf(" HRTA ");
				else if(14<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<24) printf(" HRT%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==24) printf(" HRTK ");
				else if(cardhold[i][k]%52+1==25) printf(" HRTQ ");
				else if(cardhold[i][k]%52+1==26) printf(" HRTJ ");
				
				else if(cardhold[i][k]%52+1==27) printf(" SPDA ");
				else if(27<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<37) printf(" SPD%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==37) printf(" SPDQ ");
				else if(cardhold[i][k]%52+1==38) printf(" SPDK ");
				else if(cardhold[i][k]%52+1==39) printf(" SPDJ ");
				
				else if(cardhold[i][k]%52+1==40) printf(" CLVA ");
				else if(40<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<50) printf(" CLV%d ",cardhold[i][k]%13+1);
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
				if(cardhold[i][k]%52+1==1) printf(" DIAA ");
				else if(1<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<11) printf(" DIA%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==11) printf(" DIAJ ");
				else if(cardhold[i][k]%52+1==12) printf(" DIAK ");
				else if(cardhold[i][k]%52+1==13) printf(" DIAQ ");
				
				else if(cardhold[i][k]%52+1==14) printf(" HRTA ");
				else if(14<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<24) printf(" HRT%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==24) printf(" HRTK ");
				else if(cardhold[i][k]%52+1==25) printf(" HRTQ ");
				else if(cardhold[i][k]%52+1==26) printf(" HRTJ ");
				
				else if(cardhold[i][k]%52+1==27) printf(" SPDA ");
				else if(27<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<37) printf(" SPD%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==37) printf(" SPDQ ");
				else if(cardhold[i][k]%52+1==38) printf(" SPDK ");
				else if(cardhold[i][k]%52+1==39) printf(" SPDJ ");
				
				else if(cardhold[i][k]%52+1==40) printf(" CLVA ");
				else if(40<cardhold[i][k]%52+1&&cardhold[i][k]%52+1<50) printf(" CLV%d ",cardhold[i][k]%13+1);
				else if(cardhold[i][k]%52+1==50) printf(" CLVK ");
				else if(cardhold[i][k]%52+1==51) printf(" CLVJ ");
				else if(cardhold[i][k]%52+1==52) printf(" CLVQ ");
	}
	return ;
}
