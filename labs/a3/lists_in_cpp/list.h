#include <iostream>
using namespace std;

class List
{
private:
    struct Node{
        int value;
        Node* next;
    };
    Node* head;
    Node* tail;
    size_t size;

public:

    List() : head(nullptr), tail(nullptr), size(0){}

    ~List(){ 
        clear(); 
    }

    List(const List& other) : head(nullptr), tail(nullptr), size(0){
        Node* current = other.head;
        while(current){
            append(current->value);
            current = current->next;
        }
    }

    List& operator=(const List& other){
        if (this != &other){
            clear();
            Node* current = other.head;
            while(current){
                append(current->value);
                current = current->next;
            }
        }
        return *this;
    }

    void append(int value){
        Node *newNode = new Node{value, nullptr};
        if(!head){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        ++size;
    }

    List operator+(const List& other){
        List result = *this;
        Node* current = other.head;
        while(current){
                result.append(current->value);
                current = current->next;
        }
        return result;
    }

    int& operator[](size_t index){
        if(index>=size){
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (size_t i = 0; i < index; ++i){
            current = current->next;
        }
        return current->value;
    }

    const int& operator[](size_t index) const{
        if(index>=size){
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (size_t i = 0; i < index; ++i){
            current = current->next;
        }
        return current->value;
    }

    // This function is used to print the list.
    // The signature of this function is kept since 'friend' functions have not been covered yet. You may
    // ignore the 'friend' keyword and implement the function as a normal member function.
    friend std::ostream &operator<<(std::ostream &os, const List &list)
    {
        Node* current = list.head;
        os << "[";
        while (current)
        {
            os << current->value;
            if(current->next) os << ", ";
            current = current -> next;
        }
        
        os << "]";
        return os;
    }

    size_t getSize() const{
        return size;
    }

private:
    void clear(){
        while(head){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
        size=0;
    }

};