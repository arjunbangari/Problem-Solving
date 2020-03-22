#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    long double l;
    cin>>l;
    
    long double ans = (l/3)*(l/3)*(l/3);
    
    cout<<fixed<<setprecision(6)<<ans<<endl;
    
    return 0;
}