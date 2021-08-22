#include<bits/stdc++.h>
using namespace std;

class LinkedList {
public:
	int value;
	LinkedList* next;

	LinkedList(int x) {
		value = x;
		next = NULL;
	}
};

void Display(LinkedList* head) {
	while(head) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << "\n";
}

LinkedList* createNode(LinkedList* head, int number) {
	if(head == NULL) return new LinkedList(number);
	LinkedList* temp = head;
	while(temp->next)
		temp = temp->next;
	temp->next = new LinkedList(number);
	return head;
}


LinkedList* removeNthNodeFromLast(LinkedList* head, int n) {
	LinkedList* temp = head;
	for(int i = 0; i < n - 1; i++) {
		temp = temp->next;
	}
	//cout << "hari";
	LinkedList* previous = NULL;
	LinkedList* curr = head;
	while(temp->next) {
		temp = temp->next;
		previous = curr;
		curr = curr->next;
	}
	if(!previous)
		return head->next;
	previous->next = curr->next;
	return head;
}

int main() {
	LinkedList* head = NULL;
	int number, n;
	cin >> number;
	while(number != -1) {
		head = createNode(head, number);
		cin >> number;
	}
	cout << "Enter the number N: ";
	cin >> n;
	head = removeNthNodeFromLast(head, n);
	Display(head);
	return 0;
}
