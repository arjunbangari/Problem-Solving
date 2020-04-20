#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr, arr+n);
    
    ll mn = 1e6;
    set<ll> test;
    for(ll i=0;i<n;i++)
        test.insert(arr[i]);
    
    ll val = test.size();
    if(val==1)
        mn = 0;
    
    for(ll i=0;i<=100;i++){
        set<ll> s;
        for(ll j=0;j<n;j++){
            ll temp = abs(i-arr[j]);
            if(temp)
                s.insert(temp);
        }
        
        ll sz = s.size();
        if(sz==1)
            mn = min(mn, *s.begin());
    }
    
    cout<< (mn==1e6 ? -1 : mn) <<endl;
    
    return 0;
}