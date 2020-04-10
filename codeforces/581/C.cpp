#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,k, temp,x;
    cin>>n>>k;
    
    pair<ll,ll> arr[n];
    for(ll i=0;i<n;i++){
        cin>>temp;
        arr[i] = {10-(temp%10),temp};
    }
    
    sort(arr, arr+n);
    
    vector<ll> brr;
    
    for(ll i=0;i<n;i++){
        if(k){
            if(arr[i].second!=100){
                x = min(arr[i].first, k);
                k -= x;
                arr[i].second+=x;
            }
        }
        brr.push_back(arr[i].second);
    }
    
    ll cnt=0,ans=0;
    
    for(ll i=0;i<n;i++){
        ans += brr[i]/10;
        cnt += (100-brr[i]);
    }
    
    ans += min(k,cnt)/10;
        
    cout<<ans<<endl;
    
    return 0;
}