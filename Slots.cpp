#define ll long long
#define ss second
#define ff first
#define pb push_back
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

ll freq[15];
ll n,k;
vector<pair<ll,ll>> v[25];
ll dp[25];
ll solve(int i){
  if(i==n) return 0;
  if(dp[i]!=-1) return dp[i];
  ll ans=-1;
  for(int j=0;j<k;j++){
    if(freq[j]==2) continue;
    freq[v[i][j].ss]++;
    ans=max(ans,v[i][j].ff+solve(i+1));
    freq[v[i][j].ss]--;
  }
  return dp[i]=ans;
}
int main(){
  
  int t;
  cin>>t;
  while(t--){
    cin>>n>>k;
    for(int i =0;i<=n-1;i++) v[i].clear();
    ll a[n];
    read(a,n);
    for(int j=0;j<=n-1;j++){
      for(int i=1;i<=k;i++){
        int x=(a[j]&i);
        v[j].pb({x,i});
      }      
    }
    for(int i=0;i<n;i++) dp[i]=-1;
    cout<<solve(0)<<endl;
  }
}

