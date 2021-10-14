#include "struct.h"

int main(void) {
  int n = 0;
  char s [20];
  srand(time(0));
  printf("Enter number of composition: ");
  scanf("%19s", s);
  char* endptr = NULL;
  while (atoi(s) == 0) {
    printf("Print number! Not string!\n");
    printf("Enter number of composition: ");
    scanf("%19s", s);
  }
  n = atoi(s);
  struct music_comp *buf = (struct music_comp*)malloc(sizeof(struct music_comp));
  if (find_first_structure(buf, rand() % (10000 - 0 + 1)) == -1)
  return 0;
  if (print_other_structures(n, buf) == -1)
  return 0;
  printf("End of compilation\n");
  free(buf);
  return 0;
}