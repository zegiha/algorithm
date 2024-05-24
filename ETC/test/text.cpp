#include <iostream>
using namespace std;

int arr[10][10];

int main() {
    for(int i = 0; i <= 7; i++) {
        for(int j = 0; j <= 7; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= 7; i++) {
        for(int j = 1; j <= 7; j++) {
            if(arr[i][j] == arr[i][0] * 2) cout << "● ";
            else cout << "○ ";
        }
        cout << endl;
    }
}