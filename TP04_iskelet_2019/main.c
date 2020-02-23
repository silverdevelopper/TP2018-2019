/*
 * main.c
 *
 *  Created on: Mar 7, 2019
 *      Author: Merve Unlu
 */


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"linkedlist.h"

int main(int argc, char *argv[])
{
    int test[] = {5, 1024, 10, 20, 30, 100, 2048};
    int test1[] = {10, 20, 30};
    int tmp;

    /* TODO :Alistirma 2 Basit listeyi yarat
     *           Ekrana bas */
    struct node *head;
    head=create_sample_list();

    struct node *cure=head;
    while(cure!=NULL){
        printf("%d ",cure->data);
        cure=cure->next;
    }
    
    

    /*TODO: Alistirma 3 verifyTest() fonksiyonu icin test */
    printf("\n%d ",verifyList(head,test1));

    /* TODO: Alistirma 4 Length() fonksiyonu icin test */
    printf("\n%d \n",Length(head));
    // printf("Listenin uzunlugu: %d\n", Length(list));

    // Print(list);

    /*TODO: Alistirma 5 Listeye test teki elemanlari ekle. */
    Insert(&head,test[1],0);
    Insert(&head,test[0],0);
    Insert(&head,test[5],-1);
    Insert(&head,test[6],-1);
    /* Su an liste: 5, 1024, 10, 20, 30, 100, 2048 */
    // Print(list);
    Print(head);
    
    /* TODO Alistirma 7 GetAt() fonksiyonu icin testler */
    // GetAt(list, 0, &tmp) ;
    // donen deger 5 olmali
    // printf("Donen deger %d \n",tmp );
    // GetAt(list, 6, &tmp);
    // donen deger 2048 olmali
    // printf("Donen deger %d \n",tmp );
    GetAt(head,0,&tmp);
    printf("Donen deger: %d \n",tmp);
    GetAt(head, 6, &tmp);
    printf("Donen deger: %d \n",tmp);
    /* TODO Alistirma 8 Count() fonksiyonu icin testler */
    // int number = Count(list, 5);
    
    Insert(&head,test[1],0);
    Insert(&head,test[1],0);
    Insert(&head,-33,0);
    Print(head);
    printf("\n---"); 
    struct node* arkaliste=malloc(sizeof(struct node));
    struct node* onliste=malloc(sizeof(struct node));
    Listebol(head,&onliste,&arkaliste);
    Print(onliste); 
    
   
    /* Bagli listeyi temizleyin */
    // Free(list);
    Insert(&arkaliste,-23,0);
     Print(arkaliste);
     printf("----------\n");
    Print(listeBir(onliste,arkaliste));
    Free(head);
    return 0;
}
