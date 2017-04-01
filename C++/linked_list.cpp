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

        void addNode(int data) {
            if (head == NULL) {
                head = new Node(data);
                return;
            } else {
                Node *next = head;
                while (next->next != NULL) { 
                    next = next->next;
                }
                next->next = new Node(data);
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
    list.addNode(2);
    list.iterateList();
    list.addNode(3);
    list.iterateList();
    list.addNode(4);
    list.iterateList();

    return 0;
}


