#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll prime[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 4, 9, 25, 49};
    
    ll vis = 0;
    string s;
    
    for(ll i=0;i<20;i++){
        cout<<prime[i]<<endl;
        fflush(stdout);
        cin>>s;
        if(s=="yes")
            vis++;
    }
    
    if(vis<2)
        cout<<"prime"<<endl;
    else
        cout<<"composite"<<endl;
    fflush(stdout);
    return 0;
}