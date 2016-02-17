#ifndef _AUTOVECTOR_H_
#define _AUTOVECTOR_H_

#pragma once

#include <vector>

namespace tools {
namespace data_structures { 

template<typename _Ty>
class auto_vector {
   typedef std::vector<_Ty> _Vector;
   typedef unsigned int size_u32_t;
   typedef typename std::vector<_Ty>::iterator _Iter;
   typedef const _Ty& const_reference;
public:
   auto_vector(void) { }

   size_u32_t size(void) const { return a_vect.size(); }

   void push_back(const _Ty& obj) { 
      a_vect.push_back(obj);
   }

   void erase(size_u32_t position) { 
      a_vect.erase(position);
   }   

   void erase(const _Iter& start, const _Iter& end, const _Ty& ref) { 
      a_vect.erase(start, end, ref);
   }

   void pop_back(void) { 
      a_vect.pop_back();
   }

   const_reference front(void) { 
      return a_vect.front();
   }
   
   _Iter begin(void) { 
      return a_vect.begin();
   }

   _Iter end(void) { 
      return a_vect.end();
   }

   _Ty& operator[](const size_u32_t index) { 
      return a_vect[index];
   }
private:
   _Vector a_vect;
};

} // data_structures namespace 
} // tools namespace 

#endif /* _AUTOVECTOR_H_ */