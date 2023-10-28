#include <iostream>


void merge_sort(int* arr, int* arr_copy, int size){// 3 //// 24 66 20 79
    int a = 0, b = size / 2;
    for(int i = 0; i < size; i++) {//5
        if(b == size){
            arr_copy[i] = arr[a];
            a++;
        }else if(a == size / 2){
            arr_copy[i] = arr[b];
            b++;
        }else if(arr[a] > arr[b]){
            arr_copy[i] = arr[b];
            b++;
        }else {
            arr_copy[i] = arr[a];
            a++;
        }


    }
}

void swapp(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

int arrange_second_part(int* arr, int size, int number) {// 3,1
    if (size == number + 1) return arr[number + 1];
    if (arr[size] < arr[size - 1]) {
        swapp(&arr[size], &arr[size - 1]);
    }
    return arrange_second_part(arr, size - 1, number);
}

int arrange_first_part(int* arr, int size, int number){
    if(size == 0) return arr[0];
    if(arr[size] < arr[size - 1]){
        swapp(&arr[size], &arr[size - 1]);
    }
    return arrange_first_part(arr, size - 1, number);

}

void arrange(int* arra, int* arr_copy,  int len){
    for(int i = 0; i < len / 2; i++) {
        arrange_first_part(arra, len / 2, 0);
    }
    for(int k = 0; k < len / 2; k++){
        arrange_second_part(arra, len, len / 2);
    }
    merge_sort(arra, arr_copy, len + 1);
}


int main() {
    int arra[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    //int arra[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    //int arra[] = {24, 66, 20, 79};

    int len = sizeof(arra) / sizeof(arra[0]);
    int arr_copy[len];
    std::cout << "Исходный массив: ";
    for(int i = 0; i < len; i++){
        std::cout << arra[i] << " ";
    }

    arrange(arra,arr_copy,len - 1);//9 ,5
   // for(int i = 0; i < (len / 2);i++) {
      // arrange_second_part(arra, len - 1, len / 2);//4, 2
       //arrange_first_part(arra, (len / 2) - 1, len / 2);
  // }
//
    //merge_sort(arra, arr_copy, len);


    std::cout << "\nОтсортированный массив: ";
    for(int i = 0; i < len; i++){
        std::cout << arr_copy[i] << " ";
    }

    return 0;
}
