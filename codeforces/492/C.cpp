#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
int main(){ 
    fast;
    ll n,r,avg;
    cin>>n>>r>>avg;
    pair<ll, ll> arr[n];
    ll cur=0;
    for(ll i=0;i<n;i++){
        ll first,second;
        cin>>second>>first;
        arr[i] = make_pair(first,second);
        cur+=second;
    }
    sort(arr,arr+n);
    
    ll ans=0;
    ll req = (avg*n)-cur;
    //cout<<ans<<" "<<req<<" "<<cur<<"\n";
    if(req>0){
        ll i=0;
        while(req>0){
            ll temp = min(req,r-arr[i].second);
            ans+=temp*arr[i].first;
            req-=temp;
            i++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}