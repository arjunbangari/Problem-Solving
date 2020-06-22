#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,k,s;
    cin>>n>>k>>s;
    
    if(s<k || s>(n-1)*k){
        cout<<"NO"<<endl;
        return 0;
    }
    
    vector<ll> ans(k, 1);
    
    s -= k;
    
    for(ll i=0;i<k;i++){
        ans[i] += min(n-2, s);
        s -= min(n-2, s);
    }
    
    cout<<"YES"<<endl;
    
    ll cur = 1, dir = 1;
    
    for(ll i=0;i<k;i++){
        if(dir){
            ans[i] += cur;
            cur = ans[i];
        } else {
            ans[i] = cur-ans[i];
            cur = ans[i];
        }
        dir = !dir;
    }
    
    for(auto u: ans)
        cout<<u<<" ";

    return 0;
}