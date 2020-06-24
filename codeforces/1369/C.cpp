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
        ll n,k;
        cin>>n>>k;
        
        vector<ll> arr(n), brr(k);
        for(auto &u: arr)
            cin>>u;
        
        for(auto &u: brr)
            cin>>u;
            
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        
        ll ans = 0, r = n-1;
        
        for(ll i=0;i<k;i++){
            if(brr[i]==1)
                ans += 2*arr[r];
            else 
                ans += arr[r];
            r--;
            brr[i]--;
        }
        
        for(ll i=0;i<k;i++){
            if(!brr[i])
                continue;
            ans += arr[r-brr[i]+1];
            r -= brr[i];
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}