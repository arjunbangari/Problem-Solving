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
    
    ll n,m,k;
    cin>>n>>m>>k;
    
    vector<ll> arr(n), brr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        brr[i] = arr[i];
    }
    
    sort(brr.rbegin(), brr.rend());
    
    map<ll,ll> mp;
    
    ll max_sum=0;
    
    for(ll i=0;i<m*k;i++){
        max_sum += brr[i];
        mp[brr[i]]++;
    }
    
    vector<ll> pos;
    
    ll i=0;
    while(i<n){
        ll j=i;
        ll cnt = 0;
        
        while(j<n && cnt<m){
            if(mp[arr[j]]){
                cnt++;
                mp[arr[j]]--;
            }
            j++;
        }
        
        pos.push_back(j);
        i = j;
    }
    
    cout<<max_sum<<endl;
    for(ll i=0;i<k-1;i++)
        cout<<pos[i]<<" ";
    
    return 0;
}