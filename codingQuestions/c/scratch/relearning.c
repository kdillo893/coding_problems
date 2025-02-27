#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

// pre-process directives that are fun
#define INCHES_PER_POUND 166

#define YOUR_MOM "fat"

float celsiusFromF(float f) { return (float)(f - 32) * 5 / 9; }

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
        buf[startIdx + j] = rep[j];
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

void stringStuff() {

  // string stuff
  char something[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  something[4] = '\0';

  // size of an array (capacity) is sizeof(pointer to array) / sizeof(type)
  size_t nsom = sizeof(something) / sizeof(char);
  int len = strlen(something);
  printf("%s, %lu, strlen=%d\n", something, nsom, len);

  // testing char array iteration... how to know when to terminate loops?
  int i = 0;
  while (i < (int)nsom) {
    if (something[i] == '\0')
      break;
    i++;
  }

  // initializing a string without specifying array length will
  // automatically include space for \0
  char toadd[] = "ABCDE";

  // cat will look for the end of the current string (\0) and append the src
  // argument ending with \0. This reaches outside buffer for something. if you
  // attempt to strcat past the available buffer of an array, stack smash. to
  // avoid stack smashing, need to assure the char count is less than the buffer
  // strcat can add the \0 without stack smashing if the length of non-null
  // characters add up to bufflen-1
  printf("sizecomp: toaddsize=%lu, strlen=%lu, somethingsize=%lu\n",
         strlen(toadd), strlen(something), sizeof(something));
  if (strlen(toadd) + strlen(something) * sizeof(char) >= sizeof(something)) {
    printf("No cat b/c stack smashing possible\n");
  } else {
    strcat(something + 2, toadd);
  }
  printf("AfterCAT: %s, %lu\n", something, nsom);

  printf("%d, %d, %d\n", something[0] - something[2],
         something[2] - something[0], 12123);

  // strcpy puts that string and appends \0 at location
  strcpy(something, "ABCDE");
  nsom = sizeof(something) / sizeof(char);
  printf("AfterCOPY: %s, %lu\n", something, nsom);

  for (int i = 0; i < sizeof(something) / sizeof(char); i++) {
    char val = something[i];
    printf("%c, %d\n", val, i);
  }

  printf("did I get here?\n");
}

void dumbStuff() {
  // testing some dumb number shit
  float x;
  x = 1. / 2 * 3;
  printf("x = %.1f \n", x);

  char c;
  c = 'a';
  c -= ' ';

  printf("' ' = %d, 'a' = %d, c = %c\n", ' ', 'a', c);

  // dumb stuff
  int i, j = 0;
  for (i = 0; !i; i++) {
    j++;
  }

  printf("%d\n", j);

  i = 0;
  j = 1;
  int k;
  // I never knew that shift operations were lower priority than arithmetic.
  // interesting. This commented is the same as the one with parentheses
  // k = i << j + j << i;
  k = i << (j + j) << i;

  printf("%d\n", k);
}

void f1(void) {}
int f2(void) {
  // implicit return 0; if empty, but warning make it explicit
  return 0;
}
void f3(char *s, int i) { *(s + i) = '\0'; }
int f4(char t[]) { return t[0] - t[-1]; }
void (*f5)(int);
void f6(int something) {

  //this does something

} 

void functionStuff() {
  int i;
  // can't set from incompatible return type
  //  i = f1();
  // CAN return when no return specified if return type correct
  i = f2();

  printf("%d\n", i);

  char a[] = {'a', 'b', 'c', 'd'};
  // this is the VALUE of the char passing, this is wrong
  //  f3(a[1], 1);
  // the way to correct this is pointer address passing
  f3(a + 1, 1);

  printf("%s\n", a);

  i = 2;
  // adding ints to string shifts the pointer of that string.
  i -= f4("ABDGK" + 1);
  printf("%d\n", i);

  f5 = &f6; 
}

struct IntWrap {
  int gronk;
};

struct DeepIntWrap {
  int guac;
  struct IntWrap baby;
};

void structStuff() {

  // cool stuff, you can assign the elements of a struct with braces!
  struct IntWrap s = {3};
  // can you do this deep? NEAT
  struct DeepIntWrap dp = {2, {4}};

  struct DeepIntWrap *dPointer = &dp;

  // pointers to things need -> to dereference 
  //    (we know where it is, don't have local reference to the data)
  // direct structure can reference the internals by . 
  //    (we have local reference to the data, the dot is just the offset from
  //    where we have it known in stack/local)
  printf("%d\n", dp.baby.gronk + dp.guac + s.gronk);
  printf("%d\n", dPointer->baby.gronk + dPointer->guac + s.gronk);
}

void fileioStuff() {

  int i;

  FILE *file1 = fopen("testFile", "w");
  fputs("12A", file1);
  fclose(file1);

  file1 = fopen("testFile", "r");
  // these were flipped around in the online practice tool: wrong parameters
  fseek(file1, 0, SEEK_END);
  i = ftell(file1);
  fclose(file1);

  printf("%d\n", i);

  // ftell: return current position of stream;
  //  ftell(file1);

  // fseek: move to the position in the stream
  //  fseek(file1, 0, SEEK_CUR);

  // write byte mode
  FILE *file2;
  file2 = fopen("newFile", "wb");
  printf("%d\n", file2 != NULL);
  fclose(file2);

  // can you try writing to stdin? Turns out YES. This is legal but not useful
  // This DOES reach EOF, as the input port is waiting for more
  i = fprintf(stdin, "Hello?");
  printf("%d\n", i == EOF);

  // this doesn't reach EOF... likely because output ports aren't "ending"
  i = fprintf(stderr, "Hello!");
  printf("%d\n", i == EOF);

  // can I seek to EOF on the output ports?
  fseek(stderr, 0, SEEK_END);
  i = ftell(stderr);
  printf("%d\n", i == EOF);

  // doing this makes output funky, but I want to know how the out fd works.
  fseek(stdout, 0, SEEK_END);
  i = ftell(stdout);
  printf("%d\n", i == EOF);

  // can i fstat the standard file descriptors?
  // stat library functions:
  // stat(pathname, *statbuf) -get the file from pathname then put stats in
  // buffer fstat(fd, *statbuf) - same but we already have the FD
  struct stat statbuf;
  fstat(STDOUT_FILENO, &statbuf);

  // fstats (from the stat(3type) man page)
  //  dev_t      st_dev;      /* ID of device containing file */
  //   --rdev?
  //  ino_t      st_ino;      /* Inode number */
  //  mode_t     st_mode;     /* File type and mode */
  //  nlink_t    st_nlink;    /* Number of hard links */
  //  uid_t      st_uid;      /* User ID of owner */
  //  gid_t      st_gid;      /* Group ID of owner */
  //  dev_t      st_rdev;     /* Device ID (if special file) */
  //  off_t      st_size;     /* Total size, in bytes */
  //  blksize_t  st_blksize;  /* Block size for filesystem I/O */
  //  blkcnt_t   st_blocks;   /* Number of 512 B blocks allocated */

  printf("File stats of stdout\n");
  printf("st_dev=%lu\n", statbuf.st_dev);   //?
  printf("st_rdev=%lu\n", statbuf.st_rdev); // rdev?
  printf("st_ino=%lu\n", statbuf.st_ino);   // inode?
  printf("st_mode=%u\n", statbuf.st_mode);
  printf("st_nlink=%lu\n", statbuf.st_nlink);
  printf("st_uid=%u\n", statbuf.st_uid);    // userid
  printf("st_gid=%u\n", statbuf.st_gid);    // groupid?
  printf("st_size=%lu\n", statbuf.st_size); // total size bytes
  printf("st_blksize=%lu\n", statbuf.st_blksize);
  printf("st_blocks=%lu\n", statbuf.st_blocks);
  printf("st_ctim.tv_nsec=%lu.%lu\n", statbuf.st_ctim.tv_sec,
         statbuf.st_ctim.tv_nsec);
  printf("st_atim.tv_nsec=%lu.%lu\n", statbuf.st_atim.tv_sec,
         statbuf.st_atim.tv_nsec);
  printf("st_mtim.tv_nsec=%lu.%lu\n", statbuf.st_mtim.tv_sec,
         statbuf.st_mtim.tv_nsec);

  printf("What the hell does this do?\n");


  //what if I just don't close a file and exit?
  FILE *file3 = fopen("newFile", "w");
  int j = fputs("Hello?!", file3);

  printf("%d\n", j != EOF);

}

int main(int argc, char *argv[]) {

  // testingBull();

  // read float into far
  // float far;
  // printf("Enter fahrenheit: ");
  // scanf("%f", &far);
  // printf("%.1f fahrenheit = %.1f celsius\n", far, celsiusFromF(far));

  printf("DumbStuff:\n\n");
  dumbStuff();
  printf("StringStuff:\n\n");
  stringStuff();
  printf("FunctionStuff:\n\n");
  functionStuff();
  printf("structStuff:\n\n");
  structStuff();
  printf("fileioStuff:\n\n");
  fileioStuff();

  // stdlib contains exit things
  return EXIT_SUCCESS;
}
