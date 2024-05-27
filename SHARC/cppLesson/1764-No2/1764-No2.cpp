#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool isSame(string a, string b) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    vector <string> see, speak, ans;
    int n, m, cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        see.push_back(tmp);
    }
    for(int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        speak.push_back(tmp);
    }
    sort(see.begin(), see.end());
    sort(speak.begin(), speak.end());
    int j = 0;
    for(int i = 0; i < n; i++) {
      for(; j < m; j++) {
        if(see[i] == speak[j]) ans.push_back(see[i]);
        else if(see[i] < speak[j]) break;
      }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
      cout << ans[i] << endl;
    }
    // cout << endl;
    // for(int i = 0; i < see.size(); i++) {
    //   cout << see[i] << endl;
    // }
}