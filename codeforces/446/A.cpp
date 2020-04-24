#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll arr[n];

    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    vector<ll> pre(n, 1), suf(n, 1);
    
    ll mx = 1;

    for(ll i=1;i<n;i++)
        if(arr[i]>arr[i-1])
            pre[i] += pre[i-1];
    
    for(ll i=n-2;i>=0;i--)
        if(arr[i]<arr[i+1])
            suf[i] += suf[i+1];
    
    for(ll i=0;i<n-1;i++){
        if(i>0){
            mx = max({mx, pre[i], suf[i], pre[i-1]+1, suf[i+1]+1});
            if(arr[i+1]>(arr[i-1]+1))
                mx = max(mx, pre[i-1] + suf[i+1] + 1);
        } else {
            mx = max({suf[0], suf[i+1] + 1});
        }
    }
    
    mx = max(mx, pre[n-1]);
    if(n>1)
        mx = max(mx, pre[n-2] + 1);
    
    cout<<mx<<endl;
    
    return 0;
}