#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,l;
    cin>>n>>l;
    
    vector<ll> cost(32);
    for(ll i=0;i<n;i++)
        cin>>cost[i];
    
    for(ll i=1;i<n;i++)
        cost[i] = min(cost[i], cost[i-1]*2);
    
    for(ll i=n;i<32;i++)
        cost[i] = 2*cost[i-1];
    
    ll ans = 0;
    
    for(ll i=0;i<32;i++){
        if(cost[i]<ans)
            ans = cost[i];
        if(l&(1<<i))
            ans += cost[i];
    }
    
    cout<<ans<<endl;
    
    return 0;
}