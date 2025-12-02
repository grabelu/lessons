#include <iostream>
#include <memory>
#include <vector>

template <typename T>
struct Node {
    T value;
    Node* next;

    Node (const T &new_value) {
        value = new_value;
        next = nullptr;
    }

    Node () {
        value = T();
        next = nullptr;
    }


    /*
    ~Node ()
    {
        if (!nullptr)
            delete
    }
    */
};


template <typename T>
class LinkedList {

private:
        Node<T>* head;
        Node<T>* tail;
        unsigned int size;

public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        ~LinkedList() {
            Clear();
        }

 public:
        void Clear(){
            while (head != nullptr) {
                Node<T> * tmp = head;
                head  = head->next;
                delete tmp;
            }
            tail = nullptr;
            size = 0;
        }

        void Append (const T &val) {
                if (size == 0)
                {
                    head = new Node<T> (val);
                    tail = head;
                }
                else
                {
                    tail->next = new Node<T> (val);
                    tail = tail->next;
                }

                size++;
        }

        bool DeleteVal (const T &val) {

                if (size == 0){
                    return false;
                }

                if (head->value == val) {
                    Node <T> * tmp = head;
                    head = head->next;
                    delete tmp;
                    size--;

                    return true;
                }

                Node<T>* current = head;

                while (current->next != nullptr) {

                    if (current->next->value == val)
                    {
                        Node <T> * tmp = current->next;
                        current->next = current->next->next;
                        delete tmp;

                        size--;
                        return true;
                    }

                    current = current->next;
                }

                return false;
        }

        Node<T>* Find (const T &val) const {
            Node<T>* tmp = head;

            while (tmp != tail) {
                if (tmp->value == val)
                    return tmp;
            }

            return nullptr;
        }

        void Print() const
        {
            for (Node<T> * tmp = head; tmp != nullptr; tmp = tmp->next)
                std::cout << " " << tmp->value << ";";

            std::cout << std::endl;
        }

};



int main() {
    std::cout << "Hello, world!" << std::endl; // prints text and ends line

        LinkedList <int> list;

        for (int i = 0; i < 10; i++)
            list.Append(i);

        list.Print();


        std::cout << "Delete" << std::endl;

        list.DeleteVal(5);

        list.Print();


    return 0;
}
