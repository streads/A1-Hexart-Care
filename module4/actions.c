#include <stdlib.h>
#include <stdio.h>

#include "donnees.h"


int getLength(FILE *f){
    fseek(f, 0, SEEK_SET);
    char temp[LENGTH_LINE];
    int i = 0;

    while(fgets(temp, LENGTH_LINE, f) != NULL)
    {
        i ++;
    }
    return i;
}


void read(FILE *s, struct heartBeat **h, int m) {
  fseek(s, 0, SEEK_SET);
  char tab[60];
  struct heartBeat *tmph;
  if((*h = (struct heartBeat *)malloc(sizeof(struct heartBeat) * (m))) == NULL) {
    printf("Impossible d'allouer de l'espace.\n");
    exit(-1);
  }

  int i;
  tmph = *h;
  for(i = 0; i < (m); ++i) {
    int ntok = fscanf(s, "%d;%d", &(tmph[i].timestamp), &(tmph[i].bpm));
    if(ntok != 2) {
      printf("File wrongly formatted.\n");
      exit(-1);
    }
  }

}


void fuse(struct heartBeat *a, struct heartBeat *tmp, int s0, int e0, int s1, int e1, int (cmp)(struct heartBeat *, struct heartBeat *)){
  int i0 = s0;
	for(; i0 < e1; ++i0) {
		if(s1 == e1 || (s0 < e0 && (cmp(&a[s0], &a[s1]) <= 0))) {
			tmp[i0] = a[s0];
			s0++;
		}
		else {
			tmp[i0] = a[s1];
			s1++;
		}
	}
}


void sort(int n, struct heartBeat *a, int (cmp)(struct heartBeat *, struct heartBeat *)) {
	int p0, e0, e1, strd = 1;

	struct heartBeat *tmp, *tmp0, *orig = a;

  if((tmp = malloc(n * sizeof(struct heartBeat))) == NULL) {
    fprintf(stderr, "Unable to malloc enough memory in sorting function.\n");
    exit(-1);
  }

	for(;strd < n;) {
		for(p0 = 0; p0 < (n - (2 * strd)) + 1; p0 = p0 + 2 * strd) {
			e0 = p0 + strd;
			e1 = e0 + strd;

			fuse(a, tmp, p0, e0, e0, e1, cmp);
		}
		if(p0 < n) {
			e0 = p0 + strd;
			e1 = e0 + strd;

			if(e0 > n) e0 = n;
			if(e1 > n) e1 = n;

			fuse(a, tmp, p0, e0, e0, e1, cmp);
		}

		tmp0 = a;
		a = tmp;
		tmp = tmp0;

		strd *= 2;
	}

	if(n >= 2 && tmp == orig) {
		for(p0 = 0; p0 < n; ++p0) {
			orig[p0] = a[p0];
		}
	}
}


void showReversed(int n, struct heartBeat *a) {
  int i;
  system("cls");
  printf("            TIMESTAMP             BPM\n");
  printf("_______________________________________________\n");
  for (i = n; i-- > 0; )
  {
    printf("%18d %18d\n", a[i].timestamp, a[i].bpm);
  }
  printf("_______________________________________________\n");
}


void show(int n, struct heartBeat *a) {
  int i;
  system("cls");
  printf("            TIMESTAMP             BPM\n");
  printf("_______________________________________________\n");
  for(i = 0; i < n; ++i) {
    printf("%18d %18d\n", a[i].timestamp, a[i].bpm);
  }
  printf("_______________________________________________\n");
}


void showInRange(int n, struct heartBeat *a, int min, int max) {
  int i;
  system("cls");
  printf("            TIMESTAMP             BPM\n");
  printf("_______________________________________________\n");
  for(i = 0; i < n; ++i) {
    if (min <= a[i].timestamp && a[i].timestamp <= max){
      printf("%18d %18d\n", a[i].timestamp, a[i].bpm);
    }
  }
  printf("_______________________________________________\n");
}


int moyInRange(int n, struct heartBeat *a, int min, int max) {
  int i;
  int sum = 0;
  int counter = 0;
  for(i = 0; i < n; ++i) {
    if (min <= a[i].timestamp && a[i].timestamp <= max){
      sum += a[i].bpm;
      counter++;
    }
  }
  return sum/counter;
}


int getFirstBPMInRage(int n, struct heartBeat *a, int min, int max){
    int i;
    for(i = 0; i < n; ++i) {
    if (min <= a[i].timestamp && a[i].timestamp <= max){
      return a[i].bpm;
    }
  }
}


int getLastBPMInRage(int n, struct heartBeat *a, int min, int max){
  int i;
  for (i = n; i-- > 0; )
  {
    if (min <= a[i].timestamp && a[i].timestamp <= max){
      return a[i].bpm;
    }
  }
}
