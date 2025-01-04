#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair <int, int>;

int n, m, x;

vector <int> dijkstra(vector <vector <pii>> arr) {
    priority_queue <pii, vector<pii>, greater<pii>> q;
    vector <int> dist(n + 1, -1);

    q.push({0, x});
    dist[x] = 0;

    while(!q.empty()) {
        int value = q.top().first, node = q.top().second;
        q.pop();
        if(dist[node] != -1 && dist[node] < value) continue;

        for(int i = 0; i < arr[node].size(); i++) {
            int weight = arr[node][i].second, new_node = arr[node][i].first;
            if(dist[new_node] == -1 || dist[new_node] > value + weight) {
                dist[new_node] = value + weight;
                q.push({value + weight, new_node});
            }
        }
    }

    return dist;
}

int main() {
    cin >> n >> m >> x;

    vector <vector <pii>> normal(n + 1), reverse(n + 1);

    int a, b, t; 
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        normal[a].push_back({b, t});
        reverse[b].push_back({a, t});
    }

    vector <int> go = dijkstra(normal), back = dijkstra(reverse);

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        if(ans < go[i] + back[i]) {
            ans = go[i] + back[i];
        }
    }

    cout << ans;
}