#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

// #define DEBUG
#define MOD 1000000007

int main(void)
{
    uint n;
    uint a, d;
    vector < pair<int, int> > cows;

    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    cin >> n;
    for (uint i = 0; i < n; i++)
    {
        cin >> a >> d;
        cows.push_back(make_pair(a, d));
    }
    sort(cows.begin(), cows.end());
    int last_finished = 0;
    for (uint i = 0; i < n; i++)
    {
        a = cows[i].first;
        if (a < last_finished)
            a = last_finished;
        last_finished = a + cows[i].second;
    }
    cout << last_finished << endl;
    return (0);
}