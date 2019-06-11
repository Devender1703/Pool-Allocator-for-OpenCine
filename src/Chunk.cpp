#include <iostream>
#include <cstring>

#include "../include/Chunk.h"

Chunk::Chunk(uint8_t* offset)
{
    _chunkData  = offset;
    _chunkState = State::Free;
    _nextChunk  = nullptr;    
}

void Chunk::InitChunks(Chunk* firstChunk, uint8_t* offset, unsigned int numChunk, unsigned int ChunkSize)
{  
    Chunk* tempChunk = firstChunk;
    
    for(unsigned int index = 0; index < numChunk - 1; index++)
    {  
        offset += ChunkSize;
        tempChunk->_nextChunk = new Chunk(offset);
        tempChunk = tempChunk->_nextChunk;
    }  
    
    // connect last frame to first frame and make circular queue like structure
    tempChunk->_nextChunk = firstChunk;
}

Chunk* Chunk::Allocate(uint8_t* frameData, unsigned int frameSize)
{   
     std::memcpy(_chunkData, frameData, frameSize);
     _chunkState = State::Allocated;
     
     return _nextChunk;
}

uint8_t* Chunk::GetChunkData()
{
     return _chunkData;
}

Chunk* Chunk::Free()
{
     _chunkState = State::Free;
     return _nextChunk;
}

Chunk* Chunk::NextChunk()
{
     return _nextChunk;
}

