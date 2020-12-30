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

uint n, m;

bool    is_number_valid(vector<int> &numbers, int i, int j)
{
    int     num;
    bool    up;
    bool    down;

    num = j;
    // distance with upper
    if (i-1 < 0 || numbers[i-1] == 0)
        up = true;
    else
        up = (abs(numbers[i-1] - num) <= 1);
    // distance with lower
    if (i+1 >= (int)n || numbers[i+1] == 0)
        down = true;
    else
        down = (abs(numbers[i+1] - num) <= 1);
    return (up && down);
}

ll solve(vector<int> &numbers, vector< vector<ll> > &dp)
{
    for (uint i = 1; i <= n; i++)
    {
        if (numbers[i-1] != 0)
            dp[i][numbers[i-1]] = 1;
    }

    for (uint i = 0; i <= m+1; i+=3)
    {
        dp[0][i] = 1;
        dp[n+1][i] = 1;
    }

    ll final_result = 0;

    for (uint i = 1; i <= n; i++)
    {
        ll current_line_value = 0;
        if (numbers[i-1] != 0)
        {
            uint j = numbers[i-1];
            ll cases = 0;
            for (int k = -1; k <= 1; k++)
            {
                // calculate upper
                cases = (cases + (dp[i-1][j+k]));
            }
            dp[i][j] = cases;
            current_line_value = (current_line_value + (dp[i][j]));
            continue;
        }
        for (uint j = 1; j <= m; j++)
        {
            int num_index = i-1;
            int current_num = j;

            if (is_number_valid(numbers, num_index, current_num))
            {
                ll cases = 0;
                for (int k = -1; k <= 1; k++)
                {
                    // calculate upper
                    cases = (cases + (dp[i-1][j+k]));
                }
                dp[i][j] = cases;
            }
            current_line_value = (current_line_value + (dp[i][j]));
        }
        final_result = max(final_result, current_line_value);
    }

    for (uint i = 0; i < n+2; i++)
    {
        for (uint j = 0; j < m+2; j++)
        {
            cout << dp[i][j] << "|";
        }
        cout << endl;
    }
    ll res = 0;
    for (uint i = 1; i <= m; i++)
        res = ((res % 1000000007) + (dp[n][i] % 1000000007)) % 1000000007;
    return res;
}

/*
**	START_MAIN_CODE
*/
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    cin >> n >> m;
    vector <int>    numbers(n, 0);
    vector < vector<ll> >     dp(n+2, vector<ll>(m+2, 0));

    for (uint i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    cout << solve(numbers, dp) << endl;
	return (0);
}


