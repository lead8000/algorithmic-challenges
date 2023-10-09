
class Node {
public:
    int Key;
    int Value;
    int H;
    Node* Parent{nullptr};
    Node* Left{nullptr};
    Node* Right{nullptr};

    Node(int key, int value){
        this->Key = key;
        this->Value = value;
    }
};

class MyHashMap {
private:
    Node* __root;

    Node *search(Node* current, int key) {
        if (key < current->Key) {
            if (current->Left == nullptr)
                return current;
            return search(current->Left, key);
        }
        else if (key > current->Key) {
            if (current->Right == nullptr)
                return current;
            return search(current->Right, key);
        }
        return current;
    }

    Node* insert(Node* current, int key, int value) {
        current = search(current, key);

        if (current->Key < key)
        {
            auto newNode = new Node(key, value);
            newNode->Parent = current;
            current->Left = newNode;
            return newNode;
        }
        if (current->Key > key)
        {
            auto newNode = new Node(key, value);
            newNode->Parent = current;
            current->Right = newNode;
            return newNode;
        }

        current->Value == value;
        return nullptr;
    }

    Node* min(Node* current, int key) {
        if (current->Left != nullptr)
            return min(current->Left, key);
        return current;
    }

    void rightRotation(Node* current) {

    }

    void leftRotation(Node* current) {

    }

public:
    MyHashMap() {}

    void put(int key, int value) {
        if (__root == nullptr) {
            __root = new Node(key, value);
            return;
        }
        auto insertedNode = insert(__root, key, value);
        if (insertedNode != nullptr) {

        }
    }

    int get(int key) {
        auto nearestNode = search(this->__root, key);
        if (nearestNode->Key == key) 
            return nearestNode->Value;
        return -1;
    }

    void remove(int key) {
        auto nearestNode = search(this->__root, key);
        if (nearestNode->Key == key) {
            auto updateParent = [](Node* current, Node* value) {
                if (current->Parent->Left == current) {
                    current->Parent->Left = value;
                }
                else {
                    current->Parent->Right = value;
                }
            };

            if (nearestNode->Parent == nullptr) {
                this->__root = nullptr;
                delete nearestNode;
                return;
            }
            if (nearestNode->Left == nullptr && nearestNode->Right == nullptr) {
                updateParent(nearestNode, nullptr);
                delete nearestNode;
                return;
            }
            if (nearestNode->Left == nullptr) {
                updateParent(nearestNode, nearestNode->Right);
                nearestNode->Right->Parent = nearestNode->Parent;
                delete nearestNode;
                return;
            }
            if (nearestNode->Right == nullptr) {
                updateParent(nearestNode, nearestNode->Left);
                nearestNode->Left->Parent = nearestNode->Parent;
                delete nearestNode;
                return;
            }

            auto min_max = min(nearestNode->Right, key);
            
            updateParent(nearestNode, min_max);
            
            min_max->Left = nearestNode->Left;

            if (min_max->Parent != nearestNode) {
                if (min_max->Right != nullptr) {
                    updateParent(min_max, min_max->Right);
                    min_max->Right->Parent = min_max->Parent;
                }
                min_max->Right = nearestNode->Right;
            }
            
            min_max->Parent = nearestNode->Parent;

            delete nearestNode;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */