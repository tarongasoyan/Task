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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * head1 =head; 
        if (head==NULL) {
            return NULL;
        }

         while (head1  && head1->next) {
            if (head1->val == head1->next->val) {
                head1->next = head1->next->next;
            } else { 
                head1 = head1->next;
            }
        }

        return head;
    }
};

////////////////////
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> vec;
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }
        int size = vec.size();
        for (int i = 0; i < size / 2; i++) {
            if (vec[i] != vec[size - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

////////////////////////

**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) { 
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* head1 = head;
        while (head1->next != nullptr) {
            if (head1->next->val == val) {
                head1->next = head1->next->next;
            } else {
                head1 = head1->next;    
            }
        }
        return head;
    }
};


///////////////////////
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr; 
        ListNode *next = head;
        while(head) {
            next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
//////////////////////


