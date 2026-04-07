# Smart-Bus-Tracking-and-Route-Optimization-System

## **Project Overview**

The **Smart Bus Tracking System** is a console-based application developed in C that simulates a university shuttle system. It helps students efficiently navigate between campus locations by:

* Finding the **shortest route**
* Identifying the **nearest bus stop**
* Displaying **available seats**
* Estimating **waiting time**

The system models the campus as a **weighted graph**, where each location is a node and distances represent edge weights.

---

## **Objectives**

* Design an optimized algorithm for real-world campus transport problems
* Implement **Dijkstra’s Algorithm** for shortest path
* Apply **Greedy technique** for nearest node selection
* Improve student convenience and reduce waiting time

---

## **Algorithms Used**

### 🔹 Dijkstra’s Algorithm

* Used to find the **shortest path** between two locations
* Ensures optimal routing in weighted graphs

### 🔹 Greedy Technique

* Used in:

  * Selecting the **nearest bus stop**
  * Choosing the **minimum distance node** in Dijkstra

---

## **Bus Stops (Nodes)**

* Main Gate
* Anna Auditorium
* MGR Block
* SMV
* TT
* PRP
* SJT
* MGB
* Library

---

## ⚙️ **Features**

### 1. View Bus Stops

Displays all available shuttle stops with indices.

### 2. Seat Availability

Shows number of empty seats at each stop (simulated data).

### 3. Nearest Bus Stop

Finds the closest stop from the user's location using a **greedy approach**.

### 4. Best Route Finder

Uses **Dijkstra’s Algorithm** to:

* Compute shortest path
* Display route
* Show total distance

### 5. Estimated Waiting Time

* Based on seat availability
* Fewer seats → more crowd → higher waiting time

---

## **Project Structure**

```bash
smart_bus_system/
│
├── main.c          # Entry point (menu-driven system)
├── graph.c         # Graph and node definitions
├── graph.h
├── dijkstra.c      # Shortest path + greedy logic
├── dijkstra.h
├── bus.c           # Seat & waiting time logic
├── bus.h
```

---

## **Workflow**

1. User selects feature from menu
2. Inputs source/destination (if required)
3. System processes data using algorithms
4. Output is displayed in console

---

## **Technologies Used**

* Programming Language: **C**
* Compiler: GCC / CodeBlocks / VS Code
* Data Structures:

  * Graph (Adjacency Matrix)
  * Arrays

---

## **How to Compile & Run**

```bash
gcc main.c graph.c dijkstra.c bus.c -o smartbus
./smartbus
```

---

## **Time Complexity**

| Operation             | Complexity |
| --------------------- | ---------- |
| Dijkstra Algorithm    | O(V²)      |
| Nearest Node (Greedy) | O(V)       |

---

## **Limitations**

* No graphical user interface (CLI-based)
* Uses simulated data (no real-time GPS)
* Static seat availability

---

## **Future Enhancements**

* Real-time GPS integration
* Mobile app (Android/iOS)
* Live bus tracking using IoT
* AI-based prediction of bus arrival
* Cloud database for real-time updates

---

## **Conclusion**

This project demonstrates how **algorithmic techniques like Dijkstra and Greedy** can be applied to solve real-world transportation problems efficiently. It provides a scalable foundation for building smart campus mobility solutions.

---

## **References**

* Introduction to Algorithms – Thomas H. Cormen
* Data Structures using C – Reema Thareja
* GeeksforGeeks – Dijkstra Algorithm
