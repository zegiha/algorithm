#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, m;
vector <vector <int>> arr;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        if(t == -1) t = 0;
        arr[t].push_back(i+1);
    }
}