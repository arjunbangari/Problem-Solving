#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll highest_set_bit(ll n){
    ll cnt=0;
    while(n!=0){
        cnt++;
        n /= 2;
    }
    return cnt;
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        ll max_element_so_far= arr[0], max_increase = 0;
        
        for(ll i=1;i<n;i++){
            max_element_so_far = max(max_element_so_far, arr[i]);
            max_increase = max(max_increase, max_element_so_far - arr[i]);
        }
        
        ll ans = highest_set_bit(max_increase);
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}