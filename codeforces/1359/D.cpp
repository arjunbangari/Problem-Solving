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
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    
    ll ans = 0;    
        
    for(ll i=0;i<31;i++){
        ll mx = 0, cur = 0;
        for(ll j=0;j<n;j++){
            if(arr[j]>i){
                cur = 0;
                continue;
            }
            cur += arr[j];
            mx = max(mx, arr[j]);
            ans = max(ans, cur - mx);
            
            if(cur<0){
                cur = 0;
                mx = 0;
            }
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}