#include <iostream>

#include "include/Chunk.h"
#include "include/PoolAllocator.h"

using namespace std;

int main()
{
   RawPoolAllocator *allocator = new RawPoolAllocator(1024445, 1000);
   
   delete allocator;
}
