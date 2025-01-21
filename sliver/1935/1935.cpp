#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int n;
string str;
vector <double> arr;

double calculate(double a, double b, int op) {
  switch (op) {
  case 0:
    return a + b;
  case 1:
    return a - b;
  case 2:
    return a * b;
  case 3:
    return a / b;
  }
}

int get_op(char c) {
  if(c == '+') return 0;
  if(c == '-') return 1;
  if(c == '*') return 2;
  if(c == '/') return 3;
}

int main() {
  cin >> n >> str;
  for(int i = 0; i < n; i++) {
    double t; cin >> t;
    arr.push_back(t);
  }

  stack <double> s;
  queue <int> q;

  for(int i = 0; i < str.size(); i++) {
    if('A' <= str[i] && str[i] <= 'Z') {
      while(!q.empty()) {
        double a, b;
        b = s.top(); s.pop();
        a = s.top(); s.pop();
        s.push(calculate(a, b, q.front())); q.pop();
      }
      s.push(arr[str[i] - 'A']);
    } else {
      while(!q.empty() && !(q.front() > 1 && (str[i] == '-' || str[i] == '+'))) {
        double a, b;
        b = s.top(); s.pop();
        a = s.top(); s.pop();
        s.push(calculate(a, b, q.front())); q.pop();
      }
      q.push(get_op(str[i]));
    }
  }

  while(!q.empty()) {
    double a, b;
    b = s.top(); s.pop();
    a = s.top(); s.pop();
    s.push(calculate(a, b, q.front())); q.pop();
  }

  double ans = s.top();
  printf("%.2lf", ans);
}
