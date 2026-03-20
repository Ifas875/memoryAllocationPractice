#include <iostream>
#include <string>
#include <stdint.h>


u_int8_t heap[100];


struct blockHeader{
  blockHeader *next;
  int size;
  bool empty = false;
};


int main(){
  blockHeader *start = new blockHeader();
  start->size = 100-sizeof(blockHeader);
  heap[0] = reinterpret_cast<u_int8_t>(start);
  return 0;
}