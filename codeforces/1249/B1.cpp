#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        for(ll i=0;i<n;i++){
            ll j = arr[i]-1;
            ll count = 1;
            while(j!=i){
                j = arr[j]-1;
                count++;
            }
            cout<<count<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
