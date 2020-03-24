#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll binaryExponentiation(ll x,ll n){
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2);
}

ll convert(ll n){
    ll i=0, ans=0, rem;
    while(n>0){
        rem = n%10;
        ans +=  binaryExponentiation(10,i)*(rem%2);
        n /= 10;
        i++;
    }
    return ans;
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    map<ll,ll> mp;
    
    while(t--){
        char c;
        ll a;
        cin>>c>>a;
        
        if(c=='+'){
            ll temp = convert(a);
            mp[temp]++;
        }
        else if(c=='-'){
            ll temp = convert(a);
            mp[temp]--;
        }
        else {
            cout<<mp[a]<<endl;
        }
    }
    
    return 0;
}