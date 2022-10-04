#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"


//initialising the variables
int randomise(int r);
int compare (struct MUSIC *A, struct MUSIC *B);
int convertInt(char length[20]);
int readFile();
void sortRecord(int r);

//structure to store song info
struct MUSIC record[MAX];
//array for storing the playlist
int playlist[MAX];



int main () {

  int r = readFile(); //reads and stores data

  sortRecord(r); //sorts music records

    for(int i = 0; i < r; i++){
      printf("ARTIST:  %sSONG: %sLENGTH: %s\n", record[i].artist, record[i].song, record[i].length); //printf statement to print the songs
    }

  int l = randomise(r); //randomises the playlist

   for(int i = 0; i < l; i++){
    printf("ARTIST:  %sSONG: %sLENGTH: %s\n", record[playlist[i]].artist, record[playlist[i]].song, record[playlist[i]].length);
  }

 return(0);
}

int readFile(){

  char file[30];
  char line[80];
  char temp[40];
  int r = 0;


  scanf("%s", &file);
  FILE *fp = fopen(file, "r+"); //fopen function to open the file

  if (fp  == NULL) {
    printf("File doesnt exist\n");
    FILE *fp = fopen("artistes+songs.txt", "r+");

    if ((fp = fopen("artistes+songs.txt" , "r")) == NULL) {
        printf("file not found\n");
    }

  }

  while(!feof(fp)) {   //while loop to read everything till the end of the file
    int i = 0, j = 0;

    fgets(line, 80, fp); //gets a line

      if(line[0] == '\n'){  //checks whether the line is blank
        fgets(line, 80, fp);
        r=r-1;
      }

 //checks whether or not the line contains * and then stores in in record.artist
    if(strchr(line, '*') == NULL){
      strcpy(temp, line);
    }

    else{
      strcpy(record[r].artist, temp);

// if line соntаins * then split
        while(line[i] != '*'){
          i++;
        }
        for(j = 0; j<i;j++){
          record[r].song[j] = line[j];
        }
        record[r].song[j]= '\n';
        i+=3;


                                                                              // аnd the seсоnd hаlf intо reсоrd.length
        for(j = 0; j<strlen(line);j++){
          record[r].length[j] = line[i+j];
        }

      }
      r++;

  }
  fclose(fp);


  return r;
}

int convertInt(char length[20]){                                          // FUNCTION TO CONVER THE LENGTH OF SONGS FROM CHAR TO INT
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

int randomise( int r) //randomises the playlist
{
  int l = 0;
  int i = 0;

  while(l < 3600 && i<r){ //3600 seconds = 60 minutes

    int j = rand() % (r); //adds a random song

    for(int k=0;k<=i;k++){
      while(playlist[k]==j){
        j = rand() % (r);
      }
    }
    playlist[i]=j;

    l += convertInt(record[j].length);
    i++;
  }


  return i; //returns playlist's length

}


int compare (struct MUSIC *A, struct MUSIC *B){
  return strcmp(A->artist,B->artist); //compares in quicksort
}

  void sortRecord(int r){
    qsort(record, r, sizeof(struct MUSIC), compare);
 }
