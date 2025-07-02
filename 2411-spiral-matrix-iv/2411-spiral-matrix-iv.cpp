/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//  class Solution {
// public:
//     vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
//         int dx[4] = { 0,1,0,-1 };
//         int dy[4] = { 1,0,-1,0 };
//         vector<vector<int>>v(m, vector<int> (n , -1));
//         int i = 0, j = 0, dr = 0;
//         while (head)
//         {
//             v[i][j] = head->val;
//             int ii = i + dx[dr], jj = j + dy[dr];
//             if (ii < 0 || jj < 0 || ii >= m || jj >= n || v[ii][jj] !=-1) //to avoid looping and go inner depth
//                 dr=(dr+1 ) %4 ;

//             i += dx[dr];
//             j += dy[dr];
//             head = head->next;
//         }
//         return v;
//     }
// };

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int top = 0, bottom = m-1, left = 0, right = n-1;
        ListNode* temp = head;
        while(top<=bottom&&left<=right&&temp){
            for(int i = left;i<=right&&temp;i++){
                ans[top][i] = temp->val;
                temp = temp->next;
            }
            top++;
            for(int i = top;i<=bottom&&temp;i++){
                ans[i][right] = temp->val;
                temp = temp->next;
            }
            right--;
            if(left<=right){
                for(int i = right;i>=left&&temp;i--){
                    ans[bottom][i] = temp->val;
                    temp = temp->next;
                }
                bottom--;
            }
            if(top<=bottom){
                for(int i = bottom;i>=top&&temp;i--){
                    ans[i][left] = temp->val;
                    temp = temp->next;
                }
                left++;
            }
        }
        return ans;
    }
};


