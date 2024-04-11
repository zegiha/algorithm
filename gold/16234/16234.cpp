#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, l, r, ans;
vector <vector <int>> arr;
bool sw = false;

void add(int row, int col, int*avg, queue <pair <int, int>>* q){
    pair <int, int> tmp; tmp.first = row; tmp.second = col;
    *avg += arr[row][col];
    q->push(tmp);
    sw = true;
}

void addToQ(int row, int col, int* avg, queue <pair <int, int>>* q, vector <vector <bool>>* check) {
    pair <int, int> tmp;
    if(row + 1 < n) {
        int gap = arr[row][col] - arr[row + 1][col];
        gap = gap > 0 ? gap : gap * -1;
        if(!(*check)[row + 1][col] && ((r >= gap) && (gap >= l))){
            (*check)[row + 1][col] = true;
            add(row + 1, col, avg, q);
        }
    }
    if(row - 1 >= 0) {
        int gap = arr[row][col] - arr[row - 1][col];
        gap = gap > 0 ? gap : gap * -1;
        if(!(*check)[row - 1][col] && ((r >= gap) && (gap >= l))){
            (*check)[row - 1][col] = true;
            add(row - 1, col, avg, q);
        }
    }
    if(col + 1 < n) {
        int gap = arr[row][col] - arr[row][col + 1];
        gap = gap > 0 ? gap : gap * -1;
        if(!(*check)[row][col + 1] && ((r >= gap) && (gap >= l))){
            (*check)[row][col + 1] = true;
            add(row, col + 1, avg, q);
        }
    }
    if(col - 1 >= 0) {
        int gap = arr[row][col] - arr[row][col - 1];
        gap = gap > 0 ? gap : gap * -1;
        if(!(*check)[row][col - 1] && ((r >= gap) && (gap >= l))){
            (*check)[row][col - 1] = true;
            add(row, col - 1, avg, q);
        }
    }
}

void bfs(int row, int col, int avg, vector <vector <bool>>* check) {
    queue <pair <int, int>> q;
    pair <int, int> tmp;
    vector <pair<int, int>> save;
    
    tmp.first = row;
    tmp.second = col;
    q.push(tmp);
    
    while(!q.empty()) {
        row = q.front().first;
        col = q.front().second;
        save.push_back(q.front());
        q.pop();

        addToQ(row, col, &avg, &q, check);
    }
    for(int i = 0; i < save.size(); i++) {
        arr[save[i].first][save[i].second] = avg / save.size();
    }
}

int main() {
    cin >> n >> l >> r;
    arr.resize(n + 1);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n + 1);
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    while(true) {
        vector <vector <bool>> check;
        check.resize(n + 1); for(int i = 0; i < n; i++) check[i].resize(n + 1);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!check[i][j]) {
                    check[i][j] = true;
                    bfs(i, j, arr[i][j], &check);
                }
            }
        }
        if(!sw) break;
        else ans++;
        sw = false;
    }

    cout << ans;
}