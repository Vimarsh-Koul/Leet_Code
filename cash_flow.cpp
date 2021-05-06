#include<bits/stdc++.h>
using namespace std;

int maxin(vector<int> &values){
	int ele = INT_MIN;
	int index = 0;

	for(int i=0;i<values.size();i++){
		if(ele < values[i]){
			ele = values[i];
			index = i;
		}
	}
	return index;
}

int minin(vector<int> &values){
	int ele = INT_MAX;

	int index =0;

	for(int i=0;i<values.size(); i++){
		if(ele > values[i]){
			ele = values[i];
			index = i;
		}
	}
	return index;
}


void solve(vector<int> &values){

	int maxindex = maxin(values);
	int minindex = minin(values);

	if(values[maxindex]==0 && values[minindex]==0)
		return;

	int ele = min(-values[minindex], values[maxindex]);

	values[maxindex] -= ele;
	values[minindex] += ele;

	cout<<"person "<< minindex<<" paid ₹"<<ele<<" to "<<maxindex<<endl;


	solve(values); 
}


int main(){
	vector<vector<int>> elements= {{0, 1000, 2000},{0, 0, 5000},{0, 0, 0}};

	vector<int> values(elements.size(), 0);


	for(int i=0;i<elements.size(); i++){
		for(int j=0;j< elements[i].size(); j++){
			values[i] += (elements[j][i] - elements[i][j]);
		}
		
	}
	for(auto it : values)
		cout<<it<<" ";
	
	cout<<endl;
	solve(values);
}