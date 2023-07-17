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
pair<int, int> popular[401];

void print_vector(vector<int> vec)
{
	vector<int>::iterator iter;
	cout << "totallist : ";
	for (iter =  vec.begin(); iter !=  vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
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
		popular[i].first = 0;
		popular[i].second = 0;
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
	cout << "current point : " << cur_point << " start_point : " << start_point << " res_cost : " << res_cost << endl;
	if (popular[cur_point].first * popular[cur_point].second != 0)
	{
		cout << "AAAAAAAAAAAAAA" << endl;
		for (int next_point = 1; next_point < N + 1; next_point++)
		{
			if (flag[next_point] == 0 && map[cur_point][next_point] != 0)
			{
				cout << "BBBBBBBBBBBBBBBBBb" << endl;
				if (next_point == start_point)
				{
					cout << "CCCCCCCCCCCCCCCCCc" << endl;
					res_cost += map[cur_point][next_point];
					//
					cout << "****************End Cycle // cost : " << res_cost << endl;
					totallist.push_back(res_cost);
					flag[next_point] = 1;
				}
				if (next_point != start_point && (!visited[cur_point][next_point]))
				{
					//
					cout << "next point : " << next_point << " plus : " << map[cur_point][next_point] << endl;
					res_cost += map[cur_point][next_point];
					recur(next_point, start_point, res_cost);
				}
			}
			res_cost = cost;
		}
	}
}

int manito(int n, int m)
{
	int total = 0;
	for (int i = 0; i < m; i++)
	{
		int from, to, cash;
		cin >> from >> to >> cash;
		map[from][to] = cash;
		popular[from].first = 1;
		popular[to].second = 1;
		if (from == to)
		{
			map[from][to] = 0;
			cout << "****************************SAME : " << cash << endl;
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
	cout << "Before recur : ";
	print_vector(totallist);
	for (int i = 1; i < n + 1; i++)
	{
		cout << " I : " << i << endl;
		if (popular[i].first * popular[i].second != 0)
		{
			reset_visited();
			flag[i] = 0;
			int start_point = i;
			for (int j = 1; j < n + 1; j++)
			{
				if (map[i][j] * map[j][i] > 0)
				{
					cout << "****************************EACH : " << map[i][j] + map[j][i] << endl;
					totallist.push_back(map[i][j] + map[j][i]);
					map[i][j] = 0;
					map[j][i] = 0;
				}
			}
			recur(i, start_point, total);
		}
	}
	cout << "After recur : ";
	print_vector(totallist);
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

	for (int i = 0; i < 401; i++)
	{
		popular[i].first = 0;
		popular[i].second = 0;
	}
	while (T--)
	{
		reset_case();
		cin >> N >> M;
		int ans = manito(N, M);
		cout << "#" << TestCase - T << " " << ans << "\n";
	}

	return (0);
}
