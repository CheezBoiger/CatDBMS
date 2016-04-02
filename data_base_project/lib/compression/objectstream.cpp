#include <lib/compression/objectstream.h>

#define DEFAULT_STRING_SIZE           64

namespace catdb {
namespace serialization {

ObjectStream& ObjectStream::operator<<(string& str) {
   if ((data_buff_end+DEFAULT_STRING_SIZE) <= buff_end) {
      data_buff_end = pack_string(str, DEFAULT_STRING_SIZE, data_buff_end);
   }
   return (*this);
}

ObjectStream& ObjectStream::operator>>(string& str) {
   if (data_buff_end > data_buff_start && 
      ((data_buff_start+DEFAULT_STRING_SIZE) < buff_end)) {
      uint16 temp = 0;
      str = unpack_string(data_buff_start, str, &temp);
      data_buff_start += (2+DEFAULT_STRING_SIZE);
   }
   return (*this);
}

ObjectStream& ObjectStream::operator<<(std::string& str) {
   int size_check = data_buff_end - data_buff_start;
   if ((size_check+str.size()) < MAX_BUFFER_SIZE) {
      string_packet string_p;
      string_p.str = (char*)str.c_str();
      string_p.len = (uint16)str.size();
      data_buff_end = pack_string_packet(&string_p, data_buff_end);
   }
   return (*this);
}

ObjectStream& ObjectStream::operator>>(std::string& str) {
   if (data_buff_end > data_buff_start) {
//      std::cout << "Before: " << data_buff_start << std::endl;
      string_packet p;
      p.len = 0;
      p.str = NULL;
      unpack_string_packet(data_buff_start, &p);
      for (int i = 0; i < p.len; ++i) { 
         str += p.str[i];
      }
      data_buff_start += (2+p.len);
      free(p.str);
   }
//   std::cout << "After: " << data_buff_start << std::endl;
   return (*this);
}

ObjectStream& ObjectStream::operator<<(byte& num) { 
   if ((data_buff_end+1) <= buff_end) { 
      data_buff_end = pack_uint8(num, data_buff_end);
   } 
   return (*this);
}

ObjectStream& ObjectStream::operator>>(byte& num) { 
   if (data_buff_end > data_buff_start &&
       ((data_buff_start+1) < buff_end)) {
      num = unpack_uint8(data_buff_start);
      data_buff_start += 1;
   }
   return (*this);
}

ObjectStream& ObjectStream::operator<<(int8& num) { 
   if ((data_buff_end+1) <= buff_end) { 
      data_buff_end = pack_int8(num, data_buff_end);
   }
   return (*this);
}

ObjectStream& ObjectStream::operator>>(int8& num) { 
   if (data_buff_end > data_buff_start &&
       ((data_buff_start+1) < buff_end)) { 
      num = unpack_int8(data_buff_start);
      data_buff_start += 1;
   }
   return (*this);
}

ObjectStream& ObjectStream::operator<<(uint16& num) { 
   if ((data_buff_end+2) <= buff_end) { 
      data_buff_end = pack_uint16(num, data_buff_end);
   }
   return (*this);
}

ObjectStream& ObjectStream::operator>>(uint16& num) {
   if ((data_buff_end > data_buff_start) && 
       ((data_buff_start+2) < buff_end)) {
      num = unpack_uint16(data_buff_start);
      data_buff_start += 2; 
   }
   return (*this);
}

ObjectStream& ObjectStream::operator<<(int16& num) { 
   if ((data_buff_end+2) <= buff_end) { 
      data_buff_end = pack_int16(num, data_buff_end);
   }
   return (*this);
}

ObjectStream& ObjectStream::operator>>(int16& num) { 
   if (data_buff_end > data_buff_start &&
       ((data_buff_start+2) < buff_end)) { 
      num = unpack_int16(data_buff_start);
      data_buff_start += 2;
   }
   return (*this);
}

ObjectStream& ObjectStream::operator<<(uint32& num) { 
   return (*this);
}

ObjectStream& ObjectStream::operator>>(uint32& num) { 
   return (*this);
}
} // serialization namespace 
} // catdb namespace 