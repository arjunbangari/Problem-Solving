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

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    vector<ll> deg(n+1), vis(n+1), v[n+1];
    
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        deg[x]++;
        deg[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    ll ver, mx = 0;
    
    for(ll i=1;i<=n;i++){
        if(deg[i]>mx)
            ver = i;
        mx = max(mx, deg[i]);
    }
    
    queue<ll> q;
    q.push(ver);
    vis[ver] = 1;
    
    while(!q.empty()){
        ll val = q.front();
        q.pop();
        
        for(auto u: v[val]){
            if(vis[u])
                continue;
            cout<<val<<" "<<u<<endl;
            q.push(u);
            vis[u] = 1;
        }
    }
    
    return 0;
}