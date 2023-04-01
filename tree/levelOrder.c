/**
 * Algorithm: levelOrder
 * leetcode:102
 * input:
 *     TreeNode root;           // the tree need to level order
 *     int* returnSize;         // the order result size
 *     int** returnColumnSizes; // the order Column size array
 * output:
 *       int **ret;             // the order array
 {
 init

 update node and status
 {
    que <- node[0]
    update start index, len, next index, next len, level cnt
    loop(len is not 0)
        if (curent level node left or right is not null)
            left or right add to que
            next len add
        if (the last node in current)
            if (next len is 0)
                return
            update start index, len, next index, next len, level cnt
 }
 update result
    loop(not end of level)
        update returnColumnSizes
        loop(not end of current level node)
            update ret
 }
 **/

#include "levelOrder.h"

#define MAX_NODE 2000

#define GET_S_INDEX(X)      (g_queStatus[(X)].startIndex)
#define SET_S_INDEX(X, Y)   (g_queStatus[(X)].startIndex = (Y))
#define GET_C_LEN(X)        (g_queStatus[(X)].len)
#define SET_C_LEN(X, Y)     (g_queStatus[(X)].len = (Y))

typedef struct {
    int startIndex;
    int len;
} LeverQueStatus;

static struct TreeNode g_node[MAX_NODE] = { 0 };
static LeverQueStatus g_queStatus[MAX_NODE] = { {0} };
static unsigned long long g_levelCnt = 0;

static void levelOrderInit(void);
static void UpdateNodeAndStatus(struct TreeNode* root);

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    levelOrderInit();
    UpdateNodeAndStatus(root);

    int** ret = (int**)malloc(sizeof(int*) * (g_levelCnt + 1u));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (g_levelCnt + 1u));

    for (int i = 0; i <= g_levelCnt; i++) {
        returnColumnSizes[0][i] = GET_C_LEN(i);
        int* retLever = (int*)malloc(sizeof(int) * GET_C_LEN(i));
        for (int j = 0; j < GET_C_LEN(i); j++) {
            retLever[j] = g_node[j + GET_S_INDEX(i)].val;
        }
        ret[i] = retLever;
    }

    *returnSize = (g_levelCnt + 1u);
    return ret;
}

static void levelOrderInit(void)
{
    memset(g_node, 0, sizeof(g_node));
    memset(g_queStatus, 0, sizeof(g_queStatus));
    g_levelCnt = 0;
}

static void UpdateNodeAndStatus(struct TreeNode* root)
{
    g_node[0] = root[0];

    SET_S_INDEX(g_levelCnt, 0);
    SET_C_LEN(g_levelCnt, 1);

    int nextStartIndex = GET_S_INDEX(g_levelCnt) + GET_C_LEN(g_levelCnt);
    int nextLeverLen = 0;

    while (GET_C_LEN(g_levelCnt) != 0) {
        for (int i = GET_S_INDEX(g_levelCnt); i < nextStartIndex; i++) {
            if (g_node[i].left != NULL) {
                g_node[nextStartIndex + nextLeverLen] = *(g_node[i].left);
                nextLeverLen++;
            }
            if (g_node[i].right != NULL) {
                g_node[nextStartIndex + nextLeverLen] = *(g_node[i].right);
                nextLeverLen++;
            }
            if ((i + 1) == nextStartIndex) {
                if (nextLeverLen == 0) {
                    return;
                }
                g_levelCnt++;

                SET_S_INDEX(g_levelCnt, nextStartIndex);
                SET_C_LEN(g_levelCnt, nextLeverLen);

                nextStartIndex = GET_S_INDEX(g_levelCnt) + GET_C_LEN(g_levelCnt);
                nextLeverLen = 0;
            }
        }
    }
}