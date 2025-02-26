#include <stdio.h>
#include <stdlib.h>

// pre-process directives that are fun
#define INCHES_PER_POUND 166

#define YOUR_MOM "fat"

float celsiusFromF(float f) { return (float)(f - 32) * 5 / 9; }

#include <stdio.h>

/**
 * replace instances of "sub" in "buf" with "rep"
 * NOTES: 256char max
 * TODO
 */
void repstr(char *buf, char *sub, char *rep) {
  // search buf forward to get length, checking for indexes of "sub"
  // not using c standards for string checking and replacement, trying to
  // manual-roll

  // edge, if nothing in sub or buf, what are we doing?
  if (*sub == '\0' || *buf == '\0')
    return;

  unsigned int i = 0;
  int subIndex = 0;
  int startIdx = 0;
  for (; buf[i] != 0 && i < 256; i++) {
    if (buf[i] == sub[subIndex]) {
      // we are looking for the sub, increment with looking for next.
      startIdx = i;
      subIndex++;
    }

    if (sub[subIndex] == '\0') {
      // this is the last index of the sub string..., could do in-place edit
      // with internal loop
      for (unsigned int j = 0; j < 256 && rep[j] != '\0'; j++) {
        buf[startIdx+j] = rep[j];
      }
      startIdx = i + 1;
      subIndex = 0;
    }
  }
  return;
}

void testingBull() {
  int i;
  printf("Gimme a number: ");
  scanf("%d", &i);

  int height, length, width, volume;
  float weight;
  printf("Enter height of box: ");
  scanf("%d", &height);
  printf("Enter length of box: ");
  scanf("%d", &length);
  printf("Enter width of box: ");
  scanf("%d", &width);
  volume = height * length * width;
  weight = (float)(volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;

  // printing it for no reason lol
  printf("%d, %f, %s\n", i, weight, YOUR_MOM);
}

int main(int argc, char *argv[]) {

  // testingBull();

  // read integer into i
  float far;
  printf("Enter fahrenheit: ");
  scanf("%f", &far);
  printf("%.1f fahrenheit = %.1f celsius\n", far, celsiusFromF(far));

  // stdlib contains exit things
  return EXIT_SUCCESS;
}
