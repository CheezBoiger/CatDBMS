#ifndef _CATTYPES_H_
#define _CATTYPES_H_

#pragma once

#ifndef _WIN32
typedef unsigned char             uint8_t;
typedef char                      int8_t;

typedef unsigned short            uint16_t;
typedef short                     int16_t;

typedef unsigned int              uint32_t;
typedef int                       int32_t;

typedef unsigned long long        uint64_t;
typedef long long                 int64_t;

typedef float                     float32_t;
typedef double                    float64_t;

typedef unsigned int              size_t;
#endif

#endif /* _CATTYPES_H_ */