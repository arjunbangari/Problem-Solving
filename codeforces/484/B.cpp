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
    
    ll n;
    cin>>n;
    
    vector<ll> arr, cnt(maxn);
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        if(!cnt[x])
            arr.push_back(x);
        cnt[x] = 1;
    }
    
    sort(arr.begin(), arr.end());
    
    ll ans = 0;
    
    for(auto u: arr){
        ll i = 2*u;
        while(i<maxn+u){
            auto it = lower_bound(arr.begin(), arr.end(), i);
            if(it!=arr.begin()){
                it--;
                ll val = *it;
                // cout<<i<<" "<<*it<<endl;
                ans = max(ans, val%u );
            }
            
            i += u;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}