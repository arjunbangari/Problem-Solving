#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,x;
    cin>>n>>x;
    
    vector<ll> arr(2*n+1);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        arr[i+n] = arr[i];
    }
    
    vector<ll> brr(2*n+1);
    for(ll i=0;i<2*n;i++)
        brr[i] = (arr[i]*(arr[i]+1))/2;
    
    for(ll i=2*n-2;i>=0;i--){
        arr[i] += arr[i+1];
        brr[i] += brr[i+1];
    }
    
    reverse(all(arr));
    reverse(all(brr));
    
    ll ans = 0;
    
    // for(ll i=0;i<=2*n;i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    
    // for(ll i=0;i<=2*n;i++)
    //     cout<<brr[i]<<" ";
    // cout<<endl;
    
    for(ll i=1;i<=n;i++){
        ll tx = arr[i-1] + x;
        auto it = upper_bound(all(arr), tx);
        it--;
        
        auto ind = it-arr.begin();
        
        ll res, sum, rem, days, rd;
        
        if(ind<i){
            days = arr[i]-arr[i-1];
            rd = days-x;
            res = days*(days+1)/2 - rd*(rd+1)/2;
        } else {
            res = brr[ind] - brr[i-1];
            sum = arr[ind] - arr[i-1];
            
            rem = x-sum;
            if(rem!=0){
                days = arr[ind+1]-arr[ind];
                rd = days-rem;
                res += (days*(days+1))/2 - (rd*(rd+1))/2;
            }
        }
        
        // cout<<i<<" "<<ind<<" "<<res<<endl;
        
        ans = max(ans, res);
    }
    
    cout<<ans<<endl;
    return 0;
}