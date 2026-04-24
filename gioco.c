#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
srand(time(NULL));
int V = 0;
int S = 0;

	while(1){
		int a = 4;
		int pc = rand()%3;

		system("cls");
		printf("0=Sasso, 1=Carta, 2=Forbice \n");
		printf("Punteggio: %d ", V);
		printf("a %d \n", S);
		scanf("%d", &a);
		printf("Avversario:%d \n", pc);

		if (a>2){
		continue;
		}

		if (a==0 && pc==0){
			printf("Pareggio\n");
			} else if (a==0 && pc==1){
			printf("Sconfitta\n");
			S++;
			}else if (a==0 && pc==2){
			printf("Vittoria\n");
			V++;
				}else if(a==1 && pc==0){
				printf("Vittoria\n");
				V++;
				} else if (a==1 && pc==1){
				printf("Pareggio\n");
				}else if (a==1 && pc==2) {
				printf("Sconfitta\n");
				S++;
					}else if(a==2 && pc==0){
					printf("Sconfitta\n");
					S++;
					} else if (a==2 && pc==1){
					printf("Vittoria\n");
					V++;
					}else{
					printf("Pareggio\n");}
		getchar();
		getchar();
		continue;
	}
}
