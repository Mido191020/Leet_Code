struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

class MyLinkedList {
private:
    Node* head;
    int length;

public:
    MyLinkedList() : head(nullptr), length(0) {}

    int get(int index) {
        if (index < 0 || index >= length) {
            return -1;
        }
        int ct = 0;
        Node* cur = head;
        while (cur) {
            if (ct == index) {
                return cur->val;
            }
            cur = cur->next;
            ct++;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* cur = head;
            while (cur->next) {
                cur = cur->next;
            }
            cur->next = newNode;
        }
        length++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
        } else if (index == length) {
            addAtTail(val);
        } else {
            Node* newNode = new Node(val);
            Node* cur = head;
            int ct = 0;
            while (cur) {
                if (ct + 1 == index) {
                    newNode->next = cur->next;
                    cur->next = newNode;
                    length++;
                    return;
                }
                cur = cur->next;
                ct++;
            }
        }
    }

    void deleteAtIndex(int index) {
        if (index >= length || index < 0) {
            return;
        }
        if (index == 0) {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
            length--;
            return;
        }
        Node* cur = head;
        int ct = 0;
        while (cur) {
            if (ct + 1 == index) {
                Node* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                length--;
                return;
            }
            cur = cur->next;
            ct++;
        }
    }

    ~MyLinkedList() {
        Node* p = head;
        while (head != nullptr) {
            head = head->next;
            delete p;
            p = head;
        }
    }

};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */