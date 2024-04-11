#include "LinkedList.h"

template<typename T>
class Stack : public LinkedList<T> {
public:
    bool Delete(T &ret) {
        // 스택이 비어있음
        if (this -> first == NULL) {
            return false;
        }

        // 첫 번째 노드를 삭제 (스택의 top)
        Node<T> *temp = this -> first;  
        ret = temp -> data;
        this -> first = this -> first->link;  // 노드 변경
        delete temp;    // 메모리 해제
        this -> current_size--; // 스택 크기 조정

        return true;
    }
};
