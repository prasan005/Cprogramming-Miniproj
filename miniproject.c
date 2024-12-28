#include <stdio.h>
#include <string.h>

// Structure to represent a bus
struct Bus {
    int busNumber;
    char source[50];
    char destination[50];
    int availableSeats;
    int totalSeats;
};

// Function to add a bus
void addBus(struct Bus *buses, int *count) {
    printf("Enter bus number: ");
    scanf("%d", &buses[*count].busNumber);
    getchar(); // Consume the newline character left by scanf

    printf("Enter source: ");
    fgets(buses[*count].source, 50, stdin);
    buses[*count].source[strcspn(buses[*count].source, "\n")] = '\0'; // Remove newline

    printf("Enter destination: ");
    fgets(buses[*count].destination, 50, stdin);
    buses[*count].destination[strcspn(buses[*count].destination, "\n")] = '\0'; // Remove newline

    printf("Enter total seats: ");
    scanf("%d", &buses[*count].totalSeats);

    buses[*count].availableSeats = buses[*count].totalSeats; // Initially all seats are available
    (*count)++;
    printf("Bus added successfully!\n");
}

// Function to display all buses
void displayBuses(struct Bus *buses, int count) {
    if (count == 0) {
        printf("No buses available.\n");
    } else {
        printf("\nList of Buses:\n");
        printf("Number\tSource\t\tDestination\t\tAvailable Seats\tTotal Seats\n");
        printf("-------------------------------------------------------------------------\n");
        for (int i = 0; i < count; i++) {
            printf("%d\t%s\t\t%s\t\t%d\t\t%d\n", buses[i].busNumber, buses[i].source, 
                   buses[i].destination, buses[i].availableSeats, buses[i].totalSeats);
        }
    }
}

// Function to book a seat on a bus
void bookSeat(struct Bus *buses, int count) {
    int number;
    printf("Enter bus number to book: ");
    scanf("%d", &number);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (buses[i].busNumber == number) {
            if (buses[i].availableSeats > 0) {
                buses[i].availableSeats--; // Decrease available seats
                printf("Successfully booked a seat on bus from %s to %s.\n", buses[i].source, buses[i].destination);
            } else {
                printf("Sorry, no seats available for booking.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Bus not found.\n");
    }
}

// Function to cancel a booked seat on a bus
void cancelSeat(struct Bus *buses, int count) {
    int number;
    printf("Enter bus number to cancel booking: ");
    scanf("%d", &number);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (buses[i].busNumber == number) {
            if (buses[i].availableSeats < buses[i].totalSeats) {
                buses[i].availableSeats++; // Increase available seats
                printf("Successfully canceled a seat booking on bus from %s to %s.\n", buses[i].source, buses[i].destination);
            } else {
                printf("No seats have been booked on this bus.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Bus not found.\n");
    }
}

int main() {
    struct Bus buses[100]; // Array to store buses
    int count = 0;             // Number of buses in the system
    int choice;

    while (1) {
        printf("\nBus Ticket Booking System\n");
        printf("1. Add Bus\n");
        printf("2. Display All Buses\n");
        printf("3. Book Seat\n");
        printf("4. Cancel Seat\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBus(buses, &count);
                break;
            case 2:
                displayBuses(buses, count);
                break;
            case 3:
                bookSeat(buses, count);
                break;
            case 4:
                cancelSeat(buses, count);
                break;
            case 5:
                printf("Exiting system...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}