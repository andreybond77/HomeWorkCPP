#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* next;
};

template <typename T>
class LinkedList {
    Node<T>* head = nullptr;
    Node<T>* prev, * next;
    int count = 0;
public:
    void push(T value) {
        Node<T>* newNode = new Node<T>{ value, head };
        head = newNode;
        this->prev = this->next = NULL;
        count++;
    }

   void push_front(T value) {
       Node<T>* newNode = new Node<T>{ value, head };
       head = newNode;
       this->prev = NULL;  
        if (head != NULL)
            this->prev = nullptr;
       
        count++;
    }

    
    
   void push_back(T value) {
      

       Node<T>* buf = head;
       while (buf->next != nullptr) {
           buf = buf->next;
       }
       Node<T>* newNode = new Node<T>{ value, buf->next };
       buf->next = newNode;
       count++;
     

   }
     
   void pop_back() {
       if (count == 0) return;
       Node<T>* buf = head;
       while (head->next != nullptr) {
           buf = buf->next;
           
     
       }
       
       count--;
       delete[] buf;
   }
  
   
   
   
    void showAll() {
        Node<T>* buf = head;
        while (buf->next != nullptr) {
            cout << buf->value << " ";
            buf = buf->next;
        }
        cout << buf->value;
        cout << endl;
    }

    void insert(T value, int index) {
        if (index >= count || index < 0) return;
        if (index == 0) {
            push(value);
            return;
        }
        Node<T>* buf = head;
        for (int i = 0; i < index - 1; i++) {
            buf = buf->next;
        }
        Node<T>* newNode = new Node<T>{ value, buf->next };
        buf->next = newNode;
        count++;
    }

    void pop_front() {
        if (count == 0) return;
        Node<T>* buf = head;
        head = head->next;
        count--;
        delete[] buf;
    }

};


int main()
{
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) {
        list.push(i);
    }
    list.push_front(44);
    list.showAll();
    list.push_back(33);
    list.showAll();
    list.insert(55, 5);
    list.showAll();
    list.pop_front();
    list.showAll();
   // list.pop_back();
    list.showAll();
}