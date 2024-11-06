#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
//#define int long long

int sqdis(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int n;

const int N = 1000;
vector<pair<int, int>> vec(N+1);

bool bfs(int money){
    bool visited[n+1] = {};

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while(!q.empty()){
        int num = q.front();
        q.pop();
        for(int i=1; i<=n; i++){
            if(visited[i]==0 and sqdis(vec[i].ff, vec[i].ss, vec[num].ff, vec[num].ss)<=money){
                q.push(i);
                visited[i] = 1;
            }
        }
    }


    //checking
    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            return false;
        }
    }
    return true;
}



void test(){

    //ifstream cin("moocast.in");
	//ofstream cout("moocast.out");

   cin >> n;
        for(int i=1; i<=n; i++){
            cin >> vec[i].ff >> vec[i].ss;
        }
    
    int low = 0, high = 125*1e7, ans = -1;

    while(low<=high){
        int mid = low + (high-low+1)/2;
        bool result = bfs(mid);
        if(result==true){
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    cout << ans << endl;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   //int t;
   //cin >> t;
    //while(t--)
    test();
}
