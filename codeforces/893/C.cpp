#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast;
    ll n,m,a,b;
    cin>>n>>m;
    ll gold[n+1];
    for(ll i=1;i<=n;i++)
        cin>>gold[i];
    vector<ll> v[n+1];
    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    ll ans = 0;
    
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            vis[i] = true;
            ll temp = gold[i];
            queue<ll> q;
            q.push(i);
            while(!q.empty()){
                ll val = q.front();
                q.pop();
                for(ll u: v[val]){
                    if(!vis[u]){
                        vis[u] = true;
                        q.push(u);
                        temp = min(temp,gold[u]);
                    }
                }
            }
            ans += temp;
        }
    }
    
    cout<<ans<<"\n";
    
    return 0;
}