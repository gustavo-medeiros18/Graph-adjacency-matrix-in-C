#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define vertex int

typedef struct graph *Graph;

Graph GRAPHinit(int V);
Graph GRAPHbuildPath(int V);
void GRAPHinsertArc(Graph G, vertex v, vertex w);
void GRAPHremoveArc(Graph G, vertex v, vertex w);
void GRAPHisSink(Graph G);
void GRAPHisSource(Graph G);
int GRAPHindeg(Graph G, vertex w);
int GRAPHoutdeg(Graph G, vertex v);
bool GRAPHisUndirected(Graph G);
bool GRAPHcheckWalk(Graph G, int seq[], int n);
int *UGRAPHdegrees(Graph G);
void GRAPHshow(Graph G);