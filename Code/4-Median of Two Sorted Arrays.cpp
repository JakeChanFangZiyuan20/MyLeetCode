class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) swap(nums1, nums2);

        int n1 = nums1.size(), n2 = nums2.size();
        int left = 0, right = n1, k = (n1 + n2 + 1) / 2;
        while(left <= right){
            int m1 = (left + right) / 2, m2 = k - m1;
            if(m1 < right && nums1[m1] < nums2[m2 - 1]){
                left = m1 + 1;
            } else if(m1 > left && nums1[m1 - 1] > nums2[m2]){
                right = m1 - 1;
            } else{
                int c1 = 0;
                if(m1 == 0) c1 = nums2[m2 - 1];
                else if(m2 == 0) c1 = nums1[m1 - 1];
                else c1 = max(nums1[m1 - 1], nums2[m2 - 1]);
                if((n1 + n2) % 2 == 1) return c1;

                int c2 = 0;
                if(m1 == n1) c2 = nums2[m2];
                else if(m2 == n2) c2 = nums1[m1];
                else c2 = min(nums1[m1], nums2[m2]);
                return (c1 + c2) / 2.0;
            }
        }

        return 0.0;
    }
};