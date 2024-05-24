// č	c=
// ć	c-
// dž	dz=
// đ	d-
// lj	lj
// nj	nj
// š	s=
// ž	z=

#include <iostream>
using namespace std;

string arr;

int main() {
  int ans = 0;
  cin >> arr;
  for(int i = 0; i < arr.size(); i++) {
    int j = i;
    if(i + 1 < arr.size()) {
      if(arr[i] == 'd' && arr[i + 1] == 'z' && (i + 2 < arr.size() && arr[i + 2] == '=')) i += 2;
      else if(arr[i] == 'l' && arr[i + 1] == 'j') i += 1;
      else if(arr[i] == 'n' && arr[i + 1] == 'j') i += 1;
      else if(arr[i + 1] == '=' || arr[i + 1] == '-') i += 1;
    }
    ans++;
    // cout << i << endl;
    // for(; j <= i; j++) cout << arr[j] << ' ';
    // cout << endl;
  }
  cout << ans;
}