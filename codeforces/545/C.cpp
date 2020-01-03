#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,x,h,ans=2,prev;
    cin>>n;
    pair<ll,ll> arr[n];
    for(ll i=0;i<n;i++){
       cin>>x>>h;
       arr[i] = make_pair(x,h);
    }
    if(n==1){
        cout<<1<<endl;
    } else {
        prev = arr[0].first;
        for(ll i=1;i<n-1;i++){
            if(arr[i].second<(arr[i].first-prev)){
                ans++;
                prev = arr[i].first;
            } else if(arr[i].second<(arr[i+1].first - arr[i].first)){
                ans++;
                prev = arr[i].first + arr[i].second;
            } else {
                prev = arr[i].first;
            }
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}