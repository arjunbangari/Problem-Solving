#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    ll n,m,x,y;
    cin>>n>>m;
    ll arr[100002];
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    vector<ll> adj[100002];
    ll level[100002] = {0};
    bool vis[100002] = {false};
    ll cats[100002] = {0};
    vector<ll> leaves;
    
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    queue<ll> q;
    q.push(1);
    level[1] = 0;
    vis[1] = true;
    
    if(arr[1])
        cats[1] = 1;
    
    while(!q.empty()){
        ll val = q.front();
        q.pop();
        ll count=0;
        for(ll i: adj[val]){
            if(!vis[i]){
                q.push(i);
                level[i] = level[val]+1;
                vis[i] = true;
                
                if(cats[val]>m)
                    cats[i] = cats[val];
                else{
                    if(arr[i])
                        cats[i] = cats[val] + arr[i];
                    else
                        cats[i] = 0;
                }
            } else count++;
        }
        if(count==adj[val].size())
            leaves.push_back(val);
    }
    
    ll ans=0;
    for(ll i: leaves){
        if(cats[i]<=m)
            ans++;
    }
    //for(ll i=1;i<=n;i++)
    //    cout<<cats[i]<<" "<<level[i]<<"\n";;
    cout<<ans<<"\n";
    
    return 0;
}
