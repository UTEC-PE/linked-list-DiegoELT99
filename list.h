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
        List() //Completado
        {
            head = nullptr; //No hay cabeza
            tail = nullptr; //No hay cola
            nodes = 0; //Los nodos empiezan en 0
        };

        T front() //Completado
        {
            if(!head) //Si no hay cabeza
            {
                throw "Lista Vacia"; //La lista esta vacia.
            }

            else //Si hay cabeza
                return head -> data; //Se retorna su valor
        };

        T back() //Completado
        {
            if(!head) //Si no hay cabeza
            {
                throw "Lista Vacia"; //La lista esta vacia
            }

            else //Si hay cabeza
                return tail -> data; //Se retorna el valor de la cola
        };

        void push_front(T value) //Completado
        {
            Node<T>* NewHead = new Node<T>; //Se crea un nuevo puntero a Nodo
            NewHead -> data = value; //Su data es igual al valor asignado
            NewHead -> next = nullptr; //No tiene next por el momento

            if(empty()) //Si la lista esta vacia
            {
                head = NewHead; //El nuevo nodo se vuelve cabeza
                tail = NewHead; //Y tambien cola
            }

            else //Si la lista tiene elementos
                {
                    NewHead -> next = head; //La cabeza actual se vuelve el Next
                    head = NewHead; //Y el nuevo puntero pasa a ser la nueva cabeza
                }

                nodes++; //Se aumenta el numero de nodos.
        };

        void push_back(T value) //Completado
        {
            Node<T>* NewTail = new Node<T>; //Se crea un puntero a nuevo Nodo
            NewTail -> data = value; //Se le asigna el valor dado como parametro.
            NewTail -> next = nullptr; //Este no va a tener un next.
            
            if(empty()) //Si la lista esta vacia
            {
                head = NewTail; //La cola se volvera cabeza
                tail = NewTail; //Y tambien cola.
            }

            else //Caso contrario
                {
                    tail -> next = NewTail; //La tail actual apunta a la nueva cola
                    tail = NewTail; //Y la nueva cola pasa a volverse tail.
                }

                nodes++; //Se aumenta el numero de nodos.
        };

        void pop_front() //Completado
        {
            if(!head) //Si la lista esta vacia
                throw "Lista Vacia"; //Se da la excepcion

            if(nodes == 1){head = nullptr; tail = nullptr;} //Si la lista tiene solo un elemento se resetea la cabeza y cola

            else
                {
                    Node<T>* Auxiliar = head -> next; //Creamos un Puntero a un Nodo Auxiliar, que le sigue a la cabeza
                    delete head; //Borramos la cabeza
                    head = Auxiliar; //El nodo auxiliar pasa a volverse cabeza.
                }

            nodes--; //Se reduce el numero de nodos.
        };

        void pop_back() //Completado
        {
            if(!head) //Si la lista esta vacia
                throw "Lista Vacia"; //Se da la excepcion

            if(nodes == 1){head = nullptr; tail = nullptr;} //Si solo hay un elemento se resetean cabeza y cola.

            else
            {
                Node<T>* Current = head; //Creamos un current para iterar hasta el anterior al tail.

                while(Current -> next != tail){Current = Current -> next;} //Avanza hasta el anterior.

                Current -> next = nullptr; //El current ya no apuntara a nada
                delete tail; //Se elimina la cola actual
                tail = Current; //El current se vuelve tail ahora.
            }

            nodes--; //Se reduce el numero de nodos.
        };

        T get(int position) //Completado
        {
            if(!head) //Si la lista esta vacía
                throw "Lista Vacia"; // Se da una excepcion

            else if(position > nodes - 1 || position < 0) //Si se da un valor no posible.
                throw "Valor invalido"; //Se da una excepcion

            else if(position == nodes - 1) //Por conveniencia si se nos pide el ultimo valor
                return tail -> data; //Retornamos tail

            Node<T>* Current = head; //Creamos un valor para iterar entre los valores

            while(position--) //La posicion funciona como un contador que va disminuyendo
            {
                Current = Current -> next; //El current va subiendo
            }

            return Current -> data; //Se retorna el valor del current
        };

        void concat(List<T> &other) //Completado
        {
            if(!head) //Si es que la lista esta vacia
            {
                head = other.head; //La lista concatenada basicamente se copia
                tail = other.tail;
            }

            else //Caso contrario
                {
                    tail -> next = other.head; //La cola pasa a apuntar a la cabeza de la otra lista
                    tail = other.tail; //Y la cola de esa lista se vuelve la cola de toda
                }

                nodes += other.size(); //El tamaño de los nodos aumenta por la cantidad de los nodos de la otra lista.
        };

        bool empty() //Completado
        {
                return (head == nullptr); //La lista esta vacia si la cabeza es nada.
        };

        int size() //Completado
        {
            return nodes; //El size es la cantidad de nodos que tiene la lista.
        };

        void print() //Completado
        {
            if(!head) //Si no hay cabeza
                throw "Lista Vacia"; //Damos la excepcion

            Node<T>* Current = head; //Creamos un Nodo que va a iterar entre todos los elementos.

            while(Current) //Mientras haya Current
            {
                cout << Current -> data << " "; //Se da su data seguida de un espacio.
                Current = Current -> next; //Se mueve al siguiente.
            }
        };

        void print_reverse() //Completado
        {
            if(!head) //Si la lista esta vacia
                throw "Lista Vacía"; //Se da una excepcion

            else
            {
                int Counter = size(); //Se crea un contador
                while (Counter--) //Mientras este contador no llegue a 0
                {
                    cout << get(Counter) << " "; //Se van sacando los valores en reversa.
                }
            }
        };

        void clear() //Completado
        {
            if(!head) //Si la lista ya esta vacia
                throw "La lista ya esta limpia";  //Se da la excepcion
            else
                {
                    head -> killSelf(); //La cabeza realiza la limpieza en cadena.
                }

                nodes = 0; //Se reinicia el numero de nodos tambien.
        };

        /*Iterator<T> begin();
        Iterator<T> end();*/

        /*~List();*/
};
#endif
