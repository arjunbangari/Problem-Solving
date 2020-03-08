#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    
    ll l = 1, r = n, ans=n;
    
    while(l<=r){
        ll k = (l+r)/2;
        ll temp = n,vasya=0;
        
        while(temp>0){
            vasya += min(k,temp);
            temp -= min(k,temp);
            temp -= temp/10;
        }
        
        if(2*vasya<n)
            l = k+1;
        else{
            ans = k;
            r = k-1;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}