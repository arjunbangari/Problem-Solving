#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,q,r,c,count=0;
    cin>>n>>q;
    ll arr[4][n+2];
    memset(arr,0,sizeof(arr));
    while(q--){
        cin>>r>>c;
        
        if(arr[r][c]==0){
            arr[r][c] = 1;
            for(ll i=-1;i<=1;i+=2)
                for(ll j=-1;j<=1;j++)
                    if(arr[r+i][c+j]==1)
                        count++;
        }
        else{
            arr[r][c]=0;
            for(ll i=-1;i<=1;i+=2)
                for(ll j=-1;j<=1;j++)
                    if(arr[r+i][c+j]==1)
                        count--;
        }
        cout<<(count>0 ? "No":"Yes")<<endl;
    }
    return 0;
}