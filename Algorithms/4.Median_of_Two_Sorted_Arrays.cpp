#include "AllInclude.h"

class Solution {
    public:
        int findKsmal(vector<int> &nums1, int l1, vector<int> &nums2, int l2, int k)
        {
            if(l1 >= nums1.size())
                return nums2[l2 + k - 1];
            if(l2 >= nums2.size())
                return nums1[l1 + k - 1];
            if(1 == k)
                return min(nums1[l1], nums2[l2]);
            int mid1 = (l1 + k/2 - 1 < nums1.size()) ? nums1[l1 + k / 2 - 1] : INT_MAX;
            int mid2 = (l2 + k/2 - 1 < nums2.size()) ? nums2[l2 + k / 2 - 1] : INT_MAX;
            if(mid1 < mid2)
                return findKsmal(nums1, l1 + k / 2, nums2, l2, k - k / 2);
            else
                return findKsmal(nums1, l1, nums2, l2 + k / 2, k - k / 2); 
        }

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size();
            int n = nums2.size();
            if(!m && !n) 
                return 0;
            double l = findKsmal(nums1, 0, nums2, 0, (m + n + 1) / 2);
            return (m + n) % 2 ? l : (l + findKsmal(nums1, 0, nums2, 0, (m + n + 2) / 2)) / 2.0;
        }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
                }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
