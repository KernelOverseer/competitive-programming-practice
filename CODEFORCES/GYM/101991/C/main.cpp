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
    freopen("coffee.in", "r", stdin);
    int t;
    uint n, p;
    cin >> t;
    while (t--)
    {
        uint a, b, c;
        string s;
        cin >> n >> p;
        int delivery_fees = 100/p;
        map <string, uint[3]> coffes;
        map <string, int> to_pay;
        set<string> names_check;
        vector<string> names;
        for (uint i = 0; i < n; i++)
        {
            cin >> s >> a >> b >> c;
            coffes[s][0] = a;
            coffes[s][1] = b;
            coffes[s][2] = c;
        }
        for (uint i = 0; i < p; i++)
        {
            int tyIndex;
            string s, ty, co;
            cin >> s >> ty >> co;
            if (ty == "small")
                tyIndex = 0;
            else if (ty == "medium")
                tyIndex = 1;
            else
                tyIndex = 2;
            int price = coffes[co][tyIndex];
            to_pay[s] += price;
            if (names_check.find(s) == names_check.end())
            {
                names_check.insert(s);
                names.push_back(s);
            }
        }
        for (auto s : names)
        {
            int price = to_pay[s] + delivery_fees;
            if (price % 10 == 6 || price % 10 == 1)
                price--;
            else if (price % 10 == 4 || price % 10 == 9)
                price++;
            cout << s << " "  << price << endl;
        }
    }
}