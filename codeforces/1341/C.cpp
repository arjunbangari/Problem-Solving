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
vector<ll> arr(maxn);
ll n;

ll check(ll l, ll r){
    for(ll i=l+1;i<=r;i++)
        if((arr[i]-arr[i-1])!=1)
            return 0;
    
    return 1;
}

ll solve(ll l, ll r){
    // cout<<l<<" "<<r<<endl;
    
    if(l>r)
        return 1;
    
    ll mn = inf, pos;
    for(ll i=l;i<=r;i++){
        if(arr[i]<mn)
            pos = i;
        mn = min(mn, arr[i]);
    }
    
    if(pos==r)
        return solve(l, r-1);
    else{
        if(check(pos,r))
            return solve(l, pos-1);
        else
            return 0;
    }
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        cin>>n;
        
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        ll ans = solve(0,n-1);
        
        cout<< (ans ? "Yes" : "No")<<endl;
        
    }
    
    return 0;
}