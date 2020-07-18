#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> order, vis(maxn), v[maxn];

void dfs(ll i){
    vis[i] = 1;
    for(auto u: v[i]){
        if(!vis[u])
            dfs(u);
    }
    order.push_back(i);
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        
        vector<pll> edges;
        order.clear();
        
        for(ll i=1;i<=n;i++){
            v[i].clear();
            vis[i] = 0;
        }
        
        for(ll i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            edges.push_back({b,c});
            if(a)
                v[b].push_back(c);
        }
        
        for(ll i=1;i<=n;i++){
            if(!vis[i])
                dfs(i);
        }
        
        reverse(order.begin(), order.end());
        vector<ll> pos(n+1);
        
        for(ll i=0;i<n;i++)
            pos[order[i]] = i;
            
        ll cycle = 0;
        for(ll i=1;i<=n;i++){
            for(auto u: v[i]){
                if(pos[u]<pos[i])
                    cycle = 1;
            }
        }
        
        if(cycle){
            cout<<"NO"<<endl;
            continue;
        }
        
        cout<<"YES"<<endl;
        
        for(auto u: edges){
            if(pos[u.first]>pos[u.second])
                swap(u.first, u.second);
            cout<<u.first<<" "<<u.second<<endl;
        }
    }
    
    
    return 0;
}