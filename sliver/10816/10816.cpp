#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<int> cards(N);
    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
    }
    
    cin >> M;
    vector<int> queries(M);
    for (int i = 0; i < M; ++i) {
        cin >> queries[i];
    }
    
    sort(cards.begin(), cards.end());
    
    for (int i = 0; i < M; ++i) {
        auto lower = lower_bound(cards.begin(), cards.end(), queries[i]);
        auto upper = upper_bound(cards.begin(), cards.end(), queries[i]);
        cout << upper - lower << " ";
    }
    
    return 0;
}