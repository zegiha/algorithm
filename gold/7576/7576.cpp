#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n, cnt, ans;
vector <vector <int>> arr;
queue <pair <int, int>> q; //first = row, seoncd = col

void addToQ(int row, int col) {
    pair <int, int> tmp;
    if(row + 1 < n) {
        if(arr[row + 1][col] == 0) {
            arr[row + 1][col] = 2;
            tmp.first = row + 1;
            tmp.second = col;
            q.push(tmp);
            cnt--;
        }
    }
    if(row - 1 >= 0) {
        if(arr[row - 1][col] == 0) {
            arr[row - 1][col] = 2;
            tmp.first = row - 1;
            tmp.second = col;
            q.push(tmp);
            cnt--;
        }
    }
    if(col + 1 < m) {
        if(arr[row][col + 1] == 0) {
            arr[row][col + 1] = 2;
            tmp.first = row;
            tmp.second = col + 1;
            q.push(tmp);
            cnt--;
        }
    }
    if(col - 1 >= 0) {
        if(arr[row][col - 1] == 0) {
            arr[row][col - 1] = 2;
            tmp.first = row;
            tmp.second = col - 1;
            q.push(tmp);
            cnt--;
        }
    }
}

int main() {
    cin >> m >> n;
    arr.resize(n + 1);
    for(int i = 0; i < n; i++) {
        arr[i].resize(m + 1);
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                pair <int, int> tmp;
                tmp.first = i;
                tmp.second = j;
                q.push(tmp);
            } else if(arr[i][j] == 0) {
                cnt++;
            }
        }
    }

    while(!q.empty() && cnt != 0) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            addToQ(row, col);
            // for(int i = 0; i < n; i++) {
            //     for(int j = 0; j < m; j++) cout << arr[i][j] << ' ';
            //     cout << endl;
            // }
            // cout << endl;
        }
        ans++;
        
    }
    if(cnt == 0) cout << ans;
    else cout << -1;
}

// #include <iostream>
// #include <queue>
// using namespace std;

// int arr[1001][1001] = {0, }, n, m, cnt, ans, ripen[1002][2] = {0, };
// queue <int> rowQ, colQ, endRowQ, endColQ;

// void addToQ(int row, int col) {
//     if(arr[row + 1][col] == 0 && row + 1 < n) {
//         arr[row + 1][col] = 2;
//         rowQ.push(row + 1);
//         colQ.push(col);
//         cnt--;
//     }
//     if(arr[row - 1][col] == 0 && row - 1 >= 0) {
//         arr[row - 1][col] = 2;
//         rowQ.push(row - 1);
//         colQ.push(col);
//         cnt--;
//     }
//     if(arr[row][col + 1] == 0 && col + 1 < m) {
//         arr[row][col + 1] = 2;
//         rowQ.push(row);
//         colQ.push(col + 1);
//         cnt--;
//     }
//     if(arr[row][col - 1] == 0 && col - 1 >= 0) {
//         arr[row][col - 1] = 2;
//         rowQ.push(row);
//         colQ.push(col - 1);
//         cnt--;
//     }
// }

// void bfs(int row, int col) {
//     // cout << arr[row][col] << endl;
//     addToQ(row, col);
//     if((row == endRowQ.front()) && (col == endColQ.front())) {
//         endRowQ.push(rowQ.back());
//         endColQ.push(colQ.back());
//         endRowQ.pop();
//         endColQ.pop();
//         ans++;
//         if(!cnt) return;
//     }
//     rowQ.pop();
//     colQ.pop();

//     if(rowQ.empty()) return;
//     bfs(rowQ.front(), colQ.front());
// }

// int main() {
//     cin >> m >> n;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             cin >> arr[i][j];
//             if(arr[i][j] == 1) {
//                 ripen[ripen[1001][0]][0] = i;
//                 ripen[ripen[1001][0]++][1] = j;
//             } else if(arr[i][j] == 0) cnt++;
//         }
//     }

//     for(int i = 0; i < ripen[1001][0]; i++) {
//         rowQ.push(ripen[i][0]);
//         colQ.push(ripen[i][1]);
//     }
    
//     if(ripen[1001][0] > 0 && cnt != 0) {
//         endRowQ.push(rowQ.back());
//         endColQ.push(colQ.back());
//         // cout << endRowQ.back();
//         bfs(rowQ.front(), colQ.front());
//     }


//     if(cnt == 0) cout << ans;
//     else cout << -1; 
//     // for(int i = 0; i < n; i++) {
//     //     for(int j = 0 ; j < m; j++) cout << arr[i][j] << ' ';
//     //     cout << endl;
//     // }
// }

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int m, n, arr[1001][1003], cnt, ans;
// vector <vector <queue <int>>> ripen;

// void addToQ(queue<int>* rowQ, queue<int>* colQ) {
//     int i = rowQ->front(), j = colQ->front();
//     if((i + 1 < n) && arr[i + 1][j] == 0) {
//         rowQ->push(i + 1);
//         colQ->push(j);
//         arr[i + 1][j] = 2;
//         cnt--;
//     }
//     if((i - 1 >= 0) && arr[i - 1][j] == 0) {
//         rowQ->push(i - 1);
//         colQ->push(j);
//         arr[i - 1][j] = 2;
//         cnt--;
//     }
//     if((j + 1 < m) && arr[i][j + 1] == 0) {
//         rowQ->push(i);
//         colQ->push(j + 1);
//         arr[i][j + 1] = 2;
//         cnt--;
//     }
//     if((j - 1 >= 0) && arr[i][j - 1] == 0) {
//         rowQ->push(i);
//         colQ->push(j - 1);
//         arr[i][j - 1] = 2;
//         cnt--;
//     }

//     // for(i = 0; i < n; i++) {
//     //     for(j = 0; j < m; j++) {
//     //         cout << arr[i][j] << ' ';
//     //     } cout << endl;
//     // }
// }

// bool stepOfBfs(int index, int endRow, int endCol) {
//     while(!ripen[index][0].empty()) {
//         //큐에 하위노드 추가
//         addToQ(&ripen[index][0], &ripen[index][1]);
//         //방금 하위노드를 추가한 노드가 현재 깊이의 마지막 깊이일 시 종료
//         if(endRow == ripen[index][0].front()) {
//             ripen[index][0].pop();
//             ripen[index][1].pop();
            
//             return true;
//         }
//         //추가한 노드 삭제
//         ripen[index][0].pop();
//         ripen[index][1].pop();
//     }
//     return false;
// }

// int main() {
//     cin >> m >> n;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++){
//             cin >> arr[i][j];
//             if(arr[i][j] == 0) cnt++;
//             else if(arr[i][j] == 1){
//                 vector <queue <int>> tmp;
//                 queue <int> tmpRowQ, tmpColQ;
//                 tmpRowQ.push(i);
//                 tmpColQ.push(j);
//                 tmp.push_back(tmpRowQ);
//                 tmp.push_back(tmpColQ);
//                 ripen.push_back(tmp);
//             }
//         }
//     }
//     while(cnt) {
//         bool sw = true;
//         for(int i = 0; i < ripen.size(); i++) {
//             if(stepOfBfs(i, ripen[i][0].back(), ripen[i][1].back())) sw = false;
//         }
//         //모든 노드 탐색 
//         if(sw) {
//             cout << -1;
//             return 0;
//         } else ans++;
//     }
//     cout << ans;
//     return 0;
// }

// #include <iostream>
// #include <queue>
// using namespace std;

// int arr[1001][1001], m, n, cnt = 0, ans, ripen[1002][2] = {0, };

// void addToQ(queue<int>* rowQ, queue<int>* colQ) {
//     int i = rowQ->front(), j = colQ->front();
//     if((i + 1 < n) && arr[i + 1][j] == 0) {
//         rowQ->push(i + 1);
//         colQ->push(j);
//         arr[i + 1][j] = 2;
//         cnt--;
//     }
//     if((i - 1 >= 0) && arr[i - 1][j] == 0) {
//         rowQ->push(i - 1);
//         colQ->push(j);
//         arr[i - 1][j] = 2;
//         cnt--;
//     }
//     if((j + 1 < m) && arr[i][j + 1] == 0) {
//         rowQ->push(i);
//         colQ->push(j + 1);
//         arr[i][j + 1] = 2;
//         cnt--;
//     }
//     if((j - 1 >= 0) && arr[i][j - 1] == 0) {
//         rowQ->push(i);
//         colQ->push(j - 1);
//         arr[i][j - 1] = 2;
//         cnt--;
//     }

//     for(i = 0; i < n; i++) {
//         for(j = 0; j < m; j++) {
//             cout << arr[i][j] << ' ';
//         } cout << endl;
//     }
// }
// bool bfs(int row, int col) {
//     queue<int> rowQ, colQ, endRowQ, endColQ;
//     addToQ(&rowQ, &colQ);
//     endRowQ.push(rowQ.back());
//     endColQ.push(colQ.back());

//     while(!rowQ.empty()) {

//     }
//     return false;
// }

// int main() {
//     cin >> m >> n;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             cin >> arr[i][j];
//             if(arr[i][j] == 0) cnt++;
//             else if(arr[i][j] == 1) {
//                 ripen[ripen[1001][0]][0] = i;
//                 ripen[ripen[1001][0]++][1] = j;
//             }
//         }
//     }

//     if(cnt) {
//         for(int index = 0; index < ripen[1001][0]; index++) {
//             if(ripen[index][0] != -1) {
//                 if(!bfs(ripen[index][0], ripen[index][1])) {
//                     ripen[index][0] = ripen[index][1] = -1;
//                 }
//             }
//         }
//     }
//     cout << ans;
// }