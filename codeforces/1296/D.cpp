#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,a,b,k,val;
    cin>>n>>a>>b>>k;
    ll total = a+b;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>val;
        if(val%total==0)
            arr[i] = b;
        else
            arr[i] = val%total - a;
       // cout<<val<<" "<<val%total<<" "<<arr[i]<<endl;
    }
   
    sort(arr,arr+n);
    
    ll ans=0;

    for(ll i=0;i<n;i++){
        ll x = max((ll)0,arr[i]);
            ll temp = ceil((float)x/(float)a);
            //cout<<arr[i]<<" "<<temp<<endl;
            if(k>=temp){
                ans++;
                k -= temp;
            } else
                break;
    }
    cout<<ans<<endl;
    return 0;
}