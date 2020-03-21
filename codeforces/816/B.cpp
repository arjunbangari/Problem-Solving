#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,k,q,l,r, sz = 200005;
    cin>>n>>k>>q;
    
    vector<ll> arr(sz,0), ans(sz);
    
    for(ll i=0;i<n;i++){
        cin>>l>>r;
        arr[l]++;
        arr[r+1]--;
    }
    
    for(ll i=1;i<=sz;i++)
        arr[i] += arr[i-1];
    
    ans[0] = 0;
    
    for(ll i=1;i<=sz;i++)
        ans[i] = ( arr[i]>=k ? ans[i-1]+1 : ans[i-1] );
    
    while(q--){
        cin>>l>>r;
        cout<<ans[r]-ans[l-1]<<endl;
    }
    
    
    return 0;
}