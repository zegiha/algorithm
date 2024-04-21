#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int width, height, ans;
vector <vector <int>> arr;

void getConnect(vector <pair <int, int>>* connected, int row, int col) {
    if(row % 2 == 0) {
        if(col - 1 >= 0) {
            if(row + 1 <= height + 1) connected->push_back(make_pair(row + 1, col - 1));
            if(row - 1 >= 0) connected->push_back(make_pair(row - 1, col - 1));
        }

    } else {
        if(col + 1 <= width + 1) {
            if(row + 1 <= height + 1) connected->push_back(make_pair(row + 1, col + 1));
            if(row - 1 >= 0) connected->push_back(make_pair(row - 1, col + 1));
        }
    }
    if(row + 1 <= height + 1) connected->push_back(make_pair(row + 1, col));
    if(row - 1 >= 0) connected->push_back(make_pair(row - 1, col));
    if(col + 1 <= width + 1) connected->push_back(make_pair(row, col + 1));
    if(col - 1 >= 0) connected->push_back(make_pair(row, col - 1));
}

int main() {
    cin >> width >> height;
    arr.resize(height + 3);
    for(int i = 0; i <= height + 1; i++) arr[i].resize(width + 3);
    for(int i = 1; i <= height; i++) {
        for(int j = 1; j <= width; j++) cin >> arr[i][j];
    }

    for(int i = 0; i <= height + 1; i++) {
        if((i == 0) || (i == (height + 1))) {
            for(int j = 0; j <= width + 1; j++) {
                arr[i][j] = -1;
            }
        } else {
            arr[i][0] = -1;
            arr[i][width + 1] = -1;
        }
    }

    vector <vector <int>> visit;
    visit.resize(height + 3);
    for(int i = 0; i <= height + 1; i++) visit[i].resize(width + 3);
    queue <pair <int, int>> q;
    q.push(make_pair(0, 0));
    while(!q.empty()) {
        int row = q.front().first, col = q.front().second, lastAns = ans;
        q.pop();
        vector <pair <int, int>> connect;
        getConnect(&connect, row, col);
        visit[0][0] = true;
        for(int i = 0; i < connect.size(); i++) {
            if(arr[connect[i].first][connect[i].second] == 1) ans++;
            if(arr[connect[i].first][connect[i].second] <= 0 && !visit[connect[i].first][connect[i].second]) {
                q.push(make_pair(connect[i].first, connect[i].second));
                visit[connect[i].first][connect[i].second] = true;
            }
            // cout << connect[i].second << ", " << connect[i].first << "  ||  connect(c, r)\n";
        }
        // cout << col << ", " << row << "  ||  col, row\n";
        // cout << ans - lastAns << "  ||  ans\n\n";
    }

    cout << ans;
    // cout << endl << endl << arr[0][9];
}

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int width, height, ans;
// vector <vector <int>> arr;

// void getConnect(vector <pair <int, int>>* connected, int row, int col) {
//     if(row % 2 == 0) {
//         if(col - 1 > 0) {
//             if(row + 1 <= height) connected->push_back(make_pair(row + 1, col - 1));
//             if(row - 1 > 0) connected->push_back(make_pair(row - 1, col - 1));
//         }

//     } else {
//         if(col + 1 <= width) {
//             if(row + 1 <= height) connected->push_back(make_pair(row + 1, col + 1));
//             if(row - 1 > 0) connected->push_back(make_pair(row - 1, col + 1));
//         }
//     }
//     if(row + 1 <= height) connected->push_back(make_pair(row + 1, col));
//     if(row - 1 > 0) connected->push_back(make_pair(row - 1, col));
//     if(col + 1 <= width) connected->push_back(make_pair(row, col + 1));
//     if(col - 1 > 0) connected->push_back(make_pair(row, col - 1));
// }

// void deletingIncubatedNode(int i, int j) {
//     queue <pair <int, int>> q;
//     q.push(make_pair(i, j));
//     while(!q.empty()) {
//         int row = q.front().first, col = q.front().second;
//         q.pop();
//         vector <pair <int, int>> connect;
//         getConnect(&connect, row, col);
//         for(int k = 0; k < connect.size(); k++) if(arr[connect[k].first][connect[k].second] == 0) q.push(connect[k]);
//         arr[row][col] = 2;
//     }
// }

// void delIncubatedNode() {
//     for(int i = 1; i <= height; i++) {
//         if(i == 1 || i == height) {
//             for(int j = 1; j <= width; j++) {
//                 if(arr[i][j] == 0) {
//                     deletingIncubatedNode(i, j);
//                 }
//             }
//         } else {
//             if(arr[i][1] == 0) deletingIncubatedNode(i, 1);
//             if(arr[i][width] == 0) deletingIncubatedNode(i, width);
//         }
//     }
// }

// void getWallNode() {
//     for(int i = 1; i <= height; i++) {
//         for(int j = 1; j <= width; j++) {
//             if(arr[i][j] == 1) {
//                 queue <pair <int, int>> q;
//                 q.push(make_pair(i, j));
//                 while(!q.empty()) {
//                     int row = q.front().first, col = q.front().second, cnt = 0;
//                     q.pop();
//                     arr[row][col] = 3;
//                     vector <pair <int, int>> connect;
//                     getConnect(&connect, row, col);
//                     for(int k = 0; k < connect.size(); k++) {
//                         if(arr[connect[k].first][connect[k].second] == 1) {
//                             arr[connect[k].first][connect[k].second] = 3;
//                             q.push(make_pair(connect[k].first, connect[k].second));
//                         }
//                         if(arr[connect[k].first][connect[k].second] != 2) cnt ++;
//                     }
//                     ans += 6 - cnt;
//                     // cout << col << ", " << row << "  ||  col, row\n";
//                     // cout << ans << "  ||  ans\n\n";
//                 }
//             }
//         }
//     }
// }

// int main() {
//     cin >> width >> height;
//     arr.resize(height + 2);
//     for(int i = 1; i <= height; i++) {
//         arr[i].resize(width + 2);
//         for(int j = 1; j <= width; j++) cin >> arr[i][j];
//     }
    
//     delIncubatedNode();
//     getWallNode();

//     cout << ans;
// }

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int w, h, ans;
// vector <vector <int>> arr;

// void addToQ(queue <pair <int, int>>* q, vector <vector <bool>>* check) {
//     int r = q->front().first, c = q->front().second, lastAns = ans;
//     q->pop();
//     cout << c + 1 << ", " << r + 1 << "  ||  c, r\n" << ans << "  ||  ans\n\n";
//     if(r + 1 < h) {
//         if((r + 1) % 2 == 0) {
//             if(c - 1 > -1){
//                 if(arr[r + 1][c - 1] == 0) ans++;
//                 else if(!(*check)[r + 1][c - 1]) {
//                     q->push(make_pair(r + 1, c - 1));
//                     (*check)[r + 1][c - 1] = true;
//                 }
//             }
//         } else {
//             if(c + 1 < w){
//                 if(arr[r + 1][c + 1] == 0) ans++;
//                 else if(!(*check)[r + 1][c + 1]) {
//                     q->push(make_pair(r + 1, c + 1));
//                     (*check)[r + 1][c + 1] = true;
//                 }
//             }
//         }

//         if(arr[r + 1][c] == 0) ans++;
//         else if(!(*check)[r + 1][c]) {
//             q->push(make_pair(r + 1, c));
//             (*check)[r + 1][c] = true;
//         }
//     } else ans += 2;
//     if(r - 1 > -1) {
//         if((r + 1) % 2 == 0) {
//             if(c - 1 > -1){
//                 if(arr[r - 1][c - 1] == 0) ans++;
//                 else if(!(*check)[r - 1][c - 1]) {
//                     q->push(make_pair(r - 1, c - 1));
//                     (*check)[r - 1][c - 1] = true;
//                 }
//             }
//         } else {
//             if(c + 1 < w){
//                 if(arr[r - 1][c + 1] == 0) ans++;
//                 else if(!(*check)[r - 1][c + 1]) {
//                     q->push(make_pair(r - 1, c + 1));
//                     (*check)[r - 1][c + 1] = true;
//                 }
//             }
//         }

//         if(arr[r - 1][c] == 0) ans++;
//         else if(!(*check)[r - 1][c]) {
//             q->push(make_pair(r - 1, c));
//             (*check)[r - 1][c] = true;
//         }
//     } else ans += 2;
//     if(c + 1 < w) {
//         if(arr[r][c + 1] == 0) ans++;
//         else if(!(*check)[r][c + 1]) {
//             q->push(make_pair(r, c + 1));
//             (*check)[r][c + 1] = true;
//         }
//     } else {
//         if((r + 1) % 2 == 0) ans += 2;
//         else ans++;
//     }
//     if(c - 1 > -1) {
//         if(arr[r][c - 1] == 0) ans++;
//         else if(!(*check)[r][c - 1]) {
//             q->push(make_pair(r, c - 1));
//             (*check)[r][c - 1] = true;
//         }
//     } else ans++;

//     for(int i = 0; i < h; i++) {
//         for(int j = 0; j < w; j++) {
//             cout << (*check)[i][j] << ' ';
//         }
//         cout << endl;
//     }
//     cout << ans - lastAns << endl << endl;
// }

// void getAnsWithoutIncubate(){
//     vector <vector <bool>> check;
//     check.resize(h + 1); for(int i = 0; i < h; i++) check[i].resize(w + 1);

//     for(int i = 0; i < h; i++) {
//         for(int j = 0; j < w; j++) {
//             if(arr[i][j] && !check[i][j]) {
//                 queue <pair <int, int>> q;
//                 q.push(make_pair(i, j));
//                 check[i][j] = true;

//                 while(!q.empty()) {
//                     addToQ(&q, &check);
//                 }
//                 cout << "***********************************************\n\n";
//             }
//         }
//     }
// }

// int main() {
//     cin >> w >> h;
//     arr.resize(h + 1);
//     for(int i = 0; i < h; i++) {
//         arr[i].resize(w + 1);
//         for(int j = 0; j < w; j++) cin >> arr[i][j];
//     }

//     getAnsWithoutIncubate();
//     cout << ans;
// }