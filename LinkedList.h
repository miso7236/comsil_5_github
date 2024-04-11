#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

// LinkedList
template<typename T>
class Node {    // 템플릿 형태로 변경
public:
    T data;  
    Node<T> *link;  

    Node(T element) {
        data = element;
        link = NULL;
    }
};

// LinkedList Class as a template
template<typename T>
class LinkedList {
protected:
    Node<T> *first;  // 첫번째 노드의 주소를 저장할 포인터의 타입을 T로 변경
    int current_size;
public:
    LinkedList() {
        first = NULL;
        current_size = 0;
    };

    int GetSize() {
        return current_size;
    };

    void Insert(T element);  
    virtual bool Delete(T &element);
    void Print();
};

template<typename T>
void LinkedList<T>::Insert(T element) {
    Node<T> *newnode = new Node<T>(element);
    newnode -> link = first;
    first = newnode;
    current_size++;
}

template<typename T>
bool LinkedList<T>::Delete(T &element) {
    if (first == NULL)
        return false;

    Node<T> *current = first;
    Node<T> *previous = NULL;

    while (current->link != NULL) {
        previous = current;
        current = current->link;
    }

    if (previous)
        previous->link = current->link;
    else
        first = first->link;

    element = current->data;
    delete current;
    current_size--;

    return true;
}
/*
template<typename T>
void LinkedList<T>::Print() {
    Node<T> *i;
    int index = 1;

    for (i = first; i != NULL; i = i->link) {
        cout << "[" << index << "|" << i->data << "]->";
        index++;
    }
    if (current_size != 0) {
        cout << "NULL" << endl;
    } else {
        cout << "The list is empty." << endl;
    }
}
*/

template<typename T>
void LinkedList<T>::Print(){
	Node<T> *i;
	int index = 1;

	if (current_size != 0){
		for( i = first; i != NULL; i=i->link){
			if (index == current_size){
				cout << "[" << index << "|";
				cout << i -> data << "]";  //->";
			}
			
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}

#endif
