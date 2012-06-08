/* vending.h */
typedef struct Vending_s * Vending_p;

Vending_p
VendingCreate(void);

void
VendingForget(Vending_p self);

int
VendingAmount(Vending_p self);

void
VendingDropIn(Vending_p self, 
	      int money);

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

  VendingDropIn(v, 100);
  assert(VendingAmount(v) == 100);

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
  int amount;
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
  return self->amount;
}

void
VendingDropIn(Vending_p self,
	      int money)
{
  self->amount += money;
}
