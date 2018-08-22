#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        void print_reverse(Node<T>* head);

    public:
        List()
        {
                head = nullptr;
                tail = nullptr;
        };

        T front(){return head -> data;};
        T back(){return tail -> data;};

        void push_front(T value)
        {
                Node<T>* aux = new Node<T>;
                aux -> data = value;
                aux -> next = nullptr;

                if(empty())
                {
                        head = aux;
                        tail = aux;
                        aux = nullptr;
                }

                else
                        {
                                aux -> next = head;
                                head = aux;
                        }

                        aux = nullptr;
        };

        void push_back(T value)
        {
                Node<T>* aux = new Node<T>;
                aux -> data = value;
                aux -> next = nullptr;

                if(empty())
                {
                        head = aux;
                        tail = aux;
                        aux = nullptr;
                }

                else
                        {
                                tail -> next = aux;
                                tail = aux;
                        }

                        aux = nullptr;
        };

        void pop_front()
        {
                Node<T>* aux = new Node<T>;
                aux = head -> next;
                delete head;
                head = aux;
        };

        void pop_back()
        {
        };

        T get(int position)
        {
        };

        void concat(List<T> &other)
        {

        };

        bool empty()
        {
                return (head == nullptr);
        };

        int size();
        void print();
        void print_reverse();
        void clear();


        /*Iterator<T> begin();
        Iterator<T> end();*/

        /*~List();*/
};
#endif
