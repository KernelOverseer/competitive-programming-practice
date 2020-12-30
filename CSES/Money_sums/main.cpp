/* TallMorty (Aymane Biri) */
#ifndef __APPLE__
# include <bits/stdc++.h>
# define M_PI 3.14159265358979323846
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

void    solve(vector< vector<bool> >    &dp, vector<int> &coins, uint n, uint max_sum)
{
    // init values;

    for (uint i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][coins[0]] = true;
    for (uint index = 1; index < n; index++)
    {
        for (uint sum = 0; sum <= max_sum; sum++)
        {
            int rest;

            rest = sum - coins[index];
            dp[index][sum] = dp[index - 1][sum];
            if (rest >= 0)
            {
                bool result = dp[index - 1][rest];
                if (!dp[index][sum] && result)
                    dp[index][sum] = result;
            }
        }
    }
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    uint n;
    cin >> n;
    vector <int> coins(n);
    ull coin_sum = 0;
    for (uint i = 0; i < n; i++)
    {
        cin >> coins[i];
        coin_sum += coins[i];
    }
    vector< vector<bool> >   dp(n, vector<bool>(coin_sum + 1, false));

    solve(dp, coins, n, coin_sum);
    uint results = 0;
    for (uint i = 1; i <= coin_sum; i++)
    {
        if (dp[n-1][i])
            results++;
    }
    cout << results << endl;
    for (uint i = 1; i <= coin_sum; i++)
    {
        if (dp[n-1][i])
            cout << i << " ";
    }
    cout << endl;
	return (0);
}


