#include <iostream>
#include <queue>
using namespace std;

// Heap: Priority Queue로 구현 가능.

// int main() {
//     cin.tie(NULL);
//     cout.tie(NULL);
//     ios_base::sync_with_stdio(false);

//     int n;
//     cin >> n;
//     priority_queue<int, vector<int>, greater<int>> pq;
//     for (int i = 0; i < n; i++){
//         int x;
//         cin >> x;

//         if (x == 0){
//             if (pq.empty()){
//                 cout << "0\n";
//             }
//             else {
//                 cout << pq.top() << "\n";
//                 pq.pop();
//             }
//         }

//         else{
//             pq.push(x);
//         }
//     }

//     return 0;
// }

// Min Heap 직접 구현

int heap[100001];
int hsize = 0;

void heap_insert(int x){
    int num = x;
    hsize++;
    heap[hsize] = num;
    int idx = hsize;
    while (num < heap[idx / 2] && idx > 1){
        heap[idx] = heap[idx / 2];
        idx /= 2;
    }
    heap[idx] = num;
}

void heap_delete(){
    int num = heap[hsize];
    heap[1] = num;
    hsize--;
    int idx = 1;
    int child = idx * 2;
    if (child + 1 <= hsize){
        if (heap[child + 1] < heap[child]){
            child++;
        }
    }

    while (child <= hsize && heap[child] < num){
        heap[idx] = heap[child];
        idx = child;
        child = idx * 2;
        if (child + 1 <= hsize){
            if (heap[child + 1] < heap[child]){
                child++;
            }
        }
    }
    heap[idx] = num;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;

        if (x == 0){
            if (hsize == 0){
                cout << "0\n";
            }
            else {
                cout << heap[1] << "\n";
                heap_delete();
            }
        }

        else{
            heap_insert(x);
        }
    }

    return 0;
}