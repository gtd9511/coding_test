#include <iostream>
#include <queue>

using namespace std;

int F, S, G ,U, D;

bool visited[1000001] = { false, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	int cnt = 0;
	bool flag = 0;

	visited[S] = 1;
	queue<pair<int, int> > myqueue;
	myqueue.push(make_pair(S, cnt));
	while(!myqueue.empty())
	{
		int cur = myqueue.front().first;
		cnt = myqueue.front().second;
		//cout << cur << '\n';
		myqueue.pop();
		if (cur < 1 || cur > F)
			continue;
		if (cur == G)
		{
			flag = 1;
			break;
		}
		//if (visited[cur])
		//	continue;
		if (cur + U > 0 && cur + U <= F && !visited[cur + U])
		{
			visited[cur + U] = true;
			myqueue.push(make_pair(cur + U, cnt + 1));
		}
		if (cur - D > 0 && cur - D <= F && !visited[cur - D])
		{
			visited[cur - D] = true;
			myqueue.push(make_pair(cur - D, cnt + 1));
		}
	}
	if (flag == 1)
		cout << cnt << '\n';
	else
	 	cout << "use the stairs" << '\n';
	return (0);
}
