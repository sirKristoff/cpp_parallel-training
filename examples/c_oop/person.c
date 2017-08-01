#include "person.h"
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct person_ctx {
  char name[MAX_NAME_LEN];
} person_ctx;

static void person_set_name(person *self, const char *name)
{
  if (name)
    strcpy(self->ctx->name, name);
}

static const char* person_get_name(person *self)
{
  return self->ctx->name;
}

person* person_alloc(const char *name)
{
  person *p = malloc(sizeof(person));
  person_init(p, name);

  return p;
}

void person_init(person *p, const char *name)
{
  p->ctx = malloc(sizeof(person_ctx));
  p->set_name = person_set_name;
  p->get_name = person_get_name;
  memset(p->ctx->name, 0, MAX_NAME_LEN);
  if (name)
    strcpy(p->ctx->name, name);
}

void person_free(person *p)
{
  free(p->ctx);
  free(p);
}

void person_clean(person *p)
{
  free(p->ctx);
}
