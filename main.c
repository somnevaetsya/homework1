#include "struct.h"
#include <time.h>



int main(void) {
  int n = 0;
  char s [SIZE_NAME];
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
  if (buf == NULL) {
    fprintf(stderr, "There are not enough memory for buf...");
    return EXIT_FAILURE;
  }

  if (find_first_structure(buf, RAND_COMP) == ERR)
  return EXIT_FAILURE;

  if (print_other_structures(n, buf) == ERR)
  return EXIT_FAILURE;
  printf("End of compilation\n");
  free(buf);
  return 0;
}