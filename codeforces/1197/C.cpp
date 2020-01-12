#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll ans = arr[n-1]-arr[0];
    vector<ll> temp;
    for(ll i=0;i<n-1;i++)
        temp.push_back(arr[i]-arr[i+1]);
    sort(temp.begin(),temp.end());
    
    for(ll i=0;i<k-1;i++)
        ans += temp[i];
    cout<<ans<<endl;
    
    return 0;
}