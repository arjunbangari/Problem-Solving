#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ld const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n), brr(n);
    
    for(ll i=0;i<n;i++)
        cin>>arr[i]>>brr[i];
    
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    
    ll x,y;
    
    if(n%2){
        x = arr[n/2];
        y = brr[n/2];
    } else {
        x = arr[n/2] + arr[n/2 - 1];
        y = brr[n/2] + brr[n/2 - 1];
    }
    
    cout<<y-x+1<<endl;
    
    return 0;
}