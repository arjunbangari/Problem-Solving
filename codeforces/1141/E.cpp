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
    
    ll h,n;
    cin>>h>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    ll x = 0, mn = inf;
    for(auto u: arr){
        x += u;
        mn = min(mn, x);
    }
    
    if(x>=0 && abs(mn)<h){
        cout<<-1<<endl;
        return 0;
    }
    
    ll k = 0;
    if(x!=0)
        k = (h - abs(mn))/abs(x);
    k = max(0LL, k-2);
    
    ll ans = k*n;
    h += k*x;
    
    while(h>0){
        for(ll i=0;i<n;i++){
            h += arr[i];
            ans++;
            if(h<=0)
                break;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}