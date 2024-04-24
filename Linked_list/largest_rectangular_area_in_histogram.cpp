
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
        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }
        // chota element mil chuka h -> ans store
        ans[i] = s.top();

        // push kardo curr element ko
        s.push(i);
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
        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }
        // chota element mil chuka h -> ans store
        ans[i] = s.top();

        // push kardo curr element ko
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &height)
{
    // step1; prevsmaller oi=utput
    vector<int> prev = prevSmallerElement(height);

    // step 2 : nextsmaller cell
    vector<int> next = nextSmallerElement(height);

       int size = height.size();
    int maxArea = INT_MIN;
 

    for (int i = 0; i < height.size(); i++)
    {
        int length = height[i];

        if (next[i] == -1)
        {
            next[i] = size;
        }

        int width = next[i] - prev[i] - 1;

        int area = length * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    cout <<"Answer is "<<largestRectangleArea(v)<<endl;

                return 0;
}
