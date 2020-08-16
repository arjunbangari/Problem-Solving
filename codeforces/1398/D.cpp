#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

ll rr[205], gg[205], bb[205];
ll dp[205][205][205];

ll solve(ll r, ll g, ll b){
    if(dp[r][g][b]!=-1)
        return dp[r][g][b];
    
    ll res = 0;
    
    if(r && g)
        res = max(res, rr[r]*gg[g] + solve(r-1, g-1, b));
    
    if(g && b)
        res = max(res, gg[g]*bb[b] + solve(r, g-1, b-1));
    
    if(r && b)
        res = max(res, rr[r]*bb[b] + solve(r-1, g, b-1));
    
    dp[r][g][b] = res;
    return res;
}

int main(){
    fast;
    
    ll r,g,b;
    cin>>r>>g>>b;
    
    for(ll i=1;i<=r;i++)
        cin>>rr[i];
    
    for(ll i=1;i<=g;i++)
        cin>>gg[i];
    
    for(ll i=1;i<=b;i++)
        cin>>bb[i];
    
    for(ll i=0;i<205;i++)
        for(ll j=0;j<205;j++)
            for(ll k=0;k<205;k++)
                dp[i][j][k] = -1;
    
    sort(rr+1, rr+r+1);
    sort(gg+1, gg+g+1);
    sort(bb+1, bb+b+1);
    
    ll ans = solve(r, g, b);
    
    cout<<ans<<endl;
    
    return 0;
}