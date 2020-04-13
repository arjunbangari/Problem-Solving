#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

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
        
        sort(arr, arr+n);
        
        vector<ll> ans;
        
        if(n%2)
            ans.push_back(arr[n/2]);
        
        for(ll j=n/2 - 1;j>=0;j--){
            ans.push_back(arr[j]);
            ans.push_back(arr[n-j-1]);
        }
        
        for(ll i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}