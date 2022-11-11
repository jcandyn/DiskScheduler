#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int track, head, distance;
int start = 0;
int end = 4999;

int numberOfElemsInArray(int arr[])
{
    return 0;
}

int *sortArray(int disc_req[], int SIZE)
{
    int temp = 0;
    for (int i = 0; i < SIZE + 1; i++)
    {
        for (int j = i + 1; j < SIZE + 1; j++)
        {
            if (disc_req[i] > disc_req[j])
            {
                temp = disc_req[i];
                disc_req[i] = disc_req[j];
                disc_req[j] = temp;
            }
        }
    }
    return disc_req;
}

void fcfs(int disc_req[], int head, int SIZE)
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

void clook(int disc_req[], int head, int SIZE)
{
    int totalHeadMoves = 0;
    // create new array with one more space for an element
    int arr[SIZE + 1];
    int *newArr = arr;

    for (int i = 0; i < SIZE; i++)
    {
        newArr[i] = disc_req[i]; // populate array with elements of our old array
    }

    // add the head to this new array
    newArr[SIZE] = head;

    // first sort array
    newArr = sortArray(newArr, SIZE);

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
    int arr[length + 3];
    int *newArr = arr;

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
    newArr = sortArray(newArr, newLength);

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

void SCAN(int disc_req[], int head, int length)
{

    int totalHeadMoves = 0;

    // create new array with 3 more spaces for head, end of track and beginning (4999 and 0 respectively)
    int arr[length + 2];
    int *newArr = arr;
    for (int i = 0; i < length; i++)
    {
        newArr[i] = disc_req[i]; // populate array with elements of our old array
    }

    // add the head to this new array
    newArr[length] = head;
    newArr[length + 1] = start;
    int newLength = length + 2;

    // first sort array
    newArr = sortArray(newArr, newLength);

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
    for (int i = index; i > 0; i--)
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

    for (int i = index + 1; i < newLength + 1; i++)
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

void look(int *disc_req, int head, int SIZE)
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
    disc_req = sortArray(disc_req, SIZE);
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

    // when end is reached, do opposite than c look, go from head index and decrement index until the first index is reached
    for (int i = index - 1; i >= 0; i--)
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

int validateRequests(int disc_req[], int SIZE)
{
    // first sort array
    disc_req = sortArray(disc_req, SIZE);

    // check if element at first index is less than 0
    if (disc_req[0] < 0 || disc_req[SIZE - 1] > 4999)
    {
        return 0;
    }
    return 1;
}

// Driver code
int main()
{
    // request array
    // int disc_req[10] = {2069, 1212, 2296, 2800, 544, 1618, 356, 1523, 4965, 3681}; // sample request
    int disc_req[8] = {176, 79, 34, 60, 92, 11, 41, 114}; // sample request
    int length = sizeof(disc_req) / sizeof(disc_req[0]);

    int isValid = validateRequests(disc_req, length);
    if (isValid == 0)
    {
        printf("Range of values: 0 to 4999. Entered values are not within range.");
        exit(0);
    }

    int head;
    printf("Enter an initial head value : ");
    scanf("%d", &head);

    // fcfs(disc_req, head, length);
    clook(disc_req, head, length);
    // CSCAN(disc_req, head, length);
    // SCAN(disc_req, head, length);
    // look(disc_req, head, length);
    return 0;
}