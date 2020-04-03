#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    string a,b;
    cin>>a>>b;
    
    ll ans = 0;
    
    ll i=0;
    while(i<n){
        if(a[i]!=b[i]){
            if(i!=(n-1) && a[i+1]!=a[i] && a[i+1]!=b[i+1])
                i++;
            ans++;
        }
        i++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}