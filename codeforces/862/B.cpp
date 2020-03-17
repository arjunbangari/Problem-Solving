#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<ll> v[100005];
ll vis[100005];
ll side[100005];

void dfs(ll i){
    vis[i] = 1;
    for(ll u : v[i]){
        if(!vis[u]){
            side[u] = !side[i];
            dfs(u);
        }
    }
}

int main(){
    fast;
    ll n,a,b;
    cin>>n;
    side[1] = 0;
    memset(vis, 0, sizeof(vis));
    
    for(ll i=0;i<n-1;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(1);
    
    ll x=0,y=0;
    for(ll i=1;i<=n;i++)
        side[i] ? x++ : y++ ;
    
    ll ans = x*y - n + 1;
    
    cout<<ans<<endl;
    
    return 0;
}