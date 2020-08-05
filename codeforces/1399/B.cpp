#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> arr(n), brr(n);
        for(auto &u: arr)
            cin>>u;
        for(auto &u: brr)
            cin>>u;
        
        ll mn1 = *min_element(all(arr));
        ll mn2 = *min_element(all(brr));
        
        ll ans = 0;
        
        for(ll i=0;i<n;i++){
            ll x = arr[i]-mn1, y = brr[i]-mn2;
            ans += max(x, y);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}