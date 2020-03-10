#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll c[51];

ll solve(ll n, ll k ){
    ll mid = c[n]/2 + 1;
    if(k==mid)
        return n;
    else{
        if(k>mid)
            k -= mid;
        return solve(n-1,k);    
    }
}

int main(){
    fast;
    ll n,k;
    cin>>n>>k;
    c[1] = 1;
    for(ll i=2;i<51;i++)
        c[i] = c[i-1]*2 + 1;
    
    cout<<solve(n,k)<<endl;
    
    
    return 0;
}