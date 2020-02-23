/*
 * linkedlist.c
 *
 *  Created on: Mar 7, 2019
 *      Author: Merve Unlu
 */
#include"linkedlist.h"
#include<stdio.h>
#include<stdlib.h>
struct node* listeBir(struct node *list1, struct node *list2)
{
    struct node* newlist=malloc(sizeof(struct node));
    struct node* temp;
    while(list1||list2){
       
        if(list1!=NULL && list2!=NULL)
        {
            newlist=list1;
            newlist->next=list2;
            list1=list1->next;
            list2=list2->next;
            newlist=newlist->next->next;
        }else if(list1!=NULL)
        {
           newlist=list1;
            list1=list1->next;     
            newlist=newlist->next;
        }
        else if(list2!=NULL)
        {
            newlist=list2;
            list2=list2->next;
              newlist=newlist->next;
        }
    }
    Print(newlist);
    return newlist;

}

void Listebol(struct node* liste,struct node **onliste, struct node **arkaliste)
{
    struct node* temp;
    temp=liste;
    int n=0;
    while(temp){
        n++;
        temp=temp->next;
        
    }
    printf("%d\n",n);
    if(n%2)
    n=n/2+1;
    else
        n/=2;
    printf("%d\n",n);
    temp=liste; (*onliste)=temp;
    for(int i = 0; i < n-1; i++)
    {
        
        temp=temp->next;

    }
    (*arkaliste)=temp->next;
    temp->next=NULL;
    

}
/* 10, 20, 30 elemanlarindan olusan basit bir liste
 * olusturan fonksiyon. */
// TODO: Alistirma 1
struct node* create_sample_list(void) {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = malloc(sizeof(struct node));
    if(head==NULL)
    return NULL;
    second = malloc(sizeof(struct node));
    if (second==NULL) {
        return NULL;
    }
    
    third = malloc(sizeof(struct node));
    if (third==NULL) {
        return NULL;
    }
    
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    return head;
}

/* Bagli listenin elemanlarini ekrana yazdiran fonksiyon. */
void Print(struct node* head) {
    struct node* cur = head;
    for (; cur != NULL; cur = cur->next) {
        printf("%d -> ", cur->data);
    }
    puts("NULL");
}

/* Bir listenin belli bir icerige sahip olup olmadigini
 * dogrulayan test fonksiyonu. */
int verifyList(struct node* head, int *values) {
    // TODO Alistirma 3
    struct node *cure=head;
    for(int i = 0; cure!=NULL;i++)
    {
       if(cure->data!=values[i])
       {
           //printf("\n%d-%d",cure->data,values[i]);
           return 0;
       }
       cure=cure->next; 
    }
    return 1;      
    
}

/* Parametre olarak verilen
 * head'in gosterdigi listede kac dugum oldugunu
 * hesaplayip geriye dondurun. */
int Length(struct node* head) {
   // TODO Alistirma 4
   int i=0;
   struct node* cure;
   cure = head;
   while(cure!=NULL){
       i++;
       cure=cure->next;
   }
   
   return i;
}
/* Listenin herhangi bir yerine dugum ekleyen asagidaki
 * fonksiyonu doldurun.
 * position == 0 ise listenin basina,
 * position == -1 ise listenin sonuna,
 * position baska bir deger ise araya ekleme yapacaksiniz.
 * Ornegin liste
 *      5, 10, 15
 * dugumlerinden olussun.
 *
 * position == 0  ise yeni liste: 20, 5, 10, 15
 * position == -1 ise yeni liste: 5, 10, 15, 20
 * position == 1  ise yeni liste: 5, 20, 10, 15
 *
 * olmalidir.
 */

void Insert(struct node **head, int new_value, int position) {
    // TODO Alistirma 5
    /* En one ekleme: position == 0
     * En sona ekleme: position == -1
     * Diger degerler, aralara ekleme.
     * (Position listenin uzunlugundan fazlaysa dogal olarak
     * en sona eklemis olacaksiniz) */
    struct node *new_node=malloc(sizeof(struct node));
    new_node->data=new_value;
    struct node *cur=malloc(sizeof(struct node));
    cur= *head;
    if(position==0)
    {
       new_node->next= *head;
       *head=new_node;
    }
    else if(position==-1)
    {
        struct node *cur;
        cur=*head;
        while(cur->next!=NULL)
        cur=cur->next;
        new_node->next=NULL;
        cur->next=new_node;        
    }
    else
    {
        int i=0;
        while(cur!=NULL&&i<position){

            cur=cur->next;
            i++;
        }
        struct node *tmp=malloc(sizeof(struct node));
        tmp=cur->next;
        cur->next=new_node;
        new_node->next=tmp;
    }
    
}

/* head'in gosterdigi listenin butun dugumlerini
 * free() ile temizleyin. */
void Free(struct node* head) {
   // TODO Alistirma 6
  if(head->next){
      Free(head->next); 
      
  }
   free(head);
   
}
/* position ile verilen pozisyondaki elemani *result
 * pointeriyla verilen yere yazin.
 * Eger olmayan bir pozisyon istendiyse fonksiyon 1 dondurmeli, liste sinirlari
 * dahilinde kalindi ve basarili olunduysa 0 dondurmelidir. */
int GetAt(struct node* head, int position, int *result) {
   // TODO: Alistirma 7
   struct node *curr;
   curr=head;
   int i=0;
   while(i<position){
       if (!curr) {
           return 1;
       }
       curr=curr->next;
       i++;
   }
   *result=curr->data;
   return 0;
   
}
/* Listede value degerinin kac defa
 * yer aldigini hesaplayip geri donduren fonksiyonu yazin. */
int Count(struct node* head, int value) {
  struct node* cur;
  cur=head;
  int count=0;
  while(cur){
      if (cur->data==value) {
          count++;
      }
      
      cur=cur->next;
  }
  
  return count;

}



