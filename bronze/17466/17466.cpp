#include <iostream>
using namespace std;

int main()
{
    long long N, P, mul = 1;

    cin >> N >> P;
    while (N)
    {
        mul *= N; mul %= P;
        N--;
    }

    cout << mul;
}