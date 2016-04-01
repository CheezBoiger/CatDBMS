#ifndef _SERIALIZE_H_
#define _SERIALIZE_H_

#include <lib/compression/objectstream.h>

namespace catdb {
namespace serialization {

class Serialize {
public:
   virtual ~Serialize(void) { }

   virtual void serialize(ObjectStream& stream) = 0;

   virtual void deserialize(ObjectStream& stream) = 0;
};
} // serialization namespace 
} // catdb namespace 
#endif // _SERIALIZE_H_ 