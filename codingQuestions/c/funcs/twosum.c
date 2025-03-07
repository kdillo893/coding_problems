#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define BUCKET_EXP 5

// Map thing; just int by int key since the values are ints
typedef struct map_node_t {
  int key;
  int val;
  struct map_node_t *next;
} MapNode;

typedef struct {
  MapNode **nodes;
  int bucketExp;
  int size;
} IntMap;

IntMap *initIntMap() {
  IntMap *map = malloc(sizeof(IntMap));
  //  2^bucketExp buckets
  map->bucketExp = BUCKET_EXP;
  map->size = 0;

  unsigned int buckets = 1 << map->bucketExp;

  // I need to pre-allocate heads of linked lists; these are a series of
  // pointers to MapNode
  map->nodes = calloc(buckets, sizeof(MapNode));

  //  ensure nodes have null on pointer
  // for (int i = 0; i < buckets; i++) {
  //  MapNode *node = map->nodes[i];
  //  if (node) {
  //    node->key = -1;
  //    node->val = -1;
  //    node->next = NULL;
  //  } else {
  //    printf("How many am I missing? %d\n", i);
  //  }
  //}

  return map;
}

void freeIntMap(IntMap *map) {
  unsigned int buckets = 1 << map->bucketExp;
  for (int i = 0; i < buckets; i++) {
    MapNode *next = map->nodes[i];

    while (next) {
      MapNode *cur = next;
      next = next->next;

      free(cur);
    }
  }

  free(map);
}

// intead of hashing, can truncate int key if buckets is 2^n for speed.
// 1<<bucketExp is 010000; valid indexes are that unsigned minus 1
//  key truncate on lower bits for ease of calculation
unsigned int indexForKey(IntMap *map, int key) {
  unsigned int buckets = 1 << map->bucketExp;
  unsigned int idx = key & (buckets - 1);

  return idx;
}

// intead of hashing, can truncate int key if buckets is 2^n for speed.
// 1<<bucketExp is 010000; valid indexes are that unsigned minus 1
//  key truncate on lower bits for ease of calculation
MapNode *headNodeForKey(IntMap *map, int key) {
  unsigned int buckets = 1 << map->bucketExp;
  unsigned int idx = key & (buckets - 1);

  return map->nodes[idx];
}

// returns 0 if set is good, 1 if bad
// returns 0 if set is good, 1 if bad
int intMapSet(IntMap *map, int key, int val) {
  unsigned int idx = indexForKey(map, key);
  MapNode *node = map->nodes[idx];
  MapNode *last = NULL;
  while (node) {
    if (node->key == key) {
      // replacing the value, no increment size;
      node->val = val;
      return 0;
    }

    // move to next if not found
    last = node;
    node = node->next;
  }

  // node is empty, try allocating a new one;
  node = malloc(sizeof(MapNode));
  if (!node) {
    return 1;
  }
  node->next = NULL;
  node->key = key;
  node->val = val;

  if (last) {
    last->next = node;
  } else {
    map->nodes[idx] = node;
  }

  return 0;
}

// return the value per key, -1 if invalid
int intMapGet(IntMap *map, int key) {
  unsigned int idx = indexForKey(map, key);
  MapNode *node = map->nodes[idx];

  while (node) {
    if (node->key == key) {
      // found
      return node->val;
    }

    // move to next if not found
    node = node->next;
  }

  return -1;
}

int *dummyLoop(int *res, int *nums, int numsSize, int target) {
  for (int i = 0; i < numsSize; i++) {
    int val1 = nums[i];

    for (int j = 0; j < numsSize; j++) {
      if (j == i)
        continue;

      if ((nums[j] + val1) == target) {
        if (i < j) {
          res[0] = i;
          res[1] = j;
        } else {
          res[0] = i;
          res[1] = j;
        }
        return res;
      }
    }
  }
  return res;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {

  int *res = malloc(2 * sizeof(int));
  res[0] = 0;
  res[1] = 1;

  // nums is an unordered list

  // O(n^2), space: O(1)
  // dummy way is "pick index, seek through to check sum match"
  // return dummyLoop(res, nums, numsSize, target);

  // Better: map tracking index per "solution value"
  // O(n), space:O(n)
  IntMap *map = initIntMap();
  _Bool found = 0;
  for (int i = 0; i < numsSize; i++) {
    // the key will be the desired number to add with.
    int key = target - nums[i];

    int otherIdx = intMapGet(map, key);
    if (otherIdx >= 0) {
      if (otherIdx > i) {
        res[0] = i;
        res[1] = otherIdx;
      } else {
        res[0] = otherIdx;
        res[1] = i;
      }

      found = 1;

      break;
    }

    // no index found for the target which would reach sum, insert this entry
    intMapSet(map, nums[i], i);
  }

  freeIntMap(map);

  if (found) {
    *returnSize = 2;
    return res;
  }

  // not found, free I guess.
  *returnSize = 0;
  free(res);
  return NULL;
}

// could put this in another test file... but I like seeing it here for now
void testTwoSum() {

  int size = 35;
  int n1[35];

  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    n1[i] = rand() % 100;
  }
  
  int retSize;
  int targetValue = 23;
  int* res = twoSum(n1, 35, targetValue, &retSize);
  if (retSize >= 2) {
    printf("sumtargets found at indexes [%d,%d]\n", res[0], res[1]);
    printf("target=%d, values: [%d,%d]\n",targetValue, n1[res[0]], n1[res[1]]);
  } else {
    printf("no sumtargets found\n");
  }
}
