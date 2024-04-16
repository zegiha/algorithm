#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int x, y, big;
    cin >> x >> y;
    queue <pair <int, int>> q;
    if(y > x) big = y;
    else big = x;
    vector <int> w(big + 2, 2100000000);
    
    w[x] = 0;
    q.push(make_pair(x - 1, 1));
    q.push(make_pair(x + 1, 1));
    q.push(make_pair(x * 2, 0));
    while(!q.empty()){
        int i = q.front().first, weight = q.front().second;
        q.pop();

        
        if(i <= big + 1 && i >= 0) {
            // cout << i << "  ||  i\n" << weight << "  ||  weight\n";
            if(weight < w[i]) {
                w[i] = weight;
                q.push(make_pair(i - 1, w[i] + 1));
                q.push(make_pair(i + 1, w[i] + 1));
                q.push(make_pair(i * 2, w[i]));
            }
        }
    }

    // for(int i = 0; i <= 100000; i++) {
    //     cout << w[i] << ' ';
    // }
    cout << w[y];
}

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int main() {
//     int x, y;
//     cin >> x >> y;
//     vector <int> w((y + 2) * 2, 2100000000);
//     queue <pair <int, int>> q;
//     q.push(make_pair(x, 0));

//     while(!q.empty()){
//         int index = q.front().first, weight = q.front().second;
//         q.pop();

        
//         if(index > -1 && index < y + 2){
//             if(w[index] > weight) {
//                 w[index] = weight;
//                 // cout << index << "  ||  index\n" << weight << "  ||  weight\n" << endl;
//                 if(!(index > y)) {
//                     q.push(make_pair(index - 1, w[index] + 1));
//                     q.push(make_pair(index + 1, w[index] + 1));
//                     q.push(make_pair(index * 2, w[index]));
//                 } else {
//                     q.push(make_pair(index - 1, w[index] + 1));
//                 }
//             }
//         }
//     }
//     // for(int i = 1; i <= y; i++) {
//     //     cout << w[i] << endl;
//     // }
//     cout << w[y];
// }

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