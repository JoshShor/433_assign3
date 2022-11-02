/**
* Assignment 3: CPU Scheduler
 * @file scheduler_sjf.cpp
 * @author ??? (TODO: your name)
 * @brief This Scheduler class implements the SJF scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "scheduler_sjf.h"
#include <queue>

// member functions init, print_results, and simulate here


 SchedulerSJF::SchedulerSJF()  {
     aveWaitTime = 0.0; 
     aveTurnTime = 0.0;
     waitTime = 0;
     turnTime = 0;
     count = 0;
  
 }
 
SchedulerSJF::~SchedulerSJF()
{   
}

void SchedulerSJF::init(std::vector<PCB>& process_list) 
{
    printf("simulate init size %li \n", process_list.size());  
    //pq_burst = process_list;
    for (auto &curr : process_list){
        schedulerList.push(curr);
    }
    //printf("simulate init size %li \n", schedulerList.size());  
}

void SchedulerSJF::print_results()
{
    printf("Average turn-around time = %.2f", aveTurnTime / count);
    printf(", Average waiting time = %.2f\n", aveWaitTime / count);
}

void SchedulerSJF::simulate()
{
  printf("simulate start \n");       
    while (!schedulerList.empty()) {//while the vector is not empty
        turnTime += schedulerList.top().burst_time;
        waitTime = turnTime - schedulerList.top().burst_time;
        aveWaitTime += waitTime;
        aveTurnTime += turnTime;
        count++;

        cout << schedulerList.top().name << " " << "turn-around time = " << turnTime << ", waiting time = "
             << waitTime << endl;
        schedulerList.pop();//removes the task from the vector
    }

     printf("simulate end \n");    
  
}
  
