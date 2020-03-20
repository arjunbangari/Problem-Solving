#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1)
            cout<<-1<<endl;
        else{
            cout<<5;
            for(ll i=1;i<n;i++)
                cout<<3;
            cout<<endl;
        }
    }
    return 0;
}