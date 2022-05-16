#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
  Chunk chunk;
  initChunk(&chunk);

  writeConstant(&chunk, 1.7, 123);
  for (int i=0; i < 260; i++) {
    writeConstant(&chunk, 1.2+i, 123);
  }
  writeConstant(&chunk, 3, 123);

  writeChunk(&chunk, OP_RETURN, 125);

  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
  return 0;
}
