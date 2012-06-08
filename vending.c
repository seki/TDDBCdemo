/* foo.h */
typedef struct Foo_s * Foo_p;

Foo_p
FooCreate(void);

void
FooForget(Foo_p foo);

const char *
FooFoo(Foo_p foo);

/* test.c */
#include <stdio.h>
#include <string.h>
#include <assert.h>

static int
testCore(void)
{
  Foo_p foo = FooCreate();
  assert(foo);
  assert(FooFoo(foo));
  FooForget(foo);
  return 1;
}

int
main(int argc,
     char **argv)
{
  assert(testCore());
  puts("done");
}

/* foo.c */
#include <stdlib.h>

typedef struct Foo_s {
  int foo;
} Foo_t;

Foo_p
FooCreate(void)
{
  return calloc(1, sizeof(Foo_t));
}

void
FooForget(Foo_p self)
{
  free(self);
}

const char *
FooFoo(Foo_p self)
{
  return "Foo";
}
