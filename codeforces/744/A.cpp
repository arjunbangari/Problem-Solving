#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<ll> v[1005];
ll vis[1005];
ll temp;

void dfs(ll i){
    vis[i]=1;
    temp++;
    for(ll u: v[i])
        if(!vis[u])
            dfs(u);
}

int main(){
    fast;
    
    ll n,m,k,x,y;
    cin>>n>>m>>k;
    
    ll special[k];
    map<ll,ll> mp;
    
    memset(vis, 0, sizeof(vis));
    
    for(ll i=0;i<k;i++)
        cin>>special[i];
    
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for(ll i=0;i<k;i++){
        temp = 0;
        dfs(special[i]);
        mp[special[i]] = temp;
    }
    
    // for(ll i=0;i<k;i++)
    //     cout<<mp[special[i]]<<endl;
    
    ll extra_nodes=0; // extra_edges = 0;
    
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            extra_nodes++;
            //extra_edges += (ll)v[i].size();
        }
    }
    
    //extra_edges /= 2;
    
    ll mx=-1, large_k;
    
    for(ll i=0;i<k;i++){
        if(mp[special[i]]>mx)  
            large_k = special[i];
        mx = max(mx, mp[special[i]]);
    }
    
    mp[large_k] += extra_nodes;
    
    ll total = 0;
    total += (mp[large_k]*(mp[large_k]-1))/2;
    
    for(ll i=0;i<k;i++)
        if(special[i]!=large_k)
            total += (mp[special[i]]*(mp[special[i]]-1))/2;
        
    cout<<total - m<<endl;
    
    
    return 0;
}