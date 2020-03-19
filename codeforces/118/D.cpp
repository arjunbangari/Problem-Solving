#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll n1,n2,k1,k2, m=100000000;
ll dp[105][105][15][15];
ll mem[105][105][15][15];

ll func(ll f, ll h, ll kf, ll kh){
    if((f+h)==0)
        return 1;
    if(mem[f][h][kf][kh]!=-1)
        return mem[f][h][kf][kh];
    ll ans=0;
    if(f>0 && kf>0)
        ans = ( ans + func(f-1,h,kf-1,k2) )%m;
    if(h>0 && kh>0)
        ans = ( ans + func(f,h-1,k1,kh-1) )%m;
    mem[f][h][kf][kh] = ans;
    return ans;
}

int main(){
    fast;
    cin>>n1>>n2>>k1>>k2;
    
    memset(mem, -1, sizeof(mem));
    
    ll ans = func(n1,n2,k1,k2);
    cout<<ans<<endl;
    
    return 0;
}