#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main(){
    fast;
    ll n,k;
    cin>>n>>k;
    
    ll l=1, r= n, ans;
    
    while(l<=r){
        ll v = (l+r)/2;
        ll sum = v, temp=1,i=1;
        while(temp!=0){
            temp = v/binpow(k,i);
            sum += temp;
            i++;
        }
        if(sum<n){
            l = v+1;
        } else {
            ans = v;
            r = v-1;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}