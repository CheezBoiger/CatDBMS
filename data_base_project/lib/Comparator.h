#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_
#pragma once

#define _GREATER                                             1
#define _LESSER                                             -1
#define _EQUAL                                               0

namespace catdb {

// Abstract Comparator meant for the purposes of comparing two values.
template<typename _Class>
class Comparator {
public:
  Comparator(void) { }
  virtual ~Comparator(void) { }

  virtual int operator()(const _Class& _left, const _Class& _right) {
    return compare(_left, _right);
  }

  inline int compare(const _Class& _left, const _Class& _right) {
    if(_left == _right) {
      return _EQUAL;
    } else if(_left > _right) {
      return _GREATER;
    } else {
      return _LESSER;
    }
  }
};

template<typename _Class>
class Comparable {
public:
  typedef _Class _Left;
  typedef _Class _Right;
  Comparable(void) { }
  virtual ~Comparable(void) { }

  virtual int compare_to(const _Class& _right) = 0;

  virtual bool equals(const _Class& _right) = 0;
};
} /* catdb comparator */

#endif /* _COMPARATOR_H_ */
