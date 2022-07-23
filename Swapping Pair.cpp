#define ll long long
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> set, int n, int sum)
{
   
    bool subset[n + 1][sum + 1];

   
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

 
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }


    return subset[n][sum];
}

void solve()
{
    int n;
    int m;
    vector<pair<int,int>> a;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        a.push_back({x,y});
    }
    int ans = 0;


    for (int i = 0; i < n; i++)
    {
        // cout<<a[i].first<<" "<<a[i].second<<endl;
        int mn = min(a[i].first, a[i].second);
        ans += mn;
        a[i].first -= mn;
        a[i].second -= mn;
        // cout<<a[i].first<<" "<<a[i].second<<endl;
    }


    int val = m-ans;
    // cout<<val<<endl;


    for(auto i:a)
    {
       
    }
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        arr[i] = max(a[i].first, a[i].second);

    bool ans1 = isSubsetSum(arr, n, val);
    if(ans1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


    
}
