/* vending.h */
typedef struct Vending_s * Vending_p;

Vending_p
VendingCreate(void);

void
VendingForget(Vending_p self);

int
VendingAmount(Vending_p self);

/* test.c */
#include <stdio.h>
#include <string.h>
#include <assert.h>

static int
testBuy(void)
{
  Vending_p v = VendingCreate();

  assert(v);
  assert(VendingAmount(v) == 0);

  VendingForget(v);
  return 1;
}

int
main(int argc,
     char **argv)
{
  assert(testBuy());
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

int
VendingAmount(Vending_p self)
{
  return 0;
}
