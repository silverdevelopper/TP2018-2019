/*
 * name.c
 *
 *  Created on: Mar 28, 2019
 *      Author: Merve Unlu
 */


#include "name.h"
#include<string.h>

/*
 * Parametre olarak verilen
 * veri yapisina bagli dizideki
 * elemanlari ekrana basar.
 */
// TODO: ex1
void print_db(struct dbName d){
	int ind;
	for(ind=0;ind<d.currentSize;ind++){
        printf("%s ,%d \n",d.db[ind].name,d.db[ind].value);
	}
}

/*
 * Parametre olarak verilen dosyayi acar,
 * ve icindeki sirali elemanlari veri yapisina
 * bagli dizide saklar.
 */
void read_name_file(struct dbName* d,char* filename){
    FILE * fp=fopen(filename,"r");
    if(fp){
    	// Dosya hatasiz aciliyorsa
    	char line[MAXSIZE];
    	// Her bir satiri oku
    	while(fgets(line,MAXSIZE,fp)!=NULL){
    	  //Okunan isim degerini diziye ekler.
          strcpy(d->db[d->currentSize].name,line);
          // Dizi indeksini arttirir.
          printf("%s \n",d->db[d->currentSize].name);
          d->currentSize = d->currentSize + 1;
    	}
    }
    fclose(fp);
}


/*
 * Deger dosyasini acip, icindeki sayilari
 * dizideki sirasi ile dizi elemanlarini gunceller.
 */
void read_value_file(struct dbName* d,char* filename){
   // TODO: ex2
    //filename dosyasini satir
    // satir okuyup her satirin denk geldigi
    // degeri d->db[satir].value degiskenine
	// atayin.
	// Dosya okuma icin: fgets
	// Tip donusumleri icin : atoi
	FILE *fp= fopen(filename,"r");
	char line[1];
	if(fp){
		for(int i = 0; fgets(line,1,fp); i++)
		{
			d->db[i].value=atoi(line);
		}
		
	}
}

/*
 * Dogrusal arama islemini yapar.
 * Verilen veri yapisina bagli dizide,
 * istenen isimi arar. Isim bulundugunda
 * dizideki yerini, isim yoksa -1 dondurur.
 */
int search_uniform(struct dbName d,char* name){
    // TODO: ex3
	// Dogrusal arama fonksiyonu
	// name ve d->db[ı].name karsilastirmasi icin:
	// int result = strncmp(d.db[i].name,name,strlen(name))
	int i;
	for( i = 0; i < d.currentSize; i++)
	{
		if(strcmp(name,d.db[i].name)==0)
		return i;
	}
	

	return -1;
}


/*
 * Ikili arama islemi yapar.
 * Verilen veri yapisina bagli dizide,
 * istenen ismi ikili(binary) olarak
 * arar. Isim bulundugunda dizideki yerini,
 * isim yoksa -1 dondurur.
 */
int search_binary(struct dbName d,char* name){
	// TODO: ex5
    // İkili - Binary arama fonksiyonu
	// Hint: strcmp fonksiyonunun dondurdugu degere gore alfabetik
	// sira kontrolu yapilabilir.
	// int result = strncmp(d.db[i].name,name,strlen(name))
    //     if result = 0 , ayni
	//     if result > 0 ilk karakter daha buyuk degere sahip
	//     if result < 0 ilk karakter daha kucuk degere sahip
	int bas=0; int son=d.currentSize; int orta=bas/2;
	while(bas<=son){
		orta=bas+son/2;
		if(strcmp(d.db[orta].name,name)==0)
		return orta;
		else if(strcmp(d.db[orta].name,name)<0)
		{
			son=orta-1;

		}
		else if(strcmp(d.db[orta].name,name)>0)
		{
			bas=orta+1;
		
		}
	}
	
	return -1;
}

/*
 * Verilen dizide elemanlarin deger degiskenlerine bakarak diziyi
 * boler. Deger degiskeni 1 ise Good, deger degiskeni 0 ise Bad
 * olarak atanir.
 */
void split_names(struct dbName* dAll,struct dbName* dGood,struct dbName* dBad){
   int ind;
   for(ind=0;ind<dAll->currentSize;ind++){
	   if(dAll->db[ind].value == 1){
		   strcpy(dGood->db[dGood->currentSize].name,dAll->db[ind].name);
		   dGood->db[dGood->currentSize].value = dAll->db[ind].value;
		   dGood->currentSize++;
	   }else{
		   strcpy(dBad->db[dBad->currentSize].name,dAll->db[ind].name);
		   dBad->db[dBad->currentSize].value = dAll->db[ind].value;
		   dBad->currentSize++;
	   }
   }
}

/*
 * Verilen iki veri yapisinda ismi oncelikle ilk
 * veri yapisi dizisinde, sonra da ikinci veri yapisi
 * dizisinde arar. Isim bulunamadiginda -1, bulundugunda
 * yerini geri gonderir.
 */
int search_good_bad(struct dbName dGood, struct dbName dBad,char* name){
    int result = -1;
    // TODO: ex7
    // Once dGood icerisinde, sonra dBad icerisinde arayiniz.
	result= search_binary(dGood,name);
	result=search_binary(dBad,name);
    return result;
}


