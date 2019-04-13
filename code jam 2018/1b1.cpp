#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int solve(){
	int n, l;
	cin >> n >> l;

	int ans = 0;

	priority_queue<int> pq;

	int left = n;
	rep(_,0,l){
		int c;
		cin >> c;
		left -= c;
		int res = 200 * c - n;
		while(res >= 0){
			res -= 2*n;
			ans++;
		}
		pq.push(res);
	}
	rep(i,0,left){
		int res = pq.top();
		pq.pop();
		if(res < -n){
			pq.push(-n);
			--i;
			continue;
		}
		res += 200;
		while(res >= 0){
			res -= 2*n;
			++ans;
		}
		pq.push(res);
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	rep(i,1,t+1){
		cout << "Case #" << i << ": " << solve() << endl;
	}
}