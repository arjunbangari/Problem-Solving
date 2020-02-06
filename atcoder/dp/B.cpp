#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,k;
    cin>>n>>k;
    ll h[n];
    for(ll i=0;i<n;i++)
        cin>>h[i];
    ll ans[n];
    ans[0] = 0;
    
    for(ll i=1;i<n;i++){
        ans[i] = 1e10;
        ll temp = max((ll)0,i-k);
        for(ll j=i-1;j>=temp;j--)
            ans[i] = min(ans[i], ans[j] + abs(h[i]-h[j]));
    }
    
    cout<<ans[n-1]<<endl;
    
    return 0;
}