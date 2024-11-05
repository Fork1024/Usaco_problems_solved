#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
//#define int long long

const int N = 200;
vector<int> a[N+1];
vector<int> visited(N+1);


struct Edge{
    int x, y, p;
};

int distance(int x1, int y1, int x2, int y2){
    int one = (x1-x2)*(x1-x2), two = (y1-y2)*(y1-y2);
    return one+two;
}

int bfs(int index){
    int ans = 0;

    queue<int> q;
    q.push(index);
    visited[index] = 1;

    while(!q.empty()){
        int num = q.front();
        ans++;
        q.pop();

        for(auto x:a[num]){
            if(visited[x]==0){
                q.push(x);
                visited[x] = 1;
            }

        }

    }

    return ans;
}

void test(){

    //ifstream cin("moocast.in");
	//ofstream cout("moocast.out");

    int n;
    cin >> n;
    //comparing to p^2 disatnce
    vector<Edge> vec(n+1);
        for(int i=1; i<=n; i++){
            cin >> vec[i].x >> vec[i].y >> vec[i].p;
        }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(distance(vec[i].x, vec[i].y, vec[j].x, vec[j].y) <= vec[i].p * vec[i].p) a[i].pb(j);
        }
    }

    int maxim = 0;

    for(int i=1; i<=n; i++){ //tracker should be 
            fill(visited.begin(), visited.end(), false);
        maxim = max(maxim, bfs(i));
    }

    cout << maxim << endl;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   //int t;
   //cin >> t;
    //while(t--)
    test();
}
