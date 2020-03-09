#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll n,t;
vector<ll> v[100000];
ll vis[100000];

void dfs(ll i){
    vis[i] = 1;
    for(ll u: v[i])
        if(!vis[u])
            dfs(u);
}

int main(){
    fast;
    cin>>n>>t;
    ll arr[n+1];
    
    for(ll i=1;i<n;i++){
        cin>>arr[i];
        v[i].push_back(i+arr[i]);
    }
    
    memset(vis,0,sizeof(vis));

    dfs(1);
    
    if(vis[t])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}