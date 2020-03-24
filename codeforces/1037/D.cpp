#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
map<ll,ll> mp;

bool compare(ll i, ll j){
    return mp[i]<mp[j];
}

int main(){
    fast;
    
    ll n,x,y;
    cin>>n;
    
    vector<ll> v[n+1];
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    // for(ll i=1;i<=n;i++)
    //     cout<<i<<" : ";
    //     for(ll j : v[i])
    //         cout<<j<<" ";
    //     cout<<endl;
    // }
    
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]] = i;
    }
    
    for(ll i=1;i<=n;i++)
        sort(v[i].begin(), v[i].end(), compare);
    
    ll vis[n+1] = {0};
    ll level[n+1] = {0};

    queue<ll> q;
    q.push(1);
    vector<ll> ans;
    vis[1] = 1;
    
    while(!q.empty()){
        ll val = q.front();
        ans.push_back(val);
        q.pop();
        for(ll u: v[val]){
            if(!vis[u]){
                q.push(u);
                vis[u] = 1;
                level[u] = level[val]+1;
            }
        }
    }
    
    // cout<<endl;
    // for(ll i=0;i<n;i++)
    //     cout<<ans[i]<<" ";
    // cout<<endl;
    
    for(ll i=0;i<n;i++){
        if(ans[i]!=arr[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    
    
    
    return 0;
}