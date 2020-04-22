#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        
        vector<ll> arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        ll sz = 2*k + 1;
        
        vector<ll> cnt1(sz, 0), cnt2(sz, 0);
        
        for(ll i=0;i<n/2;i++){
            cnt1[arr[i]+arr[n-i-1]]++;
            cnt2[min(arr[i], arr[n-i-1]) + 1]++;
            cnt2[max(arr[i], arr[n-i-1]) + k + 1]--;
        }
        
        for(ll i=1;i<=sz;i++)  
            cnt2[i] += cnt2[i-1];
        
        ll ans = inf;
        
        for(ll i=2;i<sz;i++){
            ll eval = (cnt2[i] - cnt1[i]) + (n - 2*cnt2[i]);
            ans = min(ans, eval);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}