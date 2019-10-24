#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int arr[n];
        map<int, int> freq;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(freq.find(arr[i])!=freq.end()){
                freq[arr[i]]++;
            }
            else{
                freq.insert(pair<int, int>(arr[i], 1));
            }
        }

        vector <int> brr;
        map<int, int>::iterator itr;
        for (itr = freq.begin(); itr != freq.end(); ++itr)
            brr.push_back(itr->second);

        int m = brr.size();
        sort(brr.begin(), brr.end());
        int ans=0,num;
        for(int i=m-1;i>=0;i--){
            if(i==(m-1)){
                ans += brr[i];
                num = brr[i];
            }
            else if(brr[i]>=num){
                if((num-1)>0){
                    num--;
                    ans+=num;
                }
                else break;
            }
            else{
                ans+= brr[i];
                num = brr[i];
            }
        }
        cout<<ans<<"\n";


    }
    return 0;
}
