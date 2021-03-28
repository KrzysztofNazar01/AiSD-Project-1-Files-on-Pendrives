#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

#define PENDR_COUNT 2
int input_files_count, pendr_size;

struct file_t {
    int id = 0;
    int size = 0;
    bool assigned = false;
};

struct pendrive_t {
    int file_count = 0;
    int used_memory = 0;
    file_t* saved_files;
};

enum Sort_types {
    SIZE = 1,
    ID = 2,
};

void Merge(file_t* left, file_t* right, file_t* arr, int size, int sort_type);
void MergeSort(file_t* arr, int size, int sort_type);

void get_files_info(file_t* files);
void save_files_on_pendr(pendrive_t* pend, file_t* files);
void show_saving_results(pendrive_t* pend);