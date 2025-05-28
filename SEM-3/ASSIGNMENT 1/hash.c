
// // ### 1. **Direct Addressing**

// // Direct addressing assumes keys are distinct and uses a direct-address table.
// #include <stdio.h>
// #define SIZE 100

// int table[SIZE] = {0};  // Initialize   all elements to 0

// // Insert key at table index
// void direct_address_insert(int key) {
//     table[key] = 1;
// }

// // Search key in table
// int direct_address_search(int key) {
//     return table[key];
// }

// // Delete key from table
// void direct_address_delete(int key) {
//     table[key] = 0;
// }

// int main() {
//     direct_address_insert(42);
//     printf("Search 42: %d\n", direct_address_search(42));
//     direct_address_delete(42);
//     return 0;
// }

// // ### 2. **Hash Tables**

// // When keys are smaller than the universe, hash tables can reduce storage needs.


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define TABLE_SIZE 10

// typedef struct Node {
//     int key;
//     int value;
//     struct Node *next;
// } Node;

// Node *table[TABLE_SIZE];

// // Hash function
// int hash(int key) {
//     return key % TABLE_SIZE;
// }

// // Insert in hash table
// void insert(int key, int value) {
//     int index = hash(key);
//     Node *new_node = (Node *)malloc(sizeof(Node));
//     new_node->key = key;
//     new_node->value = value;
//     new_node->next = table[index];
//     table[index] = new_node;
// }

// // Search in hash table
// Node *search(int key) {
//     int index = hash(key);
//     Node *current = table[index];
//     while (current) {
//         if (current->key == key) return current;
//         current = current->next;
//     }
//     return NULL;
// }

// // Delete from hash table
// void delete(int key) {
//     int index = hash(key);
//     Node *current = table[index];
//     Node *prev = NULL;

//     while (current) {
//         if (current->key == key) {
//             if (prev == NULL) {
//                 // Node to delete is the first node
//                 table[index] = current->next;
//             } else {
//                 // Node to delete is not the first node
//                 prev->next = current->next;
//             }
//             free(current);  // Free memory
//             printf("Key %d deleted.\n", key);
//             return;
//         }
//         prev = current;
//         current = current->next;
//     }
//     printf("Key %d not found.\n", key);
// }

// // Display hash table
// void display() {
//     for (int i = 0; i < TABLE_SIZE; i++) {
//         Node *current = table[i];
//         printf("table[%d]: ", i);
//         while (current) {
//             printf("(%d, %d) -> ", current->key, current->value);
//             current = current->next;
//         }
//         printf("NULL\n");
//     }
// }

// // Main function for testing
// int main() {
//     insert(12, 20);
//     insert(22, 30);
//     insert(42, 40);
//     insert(32, 50);

//     display();

//     printf("\nSearching for key 22:\n");
//     Node *node = search(22);
//     if (node) {
//         printf("Found key 22 with value %d\n", node->value);
//     } else {
//         printf("Key 22 not found\n");
//     }

//     printf("\nDeleting key 22:\n");
//     delete(22);
//     display();

//     printf("\nTrying to delete key 22 again:\n");
//     delete(22);

//     return 0;
// }


// // ### 3. **Handling Collisions**

// // #### **Chaining**


// // Insert, search, and delete are implemented in the hash table code above.


// // #### **Linear Probing**


// #define TABLE_SIZE 10
// int hash_table[TABLE_SIZE] = {0};

// int linear_probing_hash(int key) {
//     return key % TABLE_SIZE;
// }

// void insert(int key) {
//     int index = linear_probing_hash(key);
//     while (hash_table[index] != 0) {
//         index = (index + 1) % TABLE_SIZE;  // Linear probing
//     }
//     hash_table[index] = key;
// }

// //#### **Quadratic Probing**


// void quadratic_insert(int key) {
//     int index = hash(key);
//     int i = 0;
//     while (hash_table[(index + i * i) % TABLE_SIZE] != 0) {
//         i++;
//     }
//     hash_table[(index + i * i) % TABLE_SIZE] = key;
// }


// //#### **Double Hashing**

// int hash2(int key) {
//     return 7 - (key % 7);  // Second hash function
// }

// void double_hash_insert(int key) {
//     int index = hash(key);
//     int step = hash2(key);

//     while (hash_table[index] != 0) {
//         index = (index + step) % TABLE_SIZE;  // Double hashing
//     }
//     hash_table[index] = key;
// }

// // ### 4. **Hash Functions**

// // #### **Division Method**

// `
// int division_hash(int key) {
//     return key % TABLE_SIZE;
// }


// // #### **Multiplication Method**

// int multiplication_hash(int key) {
//     float A = 0.618033;  // Constant
//     return (int)(TABLE_SIZE * (key * A - (int)(key * A)));
// }


// ### 5. **Universal Hashing**
#include<stdio.h>
#include <stdlib.h>
#define PRIME 17
#define TABLE_SIZE 100
int universal_hash(int key, int a, int b) {
    return ((a * key + b) % PRIME) % TABLE_SIZE;
}

int main() {
    int a = rand() % PRIME + 1;
    int b = rand() % PRIME;
    int key = 10;
    printf("Hash value: %d\n", universal_hash(key, a, b));
    return 0;
}
