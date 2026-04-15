#include <vector>
#include <string>
#include <iostream>
using namespace std;

string isRev(string &s, string &t)
{
    int st = 0, end = s.size() - 1;

    while (st < end)
    {
        swap(s[st++], s[end--]);
    }

    if (s == t)
        return "YES";
    else
        return "NO";
}

void main()
{
    string s, t;
    cin >> s;
    cin >> t;
    cout << isRev(s, t) << endl;
}
