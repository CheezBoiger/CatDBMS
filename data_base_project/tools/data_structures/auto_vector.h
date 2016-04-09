#ifndef _AUTOVECTOR_H_
#define _AUTOVECTOR_H_

#pragma once

#include <vector>

namespace tools {
namespace data_structures { 
/**
 * Auto Vector Data Structure!
 * Implements the Standard Template Library Vector 
 * yet with modifications to simplify the structure.
 */
template<typename _Ty>
class auto_vector {
   typedef std::vector<_Ty> _Vector;
   typedef unsigned int size_u32_t;
   typedef typename std::vector<_Ty>::iterator _Iter;
   typedef const _Ty& const_reference;
public:
   /** 
    * Basic default constructor for the vector.
    */
   auto_vector(void) { }
   /**
    * @return The size of the vector.
    */
   size_u32_t size(void) const { return a_vect.size(); }
   /**
    * insert an object to the end of this vector.
    */
   void push_back(const _Ty& obj) { 
      a_vect.push_back(obj);
   }
   /**
    * erase an object at the specified position.
    */
   void erase(size_u32_t position) { 
      a_vect.erase(position);
   }   
   /**
    * Erase objects starting from a specified position, to the end. 
    */
   void erase(const _Iter& start, const _Iter& end) { 
      a_vect.erase(start, end);
   }
   /**
    * delete an object at the end of this vector.
    */
   void pop_back(void) { 
      a_vect.pop_back();
   }
   /**
    * return the object at the front of this vector.
    */
   const_reference front(void) { 
      return a_vect.front();
   }
   /**
    * Return the iterator at the beginning of this vector.
    */
   _Iter begin(void) { 
      return a_vect.begin();
   }
   /**
    * Return the iterator at the end of this vector.
    */
   _Iter end(void) { 
      return a_vect.end();
   }
   /**
    * Operator overload for the access of indices of this vector.
    */
   _Ty& operator[](const size_u32_t index) { 
      return a_vect[index];
   }
private:
   /**
    * Yes, indeed this is our vector.
    */
   _Vector a_vect;
};

} // data_structures namespace 
} // tools namespace 

#endif /* _AUTOVECTOR_H_ */