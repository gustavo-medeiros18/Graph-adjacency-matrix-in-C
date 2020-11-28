#include "grmatrix.h"

struct graph {
  int V;
  int A;
  int **adj;
};

static int **MATRIXint(int r, int c, int val) {
  int **m = malloc(r * sizeof(int *));

  for (vertex i = 0; i < r; ++i)
    m[i] = malloc(c * sizeof(int));

  for (vertex i = 0; i < r; ++i)
    for (vertex j = 0; j < c; ++j)
      m[i][j] = val;

  return m;
}

Graph GRAPHinit(int V) {
  Graph G = malloc(sizeof(Graph));

  G->V = V;
  G->A = 0;
  G->adj = MATRIXint(V, V, 0);

  return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w) {
  if (!G->adj[v][w]) {
    G->adj[v][w] = 1;
    G->A++;
  }
}

void GRAPHremoveArc(Graph G, vertex v, vertex w) {
  if (G->adj[v][w]) {
    G->adj[v][w] = 0;
    G->A--;
  }
}

void GRAPHshow(Graph G) {
  vertex v, w;

  for (v = 0; v < G->V; v++) {
    printf("[%d]:", v);

    for (w = 0; w < G->V; w++)
      if (G->adj[v][w])
        printf(" %d,", w);
    
    printf("\n");
  }
}