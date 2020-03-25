#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<ll> v[200005], used_colors;
ll max_color;
ll vis[200005], colors[200005];

void dfs(ll i, ll parent){
    vis[i] = 1;
    auto it = used_colors.begin();
    for(ll u : v[i]){
        if(!vis[u]){
            while(it!=used_colors.end()){
                if(*it!=colors[i] && *it!=colors[parent]){
                    colors[u] = *it;
                    it++;
                    break;
                }
                it++;
            }
            if(!colors[u]){
                max_color++;
                colors[u] = max_color;
                used_colors.push_back(max_color);
                it = used_colors.end();
            }
        }
    }
    
    for(ll u: v[i])
        if(!vis[u])
            dfs(u,i);
}

int main(){
    fast;
    
    ll n,x,y;
    cin>>n;
    
    for(ll i=0;i<n-1;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    memset(vis, 0, sizeof(vis));
    memset(colors, 0, sizeof(colors));
    
    colors[1] = 1;
    colors[0] = 0;
    max_color = 1;
    used_colors.push_back(1);

    dfs(1,0);
    
    cout<<max_color<<endl;
    for(ll i=1;i<=n;i++)
        cout<<colors[i]<<" ";
    
    return 0;
}