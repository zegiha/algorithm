#include <iostream>
#include <vector>

#define TMAX 101
#define MOD 1000000007

using namespace std;
using ll = long long;

int t, n, d;

class Matrix {
  public:
    vector <vector <ll>> v;

    Matrix() {
      v = vector <vector <ll>> (n, vector <ll> (n, 0));
    }

    Matrix operator * (const Matrix t) const {
      Matrix ans;

      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          for(int k = 0; k < n; k++) {
            ans.v[i][j] += v[i][k] * t.v[k][j];
            ans.v[i][j] %= MOD;
          }
        }
      }

      return ans;
    }
};

Matrix power(Matrix a, int p) {
  Matrix b;
  if(p == 0) {
    for(int i = 0; i < n; i++) b.v[i][i] = 1;
    return b;
  }

  if(p == 1) return a;

  b = power(a, p / 2);
  b = b * b;

  if(p % 2 == 0) b = b * a;

  return b;
}

int main() {
  cin >> t >> n >> d;

  Matrix arr[TMAX];

  for(int i = 1; i <= t; i++) {
    int size, start, end, cnt;
    cin >> size;
    while(size--) {
      cin >> start >> end >> cnt;
      start--; end--;
      arr[i].v[start][end] = cnt;
    }
  }
  // Matrix tmp;
  // for(int i = 0; i < n; i++) tmp.v[i][i] = 1;

  // tmp = tmp * arr[1];
  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n; j++) cout << tmp.v[i][j] << ' ';
  //   cout << '\n';
  // }


  for(int i = 0; i < n; i++) arr[0].v[i][i] = 1;
  

  for(int i = 1; i < t; i++) {
    arr[0] = arr[0] * arr[i];
  }

  arr[0] = power(arr[0], d / t);
  for(int i = 1; i <= d % t; i++) {
    arr[0] = arr[0] * arr[i];
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << arr[0].v[i][j] << ' ';
    }
    cout << '\n';
  }
}