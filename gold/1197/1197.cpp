#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e, p[10'002], ans;
vector <pair <int, pair <int, int>>> arr;

void inputting() {
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr.push_back({c, {a, b}});
    }
}

void processing() {
    sort(arr.begin(), arr.end());
    for(int i = 1; i <= v; i++) p[i] = i;
}

int get_root(int node) {
    if(p[node] == node) return node;
    return p[node] = get_root(p[node]);
}
void Union(int first, int second) {
    int
    first_root = get_root(first),
    second_root = get_root(second);

    if(first_root != second_root) p[second_root] = first_root;
}

void solving() {
    for(int i = 0; i < e; i++) {
        int
        first_root = get_root(arr[i].second.first),
        second_root = get_root(arr[i].second.second);
        if(first_root != second_root) {
            Union(arr[i].second.first, arr[i].second.second);
            ans += arr[i].first;
        }
    }
}

void printing() {
    cout << ans;
}

int main() {
    inputting();
    processing();
    solving();
    printing();
}