// Sorting of all types;
#include<iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    void swap(T *a,T *b)
    {
        T temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    void show(T *arr, int size)
    {
        for(int x = 0; x < size; x++)
        {
            cout << *(arr + x) << "  ";
        } 
        cout << endl;
    }
    
public:

    // Bubble sort - Simple enough you just keep bubbling for the length of the array
    // Complexity - n^2, n (general, best)
    void bubble_sort(T *array, int size)
    {
        for(int x = 0; x < size; x++)
        {
            for(int y = 0; y < size - 1; y++)
            {
                T temp;
                if(*(array + y) > *(array + y + 1))
                {
                    swap((array + y), (array + y + 1));
                }
            }
        }
        
        show(array, size);
    }

    // Insetion sort - You go form the starting to every data in the array and 
    // then bubble that data back to where it's suppose to go.
    // Complexity - n^2, n (general, best)
    void insertion_sort(T *array, int size)
    {
        T low;
        for(int x = 1; x < size; x++)
        {
            low = *(array + x);
            int y = x - 1;
            while(*(array + y) > low && y >= 0)
            {
                swap((array + y), (array + y + 1));
                y--;
            }
        }

        show(array, size);
    }

    // Selection sort - Start from the beginning and replace the current data point with the smallest one after it.
    // Complexity - n^2, n^2 (general, best)
    void selection_sort(T *array, int size)
    {
        int low_point;
        for(int x = 0; x < size; x++)
        {
            low_point = x;
            for(int y = x; y < size; y++)
            {
                if(*(array + y) < *(array + x))
                    low_point = y;
                swap((array + x), (array + low_point));
            }
        }
        show(array, size);
    }
};

int main()
{
    Sorting <int> int_sort;
    int *arr_1;
    int array_1[] = {4,3,2,1}; 

    arr_1 = array_1;
    int_sort.insertion_sort(arr_1, 4);
    
    Sorting <float> float_sort;
    float *arr_2;
    float array_2[] = {3.22, 4.11, 7.22, 1.33, 2.1};

    arr_2 = array_2;
    float_sort.bubble_sort(arr_2, 5);
    return 0;
}
