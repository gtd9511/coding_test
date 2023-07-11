#include <iostream>
#include <iterator>
#include <system_error>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M, TestCase;
int map[401][401] = {0,};
int tempmap[401][401] = {0, };
bool visited[401][401] = {0,};
vector<int> totallist;
int flag[401] = {0};

int check_friend(int x)
{
	int temp = 0;
	for (int i = 0; i < 401; i++)
		temp += map[x][i];
	return (temp);
}

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
	//
	// cout << "current point : " << cur_point << " start_point : " << start_point << " res_cost : " << res_cost << endl;
	for (int i = 1; i < N + 1; i++)
	{
		if (flag[i] == 0 && map[cur_point][i] != 0 && i != cur_point)
		{
			if (i == start_point)
			{
				res_cost += map[cur_point][i];
				//
				// cout << "End Cycle // cost : " << res_cost << endl;
				totallist.push_back(res_cost);
				flag[i] = 1;
			}
			if (i != start_point && (!visited[cur_point][i]))
			{
				//
				// cout << "next point : " << i << " plus : " << map[cur_point][i] << endl;
				res_cost += map[cur_point][i];
				recur(i, start_point, res_cost);
			}
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
		{
			map[from][to] = 0;
			totallist.push_back(cash);
		}
	}
	//맵 출력
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout << map[i + 1][j + 1] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	for (int i = 1; i < n; i++)
	{
		if (check_friend(i) > 0)
		{
			copy(&map[0][0], &map[0][0] + 401 * 401, &tempmap[0][0]);
			reset_visited();
			flag[i] = 0;
			int start_point = i;
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] * map[j][i] > 0)
				{
					totallist.push_back(map[i][j] + map[j][i]);
					map[i][j] = 0;
					map[j][i] = 0;
				}
			}
			recur(i, start_point, total);
			copy(&tempmap[0][0], &tempmap[0][0] + 401 * 401, &map[0][0]);
		}
	}
	//
	// vector<int>::iterator iter;
	// cout << endl << endl << "totallist : ";
	// for (iter = totallist.begin(); iter != totallist.end(); iter++)
	// 	cout << *iter << " ";
	// cout << endl;
	sort(totallist.begin(), totallist.end());
	if (!totallist.empty())
		total = totallist[0];
	else
		total = -1;
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
