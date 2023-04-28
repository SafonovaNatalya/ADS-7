// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <list>

struct SYM {
  char ch;
  int prior;
};

template<typename T>
class TPQueue {
 private:
 std::list <T> spisok;
 bool helper;
 T element;

 public:
  bool isEmpty() const {
  return spisok.empty();
  }
  void push(const T& value) {
  if (isEmpty()) {
    spisok.push_back(value);
  } else {
    helper = false;
    for (auto i = spisok.begin(); i != spisok.end(); i++) {
      if ((* i).prior < value.prior) {
        spisok.insert(i, value);
        helper = true;
        break;
      }
    }
    if (!helper) {
      spisok.push_back(value);
    }
  }
  }
  T& pop() {
  element = spisok.front();
  spisok.pop_front();
  return element;
  }
};

#endif  // INCLUDE_TPQUEUE_H_
