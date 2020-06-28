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
            
        vector<ll> crr(n);
        
        ll sb = 0, bb = 0;
        for(ll i=0;i<n;i++){
            if(arr[i]==1)
                sb++;
            else
                bb++;
            crr[i] = sb-bb;
        }
        
        sb = 0, bb = 0;
        map<ll, ll> mp;
        
        for(ll i=n-1;i>=0;i--){
            if(brr[i]==1)
                sb++;
            else
                bb++;
            mp[sb-bb] = i+1;
        }
        
        ll ans = 2*n;
        
        for(ll i=n-1;i>=0;i--){
            if(mp[-crr[i]]){
                ans = min(ans, n-i-1 + mp[-crr[i]]-1);
            }
        }
        
        for(ll i=n-1;i>=0;i--){
            if(crr[i]==0){
                ans = min(ans, n-i-1 + n);
            }
        }
        
        if(mp[0]){
            ans = min(ans, n + mp[0] - 1 );
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}