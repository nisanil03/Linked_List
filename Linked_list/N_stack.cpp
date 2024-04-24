#include <bits/stdc++.h>
using namespace std;
class Nstack
{
    int *a, *top, *next;
    int n;         // no of stack
    int size;      // size of main array
    int freesport; // tells free space in main array

public:
    Nstack(int _n, int _s) : n(_n), size(_s)
    {
        freesport = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
    }
    // push X into Mth stack.
    bool push(int X, int M)
    {
        if (freesport == -1)
        {
            return false; // stack overflow
        }

        // 1. find index
        int index = freesport;

        // 2.update freespot
        freesport = next[index];

        // 3. insert
        a[index] = X;

        // 4. update next
        next[index] = top[M - 1];

        // update top
        top[M - 1] = index;

        return true; // push success.
    }
    // pop form Mth stack.

    int pop(int M)
    {
        if (top[M - 1] == -1)
        {
            return -1; // stack overflow
        }
        int index = top[M - 1];

        top[M - 1] = next[index];
        int popedElement = a[index];

        next[index] = freesport;
        freesport = index;

        return popedElement;
    }

    ~Nstack()
    {
        delete[] a;
        delete[] top;
        delete[] next;
    }
};
int main()
{
    Nstack s(3, 6);
    cout << s.push(10, 1) << endl;
    cout << s.push(10, 1) << endl;
    cout << s.push(10, 1) << endl;
    cout << s.push(10, 1) << endl;
    cout << s.push(10, 1) << endl;
    cout << s.push(10, 1) << endl;
    cout << s.pop(1) << endl;
    return 0;
}