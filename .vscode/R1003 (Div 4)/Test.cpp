#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <iomanip>

// Sorting algorithm implementations
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(std::vector<int>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::vector<int> L(n1), R(n2);
    
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
        
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(std::vector<int>& arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}

// Benchmark function
double benchmark(void (*sortFunc)(std::vector<int>&), std::vector<int>& arr) {
    std::vector<int> temp = arr;  // Create a copy to sort
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(temp);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::ofstream outFile("sorting_results.csv");
    
    // Header for CSV
    outFile << "Size,Algorithm,Time(ms)\n";
    
    // Array sizes to test
    std::vector<int> sizes = {2000, 4000, 6000, 8000, 10000};
    
    // Number of trials for each test
    const int trials = 25;
    
    for (int size : sizes) {
        std::cout << "Testing size " << size << "...\n";
        std::uniform_int_distribution<> dis(1, 1000000);
        
        // Generate random array
        std::vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = dis(gen);
        }
        
        // Test each sorting algorithm
        std::vector<std::pair<std::string, void (*)(std::vector<int>&)>> algorithms = {
            {"Bubble Sort", bubbleSort},
            {"Insertion Sort", insertionSort},
            {"Quick Sort", quickSort},
            {"Heap Sort", heapSort},
            {"Merge Sort", mergeSort}
        };
        
        for (const auto& [name, func] : algorithms) {
            double totalTime = 0;
            for (int t = 0; t < trials; t++) {
                totalTime += benchmark(func, arr);
            }
            double avgTime = totalTime / trials;
            outFile << size << "," << name << "," << std::fixed << std::setprecision(3) << avgTime << "\n";
            std::cout << name << " completed for size " << size << "\n";
        }
    }
    
    outFile.close();
    std::cout << "Results have been written to sorting_results.csv\n";
    return 0;
}