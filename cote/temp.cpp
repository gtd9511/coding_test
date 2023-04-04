#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	vector<int> vector[3];

	vector[0].push_back(1);
	vector[0].push_back(2);
	vector[0].push_back(3);

	vector[1].push_back(1);
	vector[1].push_back(2);

	vector[2].push_back(1);
	vector[2].push_back(2);
	vector[2].push_back(3);
	vector[2].push_back(4);
	vector[2].push_back(5);

	for (int i = 0; i < 3; i++) {
		cout << "vector" << i << endl;
		for (int j = 0; j < vector[i].size(); j++) {
			cout << vector[i].at(j) << endl;
		}
		cout << endl;
	}
	return 0;
}
