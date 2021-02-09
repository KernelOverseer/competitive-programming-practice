#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

// #define DEBUG
#define MOD 1000000007

vector<string> names = {
    "Beatrice",
    "Belinda",
    "Bella",
    "Bessie",
    "Betsy",
    "Blue",
    "Buttercup",
    "Sue"
};

vector<string> perm_names = {
    "Beatrice",
    "Belinda",
    "Bella",
    "Bessie",
    "Betsy",
    "Blue",
    "Buttercup",
    "Sue"
};

bool besides[8][8];

int get_cow_index(string &s)
{
    for (int i = 0; i < 8; i++)
    {
        if (names[i] == s)
            return i;
    }
    return 0;
}


bool    is_permutation_good(void)
{
    int current, before, after;
    for (uint i = 0; i < 8; i++)
    {
        current = get_cow_index(perm_names[i]);
        before = i-1;
        after = i+1;
        if (before >= 0)
            before = get_cow_index(perm_names[before]);
        if (after < 8)
            after = get_cow_index(perm_names[after]);

        for (uint j = 0; j < 8; j++)
        {
            if (besides[current][j])
            {
                // cout << "cow ";
                // if (before >= 0)
                //    cout << names[before] << " <- ";
                // cout << names[current];
                // if (after < 8)
                //     cout << " -> " << names[after] << endl;
                if ((j != before || before < 0) && (j != after || after >= 8))
                {
                    // cout << "is not close to " << names[j] << endl;
                    return (false);
                }
                else
                {
                    // cout << "is close to " << names[j] << endl;
                }
            }
        }
    }
    return (true);
}

void solve(void)
{
    do{
        if (is_permutation_good())
        {
            return ;
        }
    }while(next_permutation(perm_names.begin(), perm_names.end()));
}

int main(void)
{
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    int n;
    string s;

    cin >> n;
    while (n--)
    {
        string cow1;
        string cow2;
        int c1, c2;
        cin >> cow1 >> s >> s >> s >> s >> cow2;
        c1 = get_cow_index(cow1);
        c2 = get_cow_index(cow2);
        besides[c1][c2] = true;
        besides[c2][c1] = true;
    }
    solve();
    for (int i = 0; i < 8; i++)
        cout << perm_names[i] << endl;
    return (0);
}