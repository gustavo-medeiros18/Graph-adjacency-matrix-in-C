#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define vertex int

typedef struct graph *Graph;

Graph GRAPHinit(int V);
void GRAPHinsertArc(Graph G, vertex v, vertex w);
void GRAPHremoveArc(Graph G, vertex v, vertex w);
void GRAPHshow(Graph G);