#define LENGTH_LINE 30
typedef struct heartBeat {
    int timestamp;
    int bpm;
} ab;

int compare_by_BPM(struct heartBeat *a, struct heartBeat *b);
int compare_by_date(struct heartBeat *a, struct heartBeat *b);
