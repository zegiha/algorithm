#include <iostream>
using namespace std;

int arr[11][11][2], n;
long long ans[11];
bool check[11];

void getAns(int primaryIndex, int index) {
    for(int i = 0; i < arr[index][10][0]; i++) {
        if(!check[arr[index][i][0]]) {
            check[arr[index][i][0]] = true;
            ans[primaryIndex] *= arr[index][i][1];
            getAns(primaryIndex, arr[index][i][0]);
        }
    }
}

void deletingGCD(int* x, int* y) {
    int a = *x, b = *y;
    while(b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    if(a != 1) {
        *x /= a;
        *y /= a;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        deletingGCD(&y1, &y2);

        arr[x1][arr[x1][10][0]][0] = x2;
        arr[x1][arr[x1][10][0]++][1] = y1;

        arr[x2][arr[x2][10][0]][0] = x1;
        arr[x2][arr[x2][10][0]++][1] = y2; 
    }
    for(int i = 0; i < n; i++) ans[i] = 1;

    cout << '{' << endl;
    for(int i = 0; i < n; i++) {
        cout << '\t' << '{' << endl;
        for(int j = 0; j < arr[i][10][0]; j++) {
            cout << '\t' << '\t' << "{  " << arr[i][j][0] << ", " << arr[i][j][1] << "  }" << endl;
        }
        cout << '\t' << '}' << endl;
    }
    cout << '}' << endl;
    
    for(int i = 0; i < n; i++) {
        check[i] = true;
        getAns(i, i);
        for(int i = 0; i < n; i++) check[i] = false;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}