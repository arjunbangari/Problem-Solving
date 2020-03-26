#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<ll> v[1005], roots;
ll vis[1005];

int main(){
    fast;
    
    ll n,a,b;
    cin>>n;
    
    for(ll i=0;i<n-1;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    memset(vis, 0, sizeof(vis));
    
    set<pair<ll,ll>> edges;
    
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            roots.push_back(i);
            
            queue<pair<ll,ll>> q;
            q.push({i,-1});
            vis[i] = 1;
            
            while(!q.empty()){
                auto val = q.front();
                q.pop();
                ll vertex = val.first, parent=val.second;
                
                for(ll u: v[vertex]){
                    if(!vis[u]){
                        q.push({u,vertex});
                        vis[u] = 1;
                    } else if(u!=parent)
                        edges.insert({min(vertex,u),max(u,vertex)});
                }
            }
            
        }
    }
    
    ll i=0;
    ll sz = roots.size();
    cout<<sz-1<<endl;
    for(auto u: edges){
        cout<<u.first<<" "<<u.second<<" ";
        cout<<roots[i]<<" "<<roots[i+1]<<endl;
        i++;
    }
    
    return 0;
}