#include <iostream>
#include <stdio.h>

#define INF 2'100'000'000.0

using namespace std;

int arr[201][201], n, m, max_edges[201][201];

double burnGraph() {
  double min_time = INF, max_time, spent_time, remain_len, max_edge;

  for(int s = 1; s <= n; s++) {
    for(int f = 1; f <= n; f++) {
      for(int t = 1; t <= n; t++) {
        max_edge = max_edges[f][t];
        if(max_edge == -1) continue;

        remain_len = max_edge - (arr[s][t] - arr[s][f]);
        if(remain_len < 0) continue;

        spent_time = remain_len / 2 + arr[s][t];
        max_time = max(max_time, spent_time);
      }
    }

    min_time = min(min_time, max_time);
  }

  return min_time;
}

int main() {
  for(int i = 0; i < 201; i++) for(int j = 0; j < 201; j++) max_edges[i][j] = -1;

  cin >> n >> m;
  int a, b, c;
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    arr[a][b] = c;
    arr[b][a] = c;
    max_edges[a][b] = max(max_edges[a][b], c);
    max_edges[b][a] = max(max_edges[b][a], c);
  }

  for (int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      for(int k = 1; k <= n; k++) {
        arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
      }
    }
  }

  printf("%.1lf", burnGraph());
}