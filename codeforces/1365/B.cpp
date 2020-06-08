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

bool solve(){
    ll n ;
    cin>>n;
    
    vector<ll> arr(n), brr(n);
    for(auto &u: arr)
        cin>>u;
    
    for(auto &u: brr)
        cin>>u;
    
    ll one = 0, zero = 0;
    
    for(ll i=0;i<n;i++){
        if(brr[i])
            one = 1;
        else
            zero = 1;
    }
    
    if(one && zero) 
        return true;
    
    for(ll i=1;i<n;i++){
        if(arr[i]<arr[i-1])
            return false;
    }
    
    return true;
    
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        cout<< ( solve() ? "Yes" : "No" )<<endl;
    }
    
    return 0;
}