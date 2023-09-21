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
    unordered_map<Node*, Node*> visited;

Node* copyRandomList(Node* head) {
    if (head == NULL) return NULL;
    
    // Check if the current node has already been copied
    if (visited.find(head) != visited.end()) {
        return visited[head];
    }
    
    // Create a new node for the current node
    Node* temp = new Node(head->val);
    visited[head] = temp;  // Store in the map to avoid duplicate work
    
    // Recursively copy the next and random pointers
    temp->next = copyRandomList(head->next);
    temp->random = copyRandomList(head->random);
    
    return temp;
}

};