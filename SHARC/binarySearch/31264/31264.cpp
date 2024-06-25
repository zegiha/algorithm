#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long targetN, shootingChance, goal;
vector<long long> target;

long long mostBig(long long e) {
    long long left = 0, right = targetN - 1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (target[mid] > e) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (right < 0) return 0;
    return target[right];
}

bool isAchieveGoal(long long e) {
    long long sum = 0;
    for (long long t = 0; t < shootingChance; t++) {
        sum += mostBig(e + sum);
        if (sum >= goal) return true;
    }
    return sum >= goal;
}

int main() {
    cin >> targetN >> shootingChance >> goal;
    target.resize(targetN);
    for (long long i = 0; i < targetN; i++) cin >> target[i];
    sort(target.begin(), target.end());

    long long left = 1, right = 100000, ans = right;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (isAchieveGoal(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
