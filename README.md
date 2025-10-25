# OOP-Assignment-24I-5669
 Question 1: 

This question contains two parts based on recursion in C++.

a) ChangeLocation (Recursive Array Manipulation)

Problem:
Write a recursive function to change (swap) the characters of a given array between two boundary indices.
void ChangeLocation(char *Array, int b1, int b2);
Example: Char array [8] == {’C’, ’O’, ’M’, ’P’, ’U’, ’T’, ’E’, ’R’}
The bounds are 3 and 7 then after the function execution the value should be like the
following: Char array [8] == {’C’, ’O’, ’E’, ’P’, ’U’, ’T’, ’M’, ’R’}
b) Write a recursive function to print the following pattern.
void PrintPattern(int &n);
Example: Enter any number = 4
4
2 2
1 3
1 1 2
1 1 1 1
 Question 2: Singly Linked List 
 Problem Description
NASA’s Earth Observation team wants to manage geospatial features (like Land, Water, or Atmospheric features) captured by satellites.  
The data is stored in a Singly Linked List, where each node represents one feature.

Each node contains:
- `FeatureID` → a unique ID number  
- `Feature*` → pointer to a feature object (can be LandFeature, WaterFeature, etc.)  
- `next` → pointer to the next node in the list

This design uses Object-Oriented Programming (OOP) principles like inheritance and polymorphism, so new feature types can be added later without modifying the linked list code.

---
Question 3: Doubly Linked List 
Problem Description
This program implements a Doubly Linked LisT to represent a simple Library Book Tracking System.

Each node in the list represents a Book and contains the following information:
- `int BookID` → Unique identifier for each book  
- `string Title` → Title of the book  
- `string Author` → Author of the book  

The system allows adding, deleting, and displaying books both forward and backward through the list.

---
Question 4: Queue — Ticket Booking System
 Problem Description
This program simulates a Ticket Booking System for a movie theater using a Queue data structure.

Each person in the queue is represented by:
- `int CustomerID` — Unique ID for each customer  
- `string Name` — Customer’s name  
- `int Tickets` — Number of tickets requested  

The system should follow FIFO (First-In-First-Out)order, meaning the first customer to enter the queue is the first to be served.

---

 Required Functionalities

| Function | Description |
|-----------|--------------|
| `enqueue(int id, string name, int tickets)` | Adds a new customer to the end of the queue |
| `dequeue()` | Removes the first customer from the queue once their tickets are issued |
| `display()` | Displays all customers currently waiting in the queue |
| Bonus:| Implement a priority queue so customers requesting more tickets get served first |

---
 Question 5: Stack & Algorithm Analysis

 Problem Description
In this task, you are required to:

1. Implement two stack data structures:
   - A linked list-based stack (using singly linked list)
   - An array-based stack (using dynamic arrays)

2. Use both stacks to implement *iterative (non-recursive)* versions of Question 1 (Recursion) — both parts:
   - Part (a): `ChangeLocation` function
   - Part (b): `PrintPattern` function

3. Perform runtime analysis comparing the time complexity and performance differences between both stack implementations.

---
