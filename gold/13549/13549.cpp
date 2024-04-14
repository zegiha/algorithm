#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    
}

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int x, y;
// pair <int, int> tmp;

// bool addToQ(int v, int w, queue <pair <int, int>>* q) {
//     tmp.first = v - 1;
//     tmp.second = w + 1;
//     if(tmp.first == y) {
//         cout << tmp.second;
//         return true;
//     } else{
//         q->push(tmp);
//     }
    
//     tmp.first = v + 1;
//     tmp.second = w + 1;
//     if(tmp.first == y) {
//         cout << tmp.second;
//         return true;
//     } else{
//         q->push(tmp);
//     }
    
//     tmp.first = v * 2;
//     tmp.second = w;
//     if(tmp.first == y) {
//         cout << tmp.second;
//         return true;
//     } else{
//         q->push(tmp);
//     }

//     q->pop();
//     return false;
// }

// int main() {
//     cin >> x >> y;
//     queue <pair <int, int>> q;
    
//     if(!addToQ(x, 0, &q)) {
//         while(true) if(addToQ(q.front().first, q.front().second, &q)) break;
//     } 

// }