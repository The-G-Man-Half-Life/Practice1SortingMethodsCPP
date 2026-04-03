# Practice1–SortingLargeDataset-CPP

> **Data Structures and Algorithms**  
> School of Applied Sciences and Engineering · EAFIT University  
> Lecturer: Alexander Narváez Berrío · April 2026
> Made by: Mateo Montoya Ospina

---

## Table of Contents

1. [Overview](#overview)
2. [Project Structure](#project-structure)
3. [Algorithms Implemented](#algorithms-implemented)
   - [QuickSort](#quicksort)
   - [HeapSort](#heapsort)
   - [AVL Tree](#avl-tree)
4. [Performance Analysis](#performance-analysis)
   - [Algorithmic Complexity (Big O)](#algorithmic-complexity-big-o)
   - [Memory Estimation](#memory-estimation)
5. [Prerequisites](#prerequisites)
6. [Build Instructions](#build-instructions)
7. [Usage](#usage)
8. [Dataset](#dataset)
9. [Design Decisions](#design-decisions)

---

## Overview

This program sorts a dataset of **100,000 words** using three independent algorithmic strategies built entirely from scratch in C++:

- **QuickSort** over a `std::vector<int>`
- **HeapSort** using a Binary Max-Heap
- **AVL Tree** via in-order traversal

For every strategy the program reports **execution time** (milliseconds) and an **estimated memory footprint** (KB), enabling a direct empirical comparison of the three approaches.

---

## Project Structure

```
Practice1SortingMethodsCPP/
│
├── build/                      # Compiled binary output. Appears once build.bat is executed
│   └── sortingMethods.exe
│
├── data/
│   └── Dataset.txt             # 100,000 words used as input
│
├── include/                    # Header files (.hpp), indicates structures and methods
│   ├── BalancedTree.hpp
│   ├── HeapSort.hpp
│   ├── Performance.hpp
│   ├── QuickSort.hpp
│   └── Utils.hpp
│
├── src/                        # Implementation files (.cpp), insert the logic behind the methods
│   ├── BalancedTree.cpp
│   ├── HeapSort.cpp
│   ├── main.cpp
│   ├── Performance.cpp
│   ├── QuickSort.cpp
│   └── Utils.cpp
│
├── .gitignore                  # Obviates the build folder once a commit is done for github
└── build.bat                   # Makes it easier the execution of the project.
```

---

## Algorithms Implemented

### Utils

**File:** `include/Utils.hpp` · `src/Utils.cpp`

File containing miscellaneous methods that will be implemented for different purposes along the project 

| Method | Responsibility |
|---|---|
| `readWordsFromFile(ubication)` | Takes care of reading the entirety of the words inside Dataset.txt |
| `convertWordsToInts(vectorSize)` | Takes care of creating a new int array based on the amount of elements where each element represents a word |
| `randomizeWordsOrd(vector, vector Size)` | Swaps elements going from the beggining to the end and using a random number to decide the number that will be that element switched with |
| `showMenu()` | Takes care of showing the menu so the user knows the avaiblable options and therefore chooses one of those option that will be stored, in case an incorrect input is inserted the menu will be shown again with a warning message |
| `pauseConsole()` | Takes care of stopping the showing of the menu for a better user experience allowing the user to decide when he wants to chooose another option from the menu |

> `include/Utils.hpp` indicates the methods that will be implemented.
> `src/Utils.cpp` Contains the logic behind the methods that `include/Utils.hpp` said.
---

### QuickSort

**File:** `include/QuickSort.hpp` · `src/QuickSort.cpp`

Implemented from scratch over a `std::vector<int>`. The pivot is always chosen as the **Last element** of each sub-array. The private interface is divided into two responsibilities:

| Method | Responsibility |
|---|---|
| `sortingQuick(vector)` | Public entry point; delegates to the recursive method SortingQuickLR |
| `sortingQuickLR(vec, start, end)` | Recursively sorts left and right sub-arrays, going always in that order |
| `partitionate(vec, start, end)` | Rearranges elements using the pivot as reference and returns the pivot's final index |

> `std::sort` and any other built-in sorting function are **not used** as requested in the file.
> `include/QuickSort.hpp` indicates the methods that will be implemented.
> `src/QuickSort.cpp` Contains the logic behind the methods that `include/QuickSort.hpp` said.
---

### HeapSort

**File:** `include/HeapSort.hpp` · `src/HeapSort.cpp`

Builds a **Max-Heap** in-place on the vector. The heap structure is represented implicitly using index arithmetic:

| Method | Responsibility |
|---|---|
| `heapingSort(vec)` | Public entry point |
| `heapify(vec, child, lastSorted)` | Moves the largest element to the top by comparing each trio (parent, left child, right child); terminates by swapping the biggest element to the parent position and a call to `maxHeapify` |
| `maxHeapify(vec, sortedLastPoint)` | Recursively reduces the unsorted region until the root element which means that the sorting is completed |
| `obtainLeftChildUbication` | Returns index of left child: `2 * father + 1` |
| `obtainRightChildUbication` | Returns index of right child: `2 * father + 2` |
| `obtainFatherUbication` | Returns index of parent: `(child - 1) / 2` |

> `include/HeapSort.hpp` indicates the methods that will be implemented.
> `src/HeapSort.cpp` Contains the logic behind the methods that `include/HeapSort.hpp` said.
---

### AVL Tree

**File:** `include/BalancedTree.hpp` · `src/BalancedTree.cpp`

A self-balancing **AVL Tree** where each node stores an `int` key. Sorting is achieved by inserting all elements into the binary tree and then performing an **in-order traversal**, which yields elements in ascending order.

**Node structure:**
```cpp
struct Node {
    int   content;   // stored value
    Node* left;      // left child pointer
    Node* right;     // right child pointer
    int   height;    // height for balance factor calculation
};
```

| Method | Responsibility |
|---|---|
| `insertNumber(int)` | Public insert; delegates to `insertHelper` |
| `insertHelper(node, value)` | Recursive BST insert + AVL rebalancing |
| `getBalanceFactor(node)` | `height(left) - height(right)` |
| `rotateRight(y)` | Right rotation to fix left-heavy imbalance |
| `rotateLeft(x)` | Left rotation to fix right-heavy imbalance |
| `getInorder()` | Returns sorted `std::vector<int>` via in-order DFS |
| `destroyTree(node)` | Post-order deletion to free heap memory (destructor) |

> `include/BalancedTree.hpp` indicates the methods that will be implemented.
> `src/BalancedTree.cpp` Contains the logic behind the methods that `include/BalancedTree.hpp` said.
---

### main

**File:** `src/main.cpp`

Center of execution where all the other files converge and the final user interact with

| Method | Responsibility |
|---|---|
| `executeQuickSort(unorganizedVector)` | This function takes care of calling the QuickSort method and its performance counter so it can print the information that can be obtained out of it |
| `executeHeapSort(unorganizedVector)` | This function takes care of calling the HeapSort method and its performance counter so it can print the information that can be obtained out of it |
| `executeBalancedTree(unorganizedVector)` | This function takes care of calling the BalancedTree method and its performance counter so it can print the information that can be obtained out of it  |
| `main` | This function takes care of obtaining all the words change them into numbers then rearrange them into an unorganizedVector, so later it can show the menu and allow for the execution of the previous sorting methods|

---

## Performance Analysis

### Algorithmic Complexity (Big O)

| Algorithm | Best Case | Average Case | Worst Case | Space |
|---|---|---|---|---|
| **QuickSort** | O(n log n) | O(n log n) | O(n²) | O(log n) |
| **HeapSort** | O(n log n) | O(n log n) | O(n log n) | O(log n) |
| **AVL Tree** | O(n log n) | O(n log n) | O(n log n) | O(n) |

**Key observations:**

- QuickSort achieves the best average-case performance in practice due to excellent cache locality, but degrades to O(n²) when the pivot selection is poor.
- HeapSort guarantees O(n log n) in all cases but has worse cache behaviour than QuickSort because heap accesses jump across memory.
- The AVL Tree always inserts in O(log n) and traversal is O(n), making the total O(n log n) guaranteed, but each node carries additional pointer and height overhead.

### Memory Estimation

Memory is computed at runtime by `MemoryEstimator` (`Performance.hpp`) using `sizeof` and the theoretical recursion depth:

| Algorithm | Data Structure | Additional Overhead |
|---|---|---|
| **QuickSort** | `sizeof(vector)` + `n × sizeof(int)` | ~32 bytes × log₂(n) recursive stack frames |
| **HeapSort** | `sizeof(vector)` + `n × sizeof(int)` | ~32 bytes × log₂(n) (heapify depth) |
| **AVL Tree** | `n × sizeof(Node)` + result vector | ~32 bytes × log₂(n) recursive stack frames |

For n = 100,000:

- QuickSort / HeapSort: ≈ **391 KB** (elements) + small stack
- AVL Tree: ≈ **2,343 KB** (nodes) + 391 KB (result vector) = ~**2,734 KB**

---

## Prerequisites

| Requirement | Version |
|---|---|
| C++ compiler (GCC/MinGW) | C++17 or later |
| Operating System | Windows (build.bat) |

---

## Build Instructions

### Windows (recommended)

Run the provided batch script from the project root:

```bat
./build.bat
```

The script will:
1. Create the `build/` directory if it does not exist.
2. Compile all `.cpp` files under `src/` with:
   - `-std=c++17` — C++17 standard
   - `-O3` — maximum compiler optimization
   - `-I include` — header search path
3. Output the binary at `build/sortingMethods.exe`.

### Manual compilation (cross-platform)

---

## Usage
Run in the power shell according to your operating system to execute the program 

```bash
# Windows
build\sortingMethods.exe

# Linux / macOS (manual build)
build/sortingMethods
```

An interactive menu will appear:

```
========================================
BIENVENIDO A LAS PRUEBAS DE ORDENAMIENTO
========================================
1. Quick Sort
2. Heap Sort
3. AVL Tree
4. Finalizar el programa
Ingrese la opcion que desee ejecutar:
```

Each option executes the selected algorithm and prints:

```
========================================
<Algorithm> Ejecutandose ...
Ordenamiento finalizado
Tiempo de ejecucion: X.XX Miliseconds
Uso de memoria estimado:
  Vector base: X bytes
  Elementos (100000 strings): X KB
  Stack recursivo: X bytes
  -> Total estimado: X KB
========================================
```

Press **Enter** after each result to return to the menu.

## Dataset

The input file `data/Dataset.txt` contains **100,000 words** derived from the `words_alpha.txt` English word list.

Since the original file is alphabetically ordered, the program automatically randomizes the word indices via `Utils::randomizeWordsOrd` (Fisher-Yates shuffle using `std::mt19937`) before any sorting algorithm is applied, ensuring a fair and reproducible benchmark.

```
words read  →  converted to integer indices  →  shuffled  →  sorted by each algorithm
```
