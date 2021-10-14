#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_NAME 20
#define ERR (-1)
#define RAND_COMP (rand() % (10000 - 0 + 1))

struct music_comp {
  char name[SIZE_NAME];
  int dur_min;
  int dur_sec;
  int bpm;
};

int find_first_structure(struct music_comp *buf, int n);
int print_other_structures(int n, struct music_comp *first);
bool cmp_bpm(int bpm, int bpm_sample);
bool cmp_duration(int dur_min, int dur_sec, int dur_min_sample, int dur_sec_sample);
