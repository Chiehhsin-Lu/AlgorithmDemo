#include<iostream>
#include "distance.h"

/**
 * Algorithm: SumAbsoluteDifferences
 * leetcode:1685
 * input:
 *     <vector>int;           // ordered Array
 * output:
 *     <vector>int;           // sum of absolute Differences array
 {
[n0, n1, ..., ni, ni+1, ...nn]
sumLeft     = (ni - n0) + ... + (ni - ni)
            = (i + 1) * ni - prefix[i]
sumRight    = (nn - ni) + ... + (ni+1 - ni)
            = prefix[n] - prefix[i] - (n - (i + 1)) * ni
 }
 **/
std::vector<int> Dsitance::getSumAbsoluteDifferences(std::vector<int>& nums) {
    std::vector<int> prefixV;
    int prefix = 0;
    for (auto& num : nums) {
        prefix += num;
        prefixV.push_back(prefix);
    }
    std::vector<int> ans;
    for (int i = 0; i < prefixV.size(); i++) {
        int left = (i + 1) * nums[i] - prefixV[i];
        int right = prefixV[prefixV.size() - 1] - prefixV[i] - (prefixV.size() - (i + 1)) * nums[i];
        ans.push_back(left + right);
    }
    return ans;
}

// test
void Dsitance::testSumAbsoluteDifferences(void)
{
    std::vector<int> ans = this->getSumAbsoluteDifferences(this->testOrderV);
    std::cout << "test SumAbsolute Differences :";
    for (auto &a : ans) {
        std::cout << a << ' ';
    }
    std::cout << std::endl;
}