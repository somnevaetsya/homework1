#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

struct music_comp {
  char name[20];
  int dur_min;
  int dur_sec;
  int bpm;
};

int find_first_structure(struct music_comp *buf, int n);
int print_other_structures(int n, 
struct music_comp *first);
bool bpm(int bpm,
 int bpm_sample);
bool duration(int dur_min, int dur_sec, int dur_min_sample, int dur_sec_sample);
