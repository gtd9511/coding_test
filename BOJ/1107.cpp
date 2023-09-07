#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int arr[10] = {0, };
int current_ch = 100;
int p_ans = 0;
int m_ans = 0;
vector<int> res;

bool check_ch(int now)
{
	// cout << "now : " << now << endl;

	// if (now == 0 && arr[0] == -1)
	// 	return false;
	// else if (now == 0 && arr[0] == 0)
	//  	return true;
	while (now > 0)
	{
		int temp_single = now % 10;
		// cout << "temp_single : " << temp_single << endl;
		if (arr[temp_single] == -1)
		{
			// cout << "No" << endl;
			return false;
		}
		now /= 10;
	}
	// cout << "YES" << endl;
	return true;
}

int main()
{
	for (int i = 0; i < 10; i++)
		arr[i] = i;
	int N, M;
	cin >> N >> M;


	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		arr[temp] = -1;
	}

	if (N == 100)
	{
		cout << 0;
		return (0);
	}
	if (N == 0)
	{
		int temp = 0;
		for (int i = 0; i < 10; i++)
		{
			if (arr[i] != -1)
				temp = i + 1;
		}
		if (temp == 0)
			cout << 100;
		else
		 	cout << temp;
		return (0);
	}
	int no_num = 0;
	no_num = abs(100 - N);
	int plus_case = N;
	int minus_case = N;
	while (!check_ch(plus_case++))
	{
		p_ans++;
		// cout << "p_ans : " << p_ans << endl;
		if (plus_case > 1000000)
		{
			p_ans = 500000;
			break;
		}
	}
	// cout << "----------------" << endl;

	while (!check_ch(minus_case--))
	{
		m_ans++;

		// if (minus_case == 0)
		// {
		// 	int check = m_ans;
		// 	for (int i = 0; i < 9; i++)
		// 	{
		// 		if (arr[i] != -1)
		// 		{
		// 			m_ans += i + 1;
		// 			break;
		// 		}
		// 	}
		// 	if (check != m_ans)
		// 		break;
		// }
		// if (minus_case == 0 && arr[0] != -1)
		// {
		// 	m_ans++;
		// 	break;
		// }
		// else if (minus_case == 0 && arr[0] == -1)
		// {
		// 	for (int i = 9; i > 0; i--)
		// 	{
		// 		if (arr[i] != -1)

		// 	}
		// 	break;
		// }

		// cout << "m_ans : " << m_ans << endl;
	}
	// cout << "----------------" << endl;

	int plus_length = 0;
	int minus_length = 0;
	while (plus_case > 0)
	{
		plus_case /= 10;
		plus_length++;
	}
	while (minus_case > 0)
	{
		minus_case /= 10;
		minus_length++;
	}
	p_ans += plus_length;
	m_ans += minus_length;
	res.push_back(no_num);
	res.push_back(p_ans);
	res.push_back(m_ans);
	sort(res.begin(), res.end());
	cout << res[0];
	// if (p_ans > m_ans)
	// 	cout << m_ans;
	// else
	// 	cout << p_ans;
	return (0);
}

//https://www.acmicpc.net/board/view/31853
