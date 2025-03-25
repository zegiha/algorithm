#include <iostream>
#include <vector>

using namespace std;

int n, arr[10][10];
vector <pair <int, int>> ap;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) ap.push_back({i, j});
        }
    }
}