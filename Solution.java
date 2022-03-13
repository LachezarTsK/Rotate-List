
public class Solution {

    public ListNode rotateRight(ListNode head, int rotations) {
        if (head == null || head.next == null || rotations == 0) {
            return head;
        }

        int totalNumberOfNodes = 1;
        ListNode tailBeforeRotation = head;
        while (tailBeforeRotation.next != null) {
            totalNumberOfNodes++;
            tailBeforeRotation = tailBeforeRotation.next;
        }

        if ((rotations % totalNumberOfNodes) == 0) {
            return head;
        }

        int movesToNewTail = totalNumberOfNodes - (rotations % totalNumberOfNodes) - 1;
        ListNode tailAfterRotation = head;

        while (movesToNewTail-- > 0) {
            tailAfterRotation = tailAfterRotation.next;
        }

        ListNode headAfterRotation = tailAfterRotation.next;
        tailAfterRotation.next = null;
        tailBeforeRotation.next = head;
        
        return headAfterRotation;
    }
}

// Class ListNode is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this class.
class ListNode {
    int val;
    ListNode next;

    ListNode() {}

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
