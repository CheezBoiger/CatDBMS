//
#ifndef _MATHEMATICS_H_
#define _MATHEMATICS_H_

namespace tools {
namespace mathematics {

// Originally from the Quake III Arena source code, fast inverse root square is 
// an amazin' piece of art mang...
float fast_rsqrt(float number) {
   long i;
   float x2, y;
   const float threehalfs = 1.5f;

   x2 = number * 0.5f;
   y = number;
   i = *(long*)&y;
   i = 0x5f3759df - (i >> 1);
   y = *(float*)&i;
   y = y * (threehalfs - (x2 * y * y));
   return y;
}
} // mathematics namespace 
} // tools namespace 

#endif // _MATHEMATICS_H_
