
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include "scheduler_fcfs.h"

using namespace std;

/**
* Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.cpp
 * @author ??? (TODO: Tam Nguyen and Josh Shor)
 * @brief This Scheduler class implements the FCSF scheduling algorithm.
 * @version 0.1
 */

/**
 * @brief Constructor for the  class.
 */
 SchedulerFCFS::SchedulerFCFS()  {
     aveWaitTime = 0.0, 
     aveTurnTime = 0.0;
     waitTIme = 0;
     turnTime = 0;
  
 }

 SchedulerFCFS::~SchedulerFCFS() {}

 /**
 * @brief This function is called once before the simulation starts.
 *        It is used to initialize the scheduler.
 * @param process_list The list of processes in the simulation.
 */
void SchedulerFCFS::init(std::vector<PCB>& process_list) {
    //("init\n");
    list = process_list;
    //printf("init %ld\n", list.size());
}

/**
 * @brief This function is called once after the simulation ends.
 *        It is used to print out the results of the simulation.
 */
void SchedulerFCFS::print_results() {
    //printf("print_results\n");
    //printf("print_results %f \n", aveTurnTime);
    //printf("print_results %f \n", aveWaitTime);
    printf("Average turn-around time: %.2f", aveTurnTime / list.size());
    printf(", Average waiting time: %.2f\n", aveWaitTime / list.size());

}

/**
 * @brief This function simulates the scheduling of processes in the ready queue.
 *        It stops when all processes are finished.
 */
void SchedulerFCFS::simulate() {
        //printf("simulate33443423433 %ld \n", list.size());

    for (unsigned i = 0; i < list.size(); i++) {//iterates through the size of the list
        turnTime += list[i].burst_time;
        waitTIme = turnTime - list[i].burst_time;
        aveTurnTime += turnTime;
        aveWaitTime += waitTIme;
      
        cout << list[i].name << " " << "turn-around time, = " << turnTime << ", waiting time = " << waitTIme << endl;
    }
}
