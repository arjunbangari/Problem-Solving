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
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    ll pos=0, neg=0, sum=0, mn=inf;
    for(auto u: arr){
        if(u>=0)
            pos = 1;
        if(u<0)
            neg = 1;
        sum += abs(u);
        mn = min(mn, abs(u));
    }
    
    ll ans;
    
    if(pos && neg)
        ans = sum;
    else
        ans = sum - 2*mn;
    
    if(n==1)
        ans = arr[0];
    
    cout<<ans<<endl;
    
    return 0;
}