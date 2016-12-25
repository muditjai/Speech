/*****
 MSMPI implementation of sorting.
 Distribute an unsorted array from a master to multiple workers which sort their part and return. 
 The master then merges to create a sorted array.
 *****/
// Comment from a branch
// Comment merge from branch 2, 3 and master

#include "stdafx.h"
#include "mpi.h"
#include "stdio.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
void populateVector(int size, vector<int>* inputArr)
{
	for (int i = 0; i < size; i++)
	{
		(*inputArr).push_back(rand() % size);
	}
}

void printVector(vector<int> inputArr)
{
	for (int i = 0; i < (int)inputArr.size(); i++)
	{
		cout << inputArr[i] << " ";
	}

	cout << endl;
}

void populateArray(const int arraySize, int inputArr[])
{
	for (int i = 0; i < arraySize; i++)
	{
		inputArr[i] = rand() % arraySize;
	}
}

void printArray(const int arraySize, const int inputArr[])
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << inputArr[i] << " ";
	}

	cout << endl;
}

vector<int> sortPartlySortedArray(const int inputArr[], const int size, const int interval)
{
	list<int> curStartIndices;
	for (int i = 0; i < size; i += interval)
	{
		curStartIndices.push_back(i);
	}

	vector<int> sortedArray;
	for (int i = 0; i < size; i++)
	{
		int min = INT_MAX;
		list<int>::iterator minIdxIter;
		for (list<int>::iterator it = curStartIndices.begin(); it != curStartIndices.end(); it++)
		{
			if (min > inputArr[*it])
			{
				min = inputArr[*it];				
				minIdxIter = it;
			}
		}

		sortedArray.push_back(min);
		(*minIdxIter)++;
		if (*minIdxIter % interval == 0)
		{
			curStartIndices.erase(minIdxIter);
		}
	}

	return sortedArray;
}

int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);
	
	/*
	vector<int> unsortedVector;
	populateVector(arraySize, &unsortedVector);
	printVector(unsortedVector);
	*/

	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int workers = size - 1;
	int arraySize = workers * 10;

	if (rank == 0)
	{
		int* unsortedArray = new int[arraySize];
		populateArray(arraySize, unsortedArray);
		printArray(arraySize, unsortedArray);

		int curArrayIdx = 0;
		// Distribute to workers
		for (int i = 1; i < size; i++)
		{
			int curArraySize = int(arraySize / workers);
			MPI_Send(unsortedArray + curArrayIdx, curArraySize, MPI_INT, i, 0, MPI_COMM_WORLD);
			
			cout << "Rank 0 Sent array to rank " << i << " - ";
			printArray(curArraySize, unsortedArray + curArrayIdx);

			curArrayIdx += curArraySize;
		}

		curArrayIdx = 0;
		// Collect from workers
		for (int i = 1; i < size; i++)
		{
			int curArraySize = int(arraySize / workers);
			MPI_Status status;
			MPI_Recv(unsortedArray + curArrayIdx, curArraySize, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
			
			cout << "Rank 0 received array from rank " << status.MPI_SOURCE << " - ";
			printArray(curArraySize, unsortedArray + curArrayIdx);

			curArrayIdx += curArraySize;
		}

		// Merge final result
		vector<int> sortedVector = sortPartlySortedArray(unsortedArray, arraySize, int(arraySize / workers));
		cout << "Final sorted array with Rank 0 - ";
		printVector(sortedVector);

		delete[] unsortedArray;
	}
	else
	{
		const int taskArraySize = int(arraySize / workers);
		int* taskArray = new int[taskArraySize];
		
		// Receive the task
		MPI_Status status;
		MPI_Recv(taskArray, taskArraySize, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		
		cout << "Rank " << rank << " received array from rank 0 - ";
		printArray(taskArraySize, taskArray);
		
		// Do the sorting
		std::sort(taskArray, taskArray + taskArraySize);

		cout << "Sorted the received array. Sending it back from rank " << rank << " - ";
		printArray(taskArraySize, taskArray);

		// Send the sorted array
		MPI_Send(taskArray, taskArraySize, MPI_INT, 0, 0, MPI_COMM_WORLD);		
		delete[] taskArray;
	}

	MPI_Finalize();
    return 0;
}

