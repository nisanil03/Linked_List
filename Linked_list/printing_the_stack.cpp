
// printing the stack or reverse the stack ka dono same hi hota hai
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.empty())
    {
        cout << "Top element is " << s.top() << endl;
        s.pop();
    }
    return 0;
}