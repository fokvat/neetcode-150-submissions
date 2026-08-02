class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> &A = nums1;
        vector<int> &B = nums2;

        int total = A.size() + B.size();
        int half = total / 2;

        // Always binary search on the smaller array
        if (A.size() > B.size()) {
            swap(A, B);
        }

        int l = 0, r = A.size() - 1;

        while (true) {
            int i = floor((l + r) / 2.0);
            int j = half - i - 2;

            int Aleft  = (i >= 0) ? A[i] : INT_MIN;
            int Aright = (i + 1 < A.size()) ? A[i + 1] : INT_MAX;

            int Bleft  = (j >= 0) ? B[j] : INT_MIN;
            int Bright = (j + 1 < B.size()) ? B[j + 1] : INT_MAX;

            // Correct partition
            if (Aleft <= Bright && Bleft <= Aright) {

                // Odd length
                if (total % 2) {
                    return min(Aright, Bright);
                }

                // Even length
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }
            // Move left
            else if (Aleft > Bright) {
                r = i - 1;
            }
            // Move right
            else {
                l = i + 1;
            }
        }

        return 0.0;
    }
};



        
