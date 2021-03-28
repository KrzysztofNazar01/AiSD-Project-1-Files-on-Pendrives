#include "Projekt1header.h"

int main(){
    
    while (scanf("%d %d", &input_files_count, &pendr_size) != EOF) {

        file_t* files = new file_t[input_files_count];
        pendrive_t* pend = new pendrive_t[PENDR_COUNT];

        for (int i = 0; i < PENDR_COUNT; i++) 
            pend[i].saved_files = new file_t[input_files_count];
        
        get_files_info(files);

        MergeSort(files, input_files_count, SIZE);

        save_files_on_pendr(pend, files);

        show_saving_results(pend);

        delete[] files;
        delete[] pend;
        
    }
    return 0;
}

void get_files_info(file_t* files){
    for (int i = 0; i < input_files_count; i++) {
        scanf_s("%10d", &files[i].id);
        scanf_s("%10d", &files[i].size);
    }
}

void show_saving_results(pendrive_t* pend){
    int saved_files_total = 0;
    for (int j = 0; j < PENDR_COUNT; j++)
        saved_files_total += pend[j].file_count;

    printf("%d \n", saved_files_total);

    for (int j = 0; j < PENDR_COUNT; j++) {

        printf("%d: ", j + 1);

        if (pend[j].file_count > 0) {
            MergeSort(pend[j].saved_files, pend[j].file_count, ID);
            for (int i = 0; i < pend[j].file_count; i++)
                printf("%d ", pend[j].saved_files[i].id);
        }
        printf("\n");
    }
}

void save_files_on_pendr(pendrive_t* pend, file_t* files){
    for (int i = 0; i < PENDR_COUNT; i++) {

        int saved_files_pendr = 0;
        bool full_pend = false;

        while (full_pend == false) {

            for (int j = 0; j < input_files_count; j++) {

                int avaliable_memmory = pendr_size - pend[i].used_memory;

                if (files[j].size <= avaliable_memmory && files[j].assigned == false) {
                    pend[i].saved_files[saved_files_pendr++] = files[j];
                    pend[i].used_memory += files[j].size;
                    files[j].assigned = true;
                }
                else
                    full_pend = true;
            }
        }
        pend[i].file_count = saved_files_pendr;
    }
}

void Merge(file_t* left, file_t* right, file_t* arr, int size, int sort_type) {

    int half_left = size / 2;
    int half_right = size - half_left;

    int i = 0, l = 0, r = 0;

    while (l < half_left && r < half_right) {
        if (sort_type == SIZE) {
            if (left[l].size < right[r].size) 
                arr[i++] = left[l++];
            else 
                arr[i++] = right[r++];
        }
        else if (sort_type == ID) {
            if (left[l].id > right[r].id) 
                arr[i++] = left[l++];
            else 
                arr[i++] = right[r++];
        }
    }

    while (r < half_right)
        arr[i++] = right[r++];

    while (l < half_left)
        arr[i++] = left[l++];
}

void MergeSort(file_t* arr, int size, int sort_type) {

    if (size < 2) return;

    int half_left = size / 2;
    int half_right = size - half_left;

    file_t* left = new file_t[half_left];
    file_t* right = new file_t[half_right];

    for (int i = 0; i < half_left; i++) 
        left[i] = arr[i];

    int further = 0;
    for (int i = half_left; i < size; i++) 
        right[further++] = arr[i];
    
    MergeSort(left, half_left, sort_type);
    MergeSort(right, half_right, sort_type);
    Merge(left, right, arr, size, sort_type);
 
    delete[] left;
    delete[] right;
}
