/*
 * main.c
 *
 *  Created on: Feb 21, 2019
 *      Author: Merve Unlu
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"contactlist.h"

int main(int argc,char* argv[]){
    
    // Alistirma 4
    ContactList cl=create_contact_list(3);
    int i;
    for (i=0; i<cl.max_number; i++) {
        Contact c;
        c.id=i;
        printf("Enterez-vous contact name %d:\n",i);
        scanf("%s",c.name);
        printf("Enterez-vous contact surname %d:\n:",i);
        scanf("%s",c.surname);
        printf("Enterez-vous tel numbber %d:\n",i);
        scanf("%s",c.tel_number);
        add_new_contact(&cl, c);
        
    }
    print_contact_list(cl);
    // Alistirma 6
    printf("isim ver bro:\n");
    char name[20];
    scanf("%s",name);
    printf("tel:%s\n",find_contact(&cl,"aa"));
    
    // alistirma 8
    char *x="fegds";
    edt_contact(cl.contact_list[0].name,x,&cl);
    printf("tel2: %s\n",cl.contact_list[0].tel_number);
    
    // Alistirma 7
    delete_contact_list(&cl);
    
    
    
    
}
