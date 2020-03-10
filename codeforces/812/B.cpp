#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll n,m;
string arr[16];

ll maxpos(string s){
    ll mxpos = 0;
    for(ll i=1;i<=m;i++)
        if(s[i]=='1')
            mxpos = i;
    return mxpos;
}

ll solve(ll nx, ll pos){
    if(nx==0)
        return 0;
    if(pos==0){
        ll temp = maxpos(arr[nx]);
        ll ans1 = solve(nx-1,0);
        ll ans2 = solve(nx-1,1);
        return min((ans1==0?temp: 2*temp + 1 +ans1),(ans2==0?temp: m+2 +ans2));
    } else {
        string t = arr[nx];
        reverse(t.begin(), t.end());
        ll temp = maxpos(t);
        ll ans1 = solve(nx-1,1);
        ll ans2 = solve(nx-1,0);
        return min((ans1==0?temp:2*temp + 1 + ans1),(ans2==0?temp:m+2+ans2));
    }
}

int main(){
    fast;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    cout<<solve(n,0)<<endl;
    
    return 0;
}