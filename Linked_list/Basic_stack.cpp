#include <bits/stdc++.h>
using namespace std;
int main()
{
    // creation
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // remove
    st.pop();

    // cleck element
    cout << "Element on top is :" << st.top() << endl;

    // size
    cout << "Size of is :" << st.size() << endl;

    // stack isempty or not checked
    if (st.empty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not empty" << endl;

        
    return 0;
}