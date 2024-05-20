// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int n, sNode, eNode, sIndex = -1, eIndex = -1;
// vector <pair <int, pair <int, int>>> node;

// bool compare(pair <int, pair <int, int>> prev, pair <int, pair <int, int>> next) {
//   int prevR = prev.second.second, nextR = next.second.second;
//   if(prevR > nextR) return true;
//   return false;
// }
// int divideCase(int firstIndex, int secondIndex) {
//   int d = node[firstIndex].second.first - node[secondIndex].second.first, r1 = node[firstIndex].second.second, r2 = node[secondIndex].second.second;
//   if(d < 0) d *= -1;
//   if(r1 + r2 < d) {
//     return 1; //out
//   } else {
//     if(r1 > r2) return 2; //firstInSecond
//     else return 3; //secondInFirst
//   }
// }

// void solveOut() {
//   int e, sameNode;
//   bool c = false;
//   vector <int> check;
//   check.resize(n + 1, 0);
//   if(node[sIndex].second.second > node[eIndex].second.second) c = true;
//   if(c) e = sIndex;
//   else e = eIndex;
// }

// int main() {
//   cin >> n;
//   for(int i = 0; i < n; i++) {
//     cin >> node[i].first >> node[i].second.first >> node[i].second.second;
//   }
//   cin >> sNode >> eNode;
//   sort(node.begin(), node.end(), compare);

//   //sNode와 eNode의 node배열 방 번호 찾기
//   for(int i = 0; i < n; i++) {
//     if(node[i].first == sNode) sNode = i;
//     if(node[i].first == eNode) eNode = i;
//     if(eNode != -1 && sNode != -1) break;
//   }

//   //sNode와 eNode의 포함 관계로 나누기
//   switch(divideCase(sIndex, eIndex)){
//     case 1:
//       solveOut();
//       break;
//     // case 2:


//   }
// }

// /*
// 시작원이 종료원의 내부에 있거나 종료원이 시작원의 내부에 있는 경운

// 시작원이 종료원의 외부에 있을 경우
// 목표: 공통된 상위 노드를 찾는다
// 1-1-1. 자신보다 반지름이 넓은 노드를 방문한다
// 1-1-2. 만약 자신보다 반지름이 넓은 노드가 없다면 0번의 체크 값을 1더한다
// 1-1-3. 체크 값을 더했을 때 0번의 값이 2라면 좌표평면이 공통노드이다
// 1-2. 자신이 위의 노드에 포함되는지 확인한다
// 1-3-1. 포함된다면 방문 노드의 체크 값은 1 더한다
// 1-3-2. 만약 값이 2가 되었다면 공통된 노드이다
// 1-3-3. 포함된다면 자신을 체크 값을 더한 노드 ( 상위노드 )로 바꾼다
// */

// // #include <iostream>
// // #include <vector>
// // #include <queue>
// // #include <algorithm>
// // using namespace std;

// // int n, start, end;
// // vector <vector <int>> tree;

// // bool compare(pair <int, pair <int, int>> prev, pair <int, pair <int, int>> next) {
// //   int prevR = prev.second.second, nextR = next.second.second;
// //   if(prevR > nextR) return true;
// //   return false;
// // }
// // bool isOut() {
// //   arr[]
// // }

// // int main() {
// //   //정보 입력 및 반지름을 기준으로 정보 정렬
// //   vector <pair <int, pair<int, int>>> nodeInfo;
// //   cin >> n;
// //   nodeInfo.resize(n + 1);
// //   for(int i = 0; i < n; i++) {
// //     int nodeNum, coordinate, radius;
// //     cin >> nodeNum >> coordinate >> radius;
// //     nodeInfo[i] = make_pair(nodeNum, make_pair(coordinate, radius));
// //   }
// //   cin >> start >> end;
// //   // sort(nodeInfo.begin(), nodeInfo.end(), compare);
// //   // for(int i = 0; i < n; i++) {
// //   //   cout << "nodeNum, coordinate, radius  ||  " << nodeInfo[i].first << ", " << nodeInfo[i].second.first << ", " << nodeInfo[i].second.second << endl;
// //   // }

// //   //내부 외부 판별
// //   if(isOut()) {

// //   }
// // }