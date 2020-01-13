#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,k,sz=0;
    cin>>n>>k;
    vector<ll> dv;
    for (int i=1; i<=sqrt(n); i++) { 
        if (n%i == 0) { 
            if (n/i == i){ 
                dv.push_back(i); 
                sz++;
            }
            else{
                dv.push_back(i);
                dv.push_back(n/i);
                sz+=2;
            }
        }
    }
    
    if(sz<k)
        cout<<-1<<endl;
    else{
        sort(dv.begin(),dv.end());
        cout<<dv[k-1]<<endl;
    }
    
    return 0;
}