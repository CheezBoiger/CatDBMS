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

   virtual bool operator()(const _Class& _left, const _Class& _right) {
      return (_left > _right);
   }

   int compare(const _Class& _left, const _Class& _right) { 
      if (_left == _right) { 
         return _EQUAL;
      } else if (_left > _right) { 
         return _GREATER;
      } else { 
         return _LESSER;
      }
   }
};
  
// Comparator class intended to check if left value is greater than
// right value.
template<typename _Class>
class GreaterComparator : public Comparator<_Class> {
public:
   // declare left and right comparator.
   typedef _Class _Left;
   typedef _Class _Right;
   GreaterComparator(void) { } 
   ~GreaterComparator(void) { }

   bool operator()(const _Class& _left, const _Class& _right) {
      return (_left > _right);
   }
};

// Comparator class intended to check if left value is less than
// right value.
template<typename _Class>
class LesserComparator : public Comparator<_Class> { 
public:
   typedef _Class _Left;
   typedef _Class _Right;
   LesserComparator(void) { }
   ~LesserComparator(void) { }
   
   bool operator()(const _Class& _left, const _Class& _right) { 
      return (_left < _right);
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
