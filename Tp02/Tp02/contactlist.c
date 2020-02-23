/*
 * contactlist.c
 *
 *  Created on: Feb 21, 2019
 *      Author: Merve Unlu
 */

#include"contactlist.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>


/*
 * Parametre olarak verilen sayi kadar
 * elemani olan bir dizi ile bunu gosteren
 * ContactList tipinde değişken oluşturur.
 */
ContactList create_contact_list(int number){
    ContactList c ;
    c.contact_list=malloc(sizeof(Contact)*number);
    c.current_number=0;
    c.max_number=number;
    // Alistirma 1
    return c;
}

void edt_contact(char *name,char *new_tel,ContactList *c)
{
    int i;
    for (i=0; i<c->max_number; i++) {
        if (strcmp(c->contact_list[i].name,name)==0) {
             strcpy(c->contact_list[i].tel_number,new_tel);
        }
    }
}

/*
 * Parametre olarak verilen listeye
 * yeni elemani ekler.
 */
void add_new_contact(ContactList* c,Contact new_cnt){
  // Alistirma 2
	/*
	 * Eleman eklerken oncelikle
	 * guncel eleman sayisi ve max sayiyi kontrol ediniz.
	 * Guncel sayi daha buyukse hafızada yeniden yer
	 * acilmasi gerekecek.
	 */
    if (c->current_number<c->max_number) {
        c->contact_list[c->current_number]=new_cnt;
        c->current_number++;
    }else
    {
        c->contact_list=realloc(c->contact_list, c->max_number*2);
        if(c->contact_list==NULL)
        {
            printf("Yeretli alan yok\n");
            return;
        }
        c->max_number++;;
        
        
    }
}

/*
 * Parametre olarak verilen
 * ContactList icindeki listeyi
 * ekrana basar.
 */
/* Kisi
 ID NO : 2
 Adi: Merve
 Soyadi: Unlu*/
void print_contact_list(ContactList c){
  // Alistirma 3
    int i;
    
    printf("----lis----\n");
    for (i=0; i<c.max_number; i++) {
        printf("ID NO: %d\n",c.contact_list[i].id);
        printf("Adi:%s \n",c.contact_list[i].name);
        printf("Soyadi:%s \n",c.contact_list[i].surname);
        printf("Soyadi:%s \n",c.contact_list[i].tel_number);
    }
    
    
}

/*
 * Parametre olarak verilen
 * kisi listesinde istenen ismi arar.
 */
char* find_contact(ContactList *c,char* name){
    int i;
    for (i=0; i<c->max_number; i++) {
        if (strcmp(c->contact_list[i].name,name)==0) {
            return c->contact_list[i].tel_number;
        }
    }
    return 0;
    // Alistirma 5
   
}

/*
 * Parametre olarak verilen
 * listeyi bellekten siler.
 */
void delete_contact_list(ContactList *c){
  // Alistirma 7
    free(c->contact_list);
}

/*
 * Parametre olarak verilen
 * kisi listesini adi verilen
 * dosyaya yazar.
 */
void save_contact_list(ContactList c,char* fname){
   // Alistirma BONUS
}
