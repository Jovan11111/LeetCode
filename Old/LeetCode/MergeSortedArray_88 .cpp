#include <stdio.h>
#include <vector>
using namespace std;

class Solution{

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        vector<int> help(m+n);
        int i, j, k;
        i = j = k = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                help[k++] = nums1[i++];
            }
            else{
                help[k++] = nums2[j++];
            }
        }
        while (i < m){
            help[k++] = nums1[i++];
        }
        while(j < n){
            help[k++] = nums2[j++];
        }
        nums1 = help;
    }
};