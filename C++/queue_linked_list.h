
#ifndef QUEUE_LINKED_LIST_H_
#define QUEUE_LINKED_LIST_H_
#include <vector>
namespace containers {
template<typename T>

class QueueLinkedList {
 public:
  struct Node {
    T value;
   private:
    Node *next;
    explicit Node(T data) : value(data), next(nullptr) {}
    friend class QueueLinkedList<T>;
  };

  QueueLinkedList();
  QueueLinkedList(const QueueLinkedList<T> &);
  QueueLinkedList(QueueLinkedList<T> &&);
  QueueLinkedList<T> &operator=(QueueLinkedList<T> a);
  std::vector<T> ToVector() const;
  std::vector<int> FindAll(const T &value) const;
  bool operator==(const QueueLinkedList<T> &a) const;
  bool operator!=(const QueueLinkedList<T> &a) const;
  Node *operator[](int a) const {
    Node *node = head;
    int count = 0;
    while (node != nullptr) {
      if (a == count) {
        return node;
      }
      count++;
      node = node->next;
    }
  }
  QueueLinkedList(std::initializer_list<T>);
  Node *Head();
  ~QueueLinkedList();
  Node *Tail() const {
    return tail;
  }
  int Find(const T &value) const;

  int Size() const;
  bool IsEmpty() const;
  void Push(const T &val);
  void Push(T &&val);
  T Pop();

 private:
  Node *head;
  Node *tail;
  int _size;
};
template<typename T>
QueueLinkedList<T>::QueueLinkedList() {
  head = nullptr;
  tail = nullptr;
  _size = 0;
}
template<class T>
typename QueueLinkedList<T>::Node * QueueLinkedList<T>::Head() {
  return QueueLinkedList<T>::head;
}
template<typename T>
QueueLinkedList<T>::QueueLinkedList(std::initializer_list<T>) {
  QueueLinkedList();
}
template<typename T>
QueueLinkedList<T>::~QueueLinkedList() {
  while (!IsEmpty()) {
    Pop();
  }
}
template<typename T>
void QueueLinkedList<T>::Push(const T &val) {
  Node *node = new Node(val);
  if (IsEmpty()) {
    head = node;
    tail = node;
    node->next = nullptr;
    head->next = tail;
  }
  tail->next = node;
  tail = node;
  node->next = nullptr;

  _size++;
}
template<typename T>
std::vector<int> QueueLinkedList<T>::FindAll(const T &val) const {
  std::vector<int> res;
  int count = 0;
  Node *temp = head;
  while (temp != nullptr) {
    if (temp->value == val) {
      res.push_back(count);
    }

    count++;
  }
  return res;
}
template <typename T>
bool QueueLinkedList<T>::operator!=(const QueueLinkedList<T> &a) const {
  bool res = (*this == a);
  return !res;
}
template<typename T>
int QueueLinkedList<T>::Find(const T &value) const {
  int count = 0;
  int i = -1;
  Node *temp = head;
  while (temp != nullptr) {
    if (temp->value == value) {
      i = count;
      break;
    }
    temp = temp->next;
    count++;
  }
  return i;
}
template<typename T>
bool QueueLinkedList<T>::IsEmpty() const {
  return (_size == 0);
}
template<typename T>
T QueueLinkedList<T>::Pop() {
  if (IsEmpty()) throw "aaa";
  T value = head->value;
  Node *temp = head;
  head = head->next;
  delete temp;
  _size--;
  return value;
}
template <typename T>
bool QueueLinkedList<T>::operator==(const QueueLinkedList<T> &a) const {
  if (_size != a._size) return false;
  int count = 0;
  Node *temp1 = head;
  Node *temp2 = a.head;
  while (temp1 != nullptr) {
    if (temp1->value == temp2->value) {
      count++;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  if (count == _size) return true;
  else
    return false;
}
template<typename T>
int QueueLinkedList<T>::Size() const {
  return _size;
}
template<typename T>
QueueLinkedList<T>::QueueLinkedList(const QueueLinkedList<T> &a) {
  _size = 0;
  Node *node = a.head;
  while (node != nullptr) {
    Push(node->value);
    node = node->next;
  }
}
template<typename T>
void QueueLinkedList<T>::Push(T &&val) {
  Push(val);
}

template<typename T>
QueueLinkedList<T> &QueueLinkedList<T>::operator=(QueueLinkedList<T> a) {
  while (!IsEmpty()) {
    Pop();
  }
  Node *node = a.head;
  while (node != nullptr) {
    Push(node->value);
    node = node->next;
  }
  return *this;
}
template<typename T>
QueueLinkedList<T>::QueueLinkedList(QueueLinkedList<T> &&a) {
  while (!IsEmpty()) {
    Pop();
  }
  _size = 0;
  Node *node = a.head;
  while (node != nullptr) {
    Push(node->value);
    node = node->next;
  }
}
template<typename T>
std::vector<T> QueueLinkedList<T>::ToVector() const {
  std::vector<T> res;
  Node *node = head;
  while (node != nullptr) {
    res.push_back(node->value);
    node = node->next;
  }
  return res;
}
}  // namespace containers

#endif   // QUEUE_LINKED_LIST_H_
