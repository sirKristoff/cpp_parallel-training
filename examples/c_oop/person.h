#ifndef PERSON_H
#define PERSON_H

struct person_ctx;

typedef struct person {
  struct person_ctx *ctx;
  void (*set_name)(struct person *self, const char *name);
  const char* (*get_name)(struct person *self);
} person;

person* person_alloc(const char *name);
void person_init(person *p, const char *name);

void person_free(person *p);
void person_clean(person *p);

#endif
