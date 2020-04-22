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
        ll n;
        cin>>n;
        
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        ll ans = 0;
        ll mx = 0;
        ll i=0;
        
        while(i<n){
            ll j=i;
            while(j<n && arr[j]>0){
                mx = max(mx, arr[j]);
                j++;
            }
            ans += mx;
            i = j+1;
            mx = 0;
        }
        
        i = 0;
        mx = inf;
        while(i<n){
            ll j=i;
            while(j<n && arr[j]<0){
                mx = min(mx, abs(arr[j]));
                j++;
            }
            if(mx!=inf)
                ans += (-mx);
            i = j+1;
            mx = inf;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}