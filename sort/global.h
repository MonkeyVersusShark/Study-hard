#ifndef __GLOBAL_H__
#define __GLOBAL_H__

inline void swap(int *n1, int *n2) {
    if (n1 != n2) {
        int temp = *n1;
        *n1 = *n2;
        *n2 = temp; 
    }
 }

#endif
