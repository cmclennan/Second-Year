/* COSC242 Lab 21
 * Breadth-First Search
 * October 2017
 * Cameron McLennan
 * 8168187
 * graph.h
 */

#ifndef graph_h
#define graph_h

#include <stdio.h>

typedef enum vertex_state { UNVISITED, VISITED_SELF, VISITED_DESCENDANTS } state_t;
typedef enum graph_type {DIRECTED, UNDIRECTED} graph_t;

typedef struct graphrec *graph;
typedef struct vertexrec vertex;

extern graph graph_new(int vertices_g);
extern graph graph_free(graph g);
extern graph graph_add_edge(graph g, int e1, int e2, graph_t t);
extern void graph_print(graph g);
extern void graph_BFS(graph g, int s);

#endif /* graph_h */

