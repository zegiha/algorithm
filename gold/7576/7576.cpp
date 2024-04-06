#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n, arr[1001][1003], cnt, ans;
vector <vector <queue <int>>> ripen;

void addToQ(queue<int>* rowQ, queue<int>* colQ) {
    int i = rowQ->front(), j = colQ->front();
    if((i + 1 < n) && arr[i + 1][j] == 0) {
        rowQ->push(i + 1);
        colQ->push(j);
        arr[i + 1][j] = 2;
        cnt--;
    }
    if((i - 1 >= 0) && arr[i - 1][j] == 0) {
        rowQ->push(i - 1);
        colQ->push(j);
        arr[i - 1][j] = 2;
        cnt--;
    }
    if((j + 1 < m) && arr[i][j + 1] == 0) {
        rowQ->push(i);
        colQ->push(j + 1);
        arr[i][j + 1] = 2;
        cnt--;
    }
    if((j - 1 >= 0) && arr[i][j - 1] == 0) {
        rowQ->push(i);
        colQ->push(j - 1);
        arr[i][j - 1] = 2;
        cnt--;
    }

    // for(i = 0; i < n; i++) {
    //     for(j = 0; j < m; j++) {
    //         cout << arr[i][j] << ' ';
    //     } cout << endl;
    // }
}

bool stepOfBfs(int index, int endRow, int endCol) {
    while(!ripen[index][0].empty()) {
        //큐에 하위노드 추가
        addToQ(&ripen[index][0], &ripen[index][1]);
        //방금 하위노드를 추가한 노드가 현재 깊이의 마지막 깊이일 시 종료
        if(endRow == ripen[index][0].front()) {
            ripen[index][0].pop();
            ripen[index][1].pop();
            
            return true;
        }
        //추가한 노드 삭제
        ripen[index][0].pop();
        ripen[index][1].pop();
    }
    return false;
}

int main() {
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0) cnt++;
            else if(arr[i][j] == 1){
                vector <queue <int>> tmp;
                queue <int> tmpRowQ, tmpColQ;
                tmpRowQ.push(i);
                tmpColQ.push(j);
                tmp.push_back(tmpRowQ);
                tmp.push_back(tmpColQ);
                ripen.push_back(tmp);
            }
        }
    }
    while(cnt) {
        bool sw = true;
        for(int i = 0; i < ripen.size(); i++) {
            if(stepOfBfs(i, ripen[i][0].back(), ripen[i][1].back())) sw = false;
        }
        //모든 노드 탐색 
        if(sw) {
            cout << -1;
            return 0;
        } else ans++;
    }
    cout << ans;
    return 0;
}

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

    // for(i = 0; i < n; i++) {
    //     for(j = 0; j < m; j++) {
    //         cout << arr[i][j] << ' ';
    //     } cout << endl;
    // }
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