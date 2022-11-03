/**
* Assignment 3: CPU Scheduler
 * @file scheduler_priority.cpp
 * @author ??? (TODO: Tam Nguyen, Josh Shor)
 * @brief This Scheduler class implements the Priority scheduling algorithm.
 * @version 0.1
 */
 //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 // Remember to add sufficient and clear comments to your code


#include "scheduler_priority.h"


/**
 * @brief Constructor for the  class.
 */
SchedulerPriority::SchedulerPriority() {
    aveWaitTime = 0.0;
    aveTurnTime = 0.0;
    waitTime = 0;
    turnTime = 0;
    count = 0;

}

SchedulerPriority::~SchedulerPriority() {}

/**
* @brief This function is called once before the simulation starts.
*        It is used to initialize the scheduler.
* @param process_list The list of processes in the simulation.
*/
void SchedulerPriority::init(std::vector<PCB>& process_list) {
    //("init\n");
    /*
    for (int i = 0; i < process_list.size(); i++) {
        schedulerList.push(i);
    }
    */
    int largest_priority = 10;

    for (int prior = largest_priority; prior > 0; prior--) {
        for (int index = 0; index < process_list.size(); index++) {
            if (process_list[index].priority == prior) {
                schedulerList.push_back(process_list[index]);
            }
        }
    }

}

/**
 * @brief This function is called once after the simulation ends.
 *        It is used to print out the results of the simulation.
 */
void SchedulerPriority::print_results() {
    //printf("print_results\n");
    //printf("print_results %f \n", aveTurnTime);
    //printf("print_results %f \n", aveWaitTime);
    printf("Average turn-around time = %.2f", aveTurnTime / count);
    printf(", Average waiting time = %.2f\n", aveWaitTime / count);

}

/**
 * @brief This function simulates the scheduling of processes in the ready queue.
 *        It stops when all processes are finished.
 */
void SchedulerPriority::simulate() {
    //printf("simulate33443423433 %ld \n", list.size());


    while (!schedulerList.empty()) {//while there are still tasks
        turnTime += schedulerList[0].burst_time;
        waitTime = turnTime - schedulerList[0].burst_time;
        aveTurnTime += turnTime;
        aveWaitTime += waitTime;
        count++;

        cout << schedulerList[0].name << " " << "turn around time" << " " << turnTime << " " << "waiting time" << " "
            << waitTime << endl;
        schedulerList.erase(schedulerList.begin());//removes the task from the vector
    }
}