/*
    bộ nhớ gồm các ô nhớ
    giá trị lưu trong ô nhớ gồm các bit
*/
#include <bits/stdc++.h>

typedef struct Node {   
    int value;
    Node* next; 
    Node* prev;
    Node(int v) {
        value = v;
        next = NULL;
        prev = NULL;
    }
};

typedef struct List {
    Node* head = NULL;
    Node* tail = NULL;
    int n = 0;
    void addNode(int v) {
        n++;
        Node* q = new Node(v);
        if(isEmpty()) {
            head = q;
            tail = q;
        } else {
            tail->next = q;
            q->prev = tail;
            tail = q;
        }
    }
    void display() {
        Node* p = head;
        printf("Danh sach co %d phan tu: ", n);
        while(p != tail) {
            printf("%d ", p->value);
            p = p->next;
        }
        printf("%d ", tail->value);
        printf("\n");
    }
    void displayprev() {
        Node* p = tail;
        printf("Danh sach co %d phan tu: ", n);
        while(p != head) {
            printf("%d ", p->value);
            p = p->prev;
        }
        printf("%d ", head->value);
        printf("\n");
    }
    void delete_() {
        while(head != NULL) {
            Node* p = head;
            head = head->next;
            n--;
            free(p);
        }
        tail = NULL;
    }
    int findValue(int v) {
        Node* p = head;
        int count = 0;
        while(p->value != v) {
            p = p->next;
            count++;
        }
        return count + 1;
    }
    void eraseValue(int v) {
        n--;
        Node* p = head;
        while(p->value != v) {
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
    bool isEmpty() {
        return head == NULL && tail == NULL;
    }
};

int main() {

    // List L;
    // L.addNode(1);
    // L.addNode(2);
    // L.addNode(3);
    // L.addNode(4);
    // L.addNode(5);
    // L.display(); 
    // L.displayprev();
    // printf("Node co gia tri = 3 la: %d\n", L.findValue(3));
    // L.eraseValue(3);
    // L.display();

    Node* first = (Node*) malloc(sizeof(Node));
    Node* second = (Node*) malloc(sizeof(Node));
    Node* third = (Node*) malloc(sizeof(Node));
    Node* fourth = (Node*) malloc(sizeof(Node));

    first->value = 1;
    first->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = fourth;
    fourth->value = 4;
    first->next->next->next->value = 5;

    printf("%d -> %d -> %d -> %d", first->value, second->value, third->value, fourth->value);

    return 0;
}