#include "3.1ass.h"

int main(void) {

  return 0;
}

uint64_t decode_od(od_t od) {
  if (od.type == IMM) {
    return od.imm;
  } else if (od.type == REG) {
    return *(uint64_t *)od.reg1;
  } else {
    uint64_t addr = MM_LEN + 0xff;
    return mm[addr % MM_LEN];
  }
}