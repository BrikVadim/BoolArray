//
// Copyright (c) 2018 Vadim Brik (https://vadimbrik.ru)
//
// Project: BoolArray
// Description: Class for storage of boolean values.
// File: BoolArray.hpp
//
// Created by Brik Vadim at 17.02.2018
// Compile tested with gcc 4.6.3 on Linux 4.15.7
//

/**
 * Class for storage of boolean values.
 */
template <size_t size>
class BoolArray {
  
public:
  BoolArray();
  ~BoolArray();
  bool Get(size_t index) const;
  void Set(size_t index, bool value);
  
private:
  unsigned char *bytes_;
  
  void set_bit(unsigned char *bitset, size_t index, bool value);
  bool get_bit(unsigned char bitset, size_t index) const;
  size_t compute_index(size_t index) const;
  size_t compute_offset(size_t index) const;
  size_t compute_bytes_count(size_t bits_c) const;
  
  void check_size(size_t index) const;
  [[noreturn]] void throw_out_exception() const;
  
};
