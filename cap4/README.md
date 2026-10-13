# Student Room Allocation System using Backtracking in C++

## 📌 Project Overview

The **Student Room Allocation System** is a console-based application developed using C++. It allocates students to rooms according to the available capacity of each room.

The project uses the **Backtracking Algorithm** to find a valid room allocation. If the current rooms cannot accommodate all students, the program asks whether another room is available. If the user agrees, the capacity of the new room is entered and the allocation process continues.

This project demonstrates the practical application of recursion and backtracking for solving resource allocation problems.

## 🎯 Objectives

- To allocate students to rooms based on room capacity.
- To implement the Backtracking Algorithm using recursion.
- To ensure that room capacities are not exceeded.
- To handle situations where the available rooms are insufficient.
- To allow users to add another room when allocation is not possible.
- To understand how backtracking solves constraint-based problems.

## ✨ Features

1. **Dynamic Input:** Accept the number of students and rooms from the user.
2. **Room Capacity Management:** Enter the capacity of each room.
3. **Automatic Allocation:** Assign students to rooms according to available capacity.
4. **Backtracking:** Undo an allocation when it prevents the remaining students from being allocated.
5. **Additional Room Support:** Ask the user whether another room is available when allocation fails.
6. **Input Validation:** Check the limits for the number of students, rooms, and room capacities.
7. **Final Allocation Display:** Display the room assigned to each student.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Algorithm:** Backtracking
- **Concepts:** Recursion, arrays, conditional statements, and loops
- **Input/Output:** `iostream`

## 🧠 Algorithm Used: Backtracking

Backtracking is an algorithmic technique that builds a solution step by step. If a choice does not lead to a valid solution, the algorithm undoes that choice and tries another option.

### Working of the Algorithm

1. Start with the first student.
2. Check each room to find one with available capacity.
3. Assign the student to the selected room.
4. Decrease the room's remaining capacity by one.
5. Recursively allocate the next student.
6. If allocation of the remaining students fails, restore the room's capacity and try another room.
7. If all students are allocated successfully, return the final allocation.
8. If no valid allocation exists, ask the user whether another room is available.
9. If another room is added, repeat the allocation process.
10. Display the final allocation when a valid solution is found.

### Pseudocode

```text
ALLOCATE_ROOM(student)

    If student == total students
        Return TRUE

    For each room
        If room has available capacity
            Assign student to room
            Decrease room capacity

            If ALLOCATE_ROOM(student + 1) is TRUE
                Return TRUE

            Restore room capacity

    Return FALSE
```

## 📂 Project Structure

```text
Student-Room-Allocation/
│
├── room_allocation.cpp
└── README.md
```

- `room_allocation.cpp` — Contains the complete C++ source code.
- `README.md` — Contains the project documentation.

## ⚙️ Requirements

- A C++ compiler such as GCC or MinGW.
- Visual Studio Code, Code::Blocks, Dev-C++, or another C++ IDE.
- Basic knowledge of C++ programming.

## 🚀 How to Run the Project

### Step 1: Clone the Repository

```bash
git clone <your-repository-url>
```

### Step 2: Open the Project Folder

```bash
cd Student-Room-Allocation
```

### Step 3: Compile the Program

```bash
g++ room_allocation.cpp -o room_allocation
```

### Step 4: Run the Program

**Windows:**

```bash
room_allocation.exe
```

**Linux/macOS:**

```bash
./room_allocation
```

## 💻 Sample Output

### Example 1: Successful Allocation

```text
Enter number of students: 5
Enter number of rooms: 2
Enter capacity of Room 1: 3
Enter capacity of Room 2: 2

Final Room Allocation:
Student 1 -> Room 1
Student 2 -> Room 1
Student 3 -> Room 1
Student 4 -> Room 2
Student 5 -> Room 2
```

### Example 2: Adding Another Room

```text
Enter number of students: 5
Enter number of rooms: 2
Enter capacity of Room 1: 2
Enter capacity of Room 2: 1

Allocation not possible with current rooms.
Is another room available? (y/n): y
Enter capacity of Room 3: 2

Final Room Allocation:
Student 1 -> Room 1
Student 2 -> Room 1
Student 3 -> Room 2
Student 4 -> Room 3
Student 5 -> Room 3
```

### Example 3: Allocation Not Possible

```text
Enter number of students: 4
Enter number of rooms: 1
Enter capacity of Room 1: 2

Allocation not possible with current rooms.
Is another room available? (y/n): n
Room allocation not possible.
```

## 📊 Complexity Analysis

Let `S` represent the number of students and `R` represent the number of rooms.

| Operation | Complexity |
|---|---|
| Try allocating students | O(R^S) worst case |
| Store student allocations | O(S) |
| Store room capacities | O(R) |
| Recursive call stack | O(S) |

**Note:** The worst-case time complexity is exponential because the algorithm may explore multiple room assignments using backtracking. The actual running time depends on the capacities and the choices explored.

## 🔍 Applications

- Student hostel room allocation.
- Hotel room assignment.
- Classroom allocation.
- Resource allocation problems.
- Capacity-constrained assignment systems.
- Scheduling and constraint satisfaction problems.

## 🔮 Future Enhancements

- Allow students to specify room preferences.
- Support different room types and capacities.
- Prevent allocation of certain students to the same room.
- Display the number of students assigned to each room.
- Minimize unused room capacity.
- Add a graphical user interface.
- Save allocation results to a file.

## 🎓 Learning Outcomes

Through this project, we learn how to:

- Implement recursion in C++.
- Apply the Backtracking Algorithm to a real-world problem.
- Use arrays to store room capacities and student allocations.
- Restore previous states when a decision fails.
- Handle invalid input and unsuccessful allocation attempts.
- Analyze the time and space complexity of an algorithm.

## 📝 Conclusion

The Student Room Allocation System demonstrates how the Backtracking Algorithm can solve a resource allocation problem. It assigns students to rooms while respecting room capacities. When an allocation fails, the algorithm reverses previous assignments and explores alternative choices. The option to add another room makes the program more flexible when the existing capacity is insufficient.

This project provides practical experience with recursion, backtracking, arrays, and constraint-based problem-solving in C++.

## 👩‍💻 Author

**Sakshi Vaidya**

B.Tech Computer Engineering

Sanjivani College of Engineering, Kopargaon
