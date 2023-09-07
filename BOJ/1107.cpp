#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool use[10] = {0, };
int p_current, m_current, p_ans = 0, m_ans = 0;

vector<int> res;

bool check_num(int num)
{
	string temp_str = to_string(num);
	for (int i = 0; i < temp_str.length(); i++)
		if (use[temp_str[i] - '0'] == 1)
			return (false);
	return (true);
}

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		use[temp] = 1;
	}
	res.push_back(abs(N - 100));
	// cout << "no_num : " << res[0] << endl;
	p_current = N;
	m_current = N;
	while (!check_num(p_current++))
	{
		p_ans++;
		if (p_current > 1000000)
		{
			p_ans = 500000;
			break;
		}
	}
	while (!check_num(m_current--))
	{
		m_ans++;
		if (m_current < -1)
		{
			m_ans = 500000;
			break;
		}
		// cout << "wm_ans : " << m_ans << endl;
	}
	// cout << m_current << " " << m_ans << endl;
	p_current--;
	m_current++;
	p_ans += to_string(p_current).length();
	m_ans += to_string(m_current).length();
	// cout << "l : " << p_current << " " << to_string(p_current).length() << endl;
	// cout << "l : " << m_current << " " << to_string(m_current).length() << endl;
	// cout << "p_ans : " << p_ans << endl;
	// cout << "m_ans : " << m_ans << endl;
	res.push_back(p_ans);
	res.push_back(m_ans);

	sort(res.begin(), res.end());

	cout << res[0];
	return (0);
}

