#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BIT_MASK(bit) (1 << (bit))
#define BIT_MASK_LL(bit) ((unsigned long long) 1 << (bit))
#define SET_BIT(value, bit) ((value) |= (BIT_MASK(bit)))
#define TEST_BIT(value, bit) ((value) & (BIT_MASK(bit)) != 0)
#define CLR_BIT(value, bit) ((value) &= ~(BIT_MASK(bit)))
#define SET_BIT_LL(value, bit) ((value) |= (BIT_MASK_LL(bit)))
#define TEST_BIT_LL(value, bit) ((value) & (BIT_MASK_LL(bit)) != 0)
#define CLR_BIT_LL(value, bit) ((value) &= ~(BIT_MASK_LL(bit)))

/**
 * given the charvalue, set high the value at the char index
 */
void setBitmap(unsigned long long bmp[4], char c) {

  // getting the & would be
  uint8_t hiBits = (BIT_MASK(7) | BIT_MASK(6));
  uint8_t i = (c & hiBits) >> 6;

  //setbit doesn't work correctly if I'm setting unsigned long long; 
  SET_BIT_LL(bmp[i], c & ~hiBits);
}

int testBitmap(int argc, char *argv[]) {

  unsigned long long bitmap[4] = {0, 0, 0, 0};

  setBitmap(bitmap, 'a');
  printf("%c aka %#x: 0x%016llx, 0x%016llx, 0x%016llx, 0x%016llx\n", 'a', 'a', bitmap[3],
         bitmap[2], bitmap[1], bitmap[0]);
  setBitmap(bitmap, 'C');
  printf("%c aka %#x: 0x%016llx, 0x%016llx, 0x%016llx, 0x%016llx\n", 'C', 'C', bitmap[3],
         bitmap[2], bitmap[1], bitmap[0]);
  setBitmap(bitmap, '9');
  printf("%c aka %#x: 0x%016llx, 0x%016llx, 0x%016llx, 0x%016llx\n", '9', '9', bitmap[3],
         bitmap[2], bitmap[1], bitmap[0]);

  return EXIT_SUCCESS;
}
