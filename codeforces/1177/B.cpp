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
    
    ll k;
    cin>>k;
    
    vector<ll> arr(15);
    arr[1] = 9;
    for(ll i=2;i<15;i++)
        arr[i] = arr[i-1]*10;
    
    for(ll i=2;i<15;i++)
        arr[i] = arr[i]*i;
    
    // for(ll i=0;i<5;i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    
    ll i = 1;
    for(;i<15;i++){
        if(k<=arr[i])
            break;
        k -= arr[i];
    }
    
    // cout<<k<<" "<<i<<endl;
    
    ll x = 1;
    for(ll j=1;j<i;j++)
        x *= 10;
    
    // cout<<x<<endl;
    
    x += k/i;
    k = k%i;
    
    if(k==0){
        x--;
        k = i;
    }
    
    string s;
    s = to_string(x);
    
    cout<<s[k-1]<<endl;
    
    return 0;
}