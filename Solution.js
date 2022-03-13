
// Function ListNode is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this function.
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

/**
 * @param {ListNode} head
 * @param {number} rotations
 * @return {ListNode}
 */
var rotateRight = function (head, rotations) {
    if (head === null || head.next === null || rotations === 0) {
        return head;
    }

    let totalNumberOfNodes = 1;
    let tailBeforeRotation = head;
    while (tailBeforeRotation.next !== null) {
        totalNumberOfNodes++;
        tailBeforeRotation = tailBeforeRotation.next;
    }

    if ((rotations % totalNumberOfNodes) === 0) {
        return head;
    }

    let movesToNewTail = totalNumberOfNodes - (rotations % totalNumberOfNodes) - 1;
    let tailAfterRotation = head;

    while (movesToNewTail-- > 0) {
        tailAfterRotation = tailAfterRotation.next;
    }

    let headAfterRotation = tailAfterRotation.next;
    tailAfterRotation.next = null;
    tailBeforeRotation.next = head;

    return headAfterRotation;
};
