//10799 쇠막대기 https://www.acmicpc.net/problem/10799

#include <iostream>
//#include <stack>
using namespace std;

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    char c;
    //stack<char> s;
    int s = 0;
    bool just_opened = false;
    while (cin >> c)
    {
        if (c == '(')
        {
            s++;
            just_opened = true;
        }
        else if (c == ')')
        {
            s--;
            if (just_opened)
            {
                n += s;
            }
            else
            {
                n++;
            }
            //cout << n << endl;
            just_opened = false;
        }
    }
    cout << n;
    return 0;
}