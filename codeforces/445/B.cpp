#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    ll n,m,x,y;
    cin>>n>>m;
    
    vector<ll> adj[51];
    bool vis[51] = {false};
    
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll count = 0;
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            count++;
            stack<ll> s;
            s.push(i);
            vis[i] = true;
            while(!s.empty()){
                ll val = s.top();
                s.pop();
                for(ll j: adj[val]){
                    if(!vis[j]){
                        vis[j] = true;
                        s.push(j);
                    }
                }
            }
        }
    }
    ll ans=1;
    //cout<<count<<"\n";
    for(ll i=0;i<(n-count);i++)
        ans*=2;
    cout<<ans<<"\n";
 
    return 0;
}
