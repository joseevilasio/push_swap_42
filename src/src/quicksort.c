/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:52:12 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/21 10:53:22 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high) {
    // Escolhe o último elemento como pivô
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        // Índice do pivô após a partição
        int pi = partition(array, low, high);

        // Ordenar recursivamente as partições
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Função para imprimir o array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int  main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted  Array\n");
    printArray(data, n);

    quickSort(data, 0, n - 1);

    printf("Sorted array in ascending order:\n");
    printArray(data,  
 n);
}