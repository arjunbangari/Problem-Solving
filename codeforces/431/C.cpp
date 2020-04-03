#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,k,d, m=1000000007;
    cin>>n>>k>>d;
    
    //dp1[i] -> possible weights = [1...k] and sum=i 
    
    ll dp1[n+1];
    memset(dp1, 0, sizeof(dp1));
    dp1[0] = 1;
    
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=k;j++){
            if(j<=i)
                dp1[i] = (dp1[i] + dp1[i-j])%m;
        }
    }
    
    
    // dp2[i] -> possible weights = [1....d-1] and sum=i. 
    
    ll dp2[n+1];
    memset(dp2, 0, sizeof(dp2));
    dp2[0] = 1;
    
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<d;j++){
            if(j<=i)
                dp2[i] = (dp2[i] + dp2[i-j])%m;
        }
    }
    
    // Answer = dp1[n] - dp2[n]
    
    cout<< ( dp1[n] - dp2[n] + m)%m <<endl;
    
    return 0;
}