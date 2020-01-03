#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,d,m,s;
    cin>>n>>d;
    pair<ll,ll> arr[n];
    for(ll i=0;i<n;i++){
        cin>>m>>s;
        arr[i] = make_pair(m,s);
    }
    sort(arr,arr+n);
    ll sum[n];
    sum[0] = arr[0].second;
    for(ll i=1;i<n;i++)
        sum[i] = sum[i-1] + arr[i].second;
    
    ll ans=-1;
    for(ll i=0;i<n;i++){
        ll temp = lower_bound(arr,arr+n,make_pair(arr[i].first+d, numeric_limits<ll>::min())) - arr;
        if(i==0)
            ans = max(ans,sum[temp-1]);
        else
            ans = max(ans,sum[temp-1]-sum[i-1]);
    }
    cout<<ans<<endl;
    
    
    return 0;
}