#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

// #define DEBUG
#define MOD 1000000007

bool    unique_nums(int a, int b)
{
    int nums[10] = {0};
    for (int i = 0; i < 5; i++)
    {
        int dig;

        dig = a % 10;
        nums[dig]++;
        a /= 10;
    }
    for (int i = 0; i < 5; i++)
    {
        int dig;

        dig = b % 10;
        nums[dig]++;
        b /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        if (nums[i] > 1)
            return (false);
    }
    return true;
}

bool unique_nums(int a)
{
    int nums[10] = {0};
    for (int i = 0; i < 5; i++)
    {
        int dig;

        dig = a % 10;
        nums[dig]++;
        a /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        if (nums[i] > 1)
            return (false);
    }
    return true;
}

bool    solve(int n)
{
    bool solution = false;
    for (int i = 1234; i < 98765; i++)
    {
        if (!unique_nums(i))
            continue;
        int possible_number;

        possible_number = n * i;
        if (possible_number <= 98765 && unique_nums(i, possible_number))
        {
            printf("%5.5d / %5.5d = %d\n", possible_number, i, n);
            solution = true;
        }
    }
    return solution;
}

int main(void)
{
    int n;
    
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        if (!solve(n))
            printf("There are no solutions for %d.\n", n);
        printf("\n");
    }
    return (0);
}