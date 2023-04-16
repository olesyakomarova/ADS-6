// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T, int size>
class TPQueue {
 private:
  T* items;
  int MAXsize;
  int HEAD, TAIL;
  int counter;

 public:
  TPQueue(): MAXsize(size), HEAD(0), TAIL(0), counter(0) {
    items = new T[MAXsize + 1];
  }

  void push(const T& item) {
    if (counter == 0) {
      items[TAIL++] = item;
      counter++;
    } else {
      int i = TAIL - 1;
      bool flag = false;
      while (i >= HEAD && item.prior > items[i].prior) {
        flag = true;
        items[i + 1] = items[i];
        items[i] = item;
        i--;
      }
      if (!flag) {
        items[TAIL] = item;
      }
      TAIL++;
      counter++;
    }
    if (TAIL > MAXsize) {
      TAIL -= MAXsize + 1;
    }
  }

  const T& pop() {
    counter--;
    if (HEAD > MAXsize) {
      HEAD -= MAXsize + 1;
    }
    return items[HEAD++];
  }

  T& front() {
    assert(count > 0);
    return items[HEAD];
  }

  bool isEmpty() const {
    return counter == 0;
  }

  bool isFull() const {
    return counter == MAXsize;
  }

  ~TPQueue() {
    delete[] items;
  }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
