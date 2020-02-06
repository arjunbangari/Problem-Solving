#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll h[n];
    for(ll i=0;i<n;i++)
        cin>>h[i];
    ll ans[n];
    ans[0] = 0;
    ans[1] = abs(h[1]-h[0]);
    
    for(ll i=2;i<n;i++)
        ans[i] = min(ans[i-1] + abs(h[i]-h[i-1]), ans[i-2] + abs(h[i]-h[i-2]));
    
    cout<<ans[n-1]<<endl;
    
    return 0;
}