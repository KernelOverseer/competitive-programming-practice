#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

// #define DEBUG
#define MOD 1000000007

int main(void)
{
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);
	int n;
	string s;
	int l;

	map<string, int> cows;
	cin >> n;
	cows["Bessie"] = 0;
	cows["Elsie"] = 0;
	cows["Daisy"] = 0;
	cows["Gertie"] = 0;
	cows["Annabelle"] = 0;
	cows["Maggie"] = 0;
	cows["Henrietta"] = 0;
	while(n--)
	{
		cin >> s >> l;
		cows[s]+=l;
	}
	vector < pair<int, string> > cow_sorted;
	for (auto c: cows)
	{
		cow_sorted.push_back(make_pair(c.second, c.first));
	}
	sort(cow_sorted.begin(), cow_sorted.end());
	int lowest = cow_sorted[0].first;
	auto result = upper_bound(cow_sorted.begin(), cow_sorted.end(), lowest, [](int value, const pair<int, string>& cow){return value < cow.first;});
	auto second_best = result;
	second_best++;
	if (result == cow_sorted.end())
		cout << "tie" << endl;
	if (result->first == second_best->first)
		cout << "tie" << endl;
	if (result->first > lowest)
		cout << result->second << endl;
	else
		cout << "tie" << endl;
	return (0);
}
