#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast; 
    ll n;
    cin>>n;
    ll arr[n];
    ll count[100005] = {0};
    ll ans[100005];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        count[arr[i]]++;
    }
    ans[0] = 0;
    ans[1] = count[1];
    for(ll i=2;i<100002;i++)
        ans[i] = max(ans[i-1], ans[i-2] + count[i]*i);
    
    cout<<ans[100001]<<"\n";

    
    
        
    return 0;
}
