#include <iostream>
using namespace std;

int allocation[50];
int capacity[50];
int students, rooms;

bool allocateRoom(int student)
{
    // All students have been allocated
    if (student == students)
        return true;

    // Try each available room
    for (int room = 0; room < rooms; room++)
    {
        if (capacity[room] > 0)
        {
            // Assign student to this room
            allocation[student] = room;
            capacity[room]--;

            // Allocate the next student
            if (allocateRoom(student + 1))
                return true;

            // Backtracking: undo the allocation
            capacity[room]++;
        }
    }

    return false;
}

int main()
{
    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of rooms: ";
    cin >> rooms;

    if (students < 1 || students > 50 ||
        rooms < 1 || rooms > 50)
    {
        cout << "Invalid input";
        return 0;
    }

    // Input capacity of each room
    for (int i = 0; i < rooms; i++)
    {
        cout << "Enter capacity of Room " << i + 1 << ": ";
        cin >> capacity[i];

        if (capacity[i] < 0)
        {
            cout << "Invalid capacity";
            return 0;
        }
    }

    // Try allocation; ask for another room if needed
    while (!allocateRoom(0))
    {
        char choice;

        cout << "\nAllocation not possible with current rooms.";
        cout << "\nIs another room available? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            if (rooms == 50)
            {
                cout << "Maximum room limit reached.";
                return 0;
            }

            cout << "Enter capacity of Room " << rooms + 1 << ": ";
            cin >> capacity[rooms];

            if (capacity[rooms] < 0)
            {
                cout << "Invalid capacity";
                return 0;
            }

            rooms++;
        }
        else
        {
            cout << "Room allocation not possible.";
            return 0;
        }
    }

    // Display final allocation
    cout << "\nFinal Room Allocation:\n";

    for (int i = 0; i < students; i++)
    {
        cout << "Student " << i + 1
             << " -> Room " << allocation[i] + 1 << endl;
    }

    return 0;
}
 