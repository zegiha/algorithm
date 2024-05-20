#include <iostream>
#include <queue>
using namespace std;

int ladderN, snakeN, ladder[101] = {0, }, snake[101] = {0, }, ans;

int main() {
  cin >> ladderN >> snakeN;
  for(int t = 0; t < ladderN; t++) {
    int index, value;
    cin >> index >> value;
    ladder[index] = value;
  }
  for(int t = 0; t < snakeN; t++) {
    int index, value;
    cin >> index >> value;
    snake[index] = value;
  }

  queue <int> q;
  bool visit[101] = {0, };
  q.push(1);
  visit[1] = true;
  while(!q.empty()) {
    int size = q.size();
    for(int t = 0; t < size; t++) {
      int e = q.front(); q.pop();
      if(e == 100) {
        cout << ans;
        return 0;
      }
      for(int dice = 1; dice <= 6; dice++) {
        int next = e + dice;
        if(snake[next] != 0 && !visit[snake[next]]) {
          visit[snake[next]] = true;
          q.push(snake[next]);
        } else if(ladder[next] != 0 && !visit[ladder[next]]) {
          visit[ladder[next]] = true;
          q.push(ladder[next]);
        } else if(!visit[next]) {
          visit[next] = true;
          q.push(next);
        }
      }
    }
    ans++;
  }
}