#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int	minX = 10001;
	int	minY = 10001;
	int	maxX = -10001;
	int	maxY = -10001;
	while (T--)
	{
		int tempX, tempY;
		cin >> tempX >> tempY;
		if (tempX >= maxX)
			maxX = tempX;
		if (tempX <= minX)
			minX = tempX;
		if (tempY >= maxY)
			maxY = tempY;
		if (tempY <= minY)
			minY = tempY;
	}
	cout << (maxX - minX) * (maxY - minY);
	return (0);
}
