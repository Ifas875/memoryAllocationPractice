#include <iostream>
#include <string>
#include <stdint.h>


struct blockHeader{
  blockHeader *next = nullptr;
  size_t size;
  bool empty = false;
};

alignas(blockHeader)  u_int8_t heap[100];
blockHeader *start = nullptr;


blockHeader * myMalloc(size_t required){
  bool status = false;
  // Searching for available block of memory
  blockHeader *subject = start;
  while(subject != nullptr){
    if(subject->size >= required){
      return subject;
    }
    else{
      subject = subject->next;
    }
  }

  // // Scenario if none of the available blocks matched the requirements
  // // Condensing free blocks
  // blockHeader *subject = start;
  // while(subject != nullptr){
    
  // }
  return nullptr;
}


void myFree(blockHeader *target){
  return;
}


int main(){
  int offset = 0;
  start = reinterpret_cast<blockHeader *>(&heap[offset]);
  start->empty = true;
  start->size = sizeof(heap) - sizeof(*start);
  offset += start->size;

  std::cout << sizeof(*start) << " " << alignof(*start) << std::endl;
  
  return 0;
}