// Object Stream File.
#ifndef _OBJECT_STREAM_H_
#define _OBJECT_STREAM_H_

#include <lib/compression/serializable.h>

namespace catdb {
namespace serialization {

// ObjectStream is a stream buffer that pushes data into a smaller, more manageable 
// chunk to hash and store for the data base.
class ObjectStream {
   typedef serial discrete;
public:
   ObjectStream(void) : buff_start(new byte[MAX_BUFFER_SIZE]) {
      buff_end = buff_start + MAX_BUFFER_SIZE;
      data_buff_end = data_buff_start = buff_start;
   }
   ~ObjectStream(void) {
      if(buff_start) {
         delete[] buff_start;
         buff_end = NULL;
         data_buff_end = NULL;
         data_buff_start = NULL;
      }
   }

   ObjectStream& operator<<(string_packet& str);
   ObjectStream& operator<<(string& str);
   ObjectStream& operator<<(uint16& num);
   ObjectStream& operator<<(int16& num);
   ObjectStream& operator<<(uint32& num);
   ObjectStream& operator<<(int32& num);
   ObjectStream& operator<<(int64& num);
   ObjectStream& operator<<(uint64& num);
   ObjectStream& operator<<(byte& num);
   ObjectStream& operator<<(int8& num);
   ObjectStream& operator<<(float32& flo);
   ObjectStream& operator<<(float64& flo);
   ObjectStream& operator<<(std::string& str);

   ObjectStream& operator>>(string_packet& str);
   ObjectStream& operator>>(string& str);
   ObjectStream& operator>>(uint16& num);
   ObjectStream& operator>>(int16& num);
   ObjectStream& operator>>(uint32& num);
   ObjectStream& operator>>(int32& num);
   ObjectStream& operator>>(int64& num);
   ObjectStream& operator>>(uint64& num);
   ObjectStream& operator>>(byte& num);
   ObjectStream& operator>>(int8& num);
   ObjectStream& operator>>(float32& flo);
   ObjectStream& operator>>(float64& flo);
   ObjectStream& operator>>(std::string& str);

   void get_cat(void) { 
   }

   operator uint32(void);
private:
   discrete data_buff_start, data_buff_end;
   discrete buff_start, buff_end;
};


} // serialization namespace 
} // catdb namespace 
#endif
