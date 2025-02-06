#include <iostream>
#include <vector>

using namespace std;

int n;
vector <vector <bool>> ans;

void printing() {
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            if(ans[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}

void making(int size) {
    if(size == n) {
        return;
    }

    int width = ans[0].size();
    for(int i = 1; i < width; i++) {
        ans[1].push_back(false);
    }

    //1. 모든 배열의 앞과 뒤에 별을 각각 추가    
    for(int i = 0; i < ans.size(); i++) {
        ans[i].insert(ans[i].begin(), false);
        ans[i].insert(ans[i].begin(), true);
        if(i != 0) ans[i].push_back(false);
        else ans[i].push_back(true);
        ans[i].push_back(true);
    }

    // *, *  *모양 만들기
    vector <bool> line;
    width += 4;
    for(int i = 0; i < width; i++) {
        if(i == 0 || i == width - 1) {
            line.push_back(true);
        } else {
            line.push_back(false);
        }
    }

    //위에서 만든 모양 넣기
    ans.insert(ans.begin(), vector <bool> (1, true));
    ans.push_back(line);

    //**** 모양 만들기
    for(int i = 0; i < width; i++) {
        line[i] = true;
    }

    ans.insert(ans.begin(), line);
    ans.push_back(line);

    making(size + 1);
}

int main() {
    cin >> n;
    if(n == 1) {
        cout << "*";
        return 0;
    }

    // 2 초기화
    for(int i = 0; i < 7; i++) {
        ans.push_back(vector <bool> (0));
        if(i == 0 || i == 6) {
            for(int j = 0; j < 5; j++) {
                ans[i].push_back(true);
            }
        } else if(i == 1) {
            ans[i].push_back(true);
        } else if(i == 2) {
            for(int j = 0; j < 5; j++) {
                if(j != 1) ans[i].push_back(true);
                else ans[i].push_back(false);
            }
        } else if(i == 3 || i == 4) {
            for(int j = 0; j < 5; j++) {
                if(j % 2 == 0) ans[i].push_back(true);
                else ans[i].push_back(false);
            }
        } else {
            for(int j = 0; j < 5; j++) {
                if(j == 0 || j == 4) ans[i].push_back(true);
                else ans[i].push_back(false);
            }
        }
    }
    
    making(2);
    printing();
}