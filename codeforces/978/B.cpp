#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    
    ll ans = 0;
    
    ll i = 0;
    while(i<n){
        if(s[i]=='x'){
            ll j = i+1;
            while(j<n && s[j]=='x')
                j++;
            ans += max(0LL, j - i -2);
            i = j;
        } else 
            i++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}