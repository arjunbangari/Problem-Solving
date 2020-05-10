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

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    vector<ll> arr(n+1);
    for(ll u=1;u<=n;u++)
        cin>>arr[u];
    
    vector<ll> brr;
    ll vis[n+1] = {0};
    
    ll i=1;
    
    while(1){
        i = arr[i];
        
        if(vis[i])
            break;
        
        brr.push_back(i);
        vis[i] = 1;
    }
    
    ll cnt = brr.size();

    ll j = 0;
    while(brr[j]!=i)
        j++;
    
    ll ans;
    
    if(k<=j){
        ans = brr[k-1];
    } else {
        ans = brr[(k-j-1)%(cnt-j) + j];
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}