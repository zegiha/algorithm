#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

string str;

int getTag(int index) {
  while(index < str.size()) {
    if(str[index] == '>') {
      return index;
    }
    index++;
  }
  return 0;
}

void printing(stack <char>* s) {
  while(!s->empty()) {
    cout << s->top();
    s->pop();
  }
}

int main() {
  stack <char> s;
  getline(cin, str, '\n');
  for(int i = 0; i <= str.size(); i++) {
    if(str[i] == '<') {
      int tagSize = getTag(i);
      if(tagSize) {
        printing(&s);
        for(int j = i; j <= tagSize; j++) cout << str[j];
        i = tagSize;
        continue;
      }
    }
    if(str[i] == ' ' || str[i] == '\0') {
      printing(&s);
      if(str[i] != '\0') cout << ' ';
    } else {
      s.push(str[i]);
    }
  }
}