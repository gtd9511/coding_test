#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    int p_score = 0;
    int d_score = 0;
    int p_ace = 0;
    int d_ace = 0;
    vector<int> p;
    vector<int> d;
    while(!cards.empty())
    {
        if ((p.size() == 0 && d.size() == 0) || (p.size() == 1 && d.size() == 1))
        {
            if (p.size() == 0 && d.size() == 0)
            {
                p_score = 0;
                d_score = 0;
                p_ace = 0;
                d_ace = 0;
            }
            int cur_card = cards.front();
            cards.erase(cards.begin());
            p.push_back(cur_card);
            if (cur_card >= 10)
                p_score += 10;
            else if (cur_card == 1)
            {
                p_ace++;
                p_score += 11;
            }
            else
                p_score += cur_card;
        }
        else if ((p.size() == 1 && d.size() == 0) || (p.size() == 2 && d.size() == 1))
        {
            int cur_card = cards.front();
            cards.erase(cards.begin());
            d.push_back(cur_card);
            if (cur_card >= 10)
                d_score += 10;
            else if (cur_card == 1)
            {
                d_ace++;
                d_score += 11;
            }
            else
                d_score += cur_card;
        }
        if (p_score == 21 && p.size() == 2)
        {
            if (d_score != 21)
                answer += 3;
            p.clear();
            d.clear();
        }
        else
        {
            // if (p_score == 21 && p.size() == 2)
            // {
            //     if (d_score != 21)
            //         answer += 3;
            //     p.clear();
            //     d.clear();
            //     // p_score = 0;
                // d_score = 0;
                // p_ace = 0;
                // d_ace = 0;
            //     continue;
            // }
            // if
            // {
                if(d[1] == 1 || d[1] >= 7)
                {
                    while (p_score < 17)
                    {
						int plus_card = cards[0];
                        cards.erase(cards.begin());
                        p.push_back(plus_card);
						if (plus_card >= 10)
							p_score += 10;
						else if (plus_card == 1)
						{
							p_ace++;
							p_score += 11;
						}
						else
							p_score += plus_card;
						if (p_score > 21 && p_ace > 0)
						{
							p_score -= 10;
							p_ace--;
						}
                    }
                }
				if (d[1] == 2 || d[1] == 3)
				{
					while (!cards.empty() && p_score < 12)
					{
						int plus_card = cards[0];
                        cards.erase(cards.begin());
                        p.push_back(plus_card);
						if (plus_card >= 10)
							p_score += 10;
						else if (plus_card == 1)
						{
							p_ace++;
							p_score += 11;
						}
						else
							p_score += plus_card;
						if (p_score > 21 && p_ace > 0)
						{
							p_score -= 10;
							p_ace--;
						}
					}
				}
				if (p_score > 21)
				{
					answer -= 2;
					p.clear();
					d.clear();
                    // p_score = 0;
                    // d_score = 0;
                    // p_ace = 0;
                    // d_ace = 0;
					continue;
				}
                if (d_score == 21 && d.size() == 2)
                {
                    answer -= 2;
                    p.clear();
                    d.clear();
                    continue;
                }
				while (!cards.empty() && d_score < 17)
				{
					int plus_card = cards[0];
                    cards.erase(cards.begin());
                    d.push_back(plus_card);
					if (plus_card >= 10)
						d_score += 10;
					else if (plus_card == 1)
					{
						d_ace++;
						d_score += 11;
					}
					else
						d_score += plus_card;
					if (d_score > 21 && d_ace > 0)
					{
						d_score -= 10;
						d_ace--;
					}
				}
                if (cards.empty() && d_score < 17)
                {
                    p.clear();
                    d.clear();
                    continue;
                }
				if (d_score > 21)
				{
					answer += 2;
					p.clear();
					d.clear();
                    // p_score = 0;
                    // d_score = 0;
                    // p_ace = 0;
                    // d_ace = 0;
					continue;
				}
			    else if (p_score > d_score)
				{
					answer += 2;
					p.clear();
					d.clear();
                    // p_score = 0;
                    // d_score = 0;
                    // p_ace = 0;
                    // d_ace = 0;
					continue;
				}
				else if (p_score < d_score)
				{
                    answer -= 2;
					p.clear();
					d.clear();
                    // p_score = 0;
                    // d_score = 0;
                    // p_ace = 0;
                    // d_ace = 0;
					continue;
				}
				else
				{
					p.clear();
					d.clear();
                    // p_score = 0;
                    // d_score = 0;
                    // p_ace = 0;
                    // d_ace = 0;
					continue;
				}
            // }
        }
        cout << p_score << " " << p_ace << endl;
        cout << d_score << " " << d_ace << endl;
        cout << answer << endl;
        cout << endl;
    }
    cout << answer << endl;
    return answer;
}
