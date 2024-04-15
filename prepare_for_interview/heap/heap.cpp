#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

class MinHeap
{
public:
    vector<int> heap;
    int current_size;

    MinHeap() : heap({numeric_limits<int>::min()}), current_size(0){};

    int get_parent_index(int index)
    {
        return index / 2;
    }
    int get_left_child_index(int index)
    {
        return index * 2;
    }
    int get_right_child_index(int index)
    {
        return index * 2 + 1;
    }

    void swap_heap(int index1, int index2)
    {
        swap(heap[index1], heap[index2]);
    }

    void heapify_up(int index)
    {
        while (get_parent_index(index) > 0)
        {
            int parent_index = get_parent_index(index);
            if (heap[index] < heap[parent_index])
                swap_heap(index, parent_index);
            index = parent_index;
        }
    }
    void push(int value)
    {
        heap.push_back(value);
        current_size++;
        heapify_up(current_size);
    }

    int get_min_child_index(int index)
    {
        int left = get_left_child_index(index);
        int right = get_right_child_index(index);
        if (right > current_size || heap[left] < heap[right])
            return left;
        else if (heap[right] < heap[left])
            return right;
    }

    void heapify_down(int index)
    {

        while (get_left_child_index(index) <= current_size)
        {
            int min_child_index = get_min_child_index(index);
            if (heap[index] > heap[min_child_index])
                swap_heap(index, min_child_index);

            index = min_child_index;
        }
    }

    int pop()
    {

        if (current_size == 0)
            return -1;
        int root = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        current_size--;

        if (current_size > 1)
            heapify_down(1);

        return root;
    }
};

int main()
{

    MinHeap *heap = new MinHeap();

    heap->push(3);
    heap->push(2);
    heap->push(1);
    heap->push(16);
    heap->push(5);
    heap->push(8);
    heap->push(11);
    heap->push(29);

    while (heap->current_size)
    {
        cout << heap->pop() << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// class MinHeap
// {
// public:
//     vector<int> heap;
//     int current_size;

//     MinHeap() : heap({numeric_limits<int>::min()}), current_size(0){};

//     int get_parent_index(int index) { return index / 2; }
//     int get_left_child_index(int index) { return index * 2; }
//     int get_right_child_index(int index) { return index * 2 + 1; }

//     void swap_heap(int index1, int index2) { swap(heap[index1], heap[index2]); }

//     void heapify_up(int index)
//     {
//         while (get_parent_index(index) > 0)
//         {
//             int parent_index = get_parent_index(index);
//             if (heap[index] < heap[parent_index])
//             {
//                 swap_heap(index, parent_index);
//             }

//             index = parent_index;
//         }
//     }
//     void push(int value)
//     {
//         heap.push_back(value);
//         current_size++;
//         heapify_up(current_size);
//     }

//     int get_min_child_index(int index)
//     {
//         int left = get_left_child_index(index);
//         int right = get_right_child_index(index);

//         if (heap[left] < heap[right] || right > current_size)
//             return left;
//         else
//             return right;
//     }

//     void heapify_down(int index)
//     {
//         while (get_left_child_index(index) <= current_size)
//         {
//             int min_child_index = get_min_child_index(index);
//             if (heap[index] > heap[min_child_index])
//                 swap_heap(index, min_child_index);
//             index = min_child_index;
//         }
//     }

//     int pop()
//     {
//         if (current_size == 0)
//             return -1;

//         int root = heap[1];
//         heap[1] = heap.back();
//         heap.pop_back();
//         current_size--;

//         if (current_size != 0)
//             heapify_down(1);

//         return root;
//     }
// };

// int main()
// {
//     MinHeap *min_heap = new MinHeap();

//     min_heap->push(3);
//     min_heap->push(2);
//     min_heap->push(1);
//     min_heap->push(5);
//     min_heap->push(9);
//     min_heap->push(4);

//     cout << min_heap->pop() << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// class MinHeap
// {
// public:
//     vector<int> heap;
//     int current_size;

//     MinHeap() : heap({-1 * numeric_limits<int>::max()}), current_size(0){};

//     int get_parent_index(int index)
//     {
//         return index / 2;
//     }
//     int get_left_child_index(int index)
//     {
//         return index * 2;
//     }
//     int get_right_child_index(int index)
//     {
//         return index * 2 + 1;
//     }

//     void swap_heap(int index1, int index2)
//     {
//         swap(heap[index1], heap[index2]);
//     }

//     void heapify_up(int index)
//     {
//         while (get_parent_index(index) > 0)
//         {
//             if (heap[index] < heap[get_parent_index(index)])
//             {
//                 swap_heap(index, get_parent_index(index));
//             }
//             index = get_parent_index(index);
//         }
//     }

//     void push(int value)
//     {
//         heap.push_back(value);
//         current_size++;
//         heapify_up(current_size);
//     }

//     int min_child_index(int index)
//     {
//         if (get_right_child_index(index) > current_size)
//             return get_left_child_index(index);
//         else
//         {

//             if (get_left_child_index(index) < get_right_child_index(index))
//                 return get_left_child_index(index);
//             else
//                 return get_right_child_index(index);
//         }
//     }

//     void heapify_down(int index)
//     {

//         while (get_left_child_index(index) <= current_size)
//         {
//             if (heap[index] > heap[min_child_index(index)])
//             {
//                 swap_heap(index, min_child_index(index));
//             }
//             index = min_child_index(index);
//         }
//     }

//     int pop()
//     {

//         if (heap.size() == 1)
//             return -1;
//         int root = heap[1];

//         heap[1] = heap.back();
//         heap.pop_back();
//         current_size--;

//         if (heap.size() == 1)
//             return root;

//         heapify_down(1);

//         return root;
//     }
// };

// int main()
// {

//     MinHeap *heap = new MinHeap();

//     heap->push(3);
//     heap->push(5);
//     heap->push(7);
//     heap->push(2);
//     heap->push(1);
//     heap->push(8);
//     heap->push(11);

//     cout << heap->pop() << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// class MiniHeap
// {
// public:
//     vector<int> heap;
//     int current_size;

//     MiniHeap() : heap({-1 * numeric_limits<int>::max()}), current_size(0){};

//     int parent_index(int index)
//     {
//         return index / 2;
//     }
//     int left_child_index(int index)
//     {
//         return 2 * index;
//     }
//     int right_child_index(int index)
//     {
//         return 2 * index + 1;
//     }
//     void swap_heap(int index1, int index2)
//     {
//         swap(heap[index1], heap[index2]);
//     }

//     void heapify_up(int index)
//     {
//         while (parent_index(index) > 0)
//         {
//             if (heap[index] < heap[parent_index(index)])
//                 swap_heap(index, parent_index(index));
//             index = parent_index(index);
//         }
//     }

//     void push(int value)
//     {
//         heap.push_back(value);
//         current_size++;

//         heapify_up(current_size);
//     }

//     int min_child_index(int index)
//     {
//         if (right_child_index(index) > current_size)
//             return left_child_index(index);
//         else
//         {

//             if (heap[left_child_index(index)] < heap[right_child_index(index)])
//                 return left_child_index(index);
//             else
//                 return right_child_index(index);
//         }
//     }

//     void heapify_down(int index)
//     {
//         while (left_child_index(index) <= heap.size())
//         {
//             int min_index = min_child_index(index);
//             if (heap[index] > heap[min_index])
//             {
//                 swap_heap(index, min_index);
//             }
//         }
//     }

//     int pop()
//     {
//         if (heap.size() == 1)
//             return 0;

//         int root = heap[1];
//         int data = heap.back();
//         heap.pop_back();

//         if (heap.size() == 1)
//             return root;

//         heap[1] = data;
//         current_size--;
//         heapify_down(heap[1]);
//         return root;
//     }
// };

// int main()
// {
//     MiniHeap *min_heap = new MiniHeap();
//     min_heap->push(5);
//     min_heap->push(6);
//     min_heap->push(2);
//     min_heap->push(9);
//     min_heap->push(13);
//     min_heap->push(11);
//     min_heap->push(5);

//     cout << min_heap->pop() << endl;
// }