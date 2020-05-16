#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    
    vector<ll> pre_sum(maxn, 0);
    
    for(ll i=a;i<=b;i++){
        pre_sum[i+b]++;
        pre_sum[i+c+1]--;
    }
    
    for(ll i=1;i<maxn;i++)
        pre_sum[i] += pre_sum[i-1];
    
    for(ll i=1;i<maxn;i++)
        pre_sum[i] += pre_sum[i-1];
    
    ll  cnt=0;
    
    for(ll i=c;i<=d;i++)
        cnt += pre_sum[maxn-1] - pre_sum[i];
    
    cout<<cnt<<endl;
    
    return 0;
}