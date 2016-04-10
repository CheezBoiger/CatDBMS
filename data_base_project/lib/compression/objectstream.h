// Object Stream File.
#ifndef _OBJECT_STREAM_H_
#define _OBJECT_STREAM_H_

#include <lib/compression/serializable.h>

#define MAX_BUFFER_SIZE                4096

namespace catdb {
namespace serialization {

/**
 * ObjectStream is a stream buffer that pushes data into a smaller, more manageable
 * chunk to hash and store for the data base.
 */
class ObjectStream {
  typedef serial discrete;
public:
  /**
   * Constructor for the ObjectStream.
   */
  ObjectStream(void) : buff_start(new byte[MAX_BUFFER_SIZE])
    , size(0) {
    buff_end = buff_start + MAX_BUFFER_SIZE;
    data_buff_end = data_buff_start = buff_start;
  }
  /**
   * ObjectStream Destructor.
   */
  ~ObjectStream(void) {
    if(buff_start) {
      delete[] buff_start;
      buff_end = NULL;
      data_buff_end = NULL;
      data_buff_start = NULL;
    }
  }

  /**
   * Writes to standard file stream.
   */
  void write_to_file(std::ofstream& file);

  /**
   * Return the data size of this stream.
   */
  uint64 get_size(void) { return size; }

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

private:
  /**
   * Data_buff_start is intended to identify the start of the memory block of data
   * stored in this ObjectStream. Data_buff_end is intended to point to the end of
   * data block.
   */
  discrete data_buff_start, data_buff_end;
  /**
   * buff_start specifies the start of the ObjectStream conveyor belt, whereas buff_end
   * specifies the end of the ObjectStream conveyor belt.
   */
  discrete buff_start, buff_end;
  /**
   * Size of the data stream in this ObjectStream.
   */
  uint64 size;
};


} // serialization namespace 
} // catdb namespace 
#endif
