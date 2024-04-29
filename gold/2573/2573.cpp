#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, glacierSum, ans;
vector <vector <int>> arr;
vector <pair <int, int>> glacier;

void printing() {
    cout << "\n***********************************\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << arr[i][j] << ' ';
        cout << "\n";
    }
}

bool isDivided() {
    int sum = 0;
    for(int i = 0; i < glacier.size(); i++) {
        if(arr[glacier[i].first][glacier[i].second] != 0) {
            vector <vector <bool>> visit;
            visit.resize(n + 1, vector <bool> (m + 1, false));
            queue <pair <int, int>> q;
            q.push(glacier[i]);
            visit[glacier[i].first][glacier[i].second] = true;
            while(!q.empty()) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                sum += arr[row][col];
                if(row + 1 < n) {
                    if(arr[row + 1][col] != 0 && !visit[row + 1][col]) {
                        q.push(make_pair(row + 1, col));
                        visit[row + 1][col] = true;
                    }
                }
                if(row - 1 >= 0) {
                    if(arr[row - 1][col] != 0 && !visit[row - 1][col]) {
                        q.push(make_pair(row - 1, col));
                        visit[row - 1][col] = true;
                    }
                }
                if(col + 1 < m) {
                    if(arr[row][col + 1] != 0 && !visit[row][col + 1]) {
                        q.push(make_pair(row, col + 1));
                        visit[row][col + 1] = true;
                    }
                }
                if(col - 1 >= 0) {
                    if(arr[row][col - 1] != 0 && !visit[row][col - 1]) {
                        q.push(make_pair(row, col - 1));
                        visit[row][col - 1] = true;
                    }
                }
            }
            // cout << glacierSum << ' ' << sum << endl;
            if(sum != glacierSum) return true;
            else return false;
        }
    }
    if(sum != glacierSum) return true;
    else return false;
}

void melting() {
    vector <vector <int>> arrCpy;
    vector <vector <bool>> visit;
    visit.resize(n + 1, vector <bool> (m + 1, false));
    arrCpy = arr;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visit[i][j] && arr[i][j] == 0) {
                queue <pair <int, int>> q;
                q.push(make_pair(i, j));
                visit[i][j] = true;
                while(!q.empty()) {
                    int row = q.front().first, col = q.front().second;
                    q.pop();
                    
                    if(row + 1 < n) {
                        if(arr[row + 1][col] == 0 && !visit[row + 1][col]) {
                            q.push(make_pair(row + 1, col));
                            visit[row + 1][col] = true;
                        } else {
                            if(arrCpy[row + 1][col] > 0) {
                                arrCpy[row + 1][col]--;
                                glacierSum--;
                            }
                        }
                    }
                    if(row - 1 >= 0) {
                        if(arr[row - 1][col] == 0 && !visit[row - 1][col]) {
                            q.push(make_pair(row - 1, col));
                            visit[row - 1][col] = true;
                        } else {
                            if(arrCpy[row - 1][col] > 0) {
                                arrCpy[row - 1][col]--;
                                glacierSum--;
                            }
                        }
                    }
                    if(col + 1 < m) {
                        if(arr[row][col + 1] == 0 && !visit[row][col + 1]) {
                            q.push(make_pair(row, col + 1));
                            visit[row][col + 1] = true;
                        } else {
                            if(arrCpy[row][col + 1] > 0) {
                                arrCpy[row][col + 1]--;
                                glacierSum--;
                            }
                        }
                    }
                    if(col - 1 >= 0) {
                        if(arr[row][col - 1] == 0 && !visit[row][col - 1]) {
                            q.push(make_pair(row, col - 1));
                            visit[row][col - 1] = true;
                        } else {
                            if(arrCpy[row][col - 1] > 0) {
                                arrCpy[row][col - 1]--;
                                glacierSum--;
                            }
                        }
                    }
                }
            }
        }
    }
    arr = arrCpy;
}

int main() {
    cin >> n >> m;
    arr.resize(n + 1, vector <int> (m + 1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] != 0) {
                glacier.push_back(make_pair(i, j));
                glacierSum += arr[i][j];
            }
        }
    }

    while(glacierSum > 0) {
        melting();
        ans++;
        // printing();
        if(isDivided()) {
            cout << ans;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int n, m, glacier, ans, glacierNum;
// vector <vector <int>> arr;

// void printing() {
//     cout << "\n***********************************\n";
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) cout << arr[i][j] << ' ';
//         cout << "\n";
//     }
// }

// bool isDivided() {
//     int cnt = 0;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             if(arr[i][j] != 0) {
//                 vector <vector <bool>> visit;
//                 queue <pair <int, int>> q;
//                 q.push(make_pair(i, j));
//                 visit.resize(n + 1, vector <bool> (m + 1, false));
//                 visit[i][j] = true;
//                 while(!q.empty()) {
//                     int row = q.front().first, col = q.front().second;
//                     q.pop();
//                     if(row + 1 < n) {
//                         if(arr[row + 1][col] != 0 && !visit[row + 1][col]) {
//                             visit[row + 1][col] = true;
//                             q.push(make_pair(row + 1, col));
//                             cnt++;
//                         }
//                     }
//                     if(row - 1 >= 0) {
//                         if(arr[row - 1][col] != 0 && !visit[row - 1][col]) {
//                             visit[row - 1][col] = true;
//                             q.push(make_pair(row - 1, col));
//                             cnt++;
//                         }
//                     }
//                     if(col + 1 < m) {
//                         if(arr[row][col + 1] != 0 && !visit[row][col + 1]) {
//                             visit[row][col + 1] = true;
//                             q.push(make_pair(row, col + 1));
//                             cnt++;
//                         }
//                     }
//                     if(col - 1 >= 0) {
//                         if(arr[row][col - 1] != 0 && !visit[row][col - 1]) {
//                             visit[row][col - 1] = true;
//                             q.push(make_pair(row, col - 1));
//                             cnt++;
//                         }
//                     }
//                 }
//                 cout << "\n***********************************\n";
//                 for(int i = 0; i < n; i++) {
//                     for(int j = 0; j < m; j++) cout << visit[i][j] << ' ';
//                     cout << "\n";
//                 }
//                 printing();
//                 cout << glacierNum << endl;
//                 if(cnt != glacierNum) {cout << "ch"; return true;}
//                 else return false;
//             }
//         }
//     }
// }

// int main() {
//     cin >> n >> m;
//     arr.resize(n + 1, vector<int> (m + 1, 0));
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             cin >> arr[i][j];
//             if(arr[i][j] != 0) {
//                 glacier += arr[i][j];
//                 glacierNum++;
//             }
//         }
//     }

//     while(glacier > 0) {
//         queue <pair <int, int>> q;
//         vector <vector <bool>> visit;
//         vector <vector <int>> arrCpy;
//         arrCpy = arr;
//         visit.resize(n + 1, vector <bool> (m + 1, false));
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(arr[i][j] == 0 && !visit[i][j]) {
//                     visit[i][j] = true;
//                     q.push(make_pair(i, j));
//                     while(!q.empty()) {
//                         int row = q.front().first, col = q.front().second;
//                         q.pop();
                        
//                         if(row + 1 < n) {
//                             if(arr[row + 1][col] == 0 && !visit[row + 1][col]) {
//                                 q.push(make_pair(row + 1, col));
//                                 visit[row + 1][col] = true;
//                             } else {
//                                 if(arrCpy[row + 1][col] != 0) {
//                                     arrCpy[row + 1][col]--;
//                                     glacier--;
//                                 } else glacierNum--;
//                             }
//                         }
//                         if(row - 1 >= 0) {
//                             if(arr[row - 1][col] == 0 && !visit[row - 1][col]) {
//                                 q.push(make_pair(row - 1, col));
//                                 visit[row - 1][col] = true;
//                             } else {
//                                 if(arrCpy[row - 1][col] != 0) {
//                                     arrCpy[row - 1][col]--;
//                                     glacier--;
//                                 } else glacierNum--;
//                             }
//                         }
//                         if(col + 1 < m) {
//                             if(arr[row][col + 1] == 0 && !visit[row][col + 1]) {
//                                 q.push(make_pair(row, col + 1));
//                                 visit[row][col + 1] = true;
//                             } else {
//                                 if(arrCpy[row][col + 1] != 0) {
//                                     arrCpy[row][col + 1]--;
//                                     glacier--;
//                                 } else glacierNum--;
//                             }
//                         }
//                         if(col - 1 >= 0) {
//                             if(arr[row][col - 1] == 0 && !visit[row][col - 1]) {
//                                 q.push(make_pair(row, col - 1));
//                                 visit[row][col - 1] = true;
//                             } else {
//                                 if(arrCpy[row][col - 1] != 0) {
//                                     arrCpy[row][col - 1]--;
//                                     glacier--;
//                                 } else glacierNum--;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         arr = arrCpy;
//         // printing();
//         ans++;
//         if(isDivided()) {
//             cout << ans;
//             return 0;
//         }
//     }
//     cout << 0;
// }