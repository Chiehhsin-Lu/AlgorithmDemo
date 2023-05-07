#pragma once

#include "common.h"

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);