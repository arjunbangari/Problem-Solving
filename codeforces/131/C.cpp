#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll ncr(ll n, ll r) { 
    ll p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            ll m = __gcd(p, k); 
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
    } 
    else
        p = 1; 
    return p;
}

int main(){
    fast;
    ll n,m,t, ans=0;
    cin>>n>>m>>t;
    ll end = min(n, t-1);
    ll start = max(4LL,t-m);
    
    for(ll i=start;i<=end;i++){
        ll ans1 = ncr(n,i);
        ll ans2 = ncr(m,t-i);
        ans += ans1*ans2;
    }
    
    cout<<ans<<endl;
    
    return 0;
}