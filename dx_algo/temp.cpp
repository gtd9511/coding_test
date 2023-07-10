#include <iostream>
#include <vector>
using namespace std;
#define N_NODE 5
int cnt = 0;
vector<int> adjList[N_NODE];
vector<int> visitOrder(N_NODE, 100);
vector<bool> finished(N_NODE, false);
void addEdge(int u, int v){
	adjList[u].push_back(v);
}
bool cycleCheck(int here) {
	// here 의 방문한 순서를 기록한다.
	visitOrder[here] = cnt;
	cnt++;
	for(int there : adjList[here]){
		// 이미 이전에 방문 했고, 재귀가 끝나지 않았으면 back edge다. -> 사이클 존재
		if(visitOrder[there] < visitOrder[here] && !finished[there]) return true;
		// 이후에 사이클이 존재한다면 true 리턴
		if(cycleCheck(there)) return true;
	}
	// here 에서의 재귀가 끝났음을 표시
	finished[here] = true;
	// 사이클이 없으므로 false 리턴
	return false;
}
int main(){
	addEdge(0, 1);
	addEdge(1, 0);
	addEdge(0, 2);
	addEdge(2, 3);
	addEdge(3, 4);
	addEdge(4, 0);
	bool ret = false;
	for(int i=0;i<N_NODE;i++) {
		if(visitOrder[i] == 100 && cycleCheck(i)) ret = true;
	}
	cout << ret;
	return 0;
}
