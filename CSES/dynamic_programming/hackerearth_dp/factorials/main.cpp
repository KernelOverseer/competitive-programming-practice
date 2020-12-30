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
int	solve(ull n, vector <int> &memo)
{
	ull	result;
	ull	mod;

	if (memo[n] != -1)
		return (memo[n]);
	mod = 1000000007;
	result = ((solve(n - 1, memo) % mod) * (n % mod)) % mod;
	memo[n] = result;
	return (result);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n;
	vector <int> memo(100001, -1);
	memo[0] = 1;
	memo[1] = 1;
	while (n--)
	{
		cin >> t;
		cout << solve(t, memo) << endl;
	}
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


