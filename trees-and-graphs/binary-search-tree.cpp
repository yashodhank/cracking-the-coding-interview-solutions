#include "binary-search-tree.h"
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <list>

using namespace std;

/**
 * Creates an empty Binary Search Tree
 *
 * @param void
 */
BinarySearchTree::BinarySearchTree()
{
    this->size = 0;

    this->root = NULL;
}

/**
 * Recursively inserts a new node into the Binary Search Tree
 *
 * @param TreeNode* curr
 * @param int val
 * @return TreeNode*
 */
TreeNode* BinarySearchTree::recursiveInsert(TreeNode* curr, int val)
{
    if (!curr) return new TreeNode(val);

    if (curr->value >= val)
    {
        curr->left = recursiveInsert(curr->left, val);
    }
    else
    {
        curr->right = recursiveInsert(curr->right, val);
    }

    curr->setHeight();

    return curr;
}

/**
 * Inserts a new node into the Binary Search Tree
 *
 * @param int val
 * @return void
 */
void BinarySearchTree::insert(int val)
{
    this->root = this->recursiveInsert(this->root, val);

    this->size++;
}

/**
 * Finds the TreeNode* that contains val, if exists
 *
 * @param TreeNode* curr
 * @param int val
 * @return TreeNode*
 */
TreeNode* BinarySearchTree::find(TreeNode* curr, int val)
{
    if (!curr) return curr;

    else if (curr->value == val) return curr;

    else if (curr->value >= val) return this->find(curr->left, val);

    return this->find(curr->right, val);
}

/**
 * Checks whether a value exists in the BST
 *
 * @param int val
 * @return bool
 */
bool BinarySearchTree::exists(int val)
{
    TreeNode* curr = this->find(this->root, val);

    return curr != NULL;
}

/**
 * Returns the number of vertices in the BST
 *
 * @return int
 */
int BinarySearchTree::getNumVertices()
{
    return this->size;
}

/**
 * Returns the entire tree inOrder
 *
 * @param TreeNode* curr
 * @param vector<int>& res
 * @return void
 */
void BinarySearchTree::inOrder(TreeNode* curr, vector<int>& res)
{
    if (!curr) return;

    this->inOrder(curr->left, res);

    res.push_back(curr->value);

    this->inOrder(curr->right, res);
}

/**
 * Returns the entire tree inOrder
 *
 * @return vector<int>
 */
vector<int> BinarySearchTree::inOrder()
{
    vector<int> res;

    this->inOrder(this->root, res);

    return res;
}

/**
 * Returns the entire tree levelOrder
 *
 * @return vector<vector<int>>
 */
vector<vector<int>> BinarySearchTree::levelOrder()
{
    int levels = this->getHeight();

    vector<vector<int>> res(levels, vector<int>());

    if (levels == 0) return res;

    queue<pair<TreeNode*, int>> levelOrderQ;

    levelOrderQ.push(make_pair(this->root, 0));

    while (!levelOrderQ.empty())
    {
        pair<TreeNode*, int> p = levelOrderQ.front();

        levelOrderQ.pop();

        int currentLevel = p.second;

        TreeNode* curr = p.first;

        res[currentLevel].push_back(curr->value);

        if (curr->left)
        {
            levelOrderQ.push(make_pair(curr->left, currentLevel+1));
        }

        if (curr->right)
        {
            levelOrderQ.push(make_pair(curr->right, currentLevel+1));
        }
    }

    return res;
}

/**
 * Returns the entire tree in levelOrder
 * Each level is returned as a linked list
 *
 * @return vector<list<int>>
 */
vector<list<int>> BinarySearchTree::levelOrderLists()
{
    int levels = this->getHeight();

    vector<list<int>> res(levels, list<int>());

    if (levels == 0) return res;

    queue<pair<TreeNode*, int>> levelOrderQ;

    levelOrderQ.push(make_pair(this->root, 0));

    while (!levelOrderQ.empty())
    {
        pair<TreeNode*, int> p = levelOrderQ.front();

        levelOrderQ.pop();

        int currentLevel = p.second;

        TreeNode* curr = p.first;

        res[currentLevel].push_back(curr->value);

        if (curr->left)
        {
            levelOrderQ.push(make_pair(curr->left, currentLevel+1));
        }

        if (curr->right)
        {
            levelOrderQ.push(make_pair(curr->right, currentLevel+1));
        }
    }

    return res;
}

/**
 * Prints the tree inOrder
 *
 * @return void
 */
void BinarySearchTree::printTree()
{
    vector<int> res = this->inOrder();

    for (int val : res)
    {
        cout << val << " ";
    }

    cout << endl;
}

/**
 * Prints the tree in level order
 *
 * @return void
 */
void BinarySearchTree::printLevelOrder()
{
    vector<vector<int>> res = this->levelOrder();

    for (int level=0; level<res.size(); level++)
    {
        printf("Printing level %d\n", level);

        for (int num : res[level])
        {
            cout << num << " ";
        }

        cout << endl;
    }
}

/**
 * Returns the height of the tree
 *
 * @param TreeNode* curr
 * @return int
 */
int BinarySearchTree::getHeight(TreeNode* curr)
{
    if (!curr) return 0;

    return 1 + max(this->getHeight(curr->left), this->getHeight(curr->right));
}

/**
 * Returns the height of the tree
 * Height of the root is 1
 *
 * @return int
 */
int BinarySearchTree::getHeight()
{
    return this->getHeight(this->root);
}

/**
 * Returns the root of the bst
 *
 * @return TreeNode*
 */
TreeNode* BinarySearchTree::getRoot()
{
    return this->root;
}

/**
 * Returns whether the height of the tree is balanced
 *
 * @param TreeNode* curr
 * @return bool
 */
bool BinarySearchTree::getBalanced(TreeNode* curr)
{
    if (!curr) return true;

    int left = curr->left ? curr->left->getHeight() : 0;

    int right = curr->right ? curr->right->getHeight() : 0;

    int diff = abs(left - right);

    if (diff > 1) return false;

    else if (!this->getBalanced(curr->left)) return false;

    else if (!this->getBalanced(curr->right)) return false;

    return true;
}

/**
 * Returns whether the height of the tree is balanced
 *
 * @return bool
 */
bool BinarySearchTree::getBalanced()
{
    return this->getBalanced(this->getRoot());
}

/**
 * Clears the binary tree
 *
 * @return void
 */
void BinarySearchTree::clear()
{
    this->root = NULL;

    this->size = 0;
}
