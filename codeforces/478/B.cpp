#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    ll temp = n-m+1;
    ll mx = (temp*(temp-1))/2;
    
    ll p = n/m;
    ll mod = n%m;
    ll mn = ((p*(p+1))/2)*mod + ((p*(p-1))/2)*(m-mod);
    cout<<mn<<" "<<mx<<"\n";
    
    return 0;
}