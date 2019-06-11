#ifndef CHUNK_H
#define CHUNK_H

#include <stdint.h>

enum State
{
    Free,
    Allocated    
};

class Chunk
{
    uint8_t* _chunkData;
    State    _chunkState; 
    Chunk*   _nextChunk;
      
public:
  
    Chunk(uint8_t* offset);
    
    void InitChunks(Chunk* firstChunk, uint8_t* offset, unsigned int numChunk, unsigned int chunkSize);
    
    Chunk* Allocate(uint8_t* chunkData, unsigned int chunkSize);
    Chunk* Free();
    
    Chunk* NextChunk();
    uint8_t* GetChunkData();
};

#endif
