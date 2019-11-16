#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main(){   
    fast;
    ll n,ans;
    cin>>n;
    if(n==1)
        ans = 1;
    else if(n==2)
        ans = 2;
    else if(n==3)
        ans = 6;
    else{
        if(n%2!=0)
            ans = n*(n-1)*(n-2);
        else if(n%3==0)
            ans = (n-1)*(n-2)*(n-3);
        else
            ans = (n)*(n-1)*(n-3);
    }
    cout<<ans<<"\n";
    return 0;
}
