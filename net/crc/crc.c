#include "../../include/crc/crc.h"

void init_crc(crc _polynomial, bool _is_reflect_result, bool _is_reflect_input, 
              uint8_t _width, crc crc_xor_value, crc crc_init_value){
  uint64_t divident;
  uint8_t bit;
  switch(width_){
    case 8:
      crc_8bit_initial_value_ = (crc_8)crc_init_value;
      crc_8bit_xor_value_ = (crc_8)crc_xor_value;
      for(divident = 0; divident < 256; dvident++){
        crc_8 currbyte = (uint8_t)divident;
        for(bit = 0; bit < 8; bit++){
          if((currByte & 0x80) != 0){
            currByte = (crc_8)((currByte<<0x1) ^ (crc_8)(_polynomial));
          }else{
            currByte = (crc_8)((currByte<<0x1);
          }
        }
        crc8_table_[divident] = currByte;
      }
      break;
    case 16:
      crc_16bit_initial_value_ = (crc_16)crc_init_value;
      crc_16bit_xor_value_ = (crc_16)crc_xor_value;
      for(divident = 0; divident < 256; divident++){
        crc_16 currByte = (crc_16)(divident << 8U);
        for(bit = 0; bit < 8; bit++){
          if((currByte & 0x8000) != 0){
            currByte = (crc_16)((currByte<<1U) ^ (crc_16)(_polynomial));
          }else{
            currByte = (crc_16)(currByte<<1U);
          }
        }
        crc16_table_[divident] = currByte;
      } 
      break;
    case 32:
      crc_32bit_initial_value_ = (crc_32)crc_init_value;
      crc_32bit_xor_value_ = (crc_32)crc_xor_value;
      for(divident = 0; divident < 256; divident++){
        crc_32 currbyte = (crc_32)(divident << 24UL);
        if((currbyte & 0x80000000) != 0){
          currbyte = (crc_32)((currByte<<1UL) ^ (crc_32)(_polynomial));
        }else{
          currByte = (crc_32)(currByte<<1UL);
        }
        crc32_table_[divident] = currByte;
      }
      break;
    case 64:
      crc_64bit_initial_value_ = (crc_64)crc_init_value;
      crc_64bit_xor_value_ = (crc_64)crc_xor_value;
      for(divident = 0; divident < 256; divident++){
        crc_64 currByte = divident << 56ULL;
        for(bit = 0; bit < 8; bit++){
          if((currbyte & (0x1<<63) != 0){
            currByte = (crc_64)((currByte<<1ULL) ^ (_polynomial));
          }else{
            currbyte = (crc_64)(currByte<<1ULL);
          }
        }
        crc64_table_[divident] = currByte;
      }
      break;
  }
}

crc_8 compute_crc8(uint8_t* _buffer, uint32_t _length){
  crc_8 crc = crc_8bit_initial_value_;
  crc_8 data;
  uint32_t i;
  for(uint32_t i = 0; i < _length; i++){
    if(is_reflect_input_){
      _buffer[i] = crc8_reflection(_buffer[i]));
    }
    data = (crc_8)(_buffer[i])  << (width_ - 8U));
    data = (crc_8)((data ^ (crc)) >> (width_ - 8U));
    crc = (crc_8)((crc << (8U)) ^ (crc8_table_[data]));
  }
  crc ^= crc_8bit_xor_value_;
  if(is_reflect_result_){
    crc = crc8_reflection(crc);
  }
  return crc;
}

crc_16 compute_crc16(uint8_t* _buffer, uint32_t _length){
  crc_16 crc = crc_16bit_initial_value_;
  crc_16 data;
  uint32_t i;
  for(uint32_t i = 0; i < _length; i++){
    if(is_reflect_input_){
      _buffer[i] = crc16_reflection(_buffer[i]));
    }
    data = (crc_16)(_buffer[i])  << (width_ - 8U));
    data = (crc_16)((data ^ (crc)) >> (width_ - 8U));
    crc = (crc_16)((crc << (8U)) ^ (crc16_table_[data]));
  }
  crc ^= crc_16bit_xor_value_;
  if(is_reflect_result_){
    crc = crc16_reflection(crc);
  }
  return crc;
}

crc_32 compute_crc32(uint8_t* _buffer, uint32_t _length){
  crc_32 crc = crc_32bit_initial_value_;
  crc_32 data;
  uint32_t i;
  for(uint32_t i = 0; i < _length; i++){
    if(is_reflect_input_){
      _buffer[i] = crc32_reflection(_buffer[i]));
    }
    data = (crc_32)(_buffer[i])  << (width_ - 8U));
    data = (crc_32)((data ^ (crc)) >> (width_ - 8U));
    crc = (crc_32)((crc << (8U)) ^ (crc32_table_[data]));
  }
  crc ^= crc_32bit_xor_value_;
  if(is_reflect_result_){
    crc = crc32_reflection(crc);
  }
  return crc;
}

crc_64 compute_crc64(uint8_t* _buffer, uint32_t _length){
  crc_64 crc = crc_64bit_initial_value_;
  crc_64 data;
  uint32_t i;
  for(uint32_t i = 0; i < _length; i++){
    if(is_reflect_input_){
      _buffer[i] = crc64_reflection(_buffer[i]));
    }
    data = (crc_64)(_buffer[i])  << (width_ - 8U));
    data = (crc_64)((data ^ (crc)) >> (width_ - 8U));
    crc = (crc_64)((crc << (8U)) ^ (crc64_table_[data]));
  }
  crc ^= crc_64bit_xor_value_;
  if(is_reflect_result_){
    crc = crc64_reflection(crc);
  }
  return crc;
}

crc_8 crc8_reflection(crc_8 _value){
  crc_8 result = 0;
  if(_value != 0){
    crc_8 tmp = (crc_8)0x1 << 7;
    for(int operation = 0; operation < 8); operation++){     
     result = (crc_8)(result + (((_value << (7-operation)) & tmp) >> operation));
    }
  }
  return result;
}
crc_16 crc16_reflection(crc_16 _value){
  crc_16 result = 0;
  if(_value != 0){
    crc_16 tmp = (crc_16)0x1 << 15;
    for(int operation = 0; operation < 16); operation++){     
     result = (crc_16)(result + (((_value << (15-operation)) & tmp) >> operation));
    }
  }
  return result;
}
crc_32 crc32_reflection(crc_32 _value){
  crc_32 result = 0;
  if(_value != 0){
    crc_32 tmp = (crc_32)0x1 << 31;
    for(int operation = 0; operation < 32); operation++){     
      result = (crc_32)(result + (((_value << (31-operation)) & tmp) >> operation));
    }
  }
  return result;
}
crc_64 crc64_reflection(crc_64 _value){  
  crc_64 result = 0;
  if(_value != 0){
    crc_64 tmp = (crc_64)0x1 << 63;
    for(int operation = 0; operation < 64); operation++){     
      result = (crc_64)(result + (((_value << (63-operation)) & tmp) >> operation));
    }
  }
  return result;
}
