#include <iostream>
#include <vector>

using namespace std;

int n, arr[100'001], ans = 2'100'000'000, total[4];
vector <vector <int>> PATTERN({
    {1, 2, 3},
    {1, 3, 2},
    {2, 1, 3},
    {2, 3, 1},
    {3, 1, 2},
    {3, 2, 1},
});

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        total[arr[i]]++;
    }

    for(auto pattern : PATTERN) {
        // cout << "----================ | pattern : ";
        // for(auto v : pattern) cout << v << " ";
        // cout << "| ================----\n";

        int unmatch[4][4] = {0, }, res = 0;
        for(int patternIdx = 0, i = 0; patternIdx < 3; patternIdx++) {
            for(int t = 0; t < total[pattern[patternIdx]]; t++) {
                if(arr[i] != pattern[patternIdx]) unmatch[pattern[patternIdx]][arr[i]]++;
                i++;
            }
        }

        // cout << "--================ | unmatch ";
        // cout << "| ================--\n";
        // for(int i = 1; i <= 3; i++) {
        //     cout << "================ | section " << i << " | ================\n";
        //     cout << i << " : ";
        //     for(int j = 1; j <= 3; j++) {
        //         cout << unmatch[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        res += min(unmatch[1][2], unmatch[2][1]);
        unmatch[1][2] -= min(unmatch[1][2], unmatch[2][1]);
        unmatch[2][1] -= min(unmatch[1][2], unmatch[2][1]);

        res += min(unmatch[1][3], unmatch[3][1]);
        unmatch[1][3] -= min(unmatch[1][3], unmatch[3][1]);

        res += min(unmatch[2][3], unmatch[3][2]);
        unmatch[2][3] -= min(unmatch[2][3], unmatch[3][2]);
        unmatch[3][2] -= min(unmatch[2][3], unmatch[3][2]);

        res += (unmatch[1][2] + unmatch[1][3]) * 2;

        // cout << "--================ | res : " << res << ' ';
        // cout << "| ================--\n";

        ans = min(ans, res);
    }

    cout << ans;
}
