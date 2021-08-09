#include<bits/stdc++.h>
using namespace std;

class LinkedList {
public:
	int data;
	LinkedList* next;
	LinkedList(int _data) {
		data = _data;
		next = NULL;
	}
};

LinkedList* createList(LinkedList* head, int data) {
	if(head == NULL)
		return new LinkedList(data);

	LinkedList* temp = head;
	while(head->next) {
		head = head->next;
	}
	head->next = new LinkedList(data);
	return temp;
}

void display(LinkedList* head) {
	if(head == NULL)
		return;
	while(head->next) {
		cout << head->data << "->";
		head = head->next;
	}
	cout << head->data << endl;
}

LinkedList* reverseList(LinkedList* head) {
	if(head == NULL)
		return head;

	LinkedList* prev = NULL;
	LinkedList* curr = head;
	LinkedList* temp = head;

	while(temp) {
		temp = temp->next;
		curr->next = prev;
		prev = curr;
		curr = temp;				
	}

	return prev;
}

LinkedList* reorderList(LinkedList* head) {
	if(head == NULL)
		return head;

	LinkedList* slow = head;
	LinkedList* fast = head;

	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	slow->next = reverseList(slow->next);

	//display(head);
	// 3->4->5->6
	// p2    p1 t

	LinkedList* p1 = slow;
	LinkedList* temp = NULL;
	LinkedList* p2 = head;

	while(p1->next && p2->next && p1 != p2) {
		temp = p1->next;
		p1->next = temp->next;
		temp->next = p2->next;
		p2->next = temp;
		p2 = p2->next->next;
	}

	return head;
}

int main() {
	int data;
	cin >> data;
	LinkedList* head = NULL;
	while(data != -1) {
		head = createList(head, data);
		cin >> data;
	}

	display(head);
	head = reorderList(head);
	display(head);

	return 0;
}

