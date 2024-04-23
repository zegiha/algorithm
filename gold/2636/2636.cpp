#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, cheese;
vector <vector <int>> arr;

void getConnect(int row, int col) {
    if(row + 1 < n) {
        if(arr[row + 1][col] == 1) {
            //todo
        }
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n + 1);
    for(int i = 0; i < n; i++) {
        arr[i].resize(m + 1);
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j]) cheese++;
        }
    }

    while(!cheese) {
        vector <vector <bool>> visit;
        visit.resize(n + 1);
        for(int i = 0; i < n; i++) visit[i].resize(m + 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((arr[i][j] == 1) && !visit[i][j]){
                    visit[i][j] = true;
                    queue <pair <int, int>> q;
                    pair <int, int> tmp;
                    // getConnect(&tmp, i, j);
                }
            }
        }
    }
}