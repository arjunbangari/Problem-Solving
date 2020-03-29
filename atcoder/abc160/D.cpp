#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,x,y;
    cin>>n>>x>>y;
    
    vector<ll> v[n+1];
    
    v[1].push_back(2);
    v[n].push_back(n-1);
    for(ll i=2;i<n;i++){
        v[i].push_back(i-1);
        v[i].push_back(i+1);
    }
    
    v[x].push_back(y);
    v[y].push_back(x);
    
    ll ans[n+1] = {0};
    
    for(ll i=1;i<=n;i++){
        queue<ll> q;
        ll vis[n+1] = {0}, level[n+1] = {0};
        q.push(i);
        vis[i] = 1;
        
        while(!q.empty()){
            ll val = q.front();
            q.pop();
            ans[level[val]]++;
            for(ll u: v[val]){
                if(!vis[u]){
                    q.push(u);
                    vis[u] = 1;
                    level[u] = level[val] + 1;
                }
            }
        }
    }
    
    for(ll i=1;i<n;i++)
        cout<<ans[i]/2<<endl;
    
    return 0;
}