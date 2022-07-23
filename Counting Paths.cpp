#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define SS(a) sort(a.begin(),a.end());
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
const int N=1e5+10;
bool isvalid(int x,int y,int N,int M)
{
    if(x>=1 && y>=1 && x<=N && y<=M)
    {
        return true;
    }
    return false;
}
void func(int x,int y,int sum,vector<vector<int>>&vec,int N,int M,int k,int &ans)
{
    if(!isvalid(x,y,N,M))
    {
        return;
    }
    if(x==N && y==M && (sum+vec[x][y])%k==0)
    {
        ans++;
    }
    func(x+1,y,sum+vec[x][y],vec,N,M,k,ans);
    func(x,y+1,sum+vec[x][y],vec,N,M,k,ans);
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin>>tc;
    //double pi=3.14159265358979323846;

    rep(i,tc)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>vec(n+1,vector<int>(m+1));
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                cin>>vec[j][k];
            }
        }
        int d;
        cin>>d;
        int ans=0;
        func(1,1,0,vec,n,m,d,ans);
        cout<<ans<<endl;

    }


    return 0;
}
