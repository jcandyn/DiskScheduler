#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int track, head, distance;
int SIZE = 8;
int start = 0;

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

// direction -> greater will be 1
// direciton <- less than, will be 0
void clook(int disc_req[], int head)
{
    int totalHeadMoves = 0;
    // create new array with one more space for an element
    int newArr[SIZE + 1];
    for (int i = 0; i < SIZE; i++)
    {
        newArr[i] = disc_req[i]; // populate array with elements of our old array
    }

    int loop;

    for (loop = 0; loop < SIZE + 1; loop++)
        printf("%d \n", newArr[loop]);

    // add the head to this new array
    newArr[SIZE] = head;

    // first sort array
    int temp = 0;
    for (int i = 0; i < SIZE + 1; i++)
    {
        for (int j = i + 1; j < SIZE + 1; j++)
        {
            if (newArr[i] > newArr[j])
            {
                temp = newArr[i];
                newArr[i] = newArr[j];
                newArr[j] = temp;
            }
        }
    }

    int index = -1;

    // find index of head
    for (int i = 0; i < SIZE + 1; i++)
    {
        if (newArr[i] == head)
        {
            index = i;
            break;
        }
    }

    printf("%s", "Seek Sequence is: \n");
    for (int i = index + 1; i < SIZE + 1; i++)
    {
        track = newArr[i];
        // get distance
        distance = abs(track - head);

        // increase the total head moves count
        totalHeadMoves += distance;

        // the current track becomes the new head
        head = track;
        printf("%d ", newArr[i]); // print all elements starting from head
    }

    // when end is reached
    for (int i = 0; i < index; i++)
    {
        track = newArr[i];
        // get distance
        distance = abs(track - head);

        // increase the total head moves count
        totalHeadMoves += distance;

        // the current track becomes the new head
        head = track;
        printf("%d ", newArr[i]); // print all elements starting from lowest value until head
    }

    printf("\nTotal head movements = %d \n", totalHeadMoves);
}

// Driver code
int main()
{
    // request array

    // int disc_req[10] = {2069, 1212, 2296, 2800, 544, 1618, 356, 1523, 4965, 3681}; // sample request

    int disc_req[8] = {176, 79, 34, 60, 92, 11, 41, 114}; // sample request
    int head = 50;                                        // this will be obtained from command line input

    // fcfs(disc_req, head);
    clook(disc_req, head);

    return 0;
}