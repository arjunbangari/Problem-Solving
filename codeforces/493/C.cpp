#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n, m;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    cin>>m;
    
    vector<ll> brr(m);
    for(auto &u: brr)
        cin>>u;
    
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    
    set<ll> s;
    for(auto u: arr){
        s.insert(u);
        s.insert(u-1);
    }
    
    for(auto u: brr){
        s.insert(u);
        s.insert(u-1);
    }
    
    ll dif = -inf, a, b, tmp1, tmp2;
    
    for(auto u: s){
        auto it2 = upper_bound(arr.begin(), arr.end(), u) - arr.begin();
        it2--;
        
        tmp1 = 2*(it2+1) + 3*(n-it2-1);
        
        auto it = upper_bound(brr.begin(), brr.end(), u) - brr.begin();
        it--;
        
        tmp2 = 2*(it+1) + 3*(m-it-1);
        
        if((tmp1-tmp2)>dif){
            dif = tmp1 - tmp2;
            a = tmp1;
            b = tmp2;
        }
        if((tmp1-tmp2)==dif){
            if(tmp1>a){
                a = tmp1;
                b = tmp2;
            }
        }
    }
    
    cout<<a<<":"<<b<<endl;
    
    return 0;
}