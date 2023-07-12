/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> nodeMap;

        Node* originalNode = head;
        while (originalNode != nullptr) {
            Node* copiedNode = new Node(originalNode->val);
            nodeMap[originalNode] = copiedNode;
            originalNode = originalNode->next;
        }

        originalNode = head;
        while (originalNode != nullptr) {
            Node* copiedNode = nodeMap[originalNode];
            copiedNode->next = nodeMap[originalNode->next];
            copiedNode->random = nodeMap[originalNode->random];
            originalNode = originalNode->next;
        }

        return nodeMap[head];
    }
};
