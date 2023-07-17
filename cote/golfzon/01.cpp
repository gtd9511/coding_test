// 블록 뭉치 a와 블록 뭉치 b 그리고 블록 뭉치 c가 있습니다. 모든 블록에는 1~5 사이의 숫자가 적혀있습니다.
// 블록 뭉치 a는 블록이 일렬로 나열되어있는 형태입니다. 왼쪽에서부터 블록에 적혀있는 숫자가 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1 ... 처럼 1부터 5까지 순환하며 무한히 나열되어있습니다.
// 블록 뭉치 b는 블록이 일렬로 나열되어있는 형태입니다. 왼쪽에서부터 블록에 적혀있는 숫자가 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5 ... 처럼 5부터 1까지 순환하며 무한히 나열되어있습니다.
// 블록 뭉치 c에는 1부터 5 사이의 무작위 숫자가 적힌 블록이 한 개 존재합니다.

// 당신은 아래 두 가지 행동을 통하여 블록 뭉치 c의 블록 개수를 늘릴 수 있습니다.
// 1. 블록 뭉치 a의 가장 왼쪽에 있는 블록 하나를 블록 뭉치 c의 가장 왼쪽으로 이동시킵니다.
// 2. 블록 뭉치 b의 가장 왼쪽에 있는 블록 하나를 블록 뭉치 c의 가장 오른쪽으로 이동시킵니다.

// 당신은 1번 행동과 2번 행동을 계속하던 중, 블록 뭉치 c에 처음 존재하던 블록에 어떤 숫자가 적혀있었는지 궁금해졌습니다.

// 두 행동을 여러 번 한 블록 뭉치 c의 상태를 나타내는 1차원 정수 배열 c가 매개변수로 주어집니다. 이때, 처음부터 존재하던 블록은 c의 왼쪽에서 몇 번째에 있는지와 그 블록에 적혀있는 숫자를 차례대로 담아서 return 하도록 solution 함수를 완성해주세요.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


vector<int> c;
string input;

vector<int> solution(vector<int> c) {
    vector<int> answer;
    int n = c.size();
    int flag = -1;

    for (int i = 1; i < n - 1; i++)
    {
	    if (c[i] != c[i - 1] - 1)
		{
			if (c[i] == 5 && c[i - 1] == 1)
			{
				flag = -1;
			}
			else
			{
				if ((c[i] == c[i + 1] + 1) || (c[i] == 1 && c[i + 1] == 5))
            	{
                	flag = i - 1;
                	answer.push_back(flag + 1);
                	answer.push_back(c[flag]);
					break;
            	}
				flag = i;
        	    answer.push_back(flag + 1);
            	answer.push_back(c[flag]);
				break;
			}
		}
    }
    return answer;
}

int main ()
{

	getline(cin, input);
	stringstream ss(input.substr(1, input.size() - 2));
	int t;
	while (ss >> t)
	{
		if (ss.peek() == ',' || ss.peek() == ' ')
		{
			ss.ignore();
		}
		c.push_back(t);
	}
	cout << solution(c)[0] << ", " << solution(c)[1] << endl;
	return 0;
}




#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> c) {
    vector<int> answer;
    int n = c.size();
    int flag = -1;

    if (c.size() == 3)
    {
        if (c[0] == 2 && c[1] == 1)
        {
            flag = 2;
            answer.push_back(flag + 1);
            answer.push_back(c[flag]);
        }
        if (c[1] == 5 && c[2] == 4)
        {
            flag = 0;
            answer.push_back(flag + 1);
            answer.push_back(c[flag]);
        }

    }
    else
    {
        for (int i = 1; i < n; i++)
        {
    	   if (c[i - 1] == 1 && c[i + 1] == 5)
           {
                flag = i;
                answer.push_back(flag + 1);
                answer.push_back(c[flag]);
                break;
            }
            if (c[i - 1] == 2 && c[i] == 1)
            {
                if (c[i + 1] != 5)
                {
                    flag = i + 1;
                    answer.push_back(flag + 1);
                    answer.push_back(c[flag]);
                    break;
                }
            }
            if (c[i] == 5 && c[i + 1] == 4)
            {
                if (c[i - 1] != 1)
                {
                    flag = i - 1;
                    answer.push_back(flag + 1);
                    answer.push_back(c[flag]);
                    break;
                }
            }
        }
    }
    return answer;
}
