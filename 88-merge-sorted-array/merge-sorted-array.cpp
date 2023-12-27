class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if(n==0) return;

        int i=m-1, j=n-1, k=(m+n)-1;
        while( j>=0){
            //check i>=0, if nums2 has more item than nums1 i will be less than 0 it will throw error, check if i>=0  
            if(i>=0 && nums1[i] >= nums2[j]){
                nums1[k--]=nums1[i--];
            }else{
                nums1[k--]=nums2[j--];
            }
        }

    }
};