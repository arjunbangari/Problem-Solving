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
    
    ll arr[m];
    for(ll i=0;i<m;i++)
        cin>>arr[i];
    
    ll i=0, last=0, ans=0;
    while(i<m){
        ll val = ( (arr[i]-last)/k + ((arr[i]-last)%k!=0))*k + last;
        ll j=i;
        while(j<m && arr[j]<=val)
            j++;
        
        ans++;
        
        last += (j-i);
        
        i = j;
        
    }
    
    cout<<ans<<endl;
    
    return 0;
}