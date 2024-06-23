#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int targetN, shootingChance, goal, ans = 1;
vector <int> target;

int mostBig(int e) {
  int left = 0, right = targetN - 1;
  int big = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (target[mid] > e) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  
  if(right < 0) return 0;
  return target[right];
}

bool isAchiveGoal(int e) {
  for(int t = 0; t < shootingChance; t++) {
    // cout << mostBig(e) << '\n';
    e += mostBig(e);
  }
  
  if(e - ans >= goal) return true;
  else return false;
}

int main() {
  cin >> targetN >> shootingChance >> goal;
  target.resize(targetN);
  for(int i = 0; i < targetN; i++) cin >> target[i];
  sort(target.begin(), target.end());

  while(true) {
    if(isAchiveGoal(ans)){
      cout << ans;
      return 0;
    }
    ans++;
  }
}