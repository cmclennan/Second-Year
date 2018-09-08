/* COSC242 Lab 21
 * Breadth-First Search
 * October 2017
 * Cameron McLennan
 * 8168187
 * main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


int main(){
	int size = 8;
	int p1;
	int p2;
	graph g = NULL;
	graph_t type = UNDIRECTED;

	scanf("%d",&size);

    g = graph_new(size);
   
	while(2 == scanf("%d%d", &p1, &p2)) {
		g = graph_add_edge(g, p1, p2, type);
	}
       
	graph_print(g);
	graph_BFS(g, 1);
	g = graph_free(g);
	exit(EXIT_SUCCESS); 
}
