//author: Ashutosh Sharma

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the range for the x and y coordinates
#define RANGE_X 20   
#define RANGE_Y 20   

// Define the structure for a point
typedef struct Point {
    int x, y;
    struct Point* next;
} Point;

// Function to create a new point
Point* create_point(int x, int y) {
    Point* new_point = (Point*)malloc(sizeof(Point));
    new_point->x = x;
    new_point->y = y;
    new_point->next = NULL;
    return new_point;
}

// Function to generate points and insert them at the end of the list
Point* generate_points_end(int m) {
    Point* head = NULL;
    Point* temp = NULL;

    for (int i = 0; i < m; i++) {
        int x = rand() % RANGE_X;
        int y = rand() % RANGE_Y;
        Point* new_point = create_point(x, y);

        if (!head) {
            head = new_point;
        } else {
            temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new_point;
        }
    }
    return head;
}

// Function to generate points and insert them at the front of the list
Point* generate_points_front(int m) {
    Point* head = NULL;

    for (int i = 0; i < m; i++) {
        int x = rand() % RANGE_X;
        int y = rand() % RANGE_Y;
        Point* new_point = create_point(x, y);
        
        new_point->next = head;
        head = new_point;
    }
    return head;
}

// Function to print the points in the list
void print_points(Point* head) {
    Point* temp = head;
    while (temp) {
        printf("(%d, %d) -> ", temp->x, temp->y);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to merge two lists of points
Point* merge_lists(Point* l1, Point* l2) {
    Point* merged = NULL;
    Point* temp1 = l1;
    Point* temp2 = l2;

    while (temp1) {
        Point* new_point = create_point(temp1->x, temp1->y);
        new_point->next = merged;
        merged = new_point;
        temp1 = temp1->next;
    }

    while (temp2) {
        int found = 0;
        Point* check = merged;
        while (check) {
            if (check->x == temp2->x && check->y == temp2->y) {
                found = 1;
                break;
            }
            check = check->next;
        }

        if (!found) {
            Point* new_point = create_point(temp2->x, temp2->y);
            new_point->next = merged;
            merged = new_point;
        }
        temp2 = temp2->next;
    }

    return merged;
}

// Function to find the intersection of two lists of points
Point* intersection(Point* l1, Point* l2) {
    Point* intersected = NULL;
    Point* temp1 = l1;

    while (temp1) {
        Point* temp2 = l2;
        while (temp2) {
            if (temp1->x == temp2->x && temp1->y == temp2->y) {
                Point* new_point = create_point(temp1->x, temp1->y);
                new_point->next = intersected;
                intersected = new_point;
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return intersected;
}

// Main function to test the point generation, merging, and intersection functions
int main() {
    srand(time(NULL));
    int m = 10;

    Point* LI = generate_points_end(m);
    Point* L2 = generate_points_front(m);

    printf("List LI (inserted at the end):\n");
    print_points(LI);
    
    printf("\nList L2 (inserted at the front):\n");
    print_points(L2);

    Point* L = merge_lists(LI, L2);
    printf("\nMerged List (LI U L2):\n");
    print_points(L);

    Point* intersection_list = intersection(LI, L2);
    printf("\nIntersection of LI and L2:\n");
    print_points(intersection_list);

    return 0;
}
