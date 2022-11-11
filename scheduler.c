#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int track, head, distance;
int SIZE = 8;
int start = 0;
int end = 4999;

int numberOfElemsInArray(int arr[]) {

}

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

 void CSCAN(int disc_req[], int head, int length)
{
    
    int totalHeadMoves = 0;
  
    // create new array with 3 more spaces for head, end of track and beginning (4999 and 0 respectively)
    int newArr[length + 3];
    for (int i = 0; i < length; i++)
    {
        newArr[i] = disc_req[i]; // populate array with elements of our old array
    }

    // add the head to this new array
    newArr[length] = head;
    newArr[length + 1] = end;
    newArr[length + 2] = start;
    int newLength = length + 3;
   

    // first sort array
    int temp = 0;
    for (int i = 0; i < newLength + 1; i++)
    {
        for (int j = i + 1; j < newLength + 1; j++)
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
    for (int i = 0; i < newLength + 1; i++)
    {
        if (newArr[i] == head)
        {
            index = i;
            break;
        }
    }
    
    printf("%s", "Seek Sequence is: \n");
    for (int i = index + 1; i < newLength + 1; i++)
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
    
    for (int i = 1; i < index; i++)
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
    int length = sizeof(disc_req) / sizeof(disc_req[0]);

    // fcfs(disc_req, head);
    //clook(disc_req, head);
    CSCAN(disc_req, head, length);

    return 0;
}