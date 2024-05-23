#include <iostream>
#include <vector>
using namespace std;

int n, nn;
vector <vector <int>> stu, arr;

/*
1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.

1 작업
1. 좋아하는 학생이 자리에 앉았는가?
  예
  좋아하는 학생 주위 앉을 수 있는 칸을 저장, 이미 저장되어 있다면 횟수 + 1
  아니요 ( 없음 )
*/

void getSum(pair <int, int>* sum, int row, int col, int e) {
  if(row + 1 <= n) {
    if(arr[row + 1][col] == 0) sum->second++;
    else {
      for(int i = 0; i < 4; i++) {
        if(stu[e][i] == arr[row + 1][col]) sum->first++;
      }
    }
  }
  if(row - 1 > 0) {
    if(arr[row - 1][col] == 0) sum->second++;
    else {
      for(int i = 0; i < 4; i++) {
        if(stu[e][i] == arr[row - 1][col]) sum->first++;
      }
    }
  }
  if(col + 1 <= n) {
    if(arr[row][col + 1] == 0) sum->second++;
    else {
      for(int i = 0; i < 4; i++) {
        if(stu[e][i] == arr[row][col + 1]) sum->first++;
      }
    }
  }
  if(col - 1 > 0) {
    if(arr[row][col - 1] == 0) sum->second++;
    else {
      for(int i = 0; i < 4; i++) {
        if(stu[e][i] == arr[row][col - 1]) sum->first++;
      }
    }
  }
}

void solve(int e) {
  pair <pair <int, int>, pair <int, int>> loc = make_pair(make_pair(0, 0), make_pair(0, 0));
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(arr[i][j] = 0) {
        pair <int, int> sum = make_pair(0, 0);
        getSum(&sum, i, j, e);
        if(loc.first.first == i && loc.first.second == j) {
          
        }
      }
    }
  }
}

int main() {
  cin >> n; nn = n * n;
  arr.resize(n + 1, vector <int> (n + 1, 0));
  stu.resize(nn + 1);
  for(int t = 0; t < nn; t++) {
    int i, v; cin >> i;
    for(int t1 = 0; t1 < 4; t1++) {
      cin >> v;
      stu[i].push_back(v);
    }
    solve(i);
  }

}