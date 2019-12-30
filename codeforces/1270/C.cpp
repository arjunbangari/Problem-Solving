#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n,sum=0,xorr = 0;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){ 
            cin>>arr[i];
            sum+=arr[i];
            xorr = xorr^arr[i];
        }
        cout<<2<<"\n"<<xorr<<" "<<sum+xorr<<"\n";
    }
    return 0;
}
