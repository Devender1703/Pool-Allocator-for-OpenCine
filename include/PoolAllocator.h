#ifndef POOLALLOC_H
#define POOLALLOC_H

#include "Chunk.h"

#define SzLimit 15 * 1024 * 1024 

class RawPoolAllocator 
{
    uint8_t* _frameBuffer; 
    
    unsigned int _frameSize;
    unsigned int _numChunk;
    
    Chunk* _firstChunk;
    Chunk* _freeThisChunk;
    Chunk* _allocateThisChunk; 
    
public:

    RawPoolAllocator(unsigned int frameSize, unsigned int numFrame);
    
    void AllocateThisChunk(uint8_t* frameData);
    uint8_t* FreeThisChunk();
};


#endif

