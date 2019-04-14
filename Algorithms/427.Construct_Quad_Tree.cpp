#include "AllInclude.h"

class Node {
    public:
        bool val;
        bool isLeaf;
        Node* topLeft;
        Node* topRight;
        Node* bottomLeft;
        Node* bottomRight;

        Node() {}

        Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = _topLeft;
            topRight = _topRight;
            bottomLeft = _bottomLeft;
            bottomRight = _bottomRight;
        }
};

class Solution {
    public: // 每次调用generate将grid整个看做一个节点, 判断是否符合条件
        Node* generate(vector<vector<int>>& grid, int left, int right, int up, int down)
        {
            Node* head = new Node(grid[up][left], true, NULL, NULL, NULL, NULL);   
            for(int i = up; i <= down; ++i)
            {
                for(int j = left; j <= right; ++j)
                {
                    if(head->val != grid[i][j])
                    {
                        head->isLeaf = false;
                        break;
                    }
                }
                if(!head->isLeaf)
                    break;
            }

            if(!head->isLeaf && up != down)
            {
                head->topLeft = generate(grid, left, (left + right) / 2, up, (up + down) / 2);
                head->bottomLeft = generate(grid, left, (left + right) / 2, (up + down) / 2 + 1, down);
                head->topRight = generate(grid, (left + right) / 2 + 1, right, up, (up + down) / 2);
                head->bottomRight = generate(grid, (left + right) / 2 + 1, right, (up + down) / 2 + 1, down);
            }

            return head;
        }

        Node* construct(vector<vector<int>>& grid) {
            return generate(grid, 0, grid.size() - 1, 0, grid.size() - 1);
        }
};
