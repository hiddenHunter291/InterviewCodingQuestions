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

LinkedList* reverseList(LinkedList* head) {
	LinkedList* current = head;
	LinkedList* temp = head;
	LinkedList* previous = NULL;
	while(current) {
		current = current->next;
		temp->next = previous;
		previous = temp;
		temp = current;
	}
	return previous;
}

LinkedList* deleteNode(LinkedList* head, int number) {
	LinkedList* previous = NULL;
	LinkedList* temp = head;
	while(temp) {
		if(temp->value == number) break;
		previous = temp;
		temp = temp->next;
	}
	if(temp == NULL) {
		cout << "Node not found" << endl;
		return head;
	}
	if(previous == NULL) return head->next;
	previous->next = temp->next;
	return head;
}

int main() {
	LinkedList* head = NULL;
	int number;
	cin >> number;
	while(number != -1) {
		head = createNode(head, number);
		cin >> number;
	}
	Display(head);
	head = reverseList(head);
	Display(head);
	return 0;
}