#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll j=0;
    while(j<n && arr[j]<=k)
        j++;
    
    
    if(j==n)
        cout<<n<<endl;
    else{
        ll ans = j;
        j = n-1;
        while(j>=0 && arr[j]<=k){
            j--;
            ans++;
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}