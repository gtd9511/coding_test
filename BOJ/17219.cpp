#include <iostream>
#include <map>
using namespace std;

map<string, string> pass_map;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		string a, b;
		cin >> a >> b;
		pass_map[a] = b;
	}

	for (int i = 0; i < M; i++)
	{
		string a;
		cin >> a;
		cout << pass_map[a] << "\n";
	}

	return(0);
}
