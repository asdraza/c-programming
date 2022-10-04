//guards
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define MAX 90

struct MUSIC{ //structure function

  char artist[MAX];
  char song[MAX];
  char length[MAX];

};
int convertInt(char length[20]);
int convertInt(char length[20]);
void sortRecord(int r);
int readFile();

#endif
