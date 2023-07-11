#include <iostream>
#include <iterator>
#include <system_error>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M, TestCase;

int map[401][401] = {0,};
bool visited[401][401] = {0,};
//그래프 별 값 비교를 위한 벡터
vector<int> totallist;
//경로 찍기 위한 벡터
// vector<int> peo;

void reset_case()
{
	for (int i = 0; i < 401; i++)
	{
		for (int j = 0; j < 401; j++)
		{
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}
	totallist.clear();
}

void reset_visited()
{
	for (int i = 0; i < 401; i++)
	{
		for (int j = 0; j < 401; j++)
			visited[i][j] = false;
	}
}

void recur(int cur_point, int start_point, int cost)
{
	int res_cost = cost;
	for (int i = 0; i < 401; i++)
		visited[i][cur_point] = true;
	// cout << "current point : " << cur_point << " start_point : " << start_point << " res_cost : " << res_cost << endl;
	for (int i = 1; i < N + 1; i++)
	{
		if (i != cur_point && i == start_point && map[cur_point][i] != 0)
		{
			res_cost += map[cur_point][i];
			// cout << "End Cycle // cost : " << res_cost << endl;
			// peo.push_back(i);
			totallist.push_back(res_cost);

			// vector<int>::iterator iter4;
			// for (iter4 = peo.begin(); iter4 != peo.end(); iter4++)
			// 	cout << *iter4 << " ";
			// cout << endl;
		}
		if (i != cur_point && i != start_point && (!visited[cur_point][i]) && map[cur_point][i] != 0)
		{
			// cout << "next point : " << i << " plus : " << map[cur_point][i] << endl;
			res_cost += map[cur_point][i];
			// peo.push_back(i);
			recur(i, start_point, res_cost);
		}
		res_cost = cost;
	}
}

int manitto(int n, int m)
{
	int total = 0;
	for (int i = 0; i < m; i++)
	{
		int from, to, cash;
		cin >> from >> to >> cash;
		map[from][to] = cash;
		if (from == to)
			totallist.push_back(cash);
	}
	// cout << endl;
	//맵 출력
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout << map[i + 1][j + 1] << " ";
	// 	}
	// 	cout << endl;
	// }

	for (int i = 1; i < n; i++)
	{
		// peo.clear();
		// peo.push_back(i);
		reset_visited();
		int start_point = i;
		// cout << "START POINT : " << i << endl;
		recur(i, start_point, total);
	}
	// vector<int>::iterator iter;
	// cout << endl << endl << "totallist : ";
	// for (iter = totallist.begin(); iter != totallist.end(); iter++)
	// 	cout << *iter << " ";
	// cout << endl;

	sort(totallist.begin(), totallist.end());
	total = totallist[0];
	return (total);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	TestCase = T;

	while (T--)
	{
		reset_case();
		cin >> N >> M;
		int ans = manitto(N, M);
		cout << "#" << TestCase - T << " " << ans << endl;
	}

	return (0);
}
