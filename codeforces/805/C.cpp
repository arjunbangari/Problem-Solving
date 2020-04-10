#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll ans = 0;
    
    ll i=1, j=n, check=1;
    
    while(i<j){
        ans += (i+j)%(n+1);
        if(check)
            i++;
        else
            j--;
        check = !check;
    }
    
    cout<<ans<<endl;
    
    return 0;
}