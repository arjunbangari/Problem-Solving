#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> v[maxn], vis(maxn), v1(maxn), v2(maxn), v3(maxn);

void bfs(ll i, vector<ll> &level){
    queue<ll> q;
    q.push(i);
    vis[i] = 1;
    level[i] = 0;
    
    while(!q.empty()){
        ll val = q.front();
        q.pop();
        for(auto u: v[val]){
            if(!vis[u]){
                vis[u] = 1;
                level[u] = level[val] + 1;
                q.push(u);
            }
        }
    }
}


int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,m,a,b,c,x,y;
        cin>>n>>m>>a>>b>>c;
        
        for(ll i=1;i<=n;i++)
            v[i].clear();
        
        vector<ll> prices(m+1);
        for(ll i=1;i<=m;i++)
            cin>>prices[i];
        
        prices[0] = 0; 
        sort(prices.begin(), prices.end());
        for(ll i=1;i<=m;i++)
            prices[i] += prices[i-1];
        
        
        for(ll i=0;i<m;i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        fill(vis.begin(), vis.begin() + n + 1, 0);
        bfs(a, v1);
        fill(vis.begin(), vis.begin() + n + 1, 0);
        bfs(b, v2);
        fill(vis.begin(), vis.begin() + n + 1, 0);
        bfs(c, v3);
        
        ll ans = inf;
        
        for(ll i=1;i<=n;i++){
            ll d1 = v1[i], d2 = v2[i], d3 = v3[i];
            if((d1 + d2 + d3)<=m){
                ll temp = prices[d2] + prices[d1 + d2 +d3];
                ans = min(ans, temp);
            }
        }
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}