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
vector <long long> weights;

int	min_diff(long long sum1, long long sum2, uint depth)
{
	long long result;

	if (depth == weights.size())
		return (abs(sum1 - sum2));
	result = abs(min(
			min_diff(sum1 + weights[depth], sum2, depth + 1),
			min_diff(sum1, sum2 + weights[depth], depth + 1)
			));
	return (result);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	uint n, w;

	cin >> n;
	for (uint i = 0; i < n; i++)
	{
		cin >> w;
		weights.push_back(w);
	}
	cout << min_diff(0, 0, 0) << endl;
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


