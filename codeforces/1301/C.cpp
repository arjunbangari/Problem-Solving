#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll zeroes = n-m;
        ll groups = m+1;
        ll k = zeroes/groups;
        ll total_substr = (n*(n+1))/2;
        ll ans = total_substr - ((k*(k+1))/2)*groups;
        ans -= (k+1)*(zeroes%groups);
        cout<<ans<<endl;
    }
    return 0;
}