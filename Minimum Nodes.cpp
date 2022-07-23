#include<bits/stdc++.h> 
using namespace std; 
int solve(vector<int> a) 
{ 
    int ans = 0; 
    for(int i = 0; i < a.size() ; i++) 
        ans += a[i]; 
    return ans; 
} 
int solve(vector<int> a, vector<int> b) 
{ 
    int ans = 0; 
    for(int i = 0; i < a.size() ; i++){ 
        int mn = min(a[i], b[i]); 
        ans += mn; 
        a[i] -= mn; 
        b[i] -= mn; 
    } 
    return ans + solve(a) + solve(b); 
} 
int solve(vector<int> a, vector<int> b, vector<int> c) 
{ 
    int ans = 0; 
    for(int i = 0; i < a.size() ; i++){ 
        int mn = min({a[i], b[i], c[i]}); 
        ans += mn; 
        a[i] -= mn; 
        b[i] -= mn; 
        c[i] -= mn; 
    } 
    int val = solve(a) + solve(b, c); 
    val = min(val, solve(b) + solve(a, c)); 
    val = min(val, solve(c) + solve(a, b)); 
    return ans + val; 
} 
int solve(vector<int> a, vector<int> b, vector<int> c, vector<int> d) 
{ 
    int ans = 0; 
    for(int i = 0; i < a.size() ; i++){ 
        int mn = min({a[i], b[i], c[i], d[i]}); 
        ans += mn; 
        a[i] -= mn; 
        b[i] -= mn; 
        c[i] -= mn; 
        d[i] -= mn; 
    } 
    int val = solve(a) + solve(b, c, d); 
    val = min(val, solve(b) + solve(a, c, d)); 
    val = min(val, solve(c) + solve(a, b, d)); 
    val = min(val, solve(d) + solve(a, b, c)); 
    val = min(val, solve(a, b) + solve(c, d)); 
    val = min(val, solve(a, c) + solve(b, d)); 
    val = min(val, solve(a, d) + solve(b, c)); 
    return ans + val; 
} 
long long solve (int N, vector<vector<int> > cnt) { 
    // Write your code here 
    int i, j, k, l; 
    int ans = 1e9; 
    assert(4 <= N && N <= 20); 
    for(i = 0; i < N ; i++) 
        for(j = 0; j < 26 ; j++) 
            assert(0 <= cnt[i][j] && cnt[i][j] <= 100000); 
    for(i = 0; i < N ; i++) 
        for(j = i+1; j < N ; j++) 
            for(k = j + 1 ; k < N ; k++) 
                for(l = k + 1 ; l < N ; l++){ 
                    ans = min(ans, solve(cnt[i], cnt[j], cnt[k], cnt[l])); 
                } 
    return (1 + ans); 
} 
 
int main() { 
 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    assert(1 <= T && T <= 5); 
    for(int t_i = 0; t_i < T; t_i++) 
    { 
        int N; 
        cin >> N; 
        vector<vector<int> > cnt(N, vector<int>(26)); 
        for (int i_cnt = 0; i_cnt < N; i_cnt++) 
        { 
            for(int j_cnt = 0; j_cnt < 26; j_cnt++) 
            { 
                cin >> cnt[i_cnt][j_cnt]; 
            } 
        } 
 
        long long out_; 
        out_ = solve(N, cnt); 
        cout << out_; 
        cout << "\n"; 
    } 
}
