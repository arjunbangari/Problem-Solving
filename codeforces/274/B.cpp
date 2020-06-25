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
vector<ll> v[maxn], values(maxn), add(maxn), sub(maxn);
 
void dfs(ll i, ll p=0){
    ll mx1 = 0;
    ll mx2 = 0;
    
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs(u, i);
        mx1 = max(mx1, add[u]);
        mx2 = max(mx2, sub[u]);
    }
    
    ll final = values[i] + mx1 - mx2;
    if(final>0)
        sub[i] += abs(final);
    if(final<0)
        add[i] += abs(final);
        
    add[i] += mx1;
    sub[i] += mx2;
} 
 
int main(){
    fast;
    
    ll n;
    cin>>n;
    
    for(ll i=1;i<n;i++){
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(ll i=1;i<=n;i++)
        cin>>values[i];
    
    dfs(1);
    
    cout<<add[1]+sub[1]<<endl;
    
    return 0;
}