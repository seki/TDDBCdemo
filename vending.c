/* vending.h */
typedef struct Vending_s * Vending_p;

Vending_p
VendingCreate(void);

void
VendingForget(Vending_p vending);

/* test.c */
#include <stdio.h>
#include <string.h>
#include <assert.h>

static int
testCore(void)
{
  Vending_p vending = VendingCreate();
  assert(vending);
  VendingForget(vending);
  return 1;
}

int
main(int argc,
     char **argv)
{
  assert(testCore());
  puts("done");
}

/* vending.c */
#include <stdlib.h>

typedef struct Vending_s {
  int vending;
} Vending_t;

Vending_p
VendingCreate(void)
{
  return calloc(1, sizeof(Vending_t));
}

void
VendingForget(Vending_p self)
{
  free(self);
}
