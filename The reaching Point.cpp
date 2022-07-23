#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int cur;
int cst;
int ans=0;
int n,m;
int mat[101][101];
int c,d;

class Solution {
public:
    void bfs(int u,int v,int cst){
    if(cst<=4){
        if((mat[u-1][v-1]%mat[c-1][d-1])==0){
            if(ans!=1&&cst==4&&(u!=c&&v!=d)){
                
            }
            else
            ans = 1;
        }
    }
    else{
        return;
    }
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    for(int i=0;i<4;i++){
        int nu = u+dx[i];
        int nv = v+dy[i];
        if(nu<=n&&nu>0&&nv>0&&nv<=m){
            bfs(nu,nv,cst+1);
        }
    }
}
    
void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b>>c>>d;
        cst = 0;
        ans = 0;
        bfs(a,b,cst);
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
};