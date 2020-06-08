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
        
    ll mx = arr[0];
    
    if(n>=2)
        mx |= arr[1];
    
    for(ll i=0;i<n;i++)
        for(ll j=i+1;j<n;j++)
            for(ll k=j+1;k<n;k++)
                mx = max(mx, (arr[i] | arr[j]) | arr[k]);
    
    cout<<mx<<endl;
    
    return 0;
}