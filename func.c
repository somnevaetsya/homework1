#include "struct.h"


int find_first_structure(struct music_comp *buf, int n) {
   if (buf == NULL) {
    fprintf( stderr, "Zero pointer!");
    return EXIT_FAILURE;
  }
  if (n == 0) {
    fprintf( stderr, "Enter non-zero nubmer!");
    return ERR;
  }
  FILE *output = NULL;
  output = fopen("../base.tsv", "r");
  if (output == NULL) return -1;
  for (int i = 0; i < n; i++) {
    fscanf(output, "%20s%d%d%d", buf->name, &(buf->dur_min), &(buf->dur_sec),
           &(buf->bpm));
  }
  fclose(output);
  return 0;
}

bool cmp_duration(int dur_min, int dur_sec, int dur_min_sample,
              int dur_sec_sample) {
  if (abs((dur_min * 60 + dur_sec) - (dur_min_sample * 60 + dur_sec_sample)) <=
      10)
    return true;
  else
    return false;
}

bool cmp_bpm(int bpm, int bpm_sample) {
  if (abs(bpm - bpm_sample) <= 2)
    return true;
  else
    return false;
}

int print_other_structures(int n, struct music_comp *first) {
  if (first == NULL) {
    fprintf( stderr, "Zero pointer!");
    return EXIT_FAILURE;
  }
  if (n == 0) {
    fprintf( stderr, "Enter non-zero nubmer!");
    return ERR;
  }
  FILE *output = NULL;
  output = fopen("../base.tsv", "r");
  if (output == NULL) return -1;
  int i = 1;
  struct music_comp *buf = (struct music_comp*)malloc(sizeof(struct music_comp));
  if (buf == NULL) {
    fprintf(stderr, "There are not enough memory for buf...");
    return EXIT_FAILURE;
  }
  while (fscanf(output, "%19s%d%d%d", buf->name, &(buf->dur_min), &(buf->dur_sec),
                &(buf->bpm)) != EOF) {
    if ((cmp_duration(buf->dur_min, buf->dur_sec, first->dur_min,
                  first->dur_sec)) &&
        cmp_bpm(buf->bpm, first->bpm)) {
      printf("%i. Name of compostion: %s\n", i, buf->name);
      printf("   Duration of compostiion: %i min %i sec\n", buf->dur_min,
             buf->dur_sec);
      printf("   Bit per minute: %i\n", buf->bpm);
      i++;
    }
    if ((i - 1) == n)
      break;
  };
  if (i < n)
    printf("There are not enough composition in database...Sorry..");
  free(buf);
  fclose(output);
  return 0;
}
