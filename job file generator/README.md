# 📝 job file generator

this program creates two binary job files (`jobs.dat` and `org.dat`) and fills them with randomly generated jobs for later use in the cpu scheduling simulator. 

## ✨ how it works

each job is stored as a binary `Job` struct:
```
struct Job {
  char jobType; // A B C D
  int processingTime;
  int typeNumber;
  int jobNumber;
  int arrivalTime;
  int waitTime = 0;
};
```

in total, 5570 jobs are created:
- 2300 type A.
- 1700 type B.
- 950 type C.
- 620 type D.

each type has its own arrival time pattern and processing time range.

the program begins by preallocating space for all 5570 jobs in both output files.

it then fills `jobs.dat` with randomized jobs grouped by type, using different arrival time patterns and processing time ranges for each category.

after all jobs are created, the program sorts them by arrival time and writes the ordered sequence into `org.dat`.

finally, it prints the organized list to the console so you can verify the generated jobs.

## ▶️ how to run

1. open the solution in visual studio.
2. right-click the job file generator project and select **set as startup project**.
3. run the program (`f5`).

the program will create jobs.dat and org.dat in the build directory and print the organized list.

## 📁 output

the generator outputs two files:
- `jobs.dat` - raw, unsorted job entries.
- `org.dat` - the same jobs sorted by arrival time and priority.

both binary files are created in the project's root folder `job file generator/`. copy `org.dat` and paste it in the other project's folder (`cpu scheduling simulator/`) in order to run part 2. 

_**note:** visual studio tends to hide files that aren't code, such as readmes or these output files. to see and move them, navigate to the project's directory in your operating system's file explorer._

## 🔧 building it

coded in visual studio, all logic lies inside `Source.cpp`.
