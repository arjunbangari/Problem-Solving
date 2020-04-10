#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const ll M = 1e9+7;

ll modularExponentiation(ll x, ll n){
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2))%M;

}

int main(){
    fast;
    
    string s;
    cin>>s;
    
    ll n = s.length();
    ll cnt=0, ans = 0;
    
    for(ll i=0;i<n;i++){
        if(s[i]=='a')
            cnt++;
        else
            ans = ( ans +modularExponentiation(2,cnt) - 1 + M )%M;
    }
    
    cout<<ans<<endl;
    
    return 0;
}