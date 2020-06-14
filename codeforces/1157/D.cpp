#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    if ( (k*(k+1))/2 > n){
        cout<<"NO"<<endl;
        return 0;
    }
    
    if(n==1){
        cout<<"YES"<<endl;
        cout<<k<<endl;
        return 0;
    }
    
    n -= (k*(k+1))/2;
    ll tmp = n/k, rem = n%k;
    
    vector<ll> arr(k);
    for(ll i=0;i<k;i++)
        arr[i] = i + 1 + tmp;
    
    ll i = k-1;
    
    while(i>=0 && rem>0){
        if(i==0){
            ll val = arr[i+1] - 1 - arr[i];
            arr[i] += min(val, rem);
            rem -= min(val, rem);
        } else {
            ll val = 2*arr[i-1] - arr[i];
            arr[i] += min(val, rem);
            rem -= min(val, rem);
        }
        
        i--;
    }
    
    if(rem>0){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    for(ll i=0;i<k;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}
