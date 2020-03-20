#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    ll arr[n];
    vector<pair<ll,ll>> brr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        brr[i] = {arr[i],i};
    }
    
    sort(brr.rbegin(), brr.rend());
    
    vector<ll> indices(k);
    ll max_sum = 0;
    
    for(ll i=0;i<k;i++){
        max_sum += brr[i].first;
        indices[i] = brr[i].second;
    }
    
    sort(indices.begin(), indices.end());
    
    ll total = 1;
    
    for(ll i=1;i<k;i++)
        total = (total*(indices[i]-indices[i-1]))%998244353;
    
    cout<<max_sum<<" "<<total<<endl;
    
    return 0;
}