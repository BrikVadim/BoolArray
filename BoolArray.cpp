//
// Copyright (c)  Vadim Brik (https://vadimbrik.ru)
//
// Project: BoolArray
// Description: Class for storage of boolean values.
// File: BoolArray.cpp
//
// Created by Brik Vadim at 17.02.2018
// Compile tested with gcc 4.6.3 on Linux 4.15.7
//

#include <stdexcept>

#define BYTE 8

/**
 * BoolArray constructor
 */
template <size_t size>
BoolArray<size>::BoolArray() : bytes_(new unsigned char[compute_bytes_count(size)]()) {}

/**
 * BoolArray destructor
 */
template <size_t size>
BoolArray<size>::~BoolArray() {
  delete[] bytes_;
  bytes_ = nullptr;
}

/**
 * Get state of bit by sequence number.
 * @param index - Sequence number from 0.
 * @return bool - State of byte at index.
 * @exception Index out of range.
 */
template <size_t size>
bool BoolArray<size>::Get(size_t index) const {
  check_size(index);
  
  size_t byteNo = compute_offset(index);
  size_t bitNo = compute_index(index);
  unsigned char bitset = bytes_[byteNo];
  
  return get_bit(bitset, bitNo);
}

/**
 * Set state of bit by sequence number.
 * @param index - Sequence number from 0.
 * @param value - new value of bit.
 * @exception Index out of range.
 */
template <size_t size>
void BoolArray<size>::Set(size_t index, bool value) {
  check_size(index);
  
  size_t byteNo = compute_offset(index);
  size_t bitNo = compute_index(index);
  unsigned char *bitset_ptr = bytes_ + byteNo;
  
  set_bit(bitset_ptr, bitNo, value);
}

template <size_t size>
void BoolArray<size>::set_bit(unsigned char *bitset, size_t index, bool value) {
  *bitset |= value << index;
}

template <size_t size>
bool BoolArray<size>::get_bit(unsigned char bitset, size_t index) const {
  return (bitset >> index) & 1;
}

template <size_t size>
size_t BoolArray<size>::compute_index(size_t index) const {
  return index - (index / BYTE) * BYTE;
}

template <size_t size>
size_t BoolArray<size>::compute_offset(size_t index) const {
  return index / BYTE;
}

template <size_t size>
size_t BoolArray<size>::compute_bytes_count(size_t bits_c) const {
  return (bits_c / BYTE) + !!(bits_c % BYTE);
}

template <size_t size>
void BoolArray<size>::check_size(size_t index) const {
  if (index < 0 || index >= size) {
      throw_out_exception();
  }
}

template <size_t size>
[[noreturn]] void BoolArray<size>::throw_out_exception() const {
  throw std::out_of_range("Index out of array size.");
}
