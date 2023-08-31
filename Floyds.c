#include <stdio.h>
#include <stdlib.h>

void floydWarshall(int **graph, int n) {
  int i, j, k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        graph[i][j] = 0;
      } else {
        graph[i][j] = 99999;
      }
    }
  }
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (graph[i][k] + graph[k][j] < graph[i][j]) {
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }
}

int main() {
  int n, e, u, v, w, i, j;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("Enter the number of edges:\n");
  scanf("%d", &e);
  int **graph = (int **)malloc((long unsigned) n * sizeof(int *));
  for (i = 0; i < n; i++) {
    graph[i] = (int *)malloc((long unsigned) n * sizeof(int));
  }
  for (i = 0; i < e; i++) {
    printf("Enter the end vertices of edge%d with its weight \n", i + 1);
    scanf("%d%d%d", &u, &v, &w);
    graph[u][v] = w;
  }

  floydWarshall(graph, n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        printf("%d ", 0);
      } else {
        printf("%d ", graph[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}
