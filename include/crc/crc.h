#include <types.h>
#ifndef __CRC_H__
#define __CRC_H__

typedef uint64_t crc;
typedef uint8_t crc_8;
typedef uint16_t crc_16;
typedef uint32_t crc_32;
typedef uint64_t crc_64;

uint8_t width_;

crc_8 crc_8bit_initial_value_;
crc_8 crc_8bit_xor_value;
crc_16 crc_16bit_initial_value_;
crc_16 crc_16bit_xor_value_;
crc_32 crc_32bit_initial_value_;
crc_32 crc_32bit_xor_value_;
crc_64 crc_64bit_initial_value_;
crc_64 crc_64bit_xor_value_;

crc_8 crc8_table[256] = {0};
crc_16 crc16_table[256] = {0};
crc_32 crc32_table[256] = {0};
crc_64 crc64_table[256] = {0};

bool is_reflect_result_;
bool is_reflect_input_;

void crc_init(crc _polynomial, bool _is_reflect_result, bool is_reflect_input, uint8_t _width);

crc_8 compute_crc8(uint8_t* _buffer, uint32_t _length);
crc_16 compute_crc16(uint8_t* _buffer, uint32_t _length);
crc_32 compute_crc32(uint8_t* _buffer, uint32_t _length);
crc_64 compute_crc64(uint8_t* _buffer, uint32_t _length);

crc_8 crc8_reflection(crc_8 _value);
crc_16 crc16_reflection(crc_16 _value);
crc_32 crc32_reflection(crc_32 _value);
crc_64 crc64_reflection(crc_64 _value);

#endif __CRC_H__
