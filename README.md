[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/jkn9TuBQ)

______________________________________
MUHAMMAD HASNAIN
ID: 21K-4714
_______________________________________

Conway's Game of Life: The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game that simulates the evolution of a population of cells on a two-dimensional grid based on a set of rules. The rules are simple: a dead cell with exactly three live neighbors becomes a live cell (birth), a live cell with two or three live neighbors survives to the next generation, and all other live cells die in the next generation due to overpopulation or loneliness. Your task is to implement the Game of Life algorithm in C language.
C language: You will be using C language to write your program.
Linux POSIX threads: You will be using POSIX threads to create multiple threads that run the Game of Life algorithm concurrently.
Mutexes and condition variables: You will be using mutexes and condition variables to synchronize access to shared data structures such as the grid of cells.
Speedup measurement: You will be using shell scripting to measure the speedup achieved by running the final application with various numbers of threads. You will compare the execution time of your program with different numbers of threads and plot a graph to visualize the speedup.
Here's a brief outline of the steps you can follow to complete the assignment:
Implement the Game of Life algorithm in C language. You can use a two-dimensional array to represent the grid of cells, and implement the rules of the game using conditional statements.
Create multiple POSIX threads to run the Game of Life algorithm concurrently. You should decide for yourself how to divide the grid into different regions that can be processed independently by different threads. 
You can use mutexes and condition variables to synchronize access to shared data structures such as the grid of cells.
Use shell scripting to measure the speedup achieved by running the final application with various numbers of threads. You can use the time command to measure the execution time of your program with different numbers of threads, and plot a graph to visualize the speedup.
Submit a report detailing your implementation, including any design decisions you made and the results of your speedup measurements.
