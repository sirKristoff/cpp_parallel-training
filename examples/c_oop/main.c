#include "person.h"
#include <stdio.h>

int main(int argc, char** argv)
{
  person p;
  person_init(&p, "Roman");
  printf("%s\n", p.get_name(&p));
  p.set_name(&p, "Stachu");
  printf("%s\n", p.get_name(&p));
  person_clean(&p);
  return 0;
}