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
    
    ll x,n;
    cin>>x>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    set<ll> s;
    for(auto u: arr)
        s.insert(u);
    
    ll mx = inf, ans = inf;
    
    for(ll i=-200;i<=200;i++){
        if(s.count(i))
            continue;
        if(abs(i-x)<mx){
            mx = abs(i-x);
            ans = i;
        } 
        if(abs(i-x)==mx){
            ans = min(ans, i);
        }
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}
