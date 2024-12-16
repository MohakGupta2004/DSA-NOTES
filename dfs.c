#include <stdio.h>
#include <stdlib.h>
#define MAX 100


void dfs(int arr[MAX][MAX], int curr, int visited[]) {
  visited[curr] = 1;
  printf("%d ", curr);
  for(int i=0;i<MAX;i++){
    if(arr[curr][i] == 1 && !visited[i]){
      dfs(arr, i, visited);
    }
  }
}

void addedge(int adj[MAX][MAX], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

int main() {
  int adj[MAX][MAX] = {0};
  int v = 5;
  addedge(adj, 1,2);
  addedge(adj, 2,4);
  addedge(adj, 1,3);
  addedge(adj, 3,4);
  addedge(adj, 4,5);
  addedge(adj, 2,5);    
  int visited[] = {0};
  dfs(adj, 1, visited);  // Start BFS from vertex 0 (0-based indexing)
  return 0;
}
