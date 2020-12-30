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
#include <time.h>
#include <unistd.h>

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

int     minimum_depth = INT_MAX;
int     minimum_steps[1000001];
int     depth = 0;

int substract_digit_from_number(int number)
{
    int result = INT_MAX;

    // depth++;
    // for (int k = 1; k < depth; k++)
    // {
    //     cout << "  ";
    // }
    // cout << "checking number " << number << endl;
    // sleep(1);
    if (number < 0)
        return INT_MAX - 1;
    if (minimum_steps[number] != -1)
    {
        // cout << "Already has value for " << number << endl;
        return (minimum_steps[number]);
    }
    string num_str = to_string(number);
    int digit;
    for (int i = num_str.size() - 1; i >= 0; i--)
    {
        digit = num_str[i] - '0';
        // cout << "will check " << number << " - " << digit << endl;
        if (digit != 0)
            result = min(result, 1 + substract_digit_from_number(number - digit));
        // cout << "Checked" << endl;
    }
    // cout << "Storing value for " << number << endl;
    minimum_steps[number] = result;
    // depth--;
    return result;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    uint number;
    cin >> number;
    for (uint i = 0; i < 1000001; i++)
        minimum_steps[i] = -1;
    minimum_steps[0] = 0;
    substract_digit_from_number(number);
    cout << minimum_steps[number] << endl;
	return (0);
}


