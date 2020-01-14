#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll x,y;
    string ans;
    cin>>x>>y;
    ll original=1,copy = 0;
    if(y==0 || (y==1 && x>0)){
        ans="No";
    } else if((x-y+1)>=0 && (x-y+1)%2==0)
        ans="Yes";
    else
        ans="No";
    
    cout<<ans<<endl;
    
    return 0;
}