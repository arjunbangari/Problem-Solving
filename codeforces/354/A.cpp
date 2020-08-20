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
    
    ll n,l,r,ql, qr;
    cin>>n>>l>>r>>ql>>qr;
    
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    ll ans = inf;
    
    for(ll i=1;i<=n;i++)
        arr[i] += arr[i-1];
    
    if(n==1){
        cout<<min(arr[1]*l, arr[1]*r)<<endl;
        return 0;
    }
    
    for(ll i=0;i<=n;i++){
        ll sum = arr[i]*l + (arr[n]-arr[i])*r;
        ll dif = max(0LL, abs( i - (n-i)) - 1);
        
        // cout<<i<<" "<<sum<<" "<<dif<<" ";
        
        if(i==0)
            sum += qr*(n-1);
        else if(i==n)
            sum += ql*(n-1);
        else if (i>(n-i))
            sum += ql*dif;
        else 
            sum += qr*dif;
        
        // cout<<sum<<endl;
        
        ans = min(ans, sum);
    }
    
    cout<<ans<<endl;
    
    return 0;
}