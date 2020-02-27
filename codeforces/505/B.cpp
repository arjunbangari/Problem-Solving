#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll n,m;
vector<pair<ll,ll>> v[105];
ll vis[105];

void dfs(ll i, ll c){
    vis[i] = 1;
    for(auto u : v[i]){
        if(!vis[u.first] && u.second==c){
            dfs(u.first,c);
        }
    }
}

int main(){
    fast;
    ll a,b,c,q;
    cin>>n>>m;
    
    set<ll> s;
    
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        s.insert(c);
    }
    
    ll colors = s.size();
    
    cin>>q;
    
    while(q--){
        ll ans = 0;
        ll from, to;
        cin>>from>>to;
        
        for(auto i : s){
            memset(vis,0,sizeof(vis));
            dfs(from, i);
            if(vis[to])
                ans++;
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}