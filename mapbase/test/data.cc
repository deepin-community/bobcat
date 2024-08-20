#include "main.ih"

size_t bufSize = 10;

bool read = false;

size_t fileSize = 0;
size_t offset = 0;
size_t currentPos = 0;
size_t realSize = 0;
size_t nToDo;

char const *what;
char const *fromTo;
char const *seek;

void (*file)();
void (*setRW)();
//bool 
void (*eofCheck)();
bool (*checkFit)();
