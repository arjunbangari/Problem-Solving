#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int walks=0;
    for(int i=0;i<n-1;i++){
            int temp = max(0,k - (arr[i]+arr[i+1]));
            arr[i+1] += temp;
            walks += temp;
        }
    
    cout<<walks<<"\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
            
    
    return 0;
}