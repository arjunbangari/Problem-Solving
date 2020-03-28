#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<ll> v[200005], tin(200005), tout(200005);
ll level[200005], parent[200005], vis[200005];
ll t;

void dfs(ll i, ll depth=0){
    vis[i] = 1;
    tin[i] = t++;
    level[i] = depth;
    for(ll u: v[i]){
        if(!vis[u]){
            parent[u] = i;
            dfs(u, depth+1);
        }
    }
    
    tout[i] = t++;
}

int main(){
    fast;
    
    ll n,m,x,y;
    cin>>n>>m;
    
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    t = 0;
    parent[1] = 1;
    dfs(1);
    
    while(m--){
        ll k;
        cin>>k;
        
        ll vertices[k];
        for(ll i=0;i<k;i++)
            cin>>vertices[i];
        
        ll mx=-1, node;
        for(ll i=0;i<k;i++){
            if(level[vertices[i]]>mx)
                node = vertices[i];
            mx = max(mx, level[vertices[i]]);
        }
        
        for(ll i=0;i<k;i++)
            vertices[i] = parent[vertices[i]];
        
        ll flag = 0;
        
        for(ll i = 0;i<k;i++ ){
            if(tin[vertices[i]]<=tin[node] && tout[vertices[i]]>=tout[node])
                continue;
            else{
                flag = 1;
                break;
            }
        }
        
        cout<< ( flag ? "NO" : "YES" )<<endl;
    }
    
    return 0;
}