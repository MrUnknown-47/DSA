#include <iostream>
#include <vector>
using namespace std;

int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

int fibDP(int n, vector<int> &f)
{
    if (n <= 1)
        return n;

    if (f[n] != -1)
        return f[n];

    return f[n] = fibDP(n - 1, f) + fibDP(n - 2, f);
}

int fibTabDP(int n)
{

    int prev2 = 0, prev1 = 1;
    int result = prev1;

    for (int i = 2; i <= n; i++)
    {
        result = prev1 + prev2;
        prev2 = prev1;
        prev1 = result;
    }
    return result;
}

int main()
{
    int n = 6;
    vector<int> f(n + 1, -1);
    cout << fibTabDP(n) << endl;
}