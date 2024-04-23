#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, small = 2100000000, ans;
vector <vector <int>> arr;
vector <pair <int, int>> virus;

void printing(vector <vector <int>>* arr) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << (*arr)[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

void addToQ(queue <pair <int, int>>* q, vector <vector <int>>* arrCpy, int row, int col) {
    if(row + 1 < n) {
        if((*arrCpy)[row + 1][col] == 0) {
            (*arrCpy)[row + 1][col] = 2;
            q->push(make_pair(row + 1, col));
        }
    }
    if(row - 1 >= 0) {
        if((*arrCpy)[row - 1][col] == 0) {
            (*arrCpy)[row - 1][col] = 2;
            q->push(make_pair(row - 1, col));
        }
    }
    if(col + 1 < m) {
        if((*arrCpy)[row][col + 1] == 0) {
            (*arrCpy)[row][col + 1] = 2;
            q->push(make_pair(row, col + 1));
        }
    }
    if(col - 1 >= 0) {
        if((*arrCpy)[row][col - 1] == 0) {
            (*arrCpy)[row][col - 1] = 2;
            q->push(make_pair(row, col - 1));
        }
    }
}

void getSpread() {
    int cnt = 0;
    vector <vector <int>> arrCpy;
    copy(arr.begin(), arr.end(), back_inserter(arrCpy));
    queue <pair <int, int>> q;
    for(int t = 0; t < virus.size(); t++) q.push(virus[t]);
    while(!q.empty()) {
        int row = q.front().first, col = q.front().second;
        q.pop();
        cnt++;
        addToQ(&q, &arrCpy, row, col);
    }
    if (cnt < small) {
        small = cnt;
        //printing(&arrCpy);
        ans = 0;
        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ; j < m; j++) if(arrCpy[i][j] == 0) ans++;
        }
    }
}

void make_wall() {
    for(int r1 = 0; r1 < n; r1++) {
        for(int c1 = 0; c1 < m; c1++) {
            if(arr[r1][c1] != 0) continue;
            arr[r1][c1] = 3;
            for(int r2 = 0; r2 < n; r2++) {
                for(int c2 = 0; c2 < m; c2++) {
                    if(arr[r2][c2] != 0) continue;
                    if(!((r2 == r1) && (c2 == c1))){
                        arr[r2][c2] = 3;
                        for(int r3 = 0; r3 < n; r3++) {
                            for(int c3 = 0; c3 < m; c3++) {
                                if(arr[r3][c3] != 0) continue;
                                if((!((r3 == r1) && (c3 == c1))) && (!((r2 == r1) && (c2 == c1)))) {
                                    arr[r3][c3] = 3;
                                    // printing();
                                    getSpread();
                                    arr[r3][c3] = 0;
                                }
                            }
                        }
                        arr[r2][c2] = 0;
                    }
                }
            }
            arr[r1][c1] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n + 1);
    for(int i = 0 ; i < n; i++) {
        arr[i].resize(m + 1);
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }
    
    make_wall();
    cout << ans;
}

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int n, m;
// vector <vector <int>> arr;
// vector <pair <int, int>> virus;

// void print_arr() {
//     cout << "\n*************************************************************************************\n";
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             cout << arr[i][j] << ' ';
//         }
//         cout << endl;
//     }
// }

// void make_wall() {
    
// }

// int main() {
//     cin >> n >> m;
//     arr.resize(n + 1);
//     for(int i = 0; i < n; i++) {
//         arr[i].resize(m + 1);
//         for(int j = 0; j < m; j++) {
//             cin >> arr[i][j];
//             if(arr[i][j] == 2) virus.push_back(make_pair(i, j));
//         }
//     }
    
//     make_wall();
// }