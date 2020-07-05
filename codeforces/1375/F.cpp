#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
// #define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here
vector<pll> a(3);

void solve(){

    ll y = 2*(a[2].first) - a[1].first - a[0].first;
    cout<<y<<endl;
    ll x,x1;
    cin>>x;

    if(x==(a[0].second)){
        cout<<(a[2].first - a[1].first)<<endl;
        cin>>x1;
        if(x1==0)
            return;
    }
    else if(x==(a[1].second)){
        cout<<(a[2].first - a[0].first)<<endl;
        cin>>x1;
        if(x1==0)
            return;
    }
    else {
        a[2].first += y;
        solve();
        return;
    }
}

int main(){
    fast;

    ll p,q,r;
    cin>>p>>q>>r;

    a[0] = {p,1};
    a[1] = {q,2};
    a[2] = {r,3};

    sort(a.begin(), a.end());

    cout<<"First"<<endl;

    solve();

    return 0;
}
