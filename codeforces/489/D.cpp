#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 2e6+5;
ll const mod = 1e9+7;
 
// code begins here
vector<ll> v[maxn], cnt(maxn);
 
void dfs(ll i, ll lv = 0){
    if(lv==2){
        cnt[i]++;
        return;
    }
    for(auto u: v[i])
        dfs(u, lv+1);
} 
 
int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    while(m--){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    
    ll ans = 0;
    
    dfs(1);
    
    for(ll i=1;i<=n;i++){
        cnt.assign(n+5, 0);
        dfs(i);

        for(ll j=1;j<=n;j++){
            if(i==j)
                continue;
            ans += (cnt[j]*(cnt[j]-1))/2;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}