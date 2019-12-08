
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, k, n, m, sum = 0, h;
    cout << "Enter the max size of disk:\n";
    cin >> m;
    cout << "Enter the number of requests:\n";
    cin >> n;
    cout << "Enter the requests:\n";
    std::vector<int> a(n), b;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] > m)
        {
            cout << "Error" << a[i] << "\n";
            return 0;
        }
    }

    cout << "Enter the head positon\n";
    cin >> h;
    int temp = h;
    a.push_back(h);
    a.push_back(m);
    sort(a.begin(), a.end());
    for (i = 0; i < a.size(); i++)
    {
        if (h == a[i])
            break;
    }
    k = i;
    if (k<n / 2)
    {
        for (i = k; i < a.size(); i++)
        {
            b.push_back(a[i]);
        }
    }
        b.push_back(0);
    for (i = 0; i <=k-1; i++)
    {
            b.push_back(a[i]);
    }

    temp = b[0];
    cout << temp;
    for (i = 1; i < b.size(); i++)
    {
        cout << " -> " << b[i];
        sum += abs(b[i] - temp);
        temp = b[i];
    }
    cout << '\n';
    cout << "Total head movements = " << sum << '\n';
    cout << "Average head movements = " << (float)sum / n << '\n';
    return 0;
}
