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

void GRAPHisSink(Graph G) {
  vertex v, w;
  bool *isSink = calloc(G->V, sizeof(bool));

  for (v = 0; v < G->V; v++)
    isSink[v] = true;

  for (v = 0; v < G->V; v++)
    for (w = 0; w < G->V; w++)
      if (G->adj[v][w]) {
        isSink[v] = false;

        break;
      }

  for (v = 0; v < G->V; v++)
    isSink[v] ? printf("[%d]: TRUE\n", v) : printf("[%d]: FALSE\n", v);
}

void GRAPHisSource(Graph G) {
  vertex v, w;
  bool *isSource = calloc(G->V, sizeof(bool));

  for (v = 0; v < G->V; v++)
    isSource[v] = true;

  for (w = 0; w < G->V; w++)
    for (v = 0; v < G->V; v++)
      if (G->adj[v][w]) {
        isSource[w] = false;

        break;
      }
  
  for (v = 0; v < G->V; v++)
    isSource[v] ? printf("[%d]: TRUE\n", v) : printf("[%d]: FALSE\n", v);
}

int GRAPHindeg(Graph G, vertex w) {
  vertex v;
  int count = 0;

  for (v = 0; v < G->V; v++)
    if (G->adj[v][w])
      count++;
  
  return count;
}

int GRAPHoutdeg(Graph G, vertex v) {
  vertex w;
  int count = 0;

  for (w = 0; w < G->V; w++)
    if (G->adj[v][w])
      count++;
  
  return count;
}

bool GRAPHisUndirected(Graph G) {
  vertex v, w;

  for (v = 0; v < G->V; v++)
    for (w = 0; w < G->V; w++)
      if (G->adj[v][w])
        if (!G->adj[w][v])
          return false;
  
  return true;
}

int *UGRAPHdegrees(Graph G) {
  vertex v, w;
  int *degs = calloc(G->V, sizeof(int));

  if (GRAPHisUndirected(G)) {
    for (v = 0; v < G->V; v++)
      degs[v] = 0;

    for (v = 0; v < G->V; v++)
      for (w = 0; w < G->V; w++)
        if (G->adj[v][w])
          degs[v]++;

    return degs;
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