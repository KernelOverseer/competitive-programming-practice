#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

// #define DEBUG
#define MOD 1000000007

typedef pair<int, int> pp;

pp maximum(pp a, pp b)
{
    pp result;
    if (a.second > b.second)
        result.second = a.second;
    else
        result.second = b.second;
    if (a.first > b.first)
        result.first = a.first;
    else
        result.first = b.first;
    return result;
}

int solve(vector< vector< pair<int, int> > > &dp, vector <pair<int, int>> &icecream, uint n, uint k)
{
    for (uint j = 0; j < k; j++)
    {
        for (uint i = 0; i < n; i++)
        {
            pp base_score = make_pair(0, 0);
            pp purchased_score = make_pair(0, 0);
            if (i > 0)
                base_score = dp[i-1][j];
            // if icecream is purchased
            if (j >= icecream[i].first)
            {
                purchased_score = make_pair(max(base_score.first, icecream[i].first), base_score.second+icecream[i].second);
                int money_left = j - icecream[i].first;
                if (money_left >= 0 && i > 0)
                {
                    purchased_score.first += dp[i-1][money_left].first;
                    purchased_score.second += dp[i-1][money_left].second;
                }
            }
            dp[i][j] = maximum(base_score, purchased_score);
        }
    }
    return ();
}

int main(void)
{
    freopen("icecream.in", "r", stdin);
    int t;
    uint n, k;

    cin >> t;
    while(t--)
    {
        uint temp;
        cin >> n >> k;
        vector <pair<int, int>> icecream(n);
        for (uint i = 0; i < n; i++)
            cin >> icecream[i].first;
        for (uint i = 0; i < n; n++)
            cin >> icecream[i].second;
        vector< vector< pair<int, int> > > dp(n, vector< pair<int, int> >(k));
        solve(dp, icecream, n, k);
    }
}