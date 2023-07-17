#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int T, N, M, TestCase;

int map[401][401] = {0,};
int tempmap[401][401] = {0, };
bool visited[401][401] = {0, };
bool flag[401] = {0, };
// bool check_friend[401] = {0,};
int total;

vector<int> totallist;
// pair <int, int> popular[401];

void print_vector(vector<int> vec)
{
	vector<int>::iterator iter;
	cout << "totallist : ";
	for (iter =  vec.begin(); iter !=  vec.end(); iter++)
		cout << *iter << " ";
	cout << "\n";
}

void reset_case()
{
	for (int i = 0; i < 401; i++)
	{
		for (int j = 0; j < 401; j++)
		{
			map[i][j] = 0;
			tempmap[i][j] = 0;
			visited[i][j] = false;
		}
		// popular[i].first = 0;
		// popular[i].second = 0;
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
	// cout << "|current point : " << cur_point << " start_point : " << start_point << " res_cost : " << res_cost << "\n";
	for (int next_point = 1; next_point < N + 1; next_point++)
	{
		if (flag[next_point] == 0 && map[cur_point][next_point] != 0)
		{
			if (next_point == start_point)
			{
				res_cost += map[cur_point][next_point];
				//
				// cout << "|********End Cycle // cost : " << res_cost << "\n";
				// totallist.push_back(res_cost);
				if (total > res_cost)
					total = res_cost;
				flag[next_point] = 1;
			}
			if (!visited[cur_point][next_point])
			{
				//
				// cout << "|next point : " << next_point << " plus : " << map[cur_point][next_point] << "\n";
				res_cost += map[cur_point][next_point];
				recur(next_point, start_point, res_cost);
			}
		}
		res_cost = cost;
	}
}

int** copy_map(int** original, int** copy)
{
	for (int i = 0; i < 401; i++)
	{
		for (int j = 0; j < 401; j++)
		{
			copy[i][j] = original[i][j];
		}
	}
	return (copy);
}

int manito(int n, int m)
{
	total = 2147483647;
	for (int i = 0; i < m; i++)
	{
		int from, to, cash;
		cin >> from >> to >> cash;
		map[from][to] = cash;
		tempmap[from][to] = cash;
		if (from == to)
		{
			map[from][to] = 0;
			tempmap[from][to] = 0;
			//
			// cout << "|********SAME CASE : " << cash << "\n";
			// totallist.push_back(cash);
			if (total > cash)
				total = cash;
		}
		// popular[from].first++;
		// popular[to].second++;
		// check_friend[from] = 1;
		// check_friend[to] = 1;
	}

	// for (int i = 1; i < n + 1; i++)
	// {
	// 	if (popular[i].first * popular[i].second == 0)
	// 	{
	// 		for (int j = 0; j < 401; j++)
	// 		{
	// 			map[i][j] = 0;
	// 			map[j][i] = 0;
	// 		}
	// 		check_friend[i] = 0;
	// 	}
	// }

	for (int i = 1; i < n + 1; i++)
	{
		// if (check_friend[i] != 0)
		// {
			copy(&map[0][0], &map[0][0] + 401 * 401, &tempmap[0][0]);
			reset_visited();
			flag[i] = 0;
			int start_point = i;
			for (int j = 1; j < n + 1; j++)
			{
				if (map[i][j] * map[j][i] > 0)
				{
					//
					// cout << "|********EACH CASE : " << map[i][j] + map[j][i] << "\n";
					// totallist.push_back(map[i][j] + map[j][i]);
					if (total > map[i][j] + map[j][i])
						total = map[i][j] + map[j][i];
					map[i][j] = 0;
					map[j][i] = 0;
				}
			}
			recur(i, start_point, 0);
			copy(&tempmap[0][0], &tempmap[0][0] + 401 * 401, &map[0][0]);
		// }
	}
	// sort(totallist.begin(), totallist.end());
	// if (!totallist.empty())
		// total = totallist[0];
	// else
		// total = -1;
	if (total == 2147483647)
		total = -1;
	return (total);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		reset_case();
		cin >> N >> M;
		int ans = manito(N, M);
		cout << "#" << i << " " << ans << "\n";
	}

	return (0);
}
