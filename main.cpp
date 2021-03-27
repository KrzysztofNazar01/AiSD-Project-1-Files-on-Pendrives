//official
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

#define PEND_COUNT 2

struct file_t {
    int id=0;
    int size=0;
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

void Merge(file_t* left, file_t* right, file_t* tab, int size, int sort_type);
void MergeSort(file_t* tab, int size, int sort_type);

int main(){

    int liczba_plikow, rozmiar_pendrajwow ;
   
    while (scanf("%d %d", &liczba_plikow, &rozmiar_pendrajwow) != EOF) {

        file_t* files = new file_t[liczba_plikow];
        pendrive_t* pend = new pendrive_t[PEND_COUNT];

        for (int i = 0; i < PEND_COUNT; i++) {
            pend[i].saved_files = new file_t[liczba_plikow];
        }

        for (int i = 0; i < liczba_plikow; i++) {
            scanf("%d", &files[i].id);
            scanf("%d", &files[i].size);
        }

        MergeSort(files, liczba_plikow, SIZE);

        int saved_files_count = 0;

        for (int i = 0; i < PEND_COUNT; i++) {
            int file_count = 0;
            bool full_pend = false;
            while (full_pend == false) {
                for (int j = 0; j < liczba_plikow; j++) {
                    if (files[j].size <= rozmiar_pendrajwow - pend[i].used_memory && files[j].assigned == false) {
                        pend[i].saved_files[file_count++] = files[j];
                        pend[i].used_memory += files[j].size;
                        files[j].assigned = true;
                    }
                    else {
                        full_pend = true;
                    }
                }
            }
            pend[i].file_count = file_count;
            saved_files_count += file_count;
        }

        printf("%d \n", saved_files_count);

        for (int j = 0; j < PEND_COUNT; j++) {

            printf("%d: ", j + 1);

            if (pend[j].file_count > 0) {
                MergeSort(pend[j].saved_files, pend[j].file_count, ID);
                for (int i = 0; i < pend[j].file_count; i++)
                    printf("%d ", pend[j].saved_files[i].id);
            }
            printf("\n");
        }

        delete[] files;
        delete[] pend;
        
    }
    return 0;
}


void Merge(file_t* left, file_t* right, file_t* tab, int size, int sort_type) {

    int half_left = size / 2;
    int half_right = size - half_left;

    int i = 0, l = 0, r = 0;

    while (l < half_left && r < half_right) {

        if (sort_type == SIZE) {
            if (left[l].size < right[r].size) {
                tab[i++] = left[l++];
            }
            else {
                tab[i++] = right[r++];
            }
        }

        if (sort_type == ID) {
            if (left[l].id > right[r].id) {
                tab[i++] = left[l++];
            }
            else {
                tab[i++] = right[r++];
            }
        }
    }

    while (r < half_right)
        tab[i++] = right[r++];

    while (l < half_left)
        tab[i++] = left[l++];

}

void MergeSort(file_t* tab, int size, int sort_type) {

    if (size < 2) return;

    int half_left = size / 2;
    int half_right = size - half_left;

    file_t* left = new file_t[half_left];
    file_t* right = new file_t[half_right];

    for (int i = 0; i < half_left; ++i) {
        left[i] = tab[i];
    }

    int further = 0;
    for (int i = half_left; i < size; ++i) {
        right[further] = tab[i];
        further++;
    }

    if (sort_type == SIZE) {
        MergeSort(left, half_left, SIZE);
        MergeSort(right, half_right, SIZE);
        Merge(left, right, tab, size, SIZE);
    }
    if (sort_type == ID) {
        MergeSort(left, half_left, ID);
        MergeSort(right, half_right, ID);
        Merge(left, right, tab, size, ID);
    }

    delete[] left;
    delete[] right;
}
