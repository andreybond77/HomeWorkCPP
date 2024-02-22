
#include <iostream>


using namespace std;


template <typename T>
class Deque {
    T* deque = nullptr;
    int count = 0;
    int capacity;

public:
    Deque(int capacity)
    {
        deque = new T[capacity];
        this->capacity = capacity;
    }

    Deque(Deque& st) {
        this->count = st.count;
        this->capacity = st.capacity;
        if (deque != nullptr) delete[]deque;
        deque = new T[capacity];
        for (int i = 0; i < count; i++) {
            deque[i] = st.deque[i];
        }
    }

    void operator = (Deque& st) {
        this->count = st.count;
        this->capacity = st.capacity;
        if (deque != nullptr) delete[]deque;
        deque = new T[capacity];
        for (int i = 0; i < count; i++) {
            deque[i] = st.deque[i];
        }
    }
    ~Deque() {
        if (deque != nullptr)
            delete[]deque;
    }
    T top() {
        return deque[count - 1];
    }

    bool empty() {
        return !count;
    }

    int size() {
        return this->count;
    }

    void push_front(T el) {
        if (count >= capacity) return;
        deque[count++] = el;
    }

   

    T pop() {
        if (count == 0) return NULL;
        count--;
        return deque[count];
    }


   // void push_back(int key);
   // void pop_back();
  
};

template <typename T>
void showDeque(Deque<T> deque) {
    while (!deque.empty()) {
        cout << deque.pop();
    }
}





int main() {
    Deque<int> deque(8);
    cout << "---push 3 4 6 9 ---" << endl;

    deque.push_front(3);
    deque.push_front(4);
    deque.push_front(6);
    deque.push_front(9);
    deque.push_front(9);
    showDeque(deque);
    cout << endl;
    deque.pop();
    showDeque(deque);
    cout << endl;
  
    
    //showInfo(stack);
   // cout << endl;
    //stack.pop();
   // showDeque(deque);
  //  cout << endl;
  //  cout << endl;
   // deque.pop_r();
  //  showDeque(deque);
   // cout << endl;
    //deque.pop_r();
   // showDeque(deque);
   // cout << "--- pop" << endl;
   // cout << deque.pop() << endl;
    //cout << "--- showAll----" << endl;
   // showDeque(deque);
   // cout << endl;
   // cout << deque.top();
   // cout << endl;

   // cout << endl;
   // showDeque(deque);
}


