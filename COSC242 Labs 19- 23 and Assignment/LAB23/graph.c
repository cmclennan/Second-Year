/* COSC242 Lab 23
 * Depth-First Search
 * October 2017
 * Cameron McLennan
 * 8168187
 * graph.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

/*
 *Global variable declaration for DFS and visit methods to use to work together
 */

static int step;

/*
 * struct: vertexrec
 * -----------------
 * Global definition of variables to be used throughout the graph 
 * implementation. Used for the vertex implementation.
 *
 * Takes no parameters but holds global variable declarations.
 * 
 * returns Nothing.
*/

struct vertexrec {
	int predecessor;
	int distance;
	int finish;
	state_t state;
};

/*
 * struct: graphrec
 * -----------------
 * Global definition of variables to be used throughout the graph 
 * implementation. 
 *
 * Takes no parameters but holds global variable declarations.
 * 
 * returns Nothing.
*/

struct graphrec {
    int **edges;
    int size;
    vertex *vertices;

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
	if(NULL == result){
		fprintf(stderr, "memory allocation error");
		exit(EXIT_FAILURE);
	}
	return result;
}

/*
 * Function: graph_new(int vertices_g)
 * -----------------------------------
 * Function to create a new graph with amount of verticies taken as
 * an input parameter.
 *
 * @param vertices_g: Takes an input of how many verticies are going
 * to be in the new graph.
 * 
 * Returns: g, which is the new graph with no edges.
*/

graph graph_new(int vertices_g){
	int h;
	int i;
	graph g = emalloc(sizeof(*g));
	g->size = vertices_g;
	g->vertices = emalloc(g->size * sizeof(g->vertices[0]));
	g->edges = emalloc(g->size * sizeof(g->edges[0]));
	for (i = 0; i < vertices_g; i++){
		g->edges[i] = emalloc(g->size * sizeof(g->edges[0][0]));
	}
	for(h = 0; h < g->size; h++){
		for(i = 0; i < g->size; i++){
			g->edges[h][i] = 0;
		}
	}

	return g;
}

/*
 * Function: graph_add_edge(graph g, int p1, int p2, graph_t t)
 * ------------------------------------------------------------
 * Function to add an edge in between two verticies, with the ability to have
 * bidirectional edges. This will be able to be used for directed and
 * undirected graphs.
 *
 * @param g: The graph that is getting edge(s) added to.
 * @param p1: Verticie which will be connected to p2 with an edge.
 * @param p2: Verticie which will be connected to p1 with an edge.
 * @param t: Type of graph, either directed or undirected.
 * 
 * Returns: g, which is the graph with edge(s) added.
*/

graph graph_add_edge(graph g, int p1, int p2, graph_t t){
	if(t == DIRECTED){
		g->edges[p1][p2] = 1;
	} else {
		g->edges[p1][p2] = 1;
		g->edges[p2][p1] = 1;
	}
	return g;

}

/*
 * Function: graph_DFS(graph g)
 * ----------------------------
 * Function to search the previously created graph using depth-first search.
 *
 * @param g: The graph that is getting being searched.
 * 
 * Returns: nothing;
*/

graph graph_DFS(graph g){
    int i;
    for(i = 0; i < g->size; i++){
        g->vertices[i].state = UNVISITED;
        g->vertices[i].predecessor = -1;
    }
    step = 0;
    for(i = 0; i < g->size; i++){
        if(g->vertices[i].state == UNVISITED){
            visit(g,i);
        }
    }
    printf("vertex distance pred finish\n");
    for (i = 0; i < g->size; i++){
    	printf("%4d%7d%7d%7d\n", i, g->vertices[i].distance, g->vertices[i].predecessor,g->vertices[i].finish);
    }
    return 0;
}



/*Function: visit(graph g, int v)
 *-------------------------------
 * Function to visit each vertex in a defined graph.
 *
 * @param g: The graph that will be read, which will have its contents visited.
 * @param v: The point that is being visited.
 * Returns: nothing.
 */

void visit(graph g, int v){
    int i;
    g->vertices[v].state = VISITED_SELF;
    step++;
    g->vertices[v].distance = step;
    for (i = 0; i < g->size; i++){
        if(g->edges[v][i] == 1 && g->vertices[i].state == UNVISITED) {
            g->vertices[i].predecessor = v;
            visit(g, i);
        }
    }
    step++;
    g->vertices[v].state = VISITED_DESCENDANTS;
    g->vertices[v].finish = step;
}

/*Function: graph_print(graph g)
 *------------------------------
 * Function to print an adjacency list, even though it isn't one.
 *
 * @param g: The graph that will be read, which will have its contents printed.
 *
 * Returns: nothing.
 */

void graph_print(graph g){
	int h;
	int i;
	printf("adjacency list: \n");
	for(h = 0; h < g->size; h++){
		printf("%d | ", h);
		for(i = 0; i < g->size; i++){
			if (g->edges[h][i] == 1){
				printf("%d, ", i);
			}
		}
		printf("\n");
	}

}

/*
 * Function: graph_free(graph g)
 * ----------------------------- 
 * Function to free the graph.
 *
 * @param g: The graph that is getting freed.
 * 
 * Returns: A freed graph.
*/

graph graph_free(graph g){
	int i;
	for(i = 0; i < g->size; i++){
		free(g->edges[i]);
	}
	free(g->edges);
	free(g->vertices);
	free(g);
	return g;
}
