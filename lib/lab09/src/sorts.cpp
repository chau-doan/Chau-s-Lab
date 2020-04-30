#include "doubly_linked_list.h"

namespace lab6 {
    // Auxiliary Functions
    unsigned partition(int* to_sort, int low, int high);

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort);
    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right);

    void quicksort(int* to_sort, int low, int high){
        if(low < high){
            int pi = partition(to_sort, low, high);
            quicksort(to_sort, low, pi - 1);
            quicksort(to_sort, pi + 1, high);
        }
    }

    void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    unsigned partition(int* to_sort, int low, int high){
        int pivot = to_sort[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++){
            if (to_sort[j] <= pivot){
                i++;
                swap(&to_sort[i], &to_sort[j]);
            }
        }
        swap(&to_sort[i+1], &to_sort[high]);
        return (i+1);
    }

    void mergesort(doubly_linked_list& to_sort){
        recursive_merge_sort(to_sort);
    }

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort){
        if (to_sort.size() >= 2){
            doubly_linked_list left = to_sort;
            doubly_linked_list right;
            if (to_sort.size() % 2 !=0)
                right = left.split(left.size() / 2 +1);
            else
                right = left.split(left.size());
            recursive_merge_sort(left);
            recursive_merge_sort(right);
            to_sort = merge(left, right);
            return to_sort;
        }

    }

    //Used for the merging the two lists
    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right){
        if(left.size() == 0)
            return right;
        if(right.size() == 0)
            return left;
        doubly_linked_list to_return;
        bool run = true;
        while (run){
            if (left.is_empty() && right.is_empty())
                run = false;
            else{
                if(left.get_data(0) <= right.get_data(0) || right.is_empty()){
                    to_return.append(left.get_data(0));
                    left.remove(0);
                }
                else{
                    to_return.append(right.get_data(0));
                    right.remove(0);
                }
            }
        }
        return to_return;
    }
}