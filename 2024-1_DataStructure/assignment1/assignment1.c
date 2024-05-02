#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// dynamic arrays struct
typedef struct DynamicArray {
    int* d_array;
    int capacity; // 크기
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

    //0으로 내용물 초기화
    D_array->capacity = input_capacity;
    D_array->size = input_size;
    memset(D_array->d_array,0,sizeof(int)*(D_array->capacity));

    return D_array;
}

// 삽입 중 배열 복사를 위한 함수
void copy_array(int* arr1, int* arr2, int size) {
    // arr1에서 arr2로 복사한다. size는 arr1의 크기
    for (int i = 0; i < size; i++)
        *(arr2 + i) = *(arr1 + i);
}

// 요소 삽입중 크기조절을 위한 함수
void dynamic_array_resize(DynamicArray *D_array, int new_capacity){
    int *new_array = (int*)malloc(sizeof(int) * new_capacity);
    if (new_array == NULL){
        return;
    }
    for (int i=0 ; i < D_array->size ; i++){
        new_array[i] = D_array -> d_array[i];
    }
    free(D_array -> d_array);
    D_array->d_array = new_array;
    D_array->capacity = new_capacity;
}

// inserting an element(back)
struct DynamicArray* dynamic_array_insert_back(DynamicArray* D_array, int insert_element) {
    // 만약 새로 저장시 capacity를 넘어갈경우, 다시 할당해줘야 한다
    if (D_array->size == D_array->capacity) {
        dynamic_array_resize(D_array,D_array->capacity * 2);
    }

    // insert_element를 insert_index 자리에 넣고 나머지를 뒤로 + 1(sizeof(int))
    // 만약 맨 마지막것 + 시 capacity넘어갈경우 다시 할당
    D_array->d_array[D_array->size] = insert_element;
    D_array->size++;
    return D_array;
}

// inserting an element(front)
struct DynamicArray* dynamic_array_insert_front(DynamicArray* D_array, int insert_element) {
    // 만약 새로 저장시 capacity를 넘어갈경우, 다시 할당해줘야 한다
    if (D_array->size == D_array->capacity) {
        dynamic_array_resize(D_array,D_array->capacity * 2);
    }

    // 맨 앞에 삽입한다. 전체를 한칸씩 뒤로 밀고 맨 앞자리에 삽입
    for (int i = D_array->size ; i > 0; i--) {
        D_array->d_array[i] = D_array ->d_array[i-1];
    }
    D_array->d_array[0] = insert_element;
    D_array->size++;

    return D_array;
}

// inserting an element(specific)
struct DynamicArray* dynamic_array_insert_specific(DynamicArray* D_array, int insert_element, int insert_index) {
    // 만약 새로 저장시 capacity를 넘어갈경우, 다시 할당해줘야 한다
    if (insert_index > D_array->size){
        printf("index out!!\n");
        return D_array;
    }
    if (insert_index == 0){
        D_array = dynamic_array_insert_front(D_array,insert_element);
        //printf("ffff\n"); 0번 인덱스에 insert
        return D_array;
    }
    if (insert_index == D_array->size){
        D_array = dynamic_array_insert_back(D_array,insert_element);
        //printf("bbbb\n"); 마지막 인덱스에 insert
        return D_array;
    }
    
    if (D_array->size == D_array->capacity) {
        dynamic_array_resize(D_array,D_array->capacity * 2);
    }

    // insert_element를 insert_index 자리에 넣고 나머지를 뒤로 + 1(sizeof(int))
    // 만약 맨 마지막것 + 시 capacity넘어갈경우 다시 할당
    for (int i = D_array->size; i > insert_index; i--){
        D_array->d_array[i] = D_array->d_array[i-1];
    }
    D_array->d_array[insert_index] = insert_element;
    D_array->size++;
    return D_array;
}

// deleting an element(front)
struct DynamicArray* dynamic_array_delete_front(DynamicArray* D_array) {
    if (D_array->size == 0) {
        return D_array; // 삭제할 요소가 없는 경우 그대로 반환
    }

    for (int i = 0; i < D_array->size ; i++){
        D_array->d_array[i] = D_array->d_array[i+1];
    }
    free(&D_array->d_array[D_array->size-1]); // 삭제한부분 메모리 할당한것 해제
    D_array->size--;
    return D_array;
}

// deleting an element(back)
struct DynamicArray* dynamic_array_delete_back(DynamicArray* D_array) {
    if (D_array->size == 0) {
        return D_array; // 삭제할 요소가 없는 경우 그대로 반환
    }

    free(&D_array->d_array[D_array->size-1]); // 삭제한부분 메모리 할당한것 해제
    D_array->size--;
    return D_array;
}

// deleting an element(specific)
struct DynamicArray* dynamic_array_delete_specific(DynamicArray* D_array, int delete_index) {
    if (D_array->size == 0) {
        return D_array; // 삭제할 요소가 없는 경우 그대로 반환
    }

    if (delete_index < 0 || delete_index >= D_array->size){
        printf("index out!!\n");
        return D_array;
    }
    
    for (int i = delete_index; i < D_array->size ; i++){
        D_array->d_array[i] = D_array->d_array[i+1];
    }
    free(&D_array->d_array[D_array->size-1]); // 삭제한부분 메모리 할당한것 해제
    D_array->size--;
    return D_array;
}

// access an element at a specific index
int dynamic_array_access(DynamicArray* D_array, int access_index) {
    if (access_index < 0 || access_index >= D_array->size){
        printf("index out!!\n");
        return 0;
    }
    int* return_element = D_array->d_array + (access_index);
    return* return_element;
}

// dynamic array 출력 함수
void dynamic_array_print(DynamicArray* D_array){
    for (int i = 0; i < D_array->size; i++)
    {
        printf("%d ",D_array->d_array[i]);
    }
    printf("\nSize : %d, Capacity: %d\n\n", D_array->size, D_array->capacity);
}


typedef struct Singly_linked_lists {
    struct Singly_linked_lists* next; // 다음 노드를 가리키는 포인터
    int data;                         // 노드의 데이터
} Singly_linked_lists;

// linked_list initialization (empty list)
struct Singly_linked_lists* linked_list_init() {
    // 링크드리스트는 개수를 정하는게 아니라 노드 하나를 생성하고 반환하기
    Singly_linked_lists* linked_list = (struct Singly_linked_lists*)malloc(sizeof(struct Singly_linked_lists));
    linked_list->next = NULL;
    linked_list->data = 0;
    return linked_list;
}

// inserting an element(front)
struct Singly_linked_lists* linked_list_insert_front(Singly_linked_lists* linked_list, int insert_element) {
    Singly_linked_lists* linked_list_front = linked_list_init();
    linked_list_front->data = insert_element;
    //앞에 연결
    linked_list_front->next = linked_list->next;
    return linked_list_front;
}

// inserting an element(back)
struct Singly_linked_lists* linked_list_insert_back(Singly_linked_lists* linked_list, int insert_element) {
    Singly_linked_lists* linked_list_back = linked_list_init();
    linked_list_back->data = insert_element;
    //뒤에 연결
    Singly_linked_lists* start = linked_list; // 처음 노드를 저장하고 반환
    while (linked_list->next != NULL){
        linked_list = linked_list->next;
    }
    linked_list->next = linked_list_back;
    return start;
}

// inserting an element(specific)
struct Singly_linked_lists* linked_list_insert_specific(Singly_linked_lists* linked_list, int insert_element, int insert_index) {
    if (insert_index == 0){
        linked_list = linked_list_insert_front(linked_list,insert_element);
        return linked_list;
    }

    Singly_linked_lists* linked_list_new = linked_list_init();
    linked_list_new->data = insert_element;

    Singly_linked_lists* start = linked_list; // 처음 노드를 저장하고 반환
    // insert index - 1 까지 접근
    int count = 0;
    while (count != insert_index - 1){
        count ++;
        linked_list = linked_list->next;
    }
    linked_list_new->next = linked_list->next;
    linked_list->next = linked_list_new;
    return start;
}

// deleting an element(front)
struct Singly_linked_lists* linked_lists_delete_front(Singly_linked_lists* linked_list) {
    if (linked_list->next == NULL || linked_list == NULL){
        return NULL;
    }
    Singly_linked_lists* del_node = linked_list;
    linked_list = linked_list->next;
    free(del_node);
    return linked_list;
}

// deleting an element(back)
struct Singly_linked_lists* linked_lists_delete_back(Singly_linked_lists* linked_list) {
    if (linked_list->next == NULL || linked_list == NULL){
        return NULL;
    }
    Singly_linked_lists* start = linked_list;
    while (linked_list->next->next != NULL){
        linked_list = linked_list -> next;
    }
    Singly_linked_lists* del_node = linked_list->next;
    linked_list->next = NULL;
    free(del_node);
    return start;
}

// deleting an element(specific)
struct Singly_linked_lists* linked_lists_delete_specific(Singly_linked_lists* linked_list, int delete_index) {
    if (linked_list->next == NULL || linked_list == NULL){
        return NULL;
    }
    Singly_linked_lists* start = linked_list;
    int count = 0;
    while (count + 1 != delete_index){
        linked_list = linked_list -> next;
        count++;
    }
    Singly_linked_lists* del_node = linked_list->next;
    linked_list->next = linked_list->next->next;
    free(del_node);
    return start;
}

// accessing the element at the head
int linked_lists_access(Singly_linked_lists* linked_list, int access_index) {
    int count = 0;
    while (count < access_index){
        count ++;
        if (linked_list->next == NULL){
            break;
        }
        linked_list = linked_list-> next;
    }

    if (linked_list == NULL){ // Null경우 0 반환하기
        printf("error");
        return 0;
    }
    else{
        return linked_list->data;
    }
}

// linked list 출력함수
void linked_lists_print(Singly_linked_lists* linked_list){
    int count = 0;
    while (linked_list != NULL){
        printf("%d ",linked_list->data);
        count ++;
        linked_list = linked_list -> next;
    }
    printf("\nsize : %d\n\n",count);
}

//DynamicArray insert test 함수
void test_insert_DynamicArray(int num){
    DynamicArray* D1 = dynamic_array_init(0, 1);
    for (int i = 0; i < num; i++){
        dynamic_array_insert_front(D1,1);
    }
    dynamic_array_print(D1);

    free(D1->d_array);
    free(D1);
}

//DynamicArray delete test 함수
void test_delete_DynamicArray(int num){
    DynamicArray* D1 = dynamic_array_init(num, num);
    for (int i = 0; i < num; i++){
        dynamic_array_delete_front(D1);
    }
    dynamic_array_print(D1);

    free(D1->d_array);
    free(D1);
}

//DynamicArray access test 함수
void test_access_DynamicArray(int num){
    DynamicArray* D1 = dynamic_array_init(0, 1);
    
    
    free(D1->d_array);
    free(D1);
}

// LinkedList test함수
void test_LinkedList(){
    Singly_linked_lists* L1 = linked_list_init();
    linked_lists_print(L1);
    free(L1);
}


int main() {
    int select_input = 0;
    int size = 0;
    printf("1.DyanmicArray\n");
    printf("2.LinkedList\n");
    printf("test select : ");
    scanf("%d",&select_input); // 테스트할것 선택
    printf("size : ");
    scanf("%d",&size); // vary the number of elements in the data structure
    printf("\n\n");

    clock_t start = clock(); // record the execution time
    if (select_input==1){
        test_insert_DynamicArray(size);
    }
    else{
        test_LinkedList();
    }
    clock_t end = clock();
    printf("execute time : %d\n",(double)(end-start) / CLOCKS_PER_SEC);
    printf("----");
    return 0;
}