#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> arr(9000), brr(9000), cnt(9000,0);

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
    
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        brr[0] = arr[0];
        
        fill(cnt.begin(), cnt.end(), 0);
        
        for(ll i=1;i<n;i++){
            brr[i] = brr[i-1] + arr[i];
            if(brr[i]<=n)
                cnt[brr[i]] = 1;
            for(ll j=0;j<i-1;j++){
                ll temp = brr[i] - brr[j];
                if(temp<=n)
                    cnt[temp] = 1;
            }
        }
            
        ll ans = 0;
            
        for(ll i=0;i<n;i++){
            if(cnt[arr[i]])
                ans++;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}