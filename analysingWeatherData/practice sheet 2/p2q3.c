
#include <stdio.h>


/*  ***Remember to modify the location of weather file in your own computer.***  */
/*  The file weather.txt should have at most five lines.  */
const char *WEATHER_FILE_PATH = "./inputfiles/weather.txt";

char weatherArr[5][70];    /*  Array to store weather data (limited to five rows)  */
int lineNum;
int i;


int main(void)
{
    FILE *fp = fopen(WEATHER_FILE_PATH, "r+");    /*  Open file for reading.  */
	
/*  This will take each row in the file and store it in weatherArr.  */
    if(fp == NULL)    /*  Check does weather file exist, etc.  */
    {
        perror("Error opening weather file");
        lineNum = -1;    /* use this as a file not found code.  */
    }
    else
    {
/*  Recall that fgets returns NULL when it gets to the end of the file.  */
        while(fgets(weatherArr[lineNum], sizeof(weatherArr[lineNum]), fp) != NULL)
            lineNum++;

        fclose (fp);
    }

/*  Print out  the lines that were read from the file.  */
    for(i = 0;  i < lineNum;  i++)
    {
        printf("\n%s\n", weatherArr[i]);
    }

    return 0;
}
