/* COSC242 Lab 21
 * Breadth-First Search
 * October 2017
 * Cameron McLennan
 * 8168187
 * queue-array.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
 * struct: queue
 * -------------
 * Global definition of variables to be used throughout the graph 
 * implementation. Used for the vertex implementation.
 *
 * Takes no parameters but holds global variable declarations.
 * 
 * returns Nothing.
*/

struct queue {
   int  *items;
   int num_items;
   int capacity;
   int head;
};

/*
 * Function: *emalloc(size_t s)
 * -----------------------------
 * Allocates memory for items, with error checking.
 *
 * @param s: Takes a size which will be how much memory to allocate.
 *
 * Returns: Allocated memory.
 */

static void *emalloc(size_t s){
   void *result = malloc(s);
   if (result == NULL){
      fprintf(stderr, "Malloc failed\n");
      exit(EXIT_FAILURE);
   }
   return result;
}

/*
 * Function: queue_new()
 * ---------------------
 * Function to create a new empty queue with a default size of 7.
 *
 * Takes no parameters.
 * 
 * Returns: An empty ready to use queue.
*/

queue queue_new() {
   int default_size = 7;
   int i;

   queue result = emalloc(sizeof(*result));
   result->capacity = default_size;
   result->num_items = 0;
   result->head = 0;
   result->items = emalloc(sizeof(result->items[0]) * result->capacity);

   for(i = 0; i < result->capacity; i++){
      result->items[i] = 0;
   }
   return result;
}

/*
 * Function: enqueue(queue q) 
 * --------------------------
 * Function to queue items in the queue.
 *
 * @param g: The queue that is getting items queued into.
 * 
 * Returns: nothing.
*/

void enqueue(queue q, double item) {
   if (q->num_items < q->capacity) {
      q->items[(q->head + q->num_items++) % q->capacity] = item;
   }
}

/*
 * Function: dequeue(queue q) 
 * --------------------------
 * Function to dequeue items from the queue.
 *
 * @param g: The queue that is getting items dequeued from.
 * 
 * Returns: An empty dequeued queue.
*/

double dequeue(queue q) {
   int dequeued;

   if (q->num_items > 0){
      dequeued = q->items[q->head];
      q->head = (q->head +1) % q->capacity;
      q->num_items--;
      return dequeued;
   }
   return 0;
}

/*
 * Function: queue_print(queue q) 
 * ------------------------------
 * Function to print out the queue itself.
 *
 * @param g: The queue that is getting printed out.
 * 
 * Returns: nothing.
*/

void queue_print(queue q) {
   /* print queue contents one per line to 2 decimal places */
   int index = 0;
   int i;
   for(i = 0; i < q->num_items; i++){
      index = (q->head + i) & q->capacity;
      printf("%d\n", q->items[index]);
   }
}

/*
 * Function: queue_print_info(queue q) 
 * -----------------------------------
 * Function to print out information on the queue.
 *
 * @param g: The queue that is getting its information printed out.
 * 
 * Returns: nothing.
*/

void queue_print_info(queue q) {
   int i;
   printf("capacity %d, num_items %d, head %d\n[", q->capacity,
         q->num_items, q->head);
   for (i = 0; i < q->capacity; i++) {
      printf("%s%d", i == 0 ? "" : ", ", q->items[i]);
   }
   printf("]\n");
}

/*
 * Function: queue_size(queue q) 
 * ----------------------------- 
 * Function to print out the size of the queue.
 *
 * @param g: The queue that is getting its size printed out.
 * 
 * Returns: The size of the queue.
*/

int queue_size(queue q) {
   return q->num_items;
}

/*
 * Function: queue_free(graph g)
 * ----------------------------- 
 * Function to free the queue.
 *
 * @param g: The queue that is getting freed.
 * 
 * Returns: A freed queue.
*/

queue queue_free(queue q) {
   free(q->items);
   free(q);
   return q;
}
