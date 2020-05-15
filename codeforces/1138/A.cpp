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
        
    ll i=0, ans = 0;
    
    while(i<n){
        ll j=i+1;
        
        while(j<n && arr[j]==arr[i])
            j++;
        
        ll k = j+1;
        while(k<n && arr[k]==arr[j])
            k++;
        
        ans = max(ans, 2*min(j-i, k-j));
        i = j;
        
    }
    
    cout<<ans<<endl;
    
    return 0;
}