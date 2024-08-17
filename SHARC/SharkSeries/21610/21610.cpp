#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector <vector <int>> arr;

void cloudInit(vector <pair <int, int>>* cloud) {
  cloud->push_back({n-1, 0});
  cloud->push_back({n-1, 1});
  cloud->push_back({n-2, 0});
  cloud->push_back({n-2, 1});
}

int moveCoordinate(int s, int repeat, char op) {
  while(repeat--) {
    if(op == '+') s++;
    else s--;

    if(s == n) s = 0;
    else if(s == -1) s = n - 1;
  }

  return s;
}
pair <int, int> getMovedCoordinate(int r, int c, int d, int s) {
  switch (d)
  {
  case 1:
    return {r, moveCoordinate(c, s, '-')};
  case 2:
    return {moveCoordinate(r, s, '-'), moveCoordinate(c, s, '-')};
  case 3:
    return {moveCoordinate(r, s, '-'), c};
  case 4:
    return {moveCoordinate(r, s, '-'), moveCoordinate(c, s, '+')};
  case 5:
    return {r, moveCoordinate(c, s, '+')};
  case 6:
    return {moveCoordinate(r, s, '+'), moveCoordinate(c, s, '+')};
  case 7:
    return {moveCoordinate(r, s, '+'), c};
  case 8:
    return {moveCoordinate(r, s, '+'), moveCoordinate(c, s, '-')};
  }
}

vector <pair <int, int>> getNewCloud(vector <vector <bool>> prevCloud) {
  vector <pair <int, int>> newCloud;
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(arr[i][j] >= 2 && !prevCloud[i][j]) {
        newCloud.push_back({i, j});
        arr[i][j] -= 2;
      }
    }
  }

  return newCloud;
}

bool isOutOfBound_when_moveToDiagonal(int r, int c, int dHalf, int s) {
    int newR, newC;
    
    switch (dHalf)
    {
    case 1: // 좌상 (왼쪽 위)
        newR = r - s;
        newC = c - s;
        break;
    case 2: // 우상 (오른쪽 위)
        newR = r - s;
        newC = c + s;
        break;
    case 3: // 우하 (오른쪽 아래)
        newR = r + s;
        newC = c + s;
        break;
    case 4: // 좌하 (왼쪽 아래)
        newR = r + s;
        newC = c - s;
        break;
    }
    
    // 새로운 좌표가 범위를 벗어났는지 체크
    return newR < 0 || newR >= n || newC < 0 || newC >= n;
}


void printingArr() {
  cout << "--------------------------------------------------\n";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) cout << arr[i][j] << ' ';
    cout << '\n';
  }
  cout << "--------------------------------------------------\n";
}

int main() {
  cin >> n >> k;
  arr.resize(n, vector <int> (n, 0));
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> arr[i][j];

  vector <pair <int, int>> cloud;
  vector <vector <bool>> prevCloud (n, vector <bool> (n, false));
  cloudInit(&cloud);

  while(k--) {
    int d, s; cin >> d >> s;

    //비바라기 마법
    for(int i = 0; i < cloud.size(); i++) {
      // cout << cloud[i].first << ' ' << cloud[i].second << endl;
      cloud[i] = getMovedCoordinate(cloud[i].first, cloud[i].second, d, s);
      // cout << cloud[i].first << ' ' << cloud[i].second << endl << endl;
      arr[cloud[i].first][cloud[i].second]++;
    }

    // printingArr();

    //물 복사 버그 & prevCloud 설정
    for(int i = 0; i < cloud.size(); i++) {
      int cnt = 0;
      for(int dHalf = 1; dHalf <= 4; dHalf++) {
        if(isOutOfBound_when_moveToDiagonal(cloud[i].first, cloud[i].second, dHalf, 1)) continue;

        pair <int, int> coordinate = getMovedCoordinate(cloud[i].first, cloud[i].second, dHalf * 2, 1);
        if(arr[coordinate.first][coordinate.second] > 0) cnt++;
      }
      arr[cloud[i].first][cloud[i].second] += cnt;

      //prevCloud
      prevCloud[cloud[i].first][cloud[i].second] = true;
    }

    cloud = getNewCloud(prevCloud);
    fill(prevCloud.begin(), prevCloud.end(), vector<bool>(n, false));

    // printingArr();
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      ans += arr[i][j];
    }
  }

  cout << ans;
}
