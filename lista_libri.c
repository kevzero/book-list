#include <stdio.h>
#include <string.h>

#define N 50

typedef struct {
	char id[40];
  	char titolo[150];
	char genere[40];  
} libro;


libro archivio_libri[N]={ 
	{"32 - 45435 - 1223- 4","Il nome della rosa", "romanzo"},
	{"78- 674 - 5435 - 1223- 4","Il linguaggio C", "informatica"},
	{"6- 7887- 6 - 8435 - 12234","Il linguaggio C++", "informatica"},
	{"324- 5- 435 - 1234","Java", "informatica"},
};


int my_index=4;
//indico il numero di elementi allocati nel vettore archivio_libri 

void stampaLibri(int pos)
{ 
int i=0;
while(i<pos)
{	
 	printf("\n\nCodice libro: %s", archivio_libri[i].id);
 	printf("\nTitolo %s ", archivio_libri[i].titolo);
	printf("\nGenere %s: ", archivio_libri[i].genere);

	i++;
 }
}

int insertLibri(int pos)
{
	char invio;
	char c;
	
	if(pos>=N) {
		printf("\n\nHai raggiunto il limite massimo di libri che puoi inserire ");
		
	scanf("%c", &invio);
	return(pos);
	}
	
	fflush(stdin);
	printf("\nISBN:");
	gets(archivio_libri[pos].id);
	fflush(stdin);	
	printf("\nTitolo:");
	gets(archivio_libri[pos].titolo);
	printf("\nGenere:");
	gets(archivio_libri[pos].genere);
	fflush(stdin);
	
	pos++;
	return(pos);
}

void stampaGenere(int pos)
{ 
	char genere[40];
	int i=0, trovato=0;
	
	printf("\nQuale genere cerchi?:");
 	scanf("%s", genere);
 	
	for (i=0; i<pos; i++){
	 	if(strcmp(archivio_libri[i].genere,genere)==0) {
	 		printf("\n\n ISBN: %s ", archivio_libri[i].id);
	 		printf("\n Titolo: %s ", archivio_libri[i].titolo);
	 		trovato=1;
		 }
 	}
 	if (trovato==0) 
		 printf("\nNon e' presente nessuna categoria:");
}

int menu_scelta(void)
{
  int selezione = 0;
  do
    {
    printf("\n" );
    printf("\n1 - Stampa libri presenti" );
    printf("\n2 - Inserisci libro");
    printf("\n3 - Ricerca libro per genere");
    printf("\n4 - Esci");
    printf("\n" );
    printf("\nEffettua una scelta: " );
    scanf("%d", &selezione );
    }
    while (selezione < 1 || selezione > 4);
  return selezione;
}

int main(void)
{
    int scelta;
    
    while((scelta=menu_scelta())!=4){
    switch(scelta){
        case 1: 
               stampaLibri(my_index);
               break;
        case 2:
               my_index=insertLibri(my_index);
               break;
        case 3:
               stampaGenere(my_index);
               break;
        case 4: break;
             }
    }             
    return 0;
}
