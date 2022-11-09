#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int track, head, distance;
int SIZE = 8;

void fcfs(int disc_req[], int head)
{
    int totalHeadMoves = 0;
    for (int i = 0; i < SIZE; i++)
    {
        track = disc_req[i];

        // get distance
        distance = abs(track - head);

        // increase the total head moves count
        totalHeadMoves += distance;

        // the current track becomes the new head
        head = track;
    }

    printf("Total head movements = %d \n", totalHeadMoves);

    // Seek sequence would be the same
    // as request array sequence
    printf("%s", "Seek Sequence is: \n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", disc_req[i]);
    }
}

// Driver code
int main()
{
    // request array

    // int disc_req[10] = {2069, 1212, 2296, 2800, 544, 1618, 356, 1523, 4965, 3681}; // sample request

    int disc_req[8] = {95, 180, 34, 119, 11, 123, 62, 64}; // sample request
    int head = 50;                                         // this will be obtained from command line input

    fcfs(disc_req, head);

    return 0;
}