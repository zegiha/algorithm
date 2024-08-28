#include <iostream>

using namespace std;

string str;

int getNext(int start, int digits) {
  if(str[start] == '0') return -1;

  int end;
  switch(digits) {
    case 1:
      end = 1;
      break;
    case 10:
      end = 2;
      break;
    case 100:
      end = 3;
      break;
  }

  if(end + start > str.size()) return -1;

  int res = 0;
  for(int i = start; i < end + start; i++) {
    res *= 10;
    res += str[i] - '0';
  }

  return res;
}

int getA(int digits) {
  return getNext(0, digits);
}

pair <int, int> solve(int digist) {
  int type;
  if(digist == 1) type = 1;
  else if (digist == 10) type = 2;
  else type = 3;

  int a = getA(digist);

  int i = type, b = a;
  while(i < str.size()) {
    if((b + 1) / 100 != 0) {
      digist = 100;
      type = 3;
    }
    else if((b + 1) / 10 != 0) {
      digist = 10;
      type = 2;
    }

    int next = getNext(i, digist);
    // cout << next << '\n';
    if(next != b + 1) return {-1, -1};
    b++;
    i += type;
  }
  
  return {a, b};
}

pair <int, int> tryFirst_and_getAB() {
  return solve(1);
}
pair <int, int> trySecond_and_getAB() {
  return solve(10);
}
pair <int, int> tryThird_and_getAB() {
  return solve(100);
}

int main() {
  cin >> str;

  pair <int, int> first = tryFirst_and_getAB();
  if(first.first != -1) {
    cout << first.first << ' ' << first.second;
    return 0;
  }
  // cout << "====================================\n";

  pair <int, int> second = trySecond_and_getAB();
  if(second.first != -1) {
    cout << second.first << ' ' << second.second;
    return 0;
  }
  // cout << "====================================\n";

  pair <int, int> third = tryThird_and_getAB();
  cout << third.first << ' ' << third.second;
}