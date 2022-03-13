
using namespace std;

// Struct ListNode is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this struct.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

class Solution {
    
public:
    ListNode* rotateRight(ListNode* head, int rotations) {
        if (head == nullptr || head->next == nullptr || rotations == 0) {
            return head;
        }

        int totalNumberOfNodes = 1;
        ListNode* tailBeforeRotation = head;
        while (tailBeforeRotation->next != nullptr) {
            totalNumberOfNodes++;
            tailBeforeRotation = tailBeforeRotation->next;
        }

        if ((rotations % totalNumberOfNodes) == 0) {
            return head;
        }

        int movesToNewTail = totalNumberOfNodes - (rotations % totalNumberOfNodes) - 1;
        ListNode* tailAfterRotation = head;

        while (movesToNewTail-- > 0) {
            tailAfterRotation = tailAfterRotation->next;
        }

        ListNode* headAfterRotation = tailAfterRotation->next;
        tailAfterRotation->next = nullptr;
        tailBeforeRotation->next = head;

        return headAfterRotation;
    }
};
