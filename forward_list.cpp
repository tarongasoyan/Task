#include <iostream>

template <typename T>
class List
{
    struct Node
    {
        T data;
        Node *next;
        Node(T d = T(), Node *ptr = nullptr) : data(d), next(ptr) {}
    };
    Node *head;

public:
    List() : head(nullptr){};
    List(const List &rhs) {
        if(rhs.head !=nullptr) {
            Node* node = new Node();
            head = node;
            Node* prev = node;
            Node* tmp = rhs.head;
            node->data = tmp->data;
            tmp = tmp->next;
            while (tmp != nullptr) {
                Node *rev = new Node();
                rev->data = tmp->data;
                prev->next = rev;
                prev = prev->next;
                tmp = tmp->next;
            }
        }
    }
    List(List && rhs) {
        this->head = rhs.head;
        rhs.head = nullptr;
    }
    ~List();
    friend std::ostream &operator<<(std::ostream &os, const List &rhs)
    {
        Node *tmp = rhs.head;
        while (tmp != nullptr)
        {
            os << tmp->data;
            tmp = tmp->next;
        }
        return os;
    }
    List<T>& operator+(List<T>& rhs) {
    Node *tmp = this->head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = rhs.head;
    rhs.head = nullptr;
    return *(this);
    }

    List<T>& operator=(const List<T>& rhs) {
    if (this->head == rhs.head)
    {  
        return *(this);
    }

    Node *node = new Node();
    head = node;
    Node *prev = node;
    Node *tmp = rhs.head;
    node->data = tmp->data;
    tmp = tmp->next;
    while (tmp != nullptr)
    {
        Node *tmpp = new Node();
        tmpp->data = tmp->data;
        prev->next = tmpp;
        prev = prev->next;
        tmp = tmp->next;
    }
    return *(this);
    }

    void print()
    {
        Node *tmp = head;
        while (tmp)
        {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
            while (tmp)
            {
                std::cout << tmp->data << " ";
                tmp = tmp->next;
            }
        }
    }
    void push_front(T);
    void push_back(T);
    void pop_back();
    void insert(int, T);
    void insert();
};

int main()
{
    List<int> obj1;
    obj1.push_back(8);
    List<int> obj;
    obj.push_back(5);
    std::cout << obj1 + obj;
    // obj.push_front(15);
    // obj.pop_back();
   
    // std::cout << std::endl;
    // obj.insert(1, 200);
    // obj.print();
    return 0;
}

template <typename T>
void List<T>::push_back(T elem)
{
    if (!head)
    {
        head = new Node(elem);
    }
    else
    {
        Node *ptr = new Node(elem);
        Node *tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = ptr;
        ptr = nullptr;
    }
}

template <typename T>
void List<T>::insert(int index, T elem)
{
    if (!head)
    {
        Node *ptr = new Node(elem);
        head = ptr;
        ptr->next = nullptr;
    }
    else
    {
        if (index == 0)
        {
            Node *ptr = new Node(elem);
            Node *tmp = head;
            head = ptr;
            ptr->next = tmp;
            tmp = nullptr;
            return;
        }
        Node *last = new Node(elem);
        Node *tmp = head;
        Node *ptr = head;
        for (int i = 0; i < index; ++i)
        {
            tmp = tmp->next;
        }
        for (int i = 0; i < index - 1; ++i)
        {
            ptr = ptr->next;
        }
        ptr->next = last;
        last->next = tmp;
        ptr = nullptr;
        tmp = nullptr;
    }
}

template <typename T>
List<T>::~List()
{
    if (head != nullptr)
    {
        while (head)
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    head = nullptr;
}

template <typename T>
void List<T>::push_front(T elem)
{
    if (!head)
    {
        head = new Node(elem);
    }
    else
    {
        Node *ptr = new Node(elem);
        Node *tmp = head;
        head = ptr;
        ptr->next = tmp;
        tmp = nullptr;
    }
}

// template <typename T>
// void List<T>::pop_back()
// {
//     if (!head)
//     {
//         return;
//     }
//     else
//     {
//         Node *tmp = head;
//         int count = 0;
//         while (tmp->next != nullptr)
//         {
//             tmp = tmp->next;
//             count++;
//         }
//         delete tmp;
//         tmp = nullptr;
//         Node *ptr = head;
//         for (int i = 0; i < count - 1; i++)
//         {
//             ptr = ptr->next;
//         }
//         ptr->next = nullptr;
//     }
// }
