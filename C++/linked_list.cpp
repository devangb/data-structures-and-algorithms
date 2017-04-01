#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int input) {
	        this->data = input;
            this->next = NULL;
        }
};

class List {
    private:
        Node *head;

    public:
        List() {
            head = NULL;
        }

        void addNode(int data, int position = -1) {
            if (head == NULL || position == 0) {
                Node* next = head;
                head = new Node(data);
                head->next = next;
                return;
            } else {
                Node *next = head;
                Node *prevNext = next->next;
                position--;
                while (next->next != NULL && position !=0) { 
                    next = next->next;
                    prevNext = next->next;
                    position--;
                }
                next->next = new Node(data);
                next->next->next = prevNext;
                return;
            }
        }

        void iterateList() {
            if (head == NULL) {
                return;
            } else {
                Node *next = head;
                while (next != NULL) {
                    printf("%d ->", next->data);
                    next = next->next;
                }
                printf("\n");
                return;
            }
        }
};

int main() {
    List list;
    list.iterateList();
    list.addNode(1);
    list.iterateList();
    list.addNode(0,0);
    list.iterateList();
    list.addNode(2,2);
    list.iterateList();
    list.addNode(5,3);
    list.iterateList();
    list.addNode(3);
    list.iterateList();
    list.addNode(4);
    list.iterateList();
    list.addNode(6,5);
    list.iterateList();

    return 0;
}


