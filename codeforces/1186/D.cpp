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
    
    ll n;
    cin>>n;
    
    vector<ld> arr(n);
    for(auto &i : arr)
        cin>>i;
    
    ll sum = 0;
    
    vector<ll> ans(n);
    for(ll i=0;i<n;i++){
        ans[i] = (ll)floor(arr[i]);
        sum += ans[i];
    }
    
    sum = abs(sum);
    
    for(ll i=0;i<n && sum>0 ;i++){
        if(floor(arr[i])==ceil(arr[i]))
            continue;
        ans[i] = (ll)(ceil(arr[i]));
        sum--;
    }
    
    for(ll i=0;i<n;i++)
        cout<<ans[i]<<endl;
    
    return 0;
}