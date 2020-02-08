#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;

	node():data{},next{nullptr} {}
	node(int d, node* ptr):data{d},next{ptr} {}
};

struct list{
	node* head;

	list():head{nullptr} {}

	void print() {
		node* curr = head;
		while(curr) {
			cout << curr->data << ' ';
			curr = curr->next;
		}
	}

        void reverse() {
		node* curr = head->next;
		node* prev = head;
		prev->next=nullptr;
		while(curr) {
			head = curr;
			curr = curr->next;
			head->next = prev;
			prev = head;
		}
	}

	void push(int i) {
		node* temp = new node(i, head);
                head = temp;  
	}

	int pop() {
		int res =0;
		if(head) {
		    res = head->data;
		    node* temp = head;
		    head = head->next;
		    delete temp;
		}
		return res;
	}
};

int main() {
	list l;
        for(int i=10;i>0;--i) {
                l.push(i);
	}
	l.print();cout << endl;
	l.reverse();
	l.print();cout << endl;
}
