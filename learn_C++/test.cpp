#include <iostream>
#include <cstring>
#define SIZE 20

using namespace std;

int main() {
    int* pArry = new int[3];
    pArry[0] = 1;
    pArry[1] = 2;
    pArry[2] = 3;

    int* p = new int;
    *p = 4;

    cout << pArry[0] 
    << endl;
    cout << p << endl;

    delete p;
    delete[] pArry;


    // int in;
    // int* inP = &in;
    // cin >> in;
    // cout << *inP;

    // string str;
    // cin >> str;
    // cout << str;
    // struct carType {
    //     int num;
    //     string name;
    //     int price;
    //     string owner;
    // };
    // carType car = {
    //     2345,
    //     "ray",
    //     39000000,
    //     "seoyul Lee"
    // };
    // cout << car.num << ' ' << car.name << ' ' << car.price << ' ' << car.owner;

    // const float PIE = 3.141592;
    // int r = 3;
    // float s = r * r * PIE;

    // int a = 3.54; // 형변환 없으 그냥 짤림
    // cout << a << endl;

    // char ch = 'A';
    // cout << (int)ch << ' ' << int(ch) << ch << endl;
    // cout << static_cast<int>(ch) << ' ' << ch << endl;

    // bool t = true;
    // cout << t;
}