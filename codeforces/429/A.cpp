#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<ll> v[100005], res;
ll init[100005], goal[100005], parent[100005], cnt[100005];
ll ans = 0;

void dfs(ll i){
    cnt[i] = cnt[parent[parent[i]]];
    init[i] = init[i]^(cnt[i]%2);
    if(init[i]!=goal[i]){
        cnt[i]++;
        ans++;
        res.push_back(i);
    }
    for(ll u: v[i]){
        if(u!=parent[i]){
            parent[u] = i;
            dfs(u);
        }
    }
    
    
}

int main(){
    fast;
    
    ll n, x, y;
    cin>>n;
    
    for(ll i=0;i<n-1;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for(ll i=1;i<=n;i++)
        cin>>init[i];
    
    for(ll i=1;i<=n;i++)
        cin>>goal[i];
        
    memset(cnt,0 , sizeof(cnt));    
    
    parent[1] = 0;
    parent[0] = 0;
    cnt[0] = 0;
    dfs(1);
    
    cout<<ans<<endl;
    for(ll u: res)
        cout<<u<<endl;
    
    return 0;
}