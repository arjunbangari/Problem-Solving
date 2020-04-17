#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    vector<ll> left(n, 1), right(n, 1);
    
    for(ll i=1;i<n;i++)
        left[i] = (arr[i]>arr[i-1] ? left[i-1]+1 : 1) ;
    
    for(ll i=n-2;i>=0;i--)
        right[i] = (arr[i]<arr[i+1] ? right[i+1]+1 : 1);
        
    ll ans = *max_element(left.begin(), left.end());
    
    for(ll i=1;i<n-1;i++)
        if(arr[i+1]>arr[i-1])
            ans = max(ans, right[i+1] + left[i-1]);
    
    cout<<ans<<endl;
    
    return 0;
}