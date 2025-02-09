#include <iostream>

using namespace std;

int dir[6], dis[6], proportion, big_w, big_l;
const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

int main() {
    cin >> proportion;
    for(int i = 0; i < 6; i++) {
        cin >> dir[i] >> dis[i];
        dir[i]--;
        if(dir[i] < 2) {
            if(big_w < dis[i]) big_w = dis[i];
        } else {
            if(big_l < dis[i]) big_l = dis[i];
        }
    }

    int big = big_w * big_l, small;

    for(int i = 0; i < 6; i++) {
        bool is_end = true;
        // cout << i << ' ' << dir[i] << ' ';
        switch(dir[i]) {
            case 3:
                // cout << 1 << '\n';
                for(int j = 0; j < 4; j++) {
                    if(j % 2 == 0) {
                        if(dir[(i + j) % 6] != 3) is_end = false;
                    } else {
                        if(dir[(i + j) % 6] != 1) is_end = false;
                    }
                }
                break;
            case 1:
                // cout << 2 << '\n';
                for(int j = 0; j < 4; j++) {
                    if(j % 2 == 0) {
                        if(dir[(i + j) % 6] != 1) is_end = false;
                    } else {
                        if(dir[(i + j) % 6] != 2) is_end = false;
                    }
                }
                break;
            case 2:
                // cout << 3 << '\n';
                for(int j = 0; j < 4; j++) {
                    if(j % 2 == 0) {
                        if(dir[(i + j) % 6] != 2) is_end = false;
                    } else {
                        if(dir[(i + j) % 6] != 0) is_end = false;
                    }
                }
                break;
            case 0:
                // cout << 4 << '\n';
                for(int j = 0; j < 4; j++) {
                    if(j % 2 == 0) {
                        if(dir[(i + j) % 6] != 0) is_end = false;
                    } else {
                        if(dir[(i + j) % 6] != 3) is_end = false;
                    }
                }
                break;
        }
        if(is_end) {
            // cout << i << "tlqkf\n";
            small = dis[(i + 1) % 6] * dis[(i + 2) % 6];
        }
    }

    cout << (big - small) * proportion;
}