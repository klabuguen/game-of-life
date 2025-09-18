#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printGrid(int ***grid, int rowSize, int colSize){
    for(int x = 1; x < rowSize+1; x++){
        printf("|");
        for(int y = 1; y < colSize+1; y++){
           printf(" %d |", (*grid)[x][y]); 
        }
        printf("\n");
    } 
}

void initializeGrid(int ***grid, int rowSize, int colSize){
    *grid = (int**)calloc(rowSize+2, sizeof(int*));
    for(int i = 0; i < rowSize+2; i++){
        (*grid)[i] = (int*)calloc(colSize+2, sizeof(int));
    }
}

void freeGrid(int ***grid, int rowSize){
    for(int i = 0; i < rowSize+2; i++){
        free((*grid)[i]);
    }
    free(*grid);
    (*grid) = NULL;
}

void insertLiveCell(int ***grid, int row, int col){
    (*grid)[row+1][col+1] = 1;
}

void runEvolutionSim(int ***grid, int cycles, int rowSize, int colSize){
    printf("Running Simulation!\n");
    
    for(int i = 0; i < cycles; i++){
        // Create a copy of the grid
        int **tmpGrid;
        initializeGrid(&tmpGrid, rowSize, colSize);
        for(int idx = 1; idx < rowSize+1; idx++){
            memcpy(tmpGrid[idx], (*grid)[idx], (colSize) * sizeof(int));
        }
        for(int j = 1; j < rowSize+1; j++){
            for(int k = 1; k < colSize+1; k++){
                // Check all 8 neighbors
                int neighbors = 0;
                if(tmpGrid[j-1][k-1] == 1) neighbors++;
                if(tmpGrid[j-1][k] == 1) neighbors++;
                if(tmpGrid[j-1][k+1] == 1) neighbors++;
                if(tmpGrid[j][k-1] == 1) neighbors++;
                if(tmpGrid[j][k+1] == 1) neighbors++;
                if(tmpGrid[j+1][k-1] == 1) neighbors++;
                if(tmpGrid[j+1][k] == 1) neighbors++;
                if(tmpGrid[j+1][k+1] == 1) neighbors++;
                // Execute rules
                if(neighbors < 2) (*grid)[j][k] = 0; // underpopulation
                else if(neighbors == 2 || neighbors == 3) (*grid)[j][k] = 1; // survival
                else if(neighbors >= 2) (*grid)[j][k] = 0; // overpopulation
                else if(tmpGrid[j][k] == 0 && neighbors == 3) (*grid)[j][k] = 1; // reproduction
            }
        }
        freeGrid(&tmpGrid, rowSize);
        printf("Cycle %d of %d\n", i+1, cycles);
        printGrid(grid, rowSize, colSize);
    }
}

int main(){
    int **gridTest, rowSize = 3, colSize = 3;
    int cycles = 4;
    printf("Initializing Grid.\n");
    initializeGrid(&gridTest, rowSize, colSize);
    printGrid(&gridTest, rowSize, colSize);
    printf("Inserting Live Cell.\n");
    insertLiveCell(&gridTest, 0, 1);
    printGrid(&gridTest, rowSize, colSize);
    printf("Inserting Live Cell.\n");
    insertLiveCell(&gridTest, 2, 1);
    printGrid(&gridTest, rowSize, colSize);
    runEvolutionSim(&gridTest, cycles, rowSize, colSize);
    return 0;
}