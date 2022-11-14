#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>

void heapAdjust(int *array, int len)
{
    int last = len / 2 - 1;

    while (last >= 0)

    {
        int temp = array[last];

        for (size_t j = 2 * last + 1; j < len; j = 2 * j + 1)
        {
            /* code */
            if (j + 1 < len && array[j] < array[j + 1])
            {
                /* code */
                j++;
            }
            if (array[last] < array[j])
            {
                /* code */
                array[last] = array[j];
                last = j;
                array[last] = temp;
                temp = array[last];
            }
            else
            {
                break;
            }
        }

        last--;
    }
}
void heapSort(int *array, int len)
{

    for (size_t i = 0; i < len; i++)
    {
        /* code */
        heapAdjust(array, len - i);

        int temp = array[0];
        array[0] = array[len - 1 - i];
        array[len - 1 - i] = temp;
    }
}
int main()
{
    int arr[] = {15, 22, 7, 88, 15, 0, 16, 12, 16, 77, 1, 67};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << len << "\n";
    heapSort(arr, len);
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        /* code */
        cout << arr[i] << "\t";
    }
    cout << "\n";
}