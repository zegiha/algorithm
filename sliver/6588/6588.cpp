#include <iostream>

using namespace std;

int n;
bool prime[1000002];

void setPrime() {
  for(int i = 2; i <= 1000000; i++) {
    prime[i] = true;
  }

  for(int i = 2; i * i <= 1000000; i++) {
    if(prime[i]) {
      for(int j = i * i; j <= 1000000; j += i) {
        prime[j] = false;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  setPrime();

  while(true) {
    cin >> n;
    if(n == 0) return 0;

    bool found = false;

    for(int i = 3; i <= n / 2; i += 2) {
      if(prime[i] && prime[n - i]) {
        cout << n << " = " << i << " + " << n - i << '\n';
        found = true;
        break;
      }
    }

    if(!found) {
      cout << "Goldbach's conjecture is wrong.\n";
    }
  }
}
// #include <iostream>

// using namespace std;

// int n;
// bool nPrime[1000001];

// void getPrime() {
//   for(int p = 2; p <= 1000000; p++) {
//     if(!nPrime[p]) {
//       int i = 2;
//       while(p * i <= 1000000) {
//         nPrime[p * i] = true;
//         i++;
//       }
//     }
//   }
// }

// int main() {
//   getPrime();
//   nPrime[1] = true;
//   nPrime[0] = true;
//   while(true) {
//     cin >> n; if(!n) return 0;
//     bool sw = true;
//     for(int i = n; i >= 2; i--) {
//       if(!nPrime[i] && !nPrime[n - i]) {
//         sw = false;
//         cout << n << " = " << n - i << " + " << i << '\n';
//         break;
//       }
//     }
//     if(sw) cout << "Goldbach's conjecture is wrong.\n";
//   }
// }