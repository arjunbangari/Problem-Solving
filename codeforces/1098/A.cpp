#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> v[maxn], sum(maxn), a(maxn, inf), parent(maxn);
ll ans = 0;

void dfs(ll i,ll p, ll level){
    if(level%2==0){
        for(auto u: v[i])
            a[i] = min(a[i], sum[u]-sum[p]);
        if(a[i]==inf)
            a[i] = 0;
        sum[i] = a[i] + sum[p];
    } else {
        if(i!=1)
            a[i] = sum[i] - sum[p];
    }
    
    for(auto u: v[i])
        dfs(u, i, level+1);
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    for(ll i=2;i<=n;i++){
        cin>>parent[i];
        v[parent[i]].push_back(i);
    }
    
    for(ll i=1;i<=n;i++)
        cin>>sum[i];
    
    a[1] = sum[1];
    dfs(1,1, 1);
    
    ll ans = a[1];
    for(ll i=2;i<=n;i++){
        if(a[i]<0 || sum[i]<sum[parent[i]]){
            cout<<-1<<endl;
            return 0;
        }
        ans += a[i];
    }
    
    cout<<ans<<endl;
    
    return 0;
}