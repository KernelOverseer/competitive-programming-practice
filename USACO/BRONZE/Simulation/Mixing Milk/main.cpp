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

    int a, b, c, am, bm, cm;

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    cin >> am >> a >> bm >> b >> cm >> c;

    for (uint i = 0; i < 100; i++)
    {
        int diff;
        if (i % 3 == 0)
        {
            diff = min(a, bm-b);
            a -= diff;
            b += diff;
        }
        else if (i % 3 == 1)
        {
            diff = min(b, cm-c);
            b -= diff;
            c += diff;
        }
        else
        {
            diff = min(c, am-a);
            c -= diff;
            a += diff;
        }
    }
    cout << a << endl << b << endl << c << endl;
	return (0);
}