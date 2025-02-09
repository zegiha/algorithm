#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector <string> restore;
vector <vector <string>> raw;

vector <string> get_split_string(string str) {
    vector <string> res;
    string temp = "";
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == ' ') {
            res.push_back(temp);
            temp = "";
        } else {
            temp += str[i];
        }
    }
    if(temp != "") res.push_back(temp);
    return res;
}

bool ans = false;
vector <int> visit;
void solve(int depth) {
    if(depth >= restore.size()) {
        bool sw = true;
        for(int i = 0; i < n; i++) {
            if(visit[i] != raw[i].size()) {
                sw = false;
                break;
            }
        }
        if(sw) ans = true;
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(visit[i] < raw[i].size() && raw[i][visit[i]] == restore[depth]) {
            // cout << i << ' ' << depth << " check\n";
            visit[i]++;
            solve(depth + 1);
            visit[i]--;
        }
    }
}

int main() {
    cin >> n; cin.ignore();
    raw.resize(n);
    visit.resize(n);
    string str;
    for(int i = 0; i < n; i++) {
        getline(cin, str, '\n');
        raw[i] = get_split_string(str);
    }
    getline(cin, str, '\n');
    restore = get_split_string(str);

    // for(int i = 0; i < n; i++) {
    //     cout << raw[i].size() << endl;
    // }

    // for(int k = 0; k < restore.size(); k++) {
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < raw[i].size(); j++) {
    //             cout << restore[k] << " == " << raw[i][j];
    //             if(raw[i][j] == restore[k]) {
    //                 cout << "true\n";
    //             } else {
    //                 cout << "false\n";
    //             }
    //         }
    //     }
    // }

    solve(0);
    if(ans) {
        cout << "Possible";
    } else {
        cout << "Impossible";
    }
}