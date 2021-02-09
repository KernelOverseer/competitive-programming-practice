#include <bits/stdc++.h>

using namespace std;

string evaluate_best(int mildred, int elsie, int bessie)
{
	vector< pair<int, string> > best(3);

	best[0].first = mildred;
	best[0].second = "Mildred";
	best[1].first = elsie;
	best[1].second = "Elsie";
	best[2].first = bessie;
	best[2].second = "Bessie";
	sort(best.rbegin(), best.rend());
	int best_score = best[0].first;
	string result = "";
	for (int i = 0; i < 3; i++)
	{
		if (best[i].first == best_score)
			result += best[i].second;
		else
			break;
	}
	return result;
}

int main(void)
{
	int mildred, elsie, bessie, n;

	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	vector< pair<int, pair<string, int> > > variations;
	cin >> n;
	while (n--)
	{
		int d, va;
		string name;

		cin >> d >> name >> va;
		variations.push_back(make_pair(d, make_pair(name, va)));
	}
	sort(variations.begin(), variations.end());
	int startDate = 0;
	mildred = 7;
	elsie = 7;
	bessie = 7;
	string best = "";
	int counter = 0;
	for (int i = 0; i < variations.size(); i++)
	{
		if (variations[i].second.first == "Mildred")
		{
			mildred += variations[i].second.second;
		}
		else if (variations[i].second.first == "Elsie")
		{
			elsie += variations[i].second.second;
		}
		else
		{
			bessie += variations[i].second.second;
		}
		string newbest = evaluate_best(mildred, elsie, bessie);
		if (newbest != best)
		{
			best = newbest;
			counter++;
		}
	}
	cout << counter << endl;
	return (0);
}
