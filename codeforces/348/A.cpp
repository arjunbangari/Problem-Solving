#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n, sum = 0, mx=-1;
    cin>>n;
    
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
        mx = max(mx, arr[i]);
    }
    
    ll ans = ceil((ld)(sum)/(ld)(n-1));
    
    cout<<max(ans,mx)<<endl;
    
    return 0;
}