//
//  main.c
//  cc
//
//  Created by gumus on 28.02.2019.
//  Copyright © 2019 mac. All rights reserved.
//
typedef struct mphoto{
    char *tags[100];
    int tagnum;
    char size;
} photo;


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100
int main(int argc, const char * argv[]) {
    // insert code here...
    
    FILE *f= fopen("/Users/mac/Desktop/ALGORTİMA ve ileri prog tp/cc/cc/a_example.txt", "r");
    if (f==NULL) {
        printf("file not  open");
    }else {
        printf("acildi\n");
    }
   
    int n=100;
    int num=0;
    char line[n];
    fscanf(f, "%d",&num);
    printf("%d\n",num);
    char size=0;
    int xtag=0;
    

    photo p[num];
    for (int i=0; i<num; i++) {
        fgets(line, N, f);
        
        fscanf(f, "%c%d",&size,&xtag);
        p[i].tagnum=xtag;
        char *tag = malloc(100);
        for (int j=0; j<p[i].tagnum; j++) {
            
            fscanf(f, "%s",tag);
            p[i].size=size;
            p[i].tags[j]=malloc(100);
            strcpy(p[i].tags[j],tag);
            
        }
        
    }
    
    for (int j=0; j<num; j++) {
        printf("%d\n",p[j].tagnum);
        for (int i=0; i<p[j].tagnum ;i++) {
            printf("%s ",p[j].tags[i]);
        }
        printf("\n");
    }
   printf("%s",p[0].tags[2]);
    return 0;
}
