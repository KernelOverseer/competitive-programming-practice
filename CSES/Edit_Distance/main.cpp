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
int n, m;

int solve(vector < vector<int> >  &dp, string &s1, string &s2)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int i = 0; i < m; i++)
        dp[0][i] = i;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i-1][j] + 1;
            dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s1[i-1] != s2[j-1]));
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dp[i][j] << "|";
    //     }
    //     cout << endl;
    // }

    return (dp[n-1][m-1]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    n = s1.size() + 1;
    m = s2.size() + 1;
    vector < vector<int> >  dp(n+1, vector<int>(m+1, 0));

    cout << solve(dp, s1, s2) << endl;
	return (0);
}


