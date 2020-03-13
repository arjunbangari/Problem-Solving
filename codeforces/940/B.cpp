#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,a,k,b;
    cin>>n>>k>>a>>b;
    
    if(k==1)
        cout<<a*(n-1)<<endl;
    else{
        ll ans = 0;
    
        while(n!=1){
            if(n<k){
                ans += a*(n-1);
                n=1;
            } else if(n%k) {
                ans += a*(n%k);
                n = n - n%k;
            } else {
                ans += min(b,(n-n/k)*a);
                n = n/k;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}