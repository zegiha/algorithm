#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, cheese, depth, remain;
vector <vector <int>> arr;

void printing() {
    cout << "\n**************************************************\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] != -1) cout << arr[i][j] << " ";
            else cout << 2 << " ";
        }
        cout << endl;
    }
    cout << "**************************************************\n";
}

void getConnected(vector <pair <int, int>>* connect, vector <vector <bool>>* visit, int row, int col) {
    if(row + 1 < n) {
        if((arr[row + 1][col] != -1) && !(*visit)[row + 1][col]) connect->push_back(make_pair(row + 1, col));
    }
    if(row - 1 >= 0) {
        if((arr[row - 1][col] != -1) && !(*visit)[row - 1][col]) connect->push_back(make_pair(row - 1, col));
    }
    if(col + 1 < m) {
        if((arr[row][col + 1] != -1) && !(*visit)[row][col + 1]) connect->push_back(make_pair(row, col + 1));
    }
    if(col - 1 >= 0) {
        if((arr[row][col - 1] != -1) && !(*visit)[row][col - 1]) connect->push_back(make_pair(row, col - 1));
    }

}

int main() {
    cin >> n >> m;
    arr.resize(n + 1, vector <int> (m + 1, 0));
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) cheese++;
        }
    }

    vector <vector <bool>> visit;
    visit.resize(n + 1, vector <bool> (m + 1, false));
    queue <pair <int, int>> q;
    q.push(make_pair(0, 0));
    visit[0][0] = true;
    while(cheese > 0) {
        vector <pair <int, int>> melt;
        while(!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            vector <pair <int, int>> connect;
            getConnected(&connect, &visit, row, col);
            for(int i = 0; i < connect.size(); i++) {
                if(arr[connect[i].first][connect[i].second] == 0) {
                    q.push(connect[i]);
                    visit[connect[i].first][connect[i].second] = true;
                    arr[connect[i].first][connect[i].second] = -1;
                }
                else if(arr[connect[i].first][connect[i].second] == 1) {
                    melt.push_back(connect[i]);
                    arr[connect[i].first][connect[i].second] = 2;
                }
            }
        }
        remain = cheese;
        
        for(int i = 0; i < melt.size(); i++) {
            arr[melt[i].first][melt[i].second] = 0;
            q.push(melt[i]);
            cheese--;
        }
        depth++;
        // printing();
        // cout << cheese << endl;
    }
    cout << depth << endl << remain;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int n, m, cheese, meltingTime, lastPiece;
// vector <vector <int>> arr;

// void printing() {
//     cout << "\n**************************************************\n";
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             if(arr[i][j] != -1) cout << arr[i][j] << " ";
//             else cout << 2 << " ";
//         }
//         cout << endl;
//     }
//     cout << "**************************************************\n";
// }


// int main() {
//     cin >> n >> m;
//     arr.resize(n + 1, vector <int>(m + 1, 0));
//     for(int i = 0;  i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             cin >> arr[i][j];
//             if(arr[i][j] == 1) cheese++;
//         }
//     }

//     vector <vector <bool>> visit;
//     visit.resize(n + 1, vector <bool> (m + 1, false));
//     queue <pair <int, int>> q;
//     q.push(make_pair(0, 0));
//     visit[0][0] = true;
//     while(cheese > 0) {
//         vector <pair <int, int>> melted;
//         while(!q.empty()) {
//             int row = q.front().first, col = q.front().second;
//             q.pop();
//             visit[row][col] = true;
//             if(row + 1 < n) {
//                 if(!visit[row + 1][col]) {
//                     if(arr[row + 1][col] == 0) q.push(make_pair(row + 1, col));
//                     else if(arr[row + 1][col] == 1) melted.push_back(make_pair(row + 1, col));
//                 }
//             }
//             if(row - 1 >= 0) {
//                 if(!visit[row - 1][col]) {
//                     if(arr[row - 1][col] == 0) q.push(make_pair(row - 1, col));
//                     else if(arr[row - 1][col] == 1) melted.push_back(make_pair(row - 1, col));
//                 }
//             }
//             if(col + 1 < m) {
//                 if(!visit[row][col + 1]) {
//                     if(arr[row][col + 1] == 0) q.push(make_pair(row, col + 1));
//                     else if(arr[row][col + 1] == 1) melted.push_back(make_pair(row, col + 1));
//                 }
//             }
//             if(col - 1 >= 0) {
//                 if(!visit[row][col - 1]) {
//                     if(arr[row][col - 1] == 0) q.push(make_pair(row, col - 1));
//                     else if(arr[row][col - 1] == 1) melted.push_back(make_pair(row, col - 1));
//                 }
//             }
//         }
//         meltingTime++;
//         if(melted.size() != 0) {
//             lastPiece = melted.size();
//             cout << melted.size();
//             for(int i = 0; i < melted.size(); i++) {
//                 cout << arr[melted[i].first][melted[i].second] << "  ||  arr\n" << melted[i].first << "  ||  row\n" << melted[i].second << "  ||  col\n\n";
//                 arr[melted[i].first][melted[i].second] = 0;
//                 q.push(melted[i]);
//                 cheese--;
//             }
//         }
//         printing();
//     }

//     cout << meltingTime << endl << lastPiece;
// }

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <list>
// using namespace std;

// int n, m, meltTime, lastPiece;
// vector <vector <int>> arr;
// list <pair <int, int>> cheese;

// void printing() {
//     cout << "\n**************************************************\n";
//     for(int i = 0; i <= n + 2; i++) {
//         for(int j = 0; j <= m + 2; j++) {
//             if(arr[i][j] != -1) cout << arr[i][j] << " ";
//             else cout << 2 << " ";
//         }
//         cout << endl;
//     }
//     cout << "**************************************************\n";
// }

// void addToQ(queue <pair <int, int>>* q, int row, int col) {
//     if(row + 1 <= n + 2) {
//         if(arr[row + 1][col] == 0) q->push(make_pair(row + 1, col));
//     }
//     if(row - 1 >= 0) {
//         if(arr[row - 1][col] == 0) q->push(make_pair(row - 1, col));
//     }
//     if(col + 1 <= m + 2) {
//         if(arr[row][col + 1] == 0) q->push(make_pair(row, col + 1));
//     }
//     if(col - 1 >= 0) {
//         if(arr[row][col - 1] == 0) q->push(make_pair(row, col - 1));
//     }
// }

// void markingAir(int i, int j) {
//     queue <pair <int, int>> q;
//     q.push(make_pair(i, j));
//     while(!q.empty()) {
//         int row = q.front().first, col = q.front().second;
//         arr[row][col] = -1;
//         addToQ(&q, row, col);
//         q.pop();
//     }
// }

// void preprocessing() {
//     for(int i = 0; i <= n + 2; i++) {
//         if((i == 0) || (i == n + 2)) {
//             for(int j = 0; j <= m + 2; j++) if(arr[i][j] == 0) markingAir(i, j);
//         } else {
//             if(arr[i][0] == 0) markingAir(i, 0);
//             if(arr[i][m + 2] == 0) markingAir(i, m + 2);
//         }
//     }
// }

// bool isN(int row, int col, int n) {
//     if(arr[row + 1][col] == n) return true;
//     if(arr[row - 1][col] == n) return true;
//     if(arr[row][col + 1] == n) return true;
//     if(arr[row][col - 1] == n) return true;
//     return false;
// }

// int main() {
//     cin >> n >> m;
//     arr.resize(n + 3, vector<int>(m + 3, 0));

//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= m; j++) {
//             cin >> arr[i][j];
//             if(arr[i][j] == 1) cheese.push_back(make_pair(i, j));
//         }
//     }
//     preprocessing();

//     while(cheese.size() > 0) {
//         lastPiece = cheese.size();

//         auto it = cheese.begin();
//         vector <vector <int>> arrCpy;
//         copy(arr.begin(), arr.end(), back_inserter(arrCpy));
//         while (it != cheese.end()) {
//             int row = it->first, col = it->second;
//             if (isN(row, col, -1)) {
//                 arrCpy[row][col] = -1;
//                 it = cheese.erase(it);
//             } else {
//                 ++it;
//             }
//         }
//         arr = arrCpy;
//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j <= m; j++) {
//                 if(arr[i][j] == 0 && isN(i, j, -1)) {
//                     markingAir(i, j);
//                 }
//             }
//         }

//         // printing();

//         meltTime++;
//     }

//     cout << meltTime << endl << lastPiece;
// }

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <list>
// using namespace std;

// // 13 12
// // 0 0 0 0 0 0 0 0 0 0 0 0
// // 0 0 0 0 0 0 0 0 0 0 0 0
// // 0 0 0 0 0 0 0 1 1 0 0 0
// // 0 1 1 1 0 0 0 1 1 0 0 0
// // 0 1 1 1 1 1 1 0 0 0 0 0
// // 0 1 1 1 1 1 0 1 1 0 0 0
// // 0 1 1 1 1 0 0 1 1 0 0 0
// // 0 0 1 1 0 0 0 1 1 0 0 0
// // 0 0 1 1 1 1 1 1 1 0 0 0
// // 0 0 1 1 1 1 1 1 1 0 0 0
// // 0 0 1 1 1 1 1 1 1 0 0 0
// // 0 0 1 1 1 1 1 1 1 0 0 0
// // 0 0 0 0 0 0 0 0 0 0 0 0

// int n, m, meltTime, lastPiece;
// vector <vector <int>> arr;
// list <pair <int, int>> cheese;

// bool isMelt(int row, int col) {
//     if(arr[row + 1][col] == -1) return true;
//     if(arr[row - 1][col] == -1) return true;
//     if(arr[row][col + 1] == -1) return true;
//     if(arr[row][col - 1] == -1) return true;
//     return false;
// }

// void addToQ(queue <pair <int, int>>* q, int row, int col) {
//     if(row + 1 <= n + 1) {
//         if(arr[row + 1][col] == 0) q->push(make_pair(row + 1, col));
//     }
//     if(row - 1 >= 0) {
//         if(arr[row - 1][col] == 0) q->push(make_pair(row - 1, col));
//     }
//     if(col + 1 <= m + 1) {
//         if(arr[row][col + 1] == 0) q->push(make_pair(row, col + 1));
//     }
//     if(col - 1 >= 0) {
//         if(arr[row][col - 1] == 0) q->push(make_pair(row, col - 1));
//     }
// }

// void markingAir(int i, int j) {
//     queue <pair <int, int>> q;
//     q.push(make_pair(i, j));
//     while(!q.empty()) {
//         int row = q.front().first, col = q.front().second;
//         q.pop();
//         addToQ(&q, row, col);
//         arr[row][col] = -1;
//     }
// }

// void getHole() {
//     vector <vector <bool>> visit;
//     visit.resize(n + 2);
//     for(int i = 0; i <= n + 1; i++) visit[i].resize(m + 2);

//     for(int i = 0; i <= n + 1; i++) {
//         if((i == 0) || (i == n + 1)) {
//             for(int j = 0; j <= m + 1; j++) {
//                 markingAir(i, j);
//             }
//         } else {
//             markingAir(i, 0);
//             markingAir(i, m + 1);
//         }
//     }
// }

// void checkHole() {
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= m; j++) {
//             if(isMelt(i, j) && arr[i][j] == 0) {
//                 markingAir(i, j);
//             }
//         }
//     }
// }

// int main() {
//     cin >> n >> m;
//     arr.resize(n + 2); for(int i = 0; i <= n + 1; i++) arr[i].resize(m + 2);
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= m; j++) {
//             cin >> arr[i][j];
//             if(arr[i][j] == 1) cheese.push_back(make_pair(i, j));
//         }
//     }
//     getHole();

//     // for(auto i = cheese.begin(); i != cheese.end(); i++) {
//     //     cout << (*i).first << " ," << (*i).second << endl;
//     // }

//     while(cheese.size()) {
//         lastPiece = cheese.size();

//         auto it = cheese.begin();
//         vector <vector <int>> arrCpy;
//         copy(arr.begin(), arr.end(), back_inserter(arrCpy));
//         while (it != cheese.end()) {
//             int row = it->first, col = it->second;
//             if (isMelt(row, col)) {
//                 arrCpy[row][col] = -1;
//                 it = cheese.erase(it);
//             } else {
//                 ++it;
//             }
//         }
//         arr = arrCpy;

//         checkHole();

//         // cout << "******************************\n";
//         // for(int i = 0; i <= n + 1; i++) {
//         //     for(int j = 0; j <= m + 1; j++) {
//         //         if(arr[i][j] == 1) cout << arr[i][j] << " ";
//         //         else if(arr[i][j] == -1) cout << 2 << " ";
//         //     }
//         //     cout << endl;
//         // } cout << endl;

//         meltTime++;
//     }

//     cout << meltTime << endl << lastPiece;
// }