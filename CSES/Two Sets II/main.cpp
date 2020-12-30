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

uint    gauss_sum(uint n)
{
    return ((n*(n+1))/2);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    uint n, m;

    cin >> n;
    m = gauss_sum(n);
    if (m%2)
    {
        cout << 0 << endl;
        return (0);
    }
    m /= 2;
    vector< vector<ull> >dp(n, vector<ull>(m+1, 0));

    for (uint i = 0; i < n; i++)
        dp[i][0] = 1;
    dp[0][1] = 1;
    
    for (uint index = 1; index < n; index++)
    {
        ull number = index + 1;
        for (uint current_sum = 1; current_sum <= m; current_sum++)
        {
            ll diff;
            ull value;

            diff = current_sum - number;
            value = dp[index - 1][current_sum] % 2000000014;
            if (diff >= 0)
                value += dp[index - 1][diff] % 2000000014;
            
            dp[index][current_sum] = value % 2000000014;
        }
    }

    // cout << "  ";
    // for (uint i = 0; i <= m; i++)
    //     cout << i % 10 << "|";
    // cout << endl;
    // cout << "  ";
    // for (uint i = 0; i <= m; i++)
    //     cout << "--";
    // cout << endl;
    // for (uint i = 0; i < n; i++)
    // {
    //     cout << i+1 << " ";
    //     for (uint j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j] % 10 << "|";
    //     }
    //     cout << endl;
    // }
    cout << dp[n-1][m]/2 << endl;
	return (0);
}


