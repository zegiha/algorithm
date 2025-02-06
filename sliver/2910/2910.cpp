#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int n, c;
map <int, pair <int, int>> m;

bool cmp(const pair <int, pair <int, int>>& a, const pair <int, pair <int, int>>& b) {
    if(a.second.first == b.second.first) {
        return a.second.second < b.second.second;
    }
    return a.second.first > b.second.first;
}

int main() {
    cin >> n >> c;

    int a, b; 
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(m.find(a) != m.end()) {
            m[a].first++;
        } else {
            m.insert({a, {1, i}});
        }
    }
    
    vector <pair <int, pair <int, int>>> tmp (m.begin(), m.end());

    sort(tmp.begin(), tmp.end(), cmp);

    for(int i = 0; i < tmp.size(); i++) {
        for(int j = 0; j < tmp[i].second.first; j++) {
            cout << tmp[i].first << ' ';
        }
    }
}