#ifndef _MATRIX_H_
#define _MATRIX_H_
#pragma once

#include "header.h"

namespace tools {
namespace math {

class Matrix {
  typedef unsigned int mx_size_t;
public:
  mx_size_t row, col;
};
} // math namespace 
} // tools namespace 

#endif /* _MATRIX_H_ */
