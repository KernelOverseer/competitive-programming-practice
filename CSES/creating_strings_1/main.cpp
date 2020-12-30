/*
 *      ╔═╗┬ ┬┌┬┐┌─┐┌┐┌┌─┐  ╔╗ ┬┬─┐┬
 *      ╠═╣└┬┘│││├─┤│││├┤   ╠╩╗│├┬┘│
 *      ╩ ╩ ┴ ┴ ┴┴ ┴┘└┘└─┘  ╚═╝┴┴└─┴
 *      1337 Coding School Khouribga
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>
#include <set>
#include <unordered_set>
#include <limits>
#include <algorithm>
#define NL '\n'
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uint;

ull mod_exp(ull base, ull exponent, ull mod);

set<string> answers;

void	solve(vector < pair<char, bool> > &input, size_t depth, string &result)
{
	if (depth >= input.size())
	{
		answers.insert(result);
		return ;
	}
	for (ull i = 0; i < input.size(); i++)
	{
		if (!input[i].second)
		{
			input[i].second = true;
			result += input[i].first;
			solve(input, depth + 1, result);
			result.resize(result.size() - 1);
			input[i].second = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char c;
	vector < pair<char, bool> > input;
	string result;
	while (cin >> c)
		input.push_back(make_pair(c, false));
	sort(input.begin(), input.end());
	solve(input, 0, result);
	cout << answers.size() << endl;
	for (auto c : answers)
		cout << c << endl;
	return (0);
}

ull mod_exp(ull base, ull exponent, ull mod)
{
    base %= mod;
    ull res = 1;
    while (exponent > 0) {
        if (exponent & 1)
            res = res * base % mod;
        base = base * base % mod;
        exponent >>= 1;
    }
    return res;
}


