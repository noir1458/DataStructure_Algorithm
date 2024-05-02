#include <stdio.h>
#include <stdlib.h>

// dynamic arrays struct
typedef struct DynamicArray {
    int* d_array;
    int capacity; // 초기 용량
    int size;     // 저장된 원소 수
}DynamicArray;

// dyanamic_array initialization with a specific size
struct DynamicArray* dynamic_array_init(int input_size, int input_capacity) {
    DynamicArray* D_array = (struct DynamicArray*)malloc(sizeof(struct DynamicArray));
    if (D_array == NULL) {
        return NULL;
    }

    D_array->d_array = (int*)malloc(input_capacity * sizeof(int));
    if (D_array->d_array == NULL) {
        free(D_array);
        return NULL;
    }

    D_array->capacity = input_capacity;
    D_array->size = input_size;
    return D_array;
}

// 삽입 중 배열 복사를 위한 함수
void copy_array(int* arr1, int* arr2, int size) {
    // arr1에서 arr2로 복사한다. size는 arr1의 크기
    for (int i = 0; i < size; i++)
        *(arr2 + i) = *(arr1 + i);
}

/*
// inserting an element(front)
struct DynamicArray* dynamic_array_specific_insert(DynamicArray* D_array, int insert_element, int insert_index) {
    // 만약 새로 저장시 capacity를 넘어갈경우, 다시 할당해줘야 한다
    if (D_array->size + 1 > D_array->capacity) {
        DynamicArray* New_d_array = dynamic_array_init(D_array->capacity + 1, D_array->capacity * 2);
        if (New_d_array == NULL)
            return NULL;
        copy_array(D_array->d_array, New_d_array->d_array, (D_array->size) * sizeof(int));
        free(D_array->d_array);
        D_array->d_array = New_d_array->d_array;
        D_array->size = New_d_array->size;
        free(New_d_array);
    }

    // insert_element를 insert_index 자리에 넣고 나머지를 뒤로 + 1(sizeof(int))
    // 만약 맨 마지막것 + 시 capacity넘어갈경우 다시 할당
    for (int i = insert_element; i < D_array.size; i++)
    {
      
    }


    return d_array;
}*/

// inserting an element(back)
struct DynamicArray* dynamic_array_back_insert(DynamicArray* D_array, int insert_element) {
    // 만약 새로 저장시 capacity를 넘어갈경우, 다시 할당해줘야 한다
    if (D_array->size + 1 > D_array->capacity) {
        DynamicArray* New_d_array = dynamic_array_init(D_array->capacity + 1, D_array->capacity * 2);
        if (New_d_array == NULL)
            return NULL;
        copy_array(D_array->d_array, New_d_array->d_array, (D_array->size) * sizeof(int));
        free(D_array->d_array);
        D_array->d_array = New_d_array->d_array;
        D_array->size = New_d_array->size;
        free(New_d_array);
    }

    // insert_element를 insert_index 자리에 넣고 나머지를 뒤로 + 1(sizeof(int))
    // 만약 맨 마지막것 + 시 capacity넘어갈경우 다시 할당
    D_array->d_array[D_array->size] = insert_element;
    return D_array;
}
/*
// inserting an element(front)
struct DynamicArray* dynamic_array_front_insert(DynamicArray* D_array, int insert_element, int insert_index) {
    // 만약 새로 저장시 capacity를 넘어갈경우, 다시 할당해줘야 한다
    if (D_array->size + 1 > D_array->capacity) {
        DynamicArray* New_d_array = dynamic_array_init(D_array->size + 1, D_array->capacity * 2);
        copy_array(D_array->d_array, New_d_array, sizeof(D_array));
        D_array = New_d_array;
    }

    // 맨 앞에 삽입한다. 전체를 한칸씩 뒤로 밀고 맨 앞자리에 삽입
    for (int i = 0; i < D_array.size; i++)
    {
        
    }


    return D_array;
}

// deleting an element
struct DynamicArray* dynamic_array_delete(int* d_array, int delete_index) {
    return d_array;
}

// access an element at a specific index
struct DynamicArray* dynamic_array_access(int* d_array, int access_index) {
    int return_element = d_array + d.array.capacity * (access_index);
    return return_element;
}

// singly linked list struct
struct singly_linked_lists
{
    struct singly_linked_lists* next;
    int data;
};

// linked_list initialization with a specific size
int* linked_list_init(int size) {
    struct singly_linked_lists linked_list;
    linked_list.data = 0;
    for (int i = 0; i < size; i++) {

    }

    return &linked_list;
}

// inserting an element
int* linked_list_inserting(int* linked_list, int insert_element, int insert_index) {

}

// deleting an element
int* linked_lists_deleting(int* linked_list, int delete_index) {

}

// accessing the element at the head
int linked_lists_access(int* linked_list, int access_index) {
    int return_element = 0;
    return return_element;
}*/

int main() {

    DynamicArray* DynamicArray1 = dynamic_array_init(2, 3);
    printf("Capacity: %d\n", DynamicArray1->capacity);
    printf("Size: %d\n", DynamicArray1->size);



}