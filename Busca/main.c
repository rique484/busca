#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int x,y,z;
int limite;

typedef struct pessoa PESSOA;
struct pessoa{
	char cpf[10];
	char nome[20];
};

struct pessoa fila[10];
struct pessoa temp[0];
struct pessoa busca[0];

void entrada(void){
	for(x=0;x<10;x++){
		printf("Entre com o cpf: ");
		scanf("%s",&fila[x].cpf);
		printf("Entre com o nome: ");
		scanf("%s",&fila[x].nome);
	system("cls");
	}
}

void org(void){
	for(x=0;x<9;x++){
		for(y=x+1;y<10;y++){
			if(strcmp(fila[x].cpf,fila[y].cpf)>0){
				printf("teste");
				/*copia de string*/strcpy(temp[0].cpf,fila[x].cpf);
				strcpy(temp[0].nome,fila[x].nome);
				
				strcpy(fila[x].cpf,fila[y].cpf);
				strcpy(fila[x].nome,fila[y].nome);
				
				strcpy(fila[y].cpf,temp[0].cpf);
				strcpy(fila[y].nome,temp[0].nome);
			}
		}
	}
}

void exibir(void){
	for(x=0;x<10;x++){
		printf("cpf: %s\n",fila[x].cpf);
		printf("nome: %s\n",fila[x].nome);
		printf("-------------------------\n");
	}
}

void buscas(void){
	
	scanf("%s",busca[0].cpf);
	
	y=0;
	z=10;
	do{
		x = /*arredonda para baixo*/floor((y+z)/2);
		if(strcmp(busca[0].cpf,fila[x].cpf)==0){
			printf("%s",fila[x].cpf);
			printf("%s",fila[x].nome);
			break;
		}else{
			if(/*comparador de string*/strcmp(busca[0].cpf,fila[x].cpf)>0){
				y = x+1;
			}else{
				z = x-1;
			}
		}
		
	}while(y<=z);
	
}

int main(int argc, char *argv[]) {

entrada();
org();
exibir();
buscas();
	return 0;
}
