// Copyright 2022 NNTU-CS
template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 private:
    struct Node {
        T value;
        Node* next;
    };
    Node* head;

 public:
    TPQueue() {
        head = nullptr;
    }
    ~TPQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push(const T& item) {
        Node* newNode = new Node;
        newNode->value = item;
        newNode->next = nullptr;
        if (head == nullptr || item.prior > head->value.prior) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr &&
               current->next->value.prior >= item.prior) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    T pop() {
        Node* temp = head;
        T result = head->value;
        head = head->next;
        delete temp;
        return result;
    }
};

struct SYM {
  char ch;
  int prior;
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
