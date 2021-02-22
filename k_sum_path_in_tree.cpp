void print(vector<int> &v,int j){
	for(int i=j; i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

void printsum(tree *root, vector<int> &v, int sum){
	if(!root)
		return;

	v.push_back(root->data);
	printsum(root->left, v, sum);
	printsum(root->right, v, sum);

	int f=0;
	for(int i=v.size()-1; i>=0; i--){
		f=f+v[i];

		if(f==sum)
			print(v, i);
	}

	v.pop_back();
}