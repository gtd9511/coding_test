#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, M;
		priority_queue<pair<int, int> > pq;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			pq.push(temp);
		}
		for (int i = 0; i < M - 1; i++)
			pq.pop();
		cout << N - pq.size() + 1 << endl;
	}
	return (0);
}
