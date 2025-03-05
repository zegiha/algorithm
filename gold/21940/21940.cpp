#include <iostream>
#include <vector>

#define INF 1'000'000'000

using namespace std;

int n, m, k;
vector <vector <int>> arr;
vector <int> member;
pair <int, vector <int>> ans = {INF, vector <int> (0)};

int main() {
    cin >> n >> m;
    arr.resize(n + 1, vector <int> (n + 1, INF));
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[a-1][b-1] = c;
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        int t; cin >> t;
        member.push_back(t-1);
    }
    for(int i = 0; i < n; i++) arr[i][i] = 0;

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j == k) continue;
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) cout << arr[i][j] << ' ';
    //     cout << '\n';
    // }

    for(int i = 0; i < n; i++) {
        int new_ans = 0;
        for(int j = 0; j < member.size(); j++) {
            int sum = arr[member[j]][i] + arr[i][member[j]];
            if(sum > new_ans) new_ans = sum;
        }

        if(new_ans < ans.first) {
            ans = {new_ans, vector <int> (1, i)};
        } else if(new_ans == ans.first) {
            ans.second.push_back(i);
        }
    }

    for(int i = 0; i < ans.second.size(); i++) cout << ans.second[i] + 1 << ' ';
}