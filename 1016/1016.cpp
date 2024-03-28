#include <iostream>
#include <cmath>
using namespace std;

long long mn, mx, primeL = -1;
bool check[1000001] = {false, };

int main() {
    cin >> mn >> mx;
    
    long long ans = mx - mn + 1, i = 2;

    while(i * i <= mx) {
        long long square = i * i;
        long long n = mn / square;
        if(mn % square != 0) n++;

        while(n * square <= mx) {
            if(!check[n * square - mn]) {
                check[n * square - mn] = true;
                ans--;
            }
            n++;
        }
        i++;
    }

    cout << ans;
}

// #include <iostream>
// #include <cmath>
// using namespace std;

// long long mn, mx, primeL = 1;
// bool prime[1000002] = {0, };

// void getNewPrime(long long peek) {
//     bool sw = true;

//     for(int i = 0; i <= primeL; i++) {
//         if(peek % prime[i] == 0) {
//             sw = false;
//             prime;
//             break;
//         }
//     }
//     if(sw) {
//         for(int i = prime[primeL] + 1; i < peek; i++) {
//             if(peek % i == 0) {
//                 sw = false;
//                 break;
//             }
//         }
//         if(sw) {
//             prime[++primeL] = peek;
//             return;
//         } else getNewPrime(peek + 1);
//     } else getNewPrime(peek + 1);
// }

// int main() {
//     cin >> mn >> mx;
    
//     long long ans = mx - mn + 1;
//     prime[primeL++] = false;
//     prime[primeL++] = true; 

//     while(prime[primeL] * prime[primeL] <= mx) {
//         long long square = prime[primeL] * prime[primeL];
//         long long n = mn / square;
//         if(mn % square != 0) n++;

//         while(n * square <= mx) {
//             ans--;
//             n++;
//         }

//         getNewPrime(prime[primeL] + 1);
//     }

//     cout << ans;
// }

// #include <iostream>
// #include <cmath>
// using namespace std;

// long long m, M, prime[10000001] = {0, }, primeL = 0;

// void getPrime(int p, int end) {
//     if(p > end) {
//         for(int i = 0; i < primeL; i++) prime[i] *= prime[i];
//         return;
//     }

//     int sw = 1;
//     for(int i = 0; i < primeL; i++) {
//         if(p % prime[i] == 0) {
//             sw = 0;
//             break;
//         }
//     }
    
//     if(sw) {
//         for(int i = (int)prime[primeL - 1] + 1; i < p; i++) {
//             if(p % i == 0) {
//                 sw = 0;
//                 break;
//             }
//         }
//         if(sw) {
//             prime[primeL++] = p;
//         }
//     }

//     getPrime(p + 1, end);
// }

// int main() {
//     cin >> m >> M;

//     prime[primeL++] = 2;
//     getPrime(3, (int)(sqrt(M)));

//     int ans = 0;
//     for(long long i = m; i <= M; i++) {
//         int sw = 1;
//         for(int j = 0; j < primeL; j++) {
//             if(i % prime[j] == 0) {
//                 sw = 0;
//                 // cout << i << "  ||  " << ((long long)(sqrt(prime[j]))) << endl;
//                 break;
//             }
//         }

//         if(sw) ans++;
//     }

//     cout << ans;
// }