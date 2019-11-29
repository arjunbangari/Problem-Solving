#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast; 
    ll n;
    cin>>n;
    ll ans = 0;
    ans += n/100;
    n = n%100;
    ans+= n/20;
    n = n%20;
    ans += n/10;
    n = n%10;
    ans += n/5;
    n = n%5;
    ans += n;
        
    cout<<ans<<'\n';
    return 0;
}
