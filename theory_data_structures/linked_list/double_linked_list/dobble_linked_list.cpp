#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  node *next = NULL;
  node *previous = NULL;
};

class List {
  private:
    node *head = new node;
  public:
    List() {
      head->next = NULL;
      head->previous = NULL;
    };
    bool isEmpty() {
      return (head->previous == NULL && head->next == NULL);
    }
    void insert(int data);
    void show(bool inverseOrder);
};

void List::insert(int data) {
  node *no = new node;
  no->data = data;
  no->next = NULL;
  no->previous = NULL;

  if (isEmpty()) {
    head->next = no;
    no->previous = head;
  } else {
    node *parent = head;
    node *ptr = head->next;
    while(ptr != NULL) {
      parent = ptr;
      ptr = ptr->next;
    }
    no->previous = parent;
    parent->next = no;
  }
}

void List::show(bool inverseOrder) {
  if (isEmpty()) {
    return;
  }
  node *parent = head;
  node *ptr = head->next;
  while(ptr != NULL) {
    parent = ptr;
    cout << ptr->data << " ";
    ptr = ptr->next;  
  }
  cout << endl;
  if (inverseOrder) {
    cout << "List inverse order: ";
    node *ptr = parent->previous;
    while(ptr != NULL) {
      if (ptr->previous != NULL) {
        cout << ptr->data << " ";
      }
      ptr = ptr->previous;
    }
    cout << endl;
  }
}

int main() {
  List list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);
  list.show(true);
  return 0;
}