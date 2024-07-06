#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <assert.h>
#include <unistd.h>

typedef enum { LO = 0, HI = 1 } State_t;

typedef struct {
    State_t state;
} Pin_t;

#endif /* COMMON_H */
