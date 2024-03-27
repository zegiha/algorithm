#include <iostream>
#include <cstring>
using namespace std;

char sig[202];

void deletePattern(int end) {
    char str[202];
    for(int i = end; i <= strlen(sig); i++) {
        str[i - end] = sig[i];
    }
    strcpy(sig, str);
}

int deletingFirstPattern() {
    if(sig[0] == '1' && sig[1] == '0') {
        int i = 2;
        while(sig[i] == '0') i++;
        if(i == 2) return 0;

        int j = i;
        while(sig[j] == '1') j++;
        if(j == i) return 0;

        if(sig[j] == '0' && sig[j + 1] == '0' && sig[j-2] == '1') j--;

        deletePattern(j);
        // for(i = 0; i < strlen(sig); i++) cout << sig[i] << ' ';
        return 1;
    } else return 0;
}

int deletingSecondPattern() {
    int i = 0;
    while(sig[i] == '0' && sig[i + 1] == '1') {
        i += 2;
    }
    if(i == 0) return 0;

    deletePattern(i);
    return 1;
}

int main()
{
    int t; cin >> t;
    while(t--) {
        int sw = 1;
        cin >> sig;
        //1. 1번 패턴 삭제
        //2. 2번 패턴 삭제
        //3. 패턴이 아닌 것은 NO and 종료
        //4. 문자열이 비었으면 YES and 종료

        while(1) {
            if(!deletingFirstPattern() && !deletingSecondPattern()) {
                cout << "NO" << endl;
                break;
            }
            if(!strlen(sig)) {
                cout << "YES" << endl;
                break;
            }
        }
    }

    return 0;
}
