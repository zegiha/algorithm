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
  bool visit[120][3] = {0, };
  q.push(1);
  visit[1][0] = true;
  while(!q.empty()) {
    int size = q.size();
    for(int t = 0; t < size; t++) {
      int e = q.front(); q.pop();
      // cout << e << endl;
      if(e == 100) {
        cout << ans;
        return 0;
      }
      for(int dice = 1; dice <= 6; dice++) {
        int next = e + dice;
        // cout << "next: " << next << endl;
        if(snake[next]) {
          if(!visit[snake[next]][3]) {
            visit[snake[next]][3] = true;
            q.push(snake[next]);
          }
        } else if(ladder[next]) {
          if(!visit[ladder[next]][2]) {
            visit[ladder[next]][2] = true;
            q.push(ladder[next]);
          }
        } else {
          if(!visit[next][0]) {
            visit[next][0] = true;
            q.push(next);
          }
        }
      }
    }
    ans++;
    // cout << "*****************\n";
  }
}