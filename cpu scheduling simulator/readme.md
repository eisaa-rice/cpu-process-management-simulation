# 🧮 cpu scheduling simulator

this program reads a binary job file (`org.dat`, created by the job file generator) and simulates how multiple processors handle those jobs over time.

## ✨ how it works

the simulator loads all 5570 jobs from `org.dat` into a stack, ordered by arrival time, then reverses them so the earliest arrivals are on top.

each job is stored using the same `Job` struct:
```
struct Job {
  char jobType;
  int processingTime;
  int typeNumber;
  int jobNumber;
  int arrivalTime;
  int waitTime;
};
```

during the run, jobs arrive into a min heap that acts as the ready queue, where shorter jobs and certain high-priority types move closer to the front.

the user chooses how many processors to simulate, and each processor either runs a job or stays idle, depending on the state of the queue.

at each time step, jobs that finish are removed, new arrivals are added to the heap, processors pull the next job from the heap, and the remaining jobs in the heap have their wait times increased.

the simulator records a detailed timeline in `log.txt` and computes summary metrics at time `500` and at the end, including queue size, average wait time, processor idle time, and how many jobs of each type arrived and completed.

## ▶️ how to run

1. make sure `org.dat` from the job file generator is copied into this project’s folder.
2. open the solution in visual studio.
3. right-click the job file generator project and select **set as startup project**.
4. run the program (`f5`).
5. when prompted, enter how many processors you want to simulate (for example, 1, 2, 4, or 8).

after the simulation finishes, check the console for a summary and open `log.txt` for the full report.

## 📥 input

the simulator expects one binary file in the project’s root folder:
- `org.dat` - the organized job file produced by the job file generator, containing 5570 jobs in order of arrival time.

## 📁 output

the simulator writes one main output file:
- log.txt - a text log that records every time step, job arrivals, jobs starting and finishing on each cpu, and the queue state.

at time `500` and at the end of the run, the program also prints:
- total jobs arrived and completed.
- jobs arrived and completed per type (`A`, `B`, `C`, `D`)
- average queue size and maximum queue size.
- total and average wait time in the queue.
- total time all cpus spent processing versus idle.

`log.txt` lives in this project’s root folder `cpu scheduling simulator/`, while `org.dat` should be copied into that same folder before running.

## 🔧 building it

coded in visual studio, the simulator is split across multiple header, class, and source files:
- `jobstack.h` / `jobstack.cpp` for the job stack
- `newheap.h` / `newheap.cpp` for the priority queue
- `processor.h` / `processor.cpp` for each cpu
- `main.cpp` for the simulation loop and metrics.
