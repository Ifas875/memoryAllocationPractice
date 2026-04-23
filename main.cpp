#include <iostream>
#include <string>
#include <stdint.h>


struct blockHeader{
  blockHeader *previous = nullptr;
  blockHeader *next = nullptr;
  size_t size;
  bool empty = false;
};

alignas(blockHeader)  u_int8_t heap[500];
blockHeader *start = nullptr;


blockHeader * myMalloc(size_t required){
  //Start from the beginning and loop forwards
  blockHeader *subject = start;

  while(subject != nullptr){
    // First scenario: FInding a suitable empty block of the right size
    if(subject->empty && subject->size >= required){

    } 
  }
}


void myFree(blockHeader *target){
  blockHeader *subject = start;
  while(subject != nullptr){
    break;
  }
}


int main(){
  start = reinterpret_cast<blockHeader *>(heap);
  start->empty = true;
  start->size = sizeof(heap) - sizeof(blockHeader);
  start->next = nullptr;
  start->previous = nullptr;

  std::cout << sizeof(*start) << " " << alignof(*start) << std::endl;
  
  return 0;
} 