class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int cut1, cut2;
        int start = 0, end = nums1.size();
        
        int total = nums1.size() + nums2.size();

        bool even = ((total%2)==0) ? true : false;

        int elements = (total + 1)/2;

        
        
        while(start<=end){
            
            int cut1 = (start + end)/2;
            
            int cut2 = elements - cut1;
            
            int l1 = (cut1<=0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2<=0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1>=nums1.size()) ? INT_MAX : nums1[cut1];
            int r2 = (cut2>=nums2.size()) ? INT_MAX : nums2[cut2];

            if(l1<=r2 and l2<=r1){
                
                if(even)
                return (max(l1,l2) + min(r1,r2))/2.0;
                
                return max(l1, l2);
            }
            
            else if(l1>r2)
                end = cut1 -1;
            
            else
                start = cut1 + 1;
            
        }
        
        return -1;
    }
};