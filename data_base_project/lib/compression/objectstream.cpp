#include <lib/compression/objectstream.h>

#include <fstream>

#define DEFAULT_STRING_SIZE           64

namespace catdb {
namespace serialization {

ObjectStream& ObjectStream::operator<<(string& str) {
  if((data_buff_end + DEFAULT_STRING_SIZE) <= buff_end) {
    data_buff_end = pack_string(str, DEFAULT_STRING_SIZE, data_buff_end);
    size += DEFAULT_STRING_SIZE;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(string& str) {
  if(data_buff_end > data_buff_start &&
     ((data_buff_start + DEFAULT_STRING_SIZE) < buff_end)) {
    uint16 temp = 0;
    str = unpack_string(data_buff_start, str, &temp);
    data_buff_start += (2 + DEFAULT_STRING_SIZE);
    size -= (2 + DEFAULT_STRING_SIZE);
  }
  return (*this);
}

ObjectStream& ObjectStream::operator<<(std::string& str) {
  int size_check = data_buff_end - data_buff_start;
  if((data_buff_end + str.size()) < buff_end) {
    string_packet string_p;
    string_p.str = (char*)str.c_str();
    string_p.len = (uint16)str.size();
    data_buff_end = pack_string_packet(&string_p, data_buff_end);
    size += (2 + str.size());
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(std::string& str) {
  if(data_buff_end > data_buff_start) {
    //      std::cout << "Before: " << data_buff_start << std::endl;
    string_packet p;
    p.len = 0;
    p.str = NULL;
    unpack_string_packet(data_buff_start, &p);
    for(int i = 0; i < p.len; ++i) {
      str += p.str[i];
    }
    data_buff_start += (2 + p.len);
    size -= (2 + p.len);
    free(p.str);
  }
  //   std::cout << "After: " << data_buff_start << std::endl;
  return (*this);
}

ObjectStream& ObjectStream::operator<<(string_packet& str) {
  if((data_buff_end + str.len) <= buff_end) {
    data_buff_end = pack_string_packet(&str, data_buff_end);
    size += (str.len + 2);
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(string_packet& str) {
  if(data_buff_end > data_buff_start) {
    unpack_string_packet(data_buff_start, &str);
    data_buff_start += (str.len + 2);
    size -= (2 + str.len);
  }
  return (*this);
}

ObjectStream& ObjectStream::operator<<(byte& num) {
  if((data_buff_end + 1) <= buff_end) {
    data_buff_end = pack_uint8(num, data_buff_end);
    size++;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(byte& num) {
  if(data_buff_end > data_buff_start &&
      ((data_buff_start + 1) < buff_end)) {
    num = unpack_uint8(data_buff_start);
    data_buff_start += 1;
    size--;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator<<(int8& num) {
  if((data_buff_end + 1) <= buff_end) {
    data_buff_end = pack_int8(num, data_buff_end);
    size++;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(int8& num) {
  if(data_buff_end > data_buff_start &&
      ((data_buff_start + 1) < buff_end)) {
    num = unpack_int8(data_buff_start);
    data_buff_start += 1;
    size--;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator<<(uint16& num) {
  if((data_buff_end + 2) <= buff_end) {
    data_buff_end = pack_uint16(num, data_buff_end);
    size += 2;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(uint16& num) {
  if((data_buff_end > data_buff_start) &&
      ((data_buff_start + 2) < buff_end)) {
    num = unpack_uint16(data_buff_start);
    data_buff_start += 2;
    size -= 2;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator<<(int16& num) {
  if((data_buff_end + 2) <= buff_end) {
    data_buff_end = pack_int16(num, data_buff_end);
    size += 2;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(int16& num) {
  if(data_buff_end > data_buff_start &&
      ((data_buff_start + 2) < buff_end)) {
    num = unpack_int16(data_buff_start);
    data_buff_start += 2;
    size -= 2;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator<<(uint32& num) {
  if((data_buff_end + 4) <= buff_end) {
    data_buff_end = pack_uint32(num, data_buff_end);
    size += 4;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(uint32& num) {
  if(data_buff_end > data_buff_start &&
      ((data_buff_start + 4) < buff_end)) {
    num = unpack_uint32(data_buff_start);
    data_buff_start += 4;
    size -= 4;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator<<(int32& num) {
  if((data_buff_end + 4) <= buff_end) {
    data_buff_end = pack_int32(num, data_buff_end);
    size += 4;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(int32& num) {
  if(data_buff_end > data_buff_start &&
      ((data_buff_start + 4) < buff_end)) {
    num = unpack_int32(data_buff_start);
    data_buff_start += 4;
    size -= 4;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator<<(uint64& num) {
  if((data_buff_end + 8) <= buff_end) {
    data_buff_end = pack_uint64(num, data_buff_end);
    size += 8;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(uint64& num) {
  if(data_buff_end > data_buff_start &&
      ((data_buff_start + 8) < buff_end)) {
    num = unpack_uint64(data_buff_start);
    data_buff_start += 8;
    size -= 8;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator<<(int64& num) {
  if((data_buff_end + 8) <= buff_end) {
    data_buff_end = pack_int64(num, data_buff_end);
    size += 8;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(int64& num) {
  if(data_buff_end > data_buff_start &&
      ((data_buff_start + 8) < buff_end)) {
    num = unpack_int64(data_buff_start);
    data_buff_start += 8;
    size -= 8;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator<<(float32& flo) {
  if((data_buff_end + 4) <= buff_end) {
    data_buff_end = pack_float32(flo, data_buff_end);
    size += 4;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(float32& flo) {
  if(data_buff_end > data_buff_start &&
      ((data_buff_start + 4) < buff_end)) {
    flo = unpack_float32(data_buff_start);
    data_buff_start += 4;
    size -= 4;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator<<(float64& flo) {
  if((data_buff_end + 8) <= buff_end) {
    data_buff_end = pack_float64(flo, data_buff_end);
    size += 8;
  }
  return (*this);
}

ObjectStream& ObjectStream::operator>>(float64& flo) {
  if(data_buff_end > data_buff_start &&
      ((data_buff_start + 8) <= buff_end)) {
    flo = unpack_float64(data_buff_start);
    data_buff_start += 8;
    size -= 8;
  }
  return (*this);
}

void ObjectStream::write_to_file(std::ofstream& file) {
  for(uint64 i = 0; i < size; ++i) {
    file << data_buff_start[i];
  }
}
} // serialization namespace 
} // catdb namespace 