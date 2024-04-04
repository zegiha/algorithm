#include <iostream>
using namespace std;

int n, m, ans = 100;
bool board[8][8] ={
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}
},
arr[51][51];

void check(int row, int col) {
    int cnt = 0, cntR = 0;
    for(int i = row; i < row + 8; i++) {
        for(int j = col; j < col + 8; j++) {
            if(arr[i][j] != board[i - row][j - col]) cnt++;
            // cout << arr[i][j] << ' ';
        } // cout << endl;
    } // cout << endl;
    if(cnt < ans) ans = cnt;
    if(64 - cnt < ans) ans = 64 - cnt;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        char tmp[51];
        cin >> tmp;
        for(int j = 0; j < m; j++) arr[i][j] = tmp[j] == 'B';
    }

    for(int i = 0; i <= n - 8; i++) {
        for(int j = 0; j <= m - 8; j++) {
            check(i, j);
            // cout << i << ' ' << j << endl << endl;
        }
    }
    cout << ans;
}

// #include <iostream>
// using namespace std;

//     int n, m, arr[51][51], ans = 257;
//     char str[51][51];

// void setArr(int i, int j, char reverse) {
//     if((i + 1 < n) && (str[i + 1][j] == reverse)) arr[i][j]++;
//     else if (i + 1 >= n) arr[i][j]++;

//     if((i - 1 >= 0) && (str[i - 1][j] == reverse)) arr[i][j]++;
//     else if(i - 1 < 0) arr[i][j]++;

//     if((j + 1 < m) && (str[i][j + 1] == reverse)) arr[i][j]++;
//     else if(j + 1 >= m) arr[i][j]++;

//     if((j - 1 >= 0) && (str[i][j - 1] == reverse)) arr[i][j]++;
//     else if(j - 1 < 0) arr[i][j]++;
// }

// int main() {
//     cin >> n >> m;
//     for(int i = 0; i < n; i++) {
//         cin >> str[i];
//     }

//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             if(str[i][j] =='B') setArr(i, j, 'W');
//             else setArr(i, j, 'B');
//         }
//     }

//     for(int i = 0; i <= n - 8; i++) {
//         for(int j = 0; j <= m - 8; j++) {
//             int cnt = 0;
//             for(int k = i; k < i + 8; k++){
//                 for(int l = j; l < j + 8; l++) {
//                     if(arr[k][l] == 0) cnt++;
//                     cout << arr[k][l] << ' ';
//                 } cout << endl;
//             } cout << endl;
//             if(cnt < ans) {
//                 cout << cnt << endl << endl;
//                 ans = cnt;
//             }
//         }
//     }

//     cout << ans;
// } 