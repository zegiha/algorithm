#include <iostream>
#include <vector>

using namespace std;

int m, cmd, n;
long long ans_sum, ans_xor;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> m;
  while(m--) {
    cin >> cmd;
    if(cmd < 3) {
      cin >> n;
    }

    switch (cmd)
    {
    case 1:
      ans_sum += n;
      ans_xor ^= n;
      break;
    case 2:
      ans_sum -= n;
      ans_xor ^= n;
      break;
    case 3:
      cout << ans_sum << '\n';
      break;
    case 4:
      cout << ans_xor << '\n';
      break;
    }
  }
}