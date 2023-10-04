class MyHashMap {

private:
struct ListNode {
    int key;
    int val;
    ListNode* next;

    ListNode() {
        this->key = -1;
        this->val = -1;
        this->next = nullptr;
    }

    ListNode(int key_, int val_) {
        this->key = key_;
        this->val = val_;
        this->next = nullptr;
    }
};

ListNode* head;

bool inMap(int key) {

    ListNode* curr = head;

    while(curr != nullptr) {

        if(curr->key == key)
            return true;

        curr = curr->next;
    }

    return false;
}

ListNode* addNode(int key, int val) {

    if(head == nullptr) {
        
        head = new ListNode(key,val);
        return head;
    }

    ListNode* curr = head;

    while(curr->next != nullptr)
        curr = curr->next;

    ListNode* newNode = new ListNode(key, val);
    curr->next = newNode;
    return head;

}

ListNode* updateKey(int key, int val) {

    ListNode* curr = head;
    while(curr != nullptr)
    {
        if(curr->key == key)
        {
            curr->val = val;
            return head;
        }
        curr = curr->next;
    }

    return head;
}

ListNode* deleteNode(int key) {

    if(head == nullptr)
        return nullptr;

    if(head->key == key) {
        head = head->next;
        return head;
    }

    ListNode* curr = head;
    while(curr->next != nullptr) {
            if(curr->next->key == key)
            {
                ListNode* temp = curr->next;
                curr->next = temp->next;
                return head;
            }

            curr = curr->next;
        }

    return head;
}

public:
    MyHashMap() {
        head = nullptr;
    }
    
    void put(int key, int value) {
        
        if(inMap(key))
        {
            head = updateKey(key, value);
            return;
        }

        head = addNode(key, value);
    }
    
    int get(int key) {
        
    if(inMap(key))
    {     
        ListNode* curr = head;
        while(curr != nullptr)
        {
            if(curr->key == key)
                return curr->val;

            curr = curr->next;
        }

    }

    return -1;    
}
    
    void remove(int key) {
        
        if(inMap(key)) 
            head = deleteNode(key);
    }

    void printList()
    {
        if(head == nullptr)
        {
            cout<<"Empty"<<endl;
            return;
        }

        ListNode* curr = head;
        while(curr != nullptr) {
            cout<<curr->key<<" : "<<curr->val<<" ";

            curr = curr->next;
        }

        cout<<endl;
    }
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
