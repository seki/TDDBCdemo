/* vending.h */
typedef struct Vending_s * Vending_p;

Vending_p
VendingCreate(void);

void
VendingForget(Vending_p self);

int
VendingAmount(Vending_p self);

int
VendingSalesAmount(Vending_p self);

int
VendingDropIn(Vending_p self, 
	      int money);

int
VendingCancel(Vending_p self);

const char *
VendingItemName(Vending_p self);

int
VendingItemPrice(Vending_p self);

int
VendingItemStock(Vending_p self);

int
VendingCanBuy(Vending_p self);

int
VendingBuy(Vending_p self);

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
  assert(VendingSalesAmount(v) == 0);
  assert(! strcmp(VendingItemName(v), "Cola"));
  assert(VendingItemPrice(v) == 120);
  assert(VendingItemStock(v) == 5);
  assert(! VendingCanBuy(v));
  assert(! VendingBuy(v));

  VendingDropIn(v, 100);
  assert(VendingAmount(v) == 100);
  assert(VendingSalesAmount(v) == 0);

  VendingDropIn(v, 100);
  assert(VendingAmount(v) == 200);
  assert(VendingCanBuy(v));

  assert(VendingBuy(v));
  assert(VendingSalesAmount(v) == 120);

  assert(VendingCancel(v) == 80);
  assert(VendingAmount(v) == 0);

  VendingDropIn(v, 1000);
  assert(VendingBuy(v));
  assert(VendingBuy(v));
  assert(VendingBuy(v));
  assert(VendingBuy(v));
  assert(! VendingBuy(v));
  assert(VendingAmount(v) == 520);
  assert(VendingSalesAmount(v) == 600);

  VendingForget(v);
  return 1;
}

static int
testDropIn(void)
{
  Vending_p v = VendingCreate();

  assert(! VendingDropIn(v, 1));
  assert(! VendingDropIn(v, 5));
  assert(VendingDropIn(v, 10));
  assert(VendingDropIn(v, 50));
  assert(VendingDropIn(v, 100));
  assert(VendingDropIn(v, 500));
  assert(VendingDropIn(v, 1000));
  assert(VendingAmount(v) == 1660);

  return 1;
}

int
main(int argc,
     char **argv)
{
  assert(testBuy());
  assert(testDropIn());
  puts("done");
}

/* vending.c */
#include <stdlib.h>

typedef struct {
  const char * name;
  int price;
  int stock;
} Item_t;

typedef struct Vending_s {
  int amount;
  int sales_amount;
  Item_t item;
} Vending_t;

Vending_p
VendingCreate(void)
{
  Vending_p self = calloc(1, sizeof(Vending_t));
  self->item.name = "Cola";
  self->item.price = 120;
  self->item.stock = 5;
  
  return self;
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

int
VendingSalesAmount(Vending_p self)
{
  return self->sales_amount;
}

int
VendingDropIn(Vending_p self,
	      int money)
{
  static int s_accept[] = {10, 50, 100, 500, 1000, 0};
  int i;
  
  for (i = 0; s_accept[i]; i++) {
    if (s_accept[i] == money) {
      self->amount += money;
      return 1;
    }
  }
  
  return 0;
}

int
VendingCancel(Vending_p self)
{
  int amount = self->amount;
  self->amount = 0;
  return amount;
}

const char *
VendingItemName(Vending_p self)
{
  return self->item.name;
}

int
VendingItemPrice(Vending_p self)
{
  return self->item.price;
}

int
VendingItemStock(Vending_p self)
{
  return self->item.stock;
}

int
VendingCanBuy(Vending_p self)
{
  return self->item.stock >= 1 && self->item.price <= self->amount;
}

int
VendingBuy(Vending_p self)
{
  if (! VendingCanBuy(self)) return 0;

  self->item.stock -= 1;
  self->amount -= self->item.price;
  self->sales_amount += self->item.price;

  return 1;
}
