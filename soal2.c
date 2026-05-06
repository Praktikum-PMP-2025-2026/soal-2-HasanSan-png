//** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
//* Modul : 04 - DYNAMIC STRUCTURES
//* Hari dan Tanggal : Selasa, 21 April 2026
//* Nama (NIM) : Hasan Al Mutawakkil (13224080)
//* Nama File : TP_1_PMP_4.c
//* Deskripsi : Merubah order


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* root) {
    if (root == NULL) return 0;
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return (leftheight > rightheight ? leftheight : rightheight) + 1;
}

void printGivenLevel(Node* root, int level) {
    if (root == NULL) return;
    if (level == 1) printf("%d ", root->data);
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void levelOrderTraversal(Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printf("LEVEL %d: ", i - 1);
        printGivenLevel(root, i);
        printf("\n");
    }

}

Node* input(int arr[], int i, int n) {
    Node* root = NULL;
    if (i < n) {
        root = createNode(arr[i]);
        root->left = input(arr, 2 * i + 1, n);
        root->right = input(arr, 2 * i + 2, n);
    }

    return root;
}

int main() {
    int n; 
    scanf("%d", &n);
    
    int Temp [99];

    for (int i = 0; i < n; i++) {
        scanf("%d", &Temp[i]);
    }

 Node* root = input(Temp, 0, n);
    
levelOrderTraversal(root);
    
    
}

