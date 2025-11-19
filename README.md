# 🖥️ cpu process management simulation

this was the final project for cs 200 and it was split into two parts. the first part was a job file generator that produced the input data, and the second part was a cpu scheduling simulator that processed that file and printed the scheduling results.

## 📂 project layout
```
cpu-process-management-simulation/
│
├── cpu scheduling simulator/   ← runs the scheduling algorithms
└── job file generator/         ← creates the input job file
```

## ⚙️ what each part does
### 🧮 cpu scheduling simulator

reads a job file, runs simple scheduling logic, tracks times, and prints the results in the console.

### 📝 job file generator

creates a text file filled with randomly generated jobs so you can test the simulator without making input files by hand.

## ▶️ how to run

1. clone this repository and open the project in visual studio.
2. right-click the project you want to run, and select **set as startup project**.
3. run the program (`f5`).

run the job file generator _first_ to produce the input file, then run the cpu scheduling simulator to process it.

## 📝 small note

check out each folder's readme for more details on how each part of the project works!

