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

    ll n,k;
    cin>>n>>k;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    for(ll j=0;j<min(k,43LL);j++){
        vector<ll> prefix(n+1, 0);
        
        for(ll i=0;i<n;i++){
            ll x = (i - arr[i] + 0.4);
            ll y = (i + arr[i] + 0.5);
            prefix[max(0LL,x)]++;
            prefix[min(y+1,n)]--;
        }
        
        for(ll i=1;i<n;i++)
            prefix[i] += prefix[i-1];
            
        for(ll i=0;i<n;i++)
            arr[i] = prefix[i];
    }
    
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}
