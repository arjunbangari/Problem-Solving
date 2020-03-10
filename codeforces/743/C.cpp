#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    if(n<=1)
        cout<<-1<<endl;
    else{
        ll x = n;
        ll y = n+1;
        ll z = n*(n+1);
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
    return 0;
}