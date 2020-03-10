#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n+1];
    arr[0] = 0;
    for(ll i=1;i<=n;i++) 
        cin>>arr[i];
    
    sort(arr, arr+n+1);
    arr[n]++;
    
    for(ll i=1;i<n;i++){
        if( arr[i] > ( arr[i-1] + 1 ) )
            arr[i]--;
    }
    
    for(ll i=n-1;i>0;i--){
        if ( (arr[i] + 1 ) < arr[i+1])
            arr[i]++;
    }

    set<ll> s;
    
    for(ll i=1;i<=n;i++)
        s.insert(arr[i]);
    
    ll ans = s.size();
    cout<<ans<<endl;
    
    
    return 0;
}