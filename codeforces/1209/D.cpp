#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e5+5;
ll const mod = 1e9+7;

// code begins here
vector<ll> v[maxn], vis(maxn);
ll cnt = 0;

void dfs(ll i){
    vis[i] = 1;
    cnt++;
    for(auto u: v[i]){
        if(!vis[u])
            dfs(u);
    }
}

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    for(ll i=0;i<k;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    ll ans = k;
    
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            cnt = 0;
            dfs(i);
            ans -= (cnt-1);
        }
    }
    
    cout<<max(ans, 0LL)<<endl;

    return 0;
}