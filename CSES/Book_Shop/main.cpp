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

int without_element(vector< vector<int> > &dp, int index, int price_i)
{
    if (index - 1 < 0 || price_i < 0)
        return (0);
    return (dp[index-1][price_i]);
}

int with_element(vector< vector<int> > &dp, int index, int price_i, int element_pages, int element_price)
{
    if (price_i - element_price < 0)
        return (0);
    int price_of_the_rest = 0;
    if (index - 1 < 0)
        price_of_the_rest = 0;
    else
        price_of_the_rest = dp[index - 1][price_i - element_price];
    return (element_pages + price_of_the_rest);
}

uint n, x;
void solve(vector< vector<int> > &dp, vector <int> &price, vector<int> &pages)
{
    for (uint price_i = 0; price_i <= x; price_i++)
    {
        for (uint index = 0; index < n; index++)
        {
            // int left = price_i - price[index];
            dp[index][price_i] = max(without_element(dp, index, price_i), with_element(dp, index, price_i, pages[index], price[index]));
        }
    }
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


    cin >> n >> x;
    vector <int> price(n);
    vector <int> pages(n);
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for (uint i = 0; i < n; i++)
        cin >> price[i];
    for (uint i = 0; i < n; i++)
        cin >> pages[i];
    solve(dp, price, pages);
    cout << dp[n-1][x] << endl;
	return (0);
}


