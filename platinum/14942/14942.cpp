#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

ll n, power[100'002], level[100'002];
pii table[100'002][18];
vector <vector <pii>> m;

void initTable() {
  ll size, l = 1;
  queue <ll> q;
  vector <bool> v(n + 2, false);

  q.push(1);
  v[1] = true;
  level[1] = l;

  while(!q.empty()) {
    size = q.size();
    l++;

    while(size--) {
      ll node = q.front();
      q.pop();

      for(int i = 0; i < m[node].size(); i++) {
        ll newNode = m[node][i].second, cost = m[node][i].first;
        if(!v[newNode]) {
          v[newNode] = true;
          q.push(newNode);

          table[newNode][0] = {cost, node};
          level[newNode] = l;
        }
      }
    }
  }

  for(int j = 1; j < 18; j++) {
    for(int i = 2; i <= n; i++) {
      pii prev = table[i][j-1];
      table[i][j] = {
        table[prev.second][j-1].first + prev.first,
        table[prev.second][j-1].second
      };
    }
  }
}

ll getAns(ll target, ll remainPower) {
  if(target == 1 || target == 0) return 1;

  ll l = 0, r = 17, m;

  int saveLevel = level[target];
  for(int i = 17; i >= 0; i--) {
    if(level[i] < saveLevel && table[target][i].first <= remainPower) {
      l = i;
      saveLevel = level[i];
    }
  }

  // while(l <= r) {
  //   m = (l + r) / 2;
  //   if(table[target][m].first <= remainPower) {
  //     l = m + 1;
  //   } else {
  //     r = m - 1;
  //   }
  // }
  // if(l-1 > 0) l--;
  // else l = 0;

  // cout << "newTarget, newReaminPower : " << table[target][l].second << ", " << remainPower - table[target][l].first << '\n';
  // cout << "target, remainPower, l : " << target << ", " << remainPower << ", " << l << "\n\n";
  if(remainPower < table[target][l].first)
    return target;
  else
    return getAns(table[target][l].second, remainPower - table[target][l].first);
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> power[i];
  m.resize(n + 1);
  for(int i = 0; i < n-1; i++) {
    ll a, b, c; cin >> a >> b >> c;
    m[a].push_back({c, b});
    m[b].push_back({c, a});
  }

  initTable();
  // cout << "=========== " << "table" << " ===========\n";
  // for(int i = 1; i <= n; i++) {
  //   for(int j = 0; j <= 18; j++) {
  //     cout << table[i][j].first << ", " << table[i][j].second << "  ||  ";
  //   }
  //   cout << '\n';
  // }
  // cout << "\n\n";

  for(int i = 1; i <= n; i++) {
    // cout << "=========== " << i << " ===========\n";
    cout << getAns(i, power[i]) << '\n';
    // cout << '\n';
  }
}