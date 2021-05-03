


#include<bits/stdc++.h>
using namespace std;


bool train(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}

int main(){
	int m,n;cin>>n>>m;
	vector<pair<int,int>> trains[n+1];

	for(int i=0;i<m;i++){
		int platform;cin>>platform;
		int arrival, dep; cin>>arrival>>dep;
		trains[platform].push_back({arrival, dep});
	}

	for(int i=0;i<n;i++)
		sort(trains[i].begin(), trains[i].end(), train);

	int count =0;

	for(int i=0;i<n;i++){
		if(trains[i].size()==0)
			continue;

		count++;
		int x =0;

		for(int j=1;j<trains[i].size(); j++){
			if(trains[i][j].second >= trains[i][x].second){
				count++;
				x=j;
			}
		}
	}
	
	cout<<count<<endl;

}