# Smart-Bus-Tracking-and-Route-Optimization-System
# Smart Bus Tracking System

**Using Dijkstra’s Algorithm, BFS, Greedy Technique, and Priority Queue (C Language)**

---

## Project Overview

The Smart Bus Tracking System is a modular, console-based application developed in C to simulate a university shuttle network. The system models campus locations as a weighted graph and provides optimized route planning and bus-related information to students.

It integrates multiple Data Structures and Algorithms (DSA) concepts such as Dijkstra’s Algorithm (optimized with a priority queue), Breadth-First Search (BFS), greedy techniques, and hash-based lookup to deliver efficient and scalable solutions.

---

## Objectives

* Design an algorithmic solution for campus transportation optimization
* Implement shortest path computation using Dijkstra’s Algorithm
* Provide minimum-stop routing using BFS
* Enable efficient bus lookup using hash map concepts
* Simulate real-world features like seat availability and route selection

---

## Features

* Display all bus stops in the system
* Show seat availability at each stop
* Perform bus lookup using hash map logic (bus ID to location and seats)
* Find the nearest bus stop using a greedy approach
* Compute shortest route based on distance using optimized Dijkstra’s Algorithm with a priority queue
* Compute route with minimum number of stops using BFS

---

## Algorithms and Data Structures Used

### Dijkstra’s Algorithm with Priority Queue

* Computes the shortest path between two nodes
* Optimized using a min-heap (priority queue)
* Time Complexity: O(E log V)

### Breadth-First Search (BFS)

* Finds the path with the minimum number of stops
* Suitable for unweighted or equal-weight scenarios
* Time Complexity: O(V + E)

### Greedy Technique

* Used to determine the nearest bus stop
* Selects the locally optimal solution at each step

### Hash Map (Array-based Implementation)

* Maps bus IDs to their current location and available seats
* Provides constant-time lookup

### Graph Representation

* Implemented using an adjacency matrix
* Nodes represent bus stops
* Edge weights represent distances

---

## System Architecture

The system follows a modular design with the following components:

* Graph Module: Stores nodes and adjacency matrix
* Processing Module: Implements algorithms (Dijkstra, BFS, Greedy, Priority Queue)
* Bus Module: Manages seat availability and bus lookup
* Main Module: Handles user interaction and program flow

---

## Project Structure

```
smart_bus_system/
│
├── main.c          # Entry point and menu-driven interface
├── graph.c         # Graph data (nodes and adjacency matrix)
├── graph.h
├── processing.c    # Dijkstra (with heap), BFS, greedy logic
├── processing.h
├── bus.c           # Seat availability and bus lookup (hash map)
├── bus.h
```

---

## How to Compile and Run

Use a C compiler such as GCC.

```
gcc main.c graph.c processing.c bus.c -o smartbus
./smartbus
```

---

## Input and Output

* Input: User selects operations and provides source/destination nodes
* Output:

  * List of stops
  * Seat availability
  * Bus lookup details
  * Nearest stop
  * Shortest path (distance-based)
  * Minimum stops path

---

## Time Complexity Summary

| Operation                      | Complexity |
| ------------------------------ | ---------- |
| Dijkstra (with priority queue) | O(E log V) |
| BFS                            | O(V + E)   |
| Greedy nearest node            | O(V)       |
| Hash map lookup                | O(1)       |

---

## Limitations

* Console-based interface (no graphical UI)
* Static data (no real-time GPS or live updates)
* Limited scalability due to adjacency matrix representation

---

## Future Enhancements

* Integration with real-time GPS tracking
* Mobile or web-based user interface
* Dynamic graph updates based on traffic conditions
* Database integration for live seat tracking
* Advanced route optimization using AI or machine learning

---

## Conclusion

This project demonstrates the practical application of multiple data structures and algorithms in solving a real-world transportation problem. By combining graph algorithms, greedy strategies, priority queues, BFS, and hash-based lookup, the system provides an efficient and scalable approach to smart campus mobility.
