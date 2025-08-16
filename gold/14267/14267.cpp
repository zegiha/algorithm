#include <iostream>
#include <vector>

using namespace std;

int n, m, nodeValue[100'001];
vector <vector <int>> children;

void spreadValue(int target, int value) {
    nodeValue[target] += value;

    for(int child : children[target]) {
        spreadValue(child, nodeValue[target]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    children.resize(n + 1, {});
    for(int i = 0; i < n; i++) {
        int bossN; cin >> bossN;
        if(bossN == -1) continue;
        children[bossN].push_back(i + 1);
    }

    int target, value;
    while(m--) {
        cin >> target >> value;
        nodeValue[target] += value;
    }

    spreadValue(1, 0);

    for(int i = 1; i <= n; i++) cout << nodeValue[i] << ' ';
}