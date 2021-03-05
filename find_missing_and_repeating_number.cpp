class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int x = 0;
        // cout<<"wtf"<<endl;
        for(int i=0;i<n;i++)
        x^=arr[i];
        // cout<<"wtf"<<endl;
        // cout<<"wtf"<<endl;
        for(int i=1;i<=n;i++)
        x^=i;
        // cout<<"wtf"<<endl;
        int num1, num2;
        num1=num2=0;
        x = x & -x;
        // cout<<"wtf"<<endl;
        for(int i=0;i<n;i++){
            if((arr[i]&x)==0)
            num1^=arr[i];
            else 
            num2^=arr[i];
        }
        // cout<<"wtf"<<endl;
        for(int i=1;i<=n;i++){
            if((i & x)==0)
                num1^=i;
            else 
                num2^=i;
        }
        static int a[2];
        // cout<<"wtf"<<endl;
        for(int i=0;i<n;i++){
            if(arr[i]==num1){
                a[0]=num1;
                a[1]=num2;
                // return new int [2] { num1, num2};
                break;
            }
            else if(arr[i]==num2){
                a[0]= num2;
                a[1]= num1;
                // return new int [2] { num2, num1};
                break;
            }
        }
        return a;
       
    }
};