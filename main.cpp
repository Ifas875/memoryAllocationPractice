#include <iostream>
#include <string>
#include <stdint.h>


u_int8_t heap[100];


struct blockHeader{
  blockHeader *next;
  int size;
};


int main(){
  return 0;
}