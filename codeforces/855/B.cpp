#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,p,q,r;
    cin>>n>>p>>q>>r;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll dp1[n],dp2[n],dp3[n];
    
    dp1[0] = arr[0]*p;
    dp2[0] = dp1[0] + arr[0]*q;
    dp3[0] = dp2[0] + arr[0]*r;
    
    for(ll i=1;i<n;i++){
        dp1[i] = max(dp1[i-1], arr[i]*p);
        dp2[i] = max(dp2[i-1], dp1[i] + arr[i]*q);
        dp3[i] = max(dp3[i-1], dp2[i] + arr[i]*r);
    }
    
    cout<<dp3[n-1]<<endl;
    
    return 0;
}