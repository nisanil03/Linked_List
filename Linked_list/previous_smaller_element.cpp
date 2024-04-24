// move left to right approach

#include <bits/stdc++.h>
using namespace std;
vector<int> prevSmallerElement(vector<int> &v)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(v.size());
    // left to right ->prev smaller element

    for (int i = 0; i < v.size(); i++)
    {
        int curr = v[i];
        // apka answer stack me
        while (s.top() >= curr)
        {
            s.pop();
        }
        // chota element mil chuka h -> ans store
        ans[i] = s.top();

        // push kardo curr element ko
        s.push(curr);
    }
    return ans;
}
vector<int> nextSmallerElement(vector<int> &v)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    for (int i = v.size() - 1; i >= 0; i--)
    {
        int curr = v[i];
        // apka answer stack me
        while (s.top() >= curr)
        {
            s.pop();
        }
        // chota element mil chuka h -> ans store
        ans[i] = s.top();

        // push kardo curr element ko
        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> v;

    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(7);

    vector<int> ans1 = nextSmallerElement(v);

    cout << "printing the ans1" << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;

    vector<int> ans2 = prevSmallerElement(v);
    cout << "printing the ans2" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << ans2[i] << " ";
    }
    cout << endl;

    return 0;
}