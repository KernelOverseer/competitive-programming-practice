/* TallMorty (Aymane Biri) */
#ifndef __APPLE__
# include <bits/stdc++.h>
# define M_PI acos(-1)
#endif
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>
#include <set>
#include <unordered_set>
#include <limits>
#include <algorithm>

/*
**	START_TEMPLATE
*/

using namespace std;
#define NL '\n'
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

ull mod_exp(ull base, ull exponent, ull mod);
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

void    fill_prime_sieve(vector<bool> &is_prime)
{
    is_prime[0] = is_prime[1] = false;
    uint i = 2;
    while (i < is_prime.size())
    {
        uint j = i + i;
        if (is_prime[i])
        {
            while (j < is_prime.size())
            {
                is_prime[j] = false;
                j += i;
            }
        }
        i++;
    }
}

/*
**	START_MAIN_CODE
*/

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    pair<uint, uint> shells[3];
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    shells[0] = make_pair(1, 0);
    shells[1] = make_pair(2, 0);
    shells[2] = make_pair(3, 0);
    uint n, a, b, g;
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> g;
        pair<int, int> temp;
        temp = shells[a-1];
        shells[a-1] = shells[b-1];
        shells[b-1] = temp;
        shells[g-1].second += 1;
    }
    uint score = 0;
    for (uint i = 0; i < 3; i++)
        score = max(score, shells[i].second);
    cout << score << endl;
	return (0);
}


