#include <bits/stdc++.h>
#define int long long
const int N = 1e5 +2 , MOD = 1e9+7 ;
using namespace std;
vector<vector<int>> multiply(vector<vector<int>> a , vector<vector<int>> b){
	int n = a.size();
	vector<vector<int>> ans(n , vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				ans[i][j]  = (ans[i][j] + (1LL*a[i][k] * b[k][j])%MOD)%MOD;
			}
		}
	}
	return ans;
}
vector<vector<int>> matrixExponentiation(vector<vector<int>> &a , int n){
	if(n==0){
		int sz = a.size();
		vector<vector<int>> ans(sz , vector<int>(sz,0));
		for(int i=0;i<n;i++){
			a[i][i]=1;
		}
		return ans;
	}
	if(n==1){
		return a;
	}
	vector<vector<int>> temp = matrixExponentiation(a ,n/2);
	vector<vector<int>> ans = multiply(temp , temp);
	if(n&1){
		ans = multiply(ans,a);
	}
	return ans;

}

signed main(){	
	int t;
	cin>>t;
	while(t--){int n,m;
	cin>>n>>m;
	
	vector<vector<int>> a(2 , vector<int>(2,0)) , b(2 , vector<int>(2,0)) ;

	a[0][0]=a[0][1]=a[1][0] = 1;
	b[0][0]=b[0][1]=b[1][0] = 1;


	vector<vector<int>> ans1 = matrixExponentiation(a , m+2);
	vector<vector<int>> ans2 = matrixExponentiation(b , n+1);

	int result = ans1[0][1] - ans2[0][1];


	if (result < 0)
	{
		result = (result + 1000000007) % 1000000007;
		cout<< (result % 1000000007);
	}
	else
	{
		cout<< (result % 1000000007);
	}
	cout<<endl;
	}
}
// #include <bits/stdc++.h>
// #define int long long
// const int N = 1e5 +2 , MOD = 1e9+7 ;
// using namespace std;
// vector<vector<int>> multiply(vector<vector<int>> a , vector<vector<int>> b){
// 	int n = a.size();
// 	vector<vector<int>> ans(n , vector<int>(n,0));
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			for(int k=0;k<n;k++){
// 				ans[i][j] += (1LL*a[i][k] * b[k][j])%MOD;
// 			}
// 		}
// 	}
// 	return ans;
// }
// vector<vector<int>> matrixExponentiation(vector<vector<int>> &a , int n){
// 	if(n==0){
// 		int sz = a.size();
// 		vector<vector<int>> ans(sz , vector<int>(sz,0));
// 		for(int i=0;i<n;i++){
// 			a[i][i]=1;
// 		}
// 		return ans;
// 	}
// 	if(n==1){
// 		return a;
// 	}
// 	vector<vector<int>> temp = matrixExponentiation(a ,n/2);
// 	vector<vector<int>> ans = multiply(temp , temp);
// 	if(n&1){
// 		ans = multiply(ans,a);
// 	}
// 	return ans;

// }
// signed main(){	
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n;
// 		cin>>n;
// 		vector<vector<int>> c(2 , vector<int>(2,0));
// 		c[0][0]=c[0][1]=c[1][0] = 1;
// 		vector<vector<int>> ans3 = matrixExponentiation(c , n);
// 		cout<<ans3[0][1]<<endl;
// 	}

// }