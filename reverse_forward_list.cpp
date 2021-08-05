#include <iostream>
using namespace std;

template<class T>
struct node {
    T data;
    node* next;

    node():data{},next{nullptr} {}
    node(T d, node* ptr):data{d},next{ptr} {}
    node(const node& n):node{n.d, n.next} {}
    node& operator=(const node& n) {
        data = n.data;
        next = n.next;
        return *this;
    }
};

template<class T>
struct list{
    node<T>* head;

    list():head{nullptr} {}

    ~list(){
        while(head) {
            node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() {
        node<T>* curr = head;
        while(curr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
    }

    void reverse() {
        if(!head)return;
        node<T>* curr = head->next;
        node<T>* prev = head;
        prev->next=nullptr;
        while(curr) {
            head = curr;
            curr = curr->next;
            head->next = prev;
            prev = head;
        }
    }

    void push(T i) {
        node<T>* temp = new node<T>(i, head);
        head = temp;
    }

    int pop() {
        int res =0;
        if(head) {
            res = head->data;
            node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        return res;
    }
};

int main() {
	cout << "test" << endl;
    list<int> l;
    l.reverse();
        for(int i=10;i>0;--i) {
                l.push(i);
    }
    l.print();cout << endl;
    l.reverse();
    l.print();cout << endl;
}
