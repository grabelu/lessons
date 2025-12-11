#include <iostream>
#include <memory>
#include <vector>

#include <gtest/gtest.h>

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

        static bool Compare (LinkedList<int> &list1, LinkedList<int> &list2)
        {
            if (list1.size != list2.size)
                return false;

            Node<T>* tmp1 = list1.head;
            Node<T>* tmp2 = list2.head;

            while(tmp1 && tmp2)
            {
                if (tmp1->value != tmp2->value)
                    return false;

                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }

            return true;
        }

};


struct LinkedListTest2 : public testing::Test {
  LinkedList<int> list1;
  LinkedList<int> list2;

  void SetUp() {
      for (int i = 0; i < 10; i++) {
          list1.Append(i);
          list2.Append(i);
      }

      std::cout << "init setup: " << std::endl;

      list1.Print();
      list2.Print();

  } // аналог конструктора


  void TearDown() {

      list1.Clear();
      list2.Clear();

      std::cout << "deinit: " << std::endl;

      list1.Print();
      list2.Print();
  } // аналог деструктора
};


TEST_F (LinkedListTest2, test2) {
    EXPECT_TRUE(LinkedList<int>::Compare(this->list1, this->list2));
}


TEST (LinkedListTest, comparetwolinkedlists)
{
    LinkedList <int> list1;
    LinkedList <int> list2;

    for (int i = 0; i < 10; i++) {
        list1.Append(i);
        list2.Append(i);
    }

    EXPECT_TRUE(LinkedList<int>::Compare(list1, list2));
}

int main(int argc, char **argv) {
    // GTest сам запускает тесты
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

