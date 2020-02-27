#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m,x,y;
    cin>>n>>m;
    vector<ll> v[n+1];
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    ll vis[n+1] = {0};
    vector<ll> ans;
    
    set<ll> s;
    s.insert(1);
    vis[1] = 1;
    
    while(!s.empty()){
        ll val = *s.begin();
        s.erase(*s.begin());
        ans.push_back(val);
        
        for(ll u: v[val]){
            if(!vis[u]){
                vis[u] = 1;
                s.insert(u);
            }
        }
    }
    
    for(ll i=0;i<n;i++)
        cout<<ans[i]<<" ";

    return 0;
}