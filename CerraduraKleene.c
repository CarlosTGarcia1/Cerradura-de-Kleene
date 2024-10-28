#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cerraduraKleene(int longitud, char *elementos);

int main(){
	int longitud=3;
	char elementos[]="abc";
	
	cerraduraKleene(longitud,elementos);
	 
	return 0;
}

void generarCombinaciones(char *cadena, int nivel, int longitud, char *elementos){
	if(nivel==longitud){
		cadena[nivel]='\0';
		printf("%s ", cadena);
		return;
		}
		for(int i=0;i<strlen(elementos);i++){
		cadena[nivel]=elementos[i];
		generarCombinaciones(cadena,nivel+1,longitud,elementos);
	}
}

void cerraduraKleene(int longitud, char *elementos){
	char *cadena=calloc(longitud+1,sizeof(char));
	if(cadena==NULL){
		printf("Error");
		return;
	}
	printf("{");
	printf(" o ");
	for(int i=1;i<=longitud;i++){
		generarCombinaciones(cadena,0,i,elementos);
		
	}
	free(cadena);
	printf("}");
}
