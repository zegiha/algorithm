#include <iostream>

using namespace std;

int h, w, x, y, a[301][301], b[602][602];

int main() {
    cin >> h >> w >> x >> y;
    for(int i = 0; i < h + x; i++) {
        for(int j = 0; j < w + y; j++) {
            cin >> b[i][j];
        }
    }
    
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < w; j++) {
            a[i][j] = b[i][j];
        }
    }
    for(int i = x; i < h; i++) {
        for(int j = 0; j < y; j++) {
            a[i][j] = b[i][j];
        }
    }

    for(int i = x; i < h; i++) {
        for(int j = y; j < w; j++) {
            a[i][j] = b[i][j] - a[i - x][j - y];
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}