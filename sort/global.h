#ifndef __GLOBAL_H__
#define __GLOBAL_H__

void swap(int *n1, int *n2) {
    *n1 ^= *n2;
    *n2 ^= *n1;
    *n1 ^= *n2;
 }

#endif
