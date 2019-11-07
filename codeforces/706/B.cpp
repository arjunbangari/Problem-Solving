#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    ll n,q;
    cin>>n;
    ll xrr[n];
    for(ll i=0; i<n; i++)
        cin>>xrr[i];
    sort(xrr, xrr + n);
    cin>>q;

    while(q--){
        ll m;
        cin>>m;
        ll ans = upper_bound(xrr, xrr+n, m) - xrr;
        cout<<ans<<"\n";
    }

    return 0;
}
