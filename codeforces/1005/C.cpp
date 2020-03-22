#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll next_power(ll n){
    ll temp = 0;
    while(n!=0){
        temp ++;
        n /= 2; 
    }
    return 1<<temp;
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr,arr+n);
    unordered_set<ll> us;
    
    for(ll i=1;i<n;i++){
        ll temp = next_power(arr[i]) - arr[i];
        // cout<<arr[i]<<" "<<temp<<endl;
        if(binary_search(arr,arr+i,temp)){
            us.insert(arr[i]);
            us.insert(temp);
        }
    }
    
    ll ans=n;
    for(ll i=0;i<n;i++)
        if(us.find(arr[i])!=us.end())
            ans--;
    
    cout<<ans<<endl;
    
    return 0;
}