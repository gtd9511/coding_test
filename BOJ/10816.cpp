#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main()
{
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		cout << upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp) << " ";
	}
	return (0);
}

//hash
// #include <iostream>
// #include <unordered_map>

// using namespace std;

// unordered_map <int, int> m;
// int N, M, card;

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cin >> N;
// 	for (int i = 0; i < N; i++) {
// 		cin >> card;
// 		m[card]++;
// 	}
// 	cin >> M;
// 	for (int i = 0; i < M; i++) {
// 		cin >> card;
// 		cout << m[card] << " ";
// 	}
// }
