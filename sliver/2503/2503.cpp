#include <iostream>
#include <vector>

using namespace std;

int n, arr[101][3];
vector <int> ans;

bool isSatisfying(int newAns) {
  
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }

  for(int h = 1; h <= 9; h++) {
    for(int t = 1; t <= 9; t++) {
      for(int o = 1; o <= 9; o++) {
        int newAns = (h * 100) + (t * 10) + o;
        if(isSatisfying(newAns)) ans.push_back(newAns);
      }
    }
  }
}