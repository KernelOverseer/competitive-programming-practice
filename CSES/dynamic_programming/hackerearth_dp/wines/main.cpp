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
#include <limits>
#include <algorithm>
#define NL '\n'
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uint;

ull mod_exp(ull base, ull exponent, ull mod);

vector <int>	wines;

int	solve(int year, int begin, int end, vector < vector<int> > &memo)
{
	int result;

	if (begin > end)
		return (0);
	if (memo[begin][end] != -1)
		return (memo[begin][end]);
	result = max(solve(year + 1, begin + 1, end, memo) + year * wines[begin],			
			solve(year + 1, begin, end - 1, memo) + year * wines[end]);
	memo[begin][end] = result;
	return (result);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int start;
	int end;
	int t;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		wines.push_back(t);
	}
	start = 0;
	end = wines.size() - 1;
	vector <int> temp_memo(n, -1);
	vector < vector <int> > memo(n, temp_memo);
	cout << solve(1, start, end, memo) << endl;
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


