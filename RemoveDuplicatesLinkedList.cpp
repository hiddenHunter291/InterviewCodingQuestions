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

LinkedList* removeDuplicates(LinkedList* head) {
    LinkedList* dummy = new LinkedList(-1);
    if(!head && !head->next) return head;
    LinkedList* tail = dummy;
    bool flag = true;
    while(head) {
        while(head && head->next && head->value == head->next->value) {
            flag = false;
            head = head->next;
        }
        if(flag) {
            tail->next = head;
            tail = tail->next;
        }
        head = head->next;
        flag = true;
    }
    tail->next = NULL;
    return dummy->next;
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
	head = removeDuplicates(head);
	Display(head);
	return 0;
}