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

ll n,m,k,s;
vector<ll> goods(maxn), v[maxn], vis(maxn), level(maxn), res(maxn);
vector<ll> ans[maxn];

void multisourcebfs(ll cur){
    for(ll i=1;i<=n;i++){
        vis[i] = 0;
        level[i] = 0;
    }
    
    queue<ll> q;
    
    for(ll i=1;i<=n;i++){
        if(goods[i]==cur){
            q.push(i);
            vis[i] = 1;
            level[i] = 0;
        }
    }
    
    while(!q.empty()){
        ll val = q.front();
        q.pop();
        
        for(auto u: v[val]){
            if(!vis[u]){
                q.push(u);
                vis[u] = 1;
                level[u] = level[val]+1;
            }
        }
    }
    
    for(ll i=1;i<=n;i++)
        ans[i].push_back(level[i]);
}

void solve(){
    for(ll i=1;i<=k;i++)
        multisourcebfs(i);
    
    for(ll i=1;i<=n;i++){
        sort(ans[i].begin(), ans[i].end());
        for(ll j=0;j<s;j++)
            res[i] += ans[i][j];
    }
}

int main(){
    fast;
    
    cin>>n>>m>>k>>s;
    
    for(ll i=1;i<=n;i++)
        cin>>goods[i];
    
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    solve();
    
    for(ll i=1;i<=n;i++)
        cout<<res[i]<<" ";
        
    return 0;
}