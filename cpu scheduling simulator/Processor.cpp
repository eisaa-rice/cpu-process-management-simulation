// Processor.cpp
#include "Processor.h"

Processor::Processor() {
    currentJob = { '\0', 0, 0, 0, 0 ,0 };
    jobArrived = 0;
}

// function to add a job to the processor stack
void Processor::PushProcessor(Job inputJob) {
    if (jobArrived == 0) {
        currentJob = inputJob;
        jobArrived++;
    }
}

// removes an item from the processor stack
Job Processor::RemoveProcessor() {
    Job tempJob = currentJob;
    currentJob = {};
    jobArrived--;

    return tempJob;
}

// checks whether the Processor stack is empty
bool Processor::IsEmpty() {
    if (jobArrived == 0) {

        return true;
    }
    return false;
}

// checks whether the Processor stack is full
bool Processor::IsFull() {
    if (jobArrived == 1) {

        return true;
    }
    return false;
}


// checks when the processor has no time remaining in the stack, else not complete
bool Processor::IsComplete() {
    if (currentJob.processingTime == 0) {
        return true;
    }
    return false;
}

// decreases the processing time in an active job in a processor
void Processor::ProcessJobOne() {
    currentJob.processingTime--;
}