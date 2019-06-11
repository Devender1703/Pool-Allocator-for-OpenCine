#include <iostream>
#include <stdint.h>
#include <cstring>

#include "../include/PoolAllocator.h"
#include "../include/Chunk.h"

RawPoolAllocator::RawPoolAllocator(unsigned int frameSize, unsigned int numFrame)
{ 
    _frameSize = frameSize;
    _numChunk  = (frameSize * numFrame <= SzLimit) ? numFrame : (SzLimit / frameSize);  
   
    _frameBuffer        = new uint8_t[_numChunk * _frameSize];
    
    _firstChunk         = new Chunk(_frameBuffer);
    _freeThisChunk      = _firstChunk;
    _allocateThisChunk  = _firstChunk;
    
    _firstChunk->InitChunks(_firstChunk, _frameBuffer, _numChunk, _frameSize);
}

void RawPoolAllocator::AllocateThisChunk(uint8_t* frameData)
{
    _allocateThisChunk = _allocateThisChunk->Allocate(frameData, _frameSize);
}

uint8_t* RawPoolAllocator::FreeThisChunk()
{   
    _freeThisChunk = _freeThisChunk->Free();
    return _freeThisChunk->GetChunkData();
}



