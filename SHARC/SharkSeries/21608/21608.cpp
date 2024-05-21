#include <iostream>
#include <vector>
using namespace std;

int n;
vector <vector <int>> arr, stu;
vector <pair <int, int>> cdn;

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

void first(int key) {
  for(int t = 0; t < stu[key].size(); t++) {
    if(arr[cdn[stu[key][t]].first][cdn[stu[key][t]].second] != 0) {
      
    }
  }
}

int main() {
  cin >> n;
  arr.resize(n + 2, vector <int> (n + 2, 0));
  stu.resize((n * n) + 2);
  cdn.resize((n * n) + 2, pair <int, int> (0, 0));
  for(int t = 0; t < n * n; t++) {
    int key; cin >> key;
    for(int i = 0; i < 4; i++) {
      int tmp; cin >> tmp;
      stu[key].push_back(tmp);
    }
    first(key);
  }
}