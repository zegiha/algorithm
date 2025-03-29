#include <iostream>
#include <vector>

using namespace std;

struct coordinate {
  int x; int y;
};


using pcc = pair <coordinate, coordinate>;

int n, max_group_size = 0, group_cnt = 0, parent[3000];
pcc arr[3000];

int ccw(coordinate p1, coordinate p2, coordinate p3) {
  int res = (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x-p1.x);

  if(res > 0) return 1;
  else if(res < 0) return -1;
  else return 0;
}

bool isSamePosition(coordinate p1, coordinate p2, coordinate p3, coordinate p4) {
  int
  l1 = ccw(p1, p2, p3) * ccw(p1, p2, p4),
  l2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

  if(l1 == 0 && l2 == 0) {
    if(p1.x == p3.x) {
      if(p1.y > p2.y) swap(p1, p2);
      if(p3.y > p4.y) swap(p3, p4);
      
      return p3.y <= p2.y && p1.y <= p4.y;
    } else {
      if(p1.x > p2.x) swap(p1, p2);
      if(p3.x > p4.x) swap(p3, p4);


      return p3.x <= p2.x && p1.x <= p4.x;
    }
  }

  return l1 <= 0 && l2 <= 0;
}

int Find(int t) {
  if(parent[t] < 0) return t;
  return parent[t] = Find(parent[t]);
}

void Union(int a, int b) {
  int root_a = Find(a), root_b = Find(b);

  if(root_a != root_b) {
    parent[root_a] += parent[root_b];
    parent[root_b] = root_a;
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first.x >> arr[i].first.y >> arr[i].second.x >> arr[i].second.y;
    parent[i] = -1;
  }
  for(int i = 0; i < n-1; i++) {
    for(int j = i+1; j < n; j++) {
      if(isSamePosition(arr[i].first, arr[i].second, arr[j].first, arr[j].second)) {
        Union(i, j);
      }
    }
  }
  
  for(int i = 0; i < n; i++) {
    // cout << parent[i] << ' ';
    if(parent[i] < 0) {
      int t = parent[i] * -1;
      if(t > max_group_size) {
        max_group_size = t;
      }
      group_cnt++;
    }
  }

  // cout << '\n';

  cout << group_cnt << '\n' << max_group_size;
}