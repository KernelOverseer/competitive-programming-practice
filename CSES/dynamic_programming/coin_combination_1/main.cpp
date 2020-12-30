/*
 *      ╔═╗┬ ┬┌┬┐┌─┐┌┐┌┌─┐  ╔╗ ┬┬─┐┬
 *      ╠═╣└┬┘│││├─┤│││├┤   ╠╩╗│├┬┘│
 *      ╩ ╩ ┴ ┴ ┴┴ ┴┘└┘└─┘  ╚═╝┴┴└─┴
 *      1337 Coding School Khouribga
 */

#ifdef  linux
# include <bits/stdc++.h>
#endif
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>
#include <limits>
#include <algorithm>
#define NL '\n'
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uint;

ull mod_exp(ull base, ull exponent, ull mod);

vector<int> coins;
bool	found[1000001];
int		result[1000001];

int	iter_solve(int x)
{
	result[0] = 1;
	for (int i = 1; i <= x; i++)
	{
		int best = 0;
		for (auto c : coins)
		{
			if (i - c >= 0)
				best = (best + result[i - c]) % 1000000007;
		}
		result[i] = best;
	}
	return (result[x]);
}

int	solve(int x)
{
	if (x == 0)
		return (0);
	if (found[x])
		return (result[x]);
	int best;
	int	local_result;

	best = 2147483627;
	for (auto c : coins)
	{
		if (x - c >= 0)
		{
			local_result = solve(x - c);
			if (local_result == -1)
				return (-1);
			best = min(best, 1 + local_result);
		}
	}
	if (best == 2147483627)
		return (-1);
	found[x] = true;
	result[x] = best;
	return (best);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int x, t;

	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		coins.push_back(t);
	}
	cout << iter_solve(x) << endl;
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


