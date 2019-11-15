#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    int num = 100200;
    bool prime[num+1]; 
    memset(prime, true, sizeof(prime)); 
    for(int p=2; p*p<=num; p++){ 
        if (prime[p] == true){ 
            for (int i=p*p; i<=num; i += p) 
                prime[i] = false; 
        } 
    } 
    prime[1] = false;
    
    ll n,m,temp,index;
    cin>>n>>m;
    ll arr[n][m];
    ll row[n] = {0};
    ll col[m] = {0};
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
            if(!prime[arr[i][j]]){
                temp=0;
                index = arr[i][j];
                while(prime[index]!=true){
                    temp++;
                    index++;
                }
                row[i]+=temp;
                col[j]+=temp;
            }
        }
    }
    ll ans = 1000000000;
    for(ll i=0;i<n;i++){
        if(row[i]<ans)
            ans = row[i];
    }
    
    for(ll i=0;i<m;i++){
        if(col[i]<ans)
            ans = col[i];
    }
    cout<<ans<<"\n";
    return 0;
}