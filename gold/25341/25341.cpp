#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct node {
    ll length;
    vector <ll> input_idx;
    vector <ll> weight;
    ll bias;
};


ll n, m, q, compressed_bias = 0;
node out;
vector <vector <ll>> input;
vector <node> hidden;
vector <ll> compressed_weight;

// void solve(int idx) {
//     ll ans = out.bias;
//     vector <ll> calc_hidden;
//     for(int i = 0; i < m; i++) {
//         ll sum = hidden[i].bias;
//         for(int j = 0; j < hidden[i].length; j++) {
//             sum += input[idx][hidden[i].input_idx[j]] * hidden[i].weight[j];
//         }
//         calc_hidden.push_back(sum);
//     }

//     for(int i = 0; i < m; i++) {
//         ans += calc_hidden[out.input_idx[i]] * out.weight[i];
//     }

//     cout << ans << '\n';
// }

int main() {
    cin >> n >> m >> q;
    // cout << "after initial value\n";
    for(int j = 0; j < m; j++) {
        node tmp;
        cin >> tmp.length;
        for(int i = 0; i < tmp.length; i++) {
            ll t; cin >> t;
            tmp.input_idx.push_back(t-1);
            // cout << "haha ";
        }
        for(int i = 0; i < tmp.length; i++) {
            ll t; cin >> t;
            tmp.weight.push_back(t);
            // cout << "jaja ";
        }
        cin >> tmp.bias;
        hidden.push_back(tmp);
        // cout << "getting hidden value\n";
    }

    // cout << "after hidden\n";

    out.length = m;
    out.input_idx = vector <ll> (m);
    out.weight = vector <ll> (m);
    for(ll i = 0; i < m; i++) {
        cin >> out.weight[i];
        out.input_idx[i] = i;
    }
    cin >> out.bias;

    // cout << "after out\n";

    compressed_bias = out.bias;
    compressed_weight.resize(n);
    for(int i = 0; i < m; i++) {
        compressed_bias += hidden[i].bias * out.weight[i];
        for(int j = 0; j < hidden[i].length; j++) {
            compressed_weight[hidden[i].input_idx[j]] += out.weight[i] * hidden[i].weight[j];
        }
    }

    for(int i = 0; i < q; i++) {
        ll ans = compressed_bias;
        for(int j = 0; j < n; j++) {
            int t; cin >> t;
            ans += compressed_weight[j] * t;
        }
        cout << ans << '\n';
    }

    // cout << "after input\n";
}