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

bool is_square(ll n){
    ld sr = sqrtl(n); 
    return ((sr - floor(sr)) == 0); 
}

ll solve(ll n){
    ld x = sqrtl(n);
    ll a = floor(x);
    ll b = ceil(x);
    return min(n - a*a, b*b - n);
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    ll square = 0, zero = 0;
    for(auto u: arr){
        if(is_square(u)){
            if(!u)
                zero++;
            square++;
        }
    }
    
    if(square>=n/2){
        ll req = square - n/2;
        square -= zero;
        ll ans = 0;
        if(square>=req)
            ans = req;
        else
            ans = square + 2*(req-square);
        
        cout<<ans<<endl;
    } else {
        vector<ll> brr;
        for(auto u: arr)
            if(!is_square(u))
                brr.push_back(solve(u));
        
        sort(brr.begin(), brr.end());
        
        ll ans =0;
        for(ll i=0;i<n/2 - square;i++)
            ans += brr[i];
        
        cout<<ans<<endl;
    }
    
    return 0;
}