#include <string>
#include <vector>
#include <queue>

using namespace std;

struct INFO
{
	int x, y, cnt;
};

INFO start = {0, 0, 0};
bool visited[50][50] = {0,};
int solution(vector<string> grid, int k) {
    int answer = -1;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<INFO> myqueue;
    myqueue.push(start);
    while (!myqueue.empty())
    {
		if (myqueue.front().x == grid.size() - 1 && myqueue.front().y == grid[0].size() - 1)
		{
			answer = myqueue.front().cnt;
		}
		if (myqueue.front().x > grid.size() || myqueue.front().x < 0 || myqueue.front().y > grid[0].size() -1 || myqueue.front().y < 0)
        continue;
        
    }
    return answer;
}
