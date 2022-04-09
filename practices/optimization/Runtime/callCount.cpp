#include <stdio.h>
#include <map>

static int count = 0;
static std::map<int, int> CountMap;

extern "C"
void countCall() {
  count++;
}

extern "C"
void printResult() {
  printf("Dynamic call count: %d\n", count);
}

extern "C"
void countCallPerInst(int id) {
  if(CountMap.count(id) == 0) {
    CountMap[id] = 0;
  } else {
    CountMap[id]++;
  }
}

extern "C"
void printResultPerInst() {
  printf("Dynamic call count: \n");
  for(auto &entry : CountMap) {
    printf("Inst ID: %d / Call count: %d\n", entry.first, entry.second);
  }
}

