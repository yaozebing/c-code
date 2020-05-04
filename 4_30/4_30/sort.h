#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int* num1, int* num2);

void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n);

void ShiftDown(int* a, int n, int root);
void HeapSort(int* a, int n);

void BubbleSort(int* a, int n);

int PartSort1(int* a, int left, int right);
int PartSort2(int* a, int left, int right);
int PartSort3(int* a, int left, int right);

void QuickSort(int* a, int left, int right);