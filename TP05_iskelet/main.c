#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include "patient.h"

int main(int argc, const char *argv[])
{
printf("hata 5");
    srand(time(NULL));
    
    struct patientInfo *queue;
    queue=malloc(sizeof(struct patientInfo));
    int i;
    
    printf("hata 4");
    for (i = 0; i < 10; i++) {
        int ssn = (rand() % 1001) + 1000;
        int sickness = (rand() % MAX_PRIO);
        printf("hata 3");
        queue = enqueue(queue, sickness, ssn);
        print_queue(queue);

        if ((rand() % 2) && (rand() % 2)) {
            /* Dequeue */
            printf("hata 2");
            struct patientInfo *out = dequeue(&queue);
            printf("****[%12s (priority: %d)] is now out of the queue!\n",
                    priority_strings[out->prio], out->prio);
        }
    }

    return 0;
}
