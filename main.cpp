#include <iostream>
#include <string>
#include <stdint.h>


struct blockHeader{
  blockHeader *next;
  size_t size;
  bool empty = false;
};

alignas(blockHeader)  u_int8_t heap[100];


int main(){
  int offset = 0;
  blockHeader *start = reinterpret_cast<blockHeader *>(&heap[offset]);
  start->empty = true;
  start->size = sizeof(heap) - sizeof(*start);
  offset += start->size;

  std::cout << sizeof(*start) << " " << alignof(*start) << std::endl;
  
  return 0;
}