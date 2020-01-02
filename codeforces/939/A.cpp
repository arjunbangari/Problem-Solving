#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    ll n;
    cin>>n;
    ll arr[n+1];
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(arr[arr[arr[i]]]==i){
            ans=1;
            break;
        }
    }
    cout<<(ans?"YES":"NO");
    return 0;
}
