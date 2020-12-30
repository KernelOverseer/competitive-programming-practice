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
#include <set>
#include <algorithm>
#define NL '\n'
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uint;

ull mod_exp(ull base, ull exponent, ull mod);

vector <int>	coins;
vector <bool>	found(1000001);
vector <int>	result(1000001);
//vector < vector <int> > result_sequence(1000001);
set < vector <int> > comb;

int	solve(int x, vector <int> &sequence)
{
	if (x == 0)
	{
		comb.insert(sequence);
		return (1);
	}
	if (found[x])
		return (result[x]);
	int best;
	best = 0;
	for (auto c : coins)
	{
		if (x - c >= 0)
		{
			sequence.push_back(c);
			best = (best + solve(x - c, sequence)) % 1000000007;
			sequence.pop_back();
		}
	}
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
	vector <int> sequ(0);
	solve(x, sequ);
	cout << comb.size() << endl;
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


