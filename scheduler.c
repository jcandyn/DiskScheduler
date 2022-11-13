#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int track, head, distance;
int start = 0;
int end = 4999;

/**
 * @brief helper method to sort array in ascending order
 *
 * @param disc_req
 * @param SIZE
 * @return int*
 */
int *sortArray(int disc_req[], int SIZE)
{
    int temp = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
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

/**
 * @brief Tracks are serviced in the same order of the request array
 *
 * @param disc_req
 * @param head
 * @param SIZE
 */
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

/**
 * @brief Tracks closer to head are serviced first
 *
 * @param disc_req
 * @param head
 * @param length
 */
void SSTF(int disc_req[], int head, int length)
{
    int min;
    int pending = length;
    int i, totalHeadMoves = 0, index;
    int serviced[100];

    // keep track of requests serviced (1) or not serviced (0)
    for (i = 0; i < length; i++)
    {
        serviced[i] = 0;
    }
    printf("%s", "Seek Sequence is: \n");
    printf("%d ", head);

    while (pending > 0) // while there are still requests in queue
    {
        min = 4999; // biggest val possible

        for (i = 0; i < length; i++)
        {
            track = abs(head - disc_req[i]);     // current difference
            if (serviced[i] == 0 && track < min) // get smallest diff
            {
                min = track;
                index = i;
            }
        }

        pending--;           // one less request to service
        serviced[index] = 1; // mark current track as serviced
        totalHeadMoves += abs(head - disc_req[index]);
        head = disc_req[index]; // element at this index becomes the head, the last serviced track

        printf("%d ", head);
    }

    printf("\nTotal head movements = %d \n", totalHeadMoves);
}

/**
 * @brief Tracks are serviced all in one direction, then when head is met,
 * the direction changes and the rest of the tracks are serviced using that new direction away from the head
 *
 * @param disc_req
 * @param head
 * @param SIZE
 */
void clook(int disc_req[], int head, int SIZE)
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
    int *arr = sortArray(newArr, SIZE + 1);

    int index = -1;

    // find index of head
    for (int i = 0; i < SIZE + 1; i++)
    {
        if (arr[i] == head)
        {
            index = i;
            break;
        }
    }

    printf("%s", "Seek Sequence is: \n");
    for (int i = index; i < SIZE + 1; i++)
    {
        track = arr[i];
        // get distance
        distance = abs(track - head);

        // increase the total head moves count
        totalHeadMoves += distance;

        // the current track becomes the new head
        head = track;
        printf("%d ", arr[i]); // print all elements starting from head
    }

    // when end is reached
    for (int i = 0; i < index; i++)
    {
        track = arr[i];
        // get distance
        distance = abs(track - head);

        // increase the total head moves count
        totalHeadMoves += distance;

        // the current track becomes the new head
        head = track;
        printf("%d ", arr[i]); // print all elements starting from lowest value until head
    }

    printf("\nTotal head movements = %d \n", totalHeadMoves);
}

void look(int disc_req[], int head, int SIZE)
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
    int *arr = sortArray(newArr, SIZE + 1);
    int index = -1;

    // find index of head
    for (int i = 0; i < SIZE + 1; i++)
    {
        if (arr[i] == head)
        {
            index = i;
            break;
        }
    }

    printf("%s", "Seek Sequence is: \n");
    for (int i = index + 1; i < SIZE + 1; i++)
    {
        track = arr[i];
        // get distance
        distance = abs(track - head);

        // increase the total head moves count
        totalHeadMoves += distance;

        // the current track becomes the new head
        head = track;
        printf("%d ", arr[i]); // print all elements starting from head
    }

    // when end is reached, do opposite than c look, go from head index and decrement index until the first index is reached
    for (int i = index - 1; i >= 0; i--)
    {
        track = arr[i];
        // get distance
        distance = abs(track - head);

        // increase the total head moves count
        totalHeadMoves += distance;

        // the current track becomes the new head
        head = track;
        printf("%d ", arr[i]); // print all elements starting from lowest value until head
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
    int *arr = sortArray(newArr, newLength);
    int loop;

    int index = -1;

    // find index of head
    for (int i = 0; i < newLength + 1; i++)
    {
        if (arr[i] == head)
        {
            index = i;
            break;
        }
    }

    printf("%s", "Seek Sequence is: \n");
    for (int i = index + 1; i < newLength; i++)
    {
        track = arr[i];
        // get distance
        distance = abs(track - head);

        // increase the total head moves count
        totalHeadMoves += distance;

        // the current track becomes the new head
        head = track;
        printf("%d ", arr[i]); // print all elements starting from head
    }

    for (int i = 0; i < index; i++)
    {
        track = arr[i];
        // get distance
        distance = abs(track - head);

        // increase the total head moves count
        totalHeadMoves += distance;

        // the current track becomes the new head
        head = track;
        printf("%d ", arr[i]); // print all elements starting from lowest value until head
    }

    printf("\nTotal head movements = %d \n", totalHeadMoves);
}

void SCAN(int disc_req[], int head, int length)
{

    int totalHeadMoves = 0;

    // create new array with 3 more spaces for head, end of track and beginning (4999 and 0 respectively)
    int newArr[length + 2];

    for (int i = 0; i < length; i++)
    {
        newArr[i] = disc_req[i]; // populate array with elements of our old array
    }

    // add the head to this new array
    newArr[length] = head;
    newArr[length + 1] = start;
    int newLength = length + 2;

    // first sort array

    int *arr = sortArray(newArr, newLength);

    int index = -1;

    // find index of head
    for (int i = 0; i < newLength; i++)
    {
        if (arr[i] == head)
        {
            index = i;
            break;
        }
    }

    printf("%s", "Seek Sequence is: \n");
    for (int i = index - 1; i > 0; i--)
    {
        track = arr[i];
        // get distance
        distance = abs(track - head);

        // increase the total head moves count
        totalHeadMoves += distance;

        // the current track becomes the new head
        head = track;
        printf("%d ", arr[i]); // print all elements starting from head
    }

    arr[index] = 0; // replace head (where direction changes with value 0)

    for (int i = index; i < newLength; i++)
    {
        track = arr[i];
        // get distance
        distance = abs(track - head);

        // increase the total head moves count
        totalHeadMoves += distance;

        // the current track becomes the new head
        head = track;
        printf("%d ", arr[i]); // print all elements starting from lowest value until head
    }

    printf("\nTotal head movements = %d \n", totalHeadMoves);
}

int validateRequests(int arrForValidation[], int SIZE)
{
    // first sort array
    arrForValidation = sortArray(arrForValidation, SIZE);
    // check if element at first index is less than 0 or if last element is greater than 4999
    if (arrForValidation[0] < 0 || arrForValidation[SIZE - 1] > 4999)
    {
        return 0;
    }
    return 1;
}

int validateHead(int arrForValidation[], int SIZE, int head)
{
    // first sort array
    arrForValidation = sortArray(arrForValidation, SIZE);

    // check if element at first index is less than 0 or if last element is greater than 4999
    if (head < arrForValidation[0] || head > arrForValidation[SIZE - 1])
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

    int arrForValidation[length];
    for (int i = 0; i < length; i++)
    {
        arrForValidation[i] = disc_req[i]; // populate array with elements of original array
    }

    int isValid = validateRequests(arrForValidation, length);
    if (isValid == 0)
    {
        printf("Range of values: 0 to 4999. Entered values are not within range.");
        exit(0);
    }

    int head;
    printf("Enter an initial head value : ");
    scanf("%d", &head);

    int isHeadValid;
    isHeadValid = validateHead(arrForValidation, length, head);
    if (isHeadValid == 0)
    {
        printf("Head is outside range of request values");
        exit(0);
    }

    // fcfs(disc_req, head, length);
    // SSTF(disc_req, head, length);
    clook(disc_req, head, length);
    // CSCAN(disc_req, head, length);
    // SCAN(disc_req, head, length);
    // look(disc_req, head, length);
    return 0;
}