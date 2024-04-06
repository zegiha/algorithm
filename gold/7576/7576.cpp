#include <iostream>
#include <queue>
using namespace std;

int n, m, arr[1001][1001];

int main() {
    int map[1001][1001], root[1001][2] = {0, }, rootN = 0;
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j]) {
                root[rootN][0] = i;
                root[rootN++][1] = j;
            }
        }
    }
    
}