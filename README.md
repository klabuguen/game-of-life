# Conway's Game of Life (C Implementation)

This repository contains a **C implementation** of Conway's Game of Life — a cellular automaton devised by mathematician John Conway.  
The program simulates the evolution of a grid of cells based on simple rules and prints out each generation in **text form**.

---

## About the Game

The Game of Life is a zero-player game that evolves from an initial state without further input.  
Each cell on the grid is either **alive (`1`)** or **dead (`0`)**, and its state in the next generation is determined by four simple rules:

1. Any live cell with fewer than two live neighbors dies (underpopulation).  
2. Any live cell with two or three live neighbors lives on to the next generation (survival).  
3. Any live cell with more than three live neighbors dies (overpopulation).  
4. Any dead cell with exactly three live neighbors becomes alive (reproduction).  

---

## Features

- Prints the grid to the terminal for each generation  
- Supports configurable grid sizes and iteration counts  
- Uses simple ASCII symbols for visualization (`1` = alive, `0` = dead)  
- Written in **pure C**, with no external dependencies  

---

## Getting Started

### Clone the Repository

```bash
git clone https://github.com/klabuguen/game-of-life.git
cd game-of-life
```
