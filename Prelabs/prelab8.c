#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node_ {
    int data;
    struct node_ *next;
} Queue;

Queue* enqueue(Queue* queue, int data); 

int main(void) {
    
    Queue* queue = NULL;
    
    queue = enqueue(queue, 1);
    
    assert(queue->next == NULL);
    assert(queue->data == 1);

    queue = enqueue(queue, 2);

    assert(queue->data == 1);
    assert(queue->next != NULL);
    assert(queue->next->data == 2);

    free(queue->next);
    free(queue);

    printf("You have successfully completed the prelab\n");

    return 0;
}

Queue*enqueue(Queue* queue, int data)
{

}

