#ifndef CARDIO_H
#define CARDIO_H
#ifdef __cplusplus
extern "C" {
#endif

#define detectionLimit 600

typedef struct hearbeat {
  int beat;
  int period;
  int startTime;
  int bpm;
  short isOver;
}hearbeat;

// fonction permettant d'initialiser notre structure heartbeat avec
// des valeurs coherentes.
void startCapture(hearbeat *HB, int startTime, int period);


// ajoute un battement (HB->beat += 1);
void beat(hearbeat *HB);

int processing(hearbeat *HB, int sensorValue);

// fonction permettant une fois la capture finir d'obtenir le nombre
// de battement par minute
void determineBPM(hearbeat *HB);

// fonction qui permet de dire que notre capture est fini et ensuite
// capturer le nombre de battement par minute
int stopCapture(hearbeat *HB);

#ifdef __cplusplus
} // extern "C"
#endif
#endif
