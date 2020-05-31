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
    
    ll t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        ll n = s.length();
        
        vector<ll> arr(n), brr(n), crr(n), drr(n);
        
        arr[0] = (s[0]!='1');
        brr[0] = (s[0]!='0');
        crr[n-1] = (s[n-1]!='1');
        drr[n-1] = (s[n-1]!='0');
        
        for(ll i=1;i<n;i++){
            arr[i] = arr[i-1] + (s[i]!='1');
            brr[i] = brr[i-1] + (s[i]!='0');
        }
        
        for(ll i=n-2;i>=0;i--){
            crr[i] = crr[i+1] + (s[i]!='1');
            drr[i] = drr[i+1] + (s[i]!='0');
        }
        
        ll mn = min(arr[n-1], brr[n-1]);
        
        for(ll i=0;i<n-1;i++){
            mn = min(mn, arr[i] + drr[i+1]);
            mn = min(mn, brr[i] + crr[i+1]);
        }
        
        cout<<mn<<endl;
    }
    
    return 0;
}