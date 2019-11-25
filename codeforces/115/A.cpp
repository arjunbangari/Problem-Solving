#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    ll n,p;
    cin>>n;
    ll level[2002] = {0};
    bool vis[2002];
    memset(vis, false, sizeof(vis));
    vector<ll> adj[2002];
    vector<ll> root;
    
    for(ll i=1;i<=n;i++){
        cin>>p;
        if(p!=-1){
            adj[p].push_back(i);
        } else {
            root.push_back(i);
        }
    }
    
    for(ll j: root){
        if(!vis[j]){
            std::queue<ll> q;
            q.push(j);
            vis[j] = true;
            
            while(!q.empty()){
                ll temp = q.front();
                q.pop();
                for(ll i: adj[temp]){
                    if(!vis[i]){
                        q.push(i);
                        vis[i] = true;
                        level[i] = level[temp]+1;
                    }
                }
            }
        }
    }
    ll ans = *max_element(level,level+2002);
    cout<<++ans<<"\n";
    return 0;
}
