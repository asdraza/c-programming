#include <string.h>
#include <stdio.h>
#include "library.h"

int readFile()
{

  char file[30];
  char line[80];
  char temp[40];
  int r = 0;

  scanf("%s", &file);
  FILE *fp = fopen(file, "r+");

  if (fp  == NULL) {
    printf("File doesn't exist\n");
    FILE *fp = fopen("artistes+songs.txt", "r+");

    if ((fp = fopen("artistes+songs.txt" , "r")) == NULL) {
        printf("file not found\n");
    }
  }

  while(!feof(fp)) {
    int i = 0, j = 0;

    fgets(line, 80, fp);

      if(line[0] == '\n'){
        fgets(line, 80, fp);
        r=r-1;
      }

    //if there is no * then stоre intо reсоrd.аrtist
    if(strchr(line, '*') == NULL){
      strcpy(temp, line);
    }

    else{
      strcpy(record[r].artist, temp);

      //if there is no * then split the string
        while(line[i] != '*'){
          i++;
        }
        for(j = 0; j<i;j++){
          record[r].song[j] = line[j];
        }
        record[r].song[j]= '\n';
        i+=3;


    // store the other half intо reсоrd.length
        for(j = 0; j<strlen(line);j++){
          record[r].length[j] = line[i+j];
        }

      }
      r++;

  }
  fclose(fp);


  return r;
}


int convertInt(char length[20]) //converts the song's length from char to int
{
  int i =0, j=0;
  char min[10];
  char sec[10];
  while(length[i] != ':'){
    i++;
  }

  for(j = 0; j<i ;j++){
    min[j]=length[j];
  }

  sec[0]=length[j+i];
  sec[1]=length[j+i+1];

  int l = atoi(min) * 60;
  l += atoi(sec);

  return l;
}
//compare function to compare in quicksort
int compare (struct MUSIC *A, struct MUSIC *B){
  return strcmp(A->artist,B->artist);
}

  void sortRecord(int r){
    qsort(record, r, sizeof(struct MUSIC), compare); //sorts the records depending on compare
 }
