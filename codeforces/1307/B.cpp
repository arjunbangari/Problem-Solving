#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        ll flag = 0;
        for(ll i=0;i<n;i++)
            if(arr[i]==x)
                flag = 1;
            
        if(flag)
            cout<<1<<endl;
        else{
            ll mx = *max_element(arr,arr+n);
            if(x%mx){
                ll ans = x/mx + 1;
                cout<<max(2LL,ans)<<endl;
            } else {
                cout<<x/mx<<endl;
            }
        }
    }
    
    return 0;
}