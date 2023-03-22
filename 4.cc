/*
 * @Author: tangxiao
 * @Date: 2023-01-28 13:56:53
 * @LastEditTime: 2023-01-28 18:38:11
 * @LastEditors: tangxiao
 * @Copyright: 2022 FT. All right reserved.
 * @Description: Do not edit
 */
#include <iostream>
#include <string>
#include <vector>
#include<cmath>
using namespace std;

// class Solution {
//    public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();
//         int left = (m + n + 1) / 2;
//         int right = (m + n + 2) / 2;
//         if ((m + n) % 2 == 1) {
//             return findKth(nums1, 0, nums2, 0, left);

//         } else {
//             return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
//         }
//     }
//     // i: nums1的起始位置 j: nums2的起始位置
//    public:
//     int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
//         if (i >= nums1.size())
//             return nums2[j + k - 1];  // nums1为空数组
//         if (j >= nums2.size())
//             return nums1[i + k - 1];  // nums2为空数组
//         if (k == 1) {
//             return nums1[i] < nums2[j] ? nums1[i] : nums2[j];
//         }
//         int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : 1000001;
//         int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : 1000001;
//         if (midVal1 < midVal2) {
//             return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
//         } else {
//             return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
//         }
//     }
// };

// class Solution {
//    public:
//     int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
//         /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
//          * 这里的 "/" 表示整除
//          * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
//          * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
//          * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
//          * 这样 pivot 本身最大也只能是第 k-1 小的元素
//          * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
//          * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
//          * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
//          */

//         int m = nums1.size();
//         int n = nums2.size();
//         int index1 = 0, index2 = 0;

//         while (true) {
//             // 边界情况
//             if (index1 == m) {
//                 return nums2[index2 + k - 1];
//             }
//             if (index2 == n) {
//                 return nums1[index1 + k - 1];
//             }
//             if (k == 1) {
//                 return min(nums1[index1], nums2[index2]);
//             }

//             // 正常情况
//             int newIndex1 = min(index1 + k / 2 - 1, m - 1);
//             int newIndex2 = min(index2 + k / 2 - 1, n - 1);
//             int pivot1 = nums1[newIndex1];
//             int pivot2 = nums2[newIndex2];
//             if (pivot1 <= pivot2) {
//                 k -= newIndex1 - index1 + 1;
//                 index1 = newIndex1 + 1;
//             } else {
//                 k -= newIndex2 - index2 + 1;
//                 index2 = newIndex2 + 1;
//             }
//         }
//     }

//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int totalLength = nums1.size() + nums2.size();
//         if (totalLength % 2 == 1) {
//             return getKthElement(nums1, nums2, (totalLength + 1) / 2);
//         } else {
//             return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
//         }
//     }
// };

class Solution {
   public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        // median1：前一部分的最大值
        // median2：后一部分的最小值
        int median1 = 0, median2 = 0;

        while (left <= right) {
            // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            int nums_im1 = (i == 0 ? -1000001 : nums1[i - 1]);
            int nums_i = (i == m ? 1000001 : nums1[i]);
            int nums_jm1 = (j == 0 ? -1000001 : nums2[j - 1]);
            int nums_j = (j == n ? 1000001 : nums2[j]);

            if (nums_im1 <= nums_j) {
                median1 = max(nums_im1, nums_jm1);
                median2 = min(nums_i, nums_j);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};
