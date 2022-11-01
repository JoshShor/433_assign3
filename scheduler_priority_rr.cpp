/**
* Assignment 3: CPU Scheduler
 * @file scheduler_rr.h
 * @author ??? (Tam Nguyen, Josh Shor)
 * @brief This Scheduler class implements the RoundRobin (RR) scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
//

#include "scheduler_rr.h"

// TODO: add implementation of SchedulerFCFS constructor, destrcutor and 
// member functions init, print_results, and simulate here

SchedulerRR::SchedulerRR(int time_quantum)
{
    TimeQ = time_quantum;
    averageWT = 0.0;
    averageTAT = 0.0;
    turnaroundT = 0;
    count = 0;
    loop = 0; 
}

SchedulerRR::~SchedulerRR()
{
    averageWT = 0.0;                //average wait time
    averageTAT = 0.0;               //average turn around time
    turnaroundT = 0;                //turnaround time
    count = 0;                      //count increment
    loop = 0;                       //loop
}

void SchedulerRR::init(std::vector<PCB>& process_list) 
{
    //printf("simulate init size %li \n", process_list.size());  
    rr_vect = process_list;
    //printf("simulate init size %li \n", rr_vect.size());  
}

void SchedulerRR::print_results()
{
    printf("Average turn-around time = %.2f", averageTAT / count);
    printf(", Average waiting time = %.2f\n", averageWT / count);
}

void SchedulerRR::simulate()
{
  //printf("simulate start \n");       

    while (!rr_vect.empty()) {//while there are still PCB in the vector
        //printf("simulate start2 \n");    
        size = rr_vect.size();

        for (int s = 1; s <= size; s++) {//loops through each iteration of the vector
            PCB temp = rr_vect[0];
            waitT = turnaroundT;
            //printf("simulate start3 \n");

            if (temp.burst_time <= TimeQ) {//if the burst is shorter or equal to the Time Quantum
                waitT = (waitT - (loop * TimeQ));
                turnaroundT += temp.burst_time;
                //printf("%s turn around time = %d, waiting time = %d \n", temp.name, turnaroundT, waitT);
                count++;
                averageTAT += turnaroundT;
                averageWT += waitT;
                rr_vect.erase(rr_vect.begin());//removes the PCB from the vector
            } else {//burst is longer thanthe time quantum
                turnaroundT += TimeQ;
                PCB temp2 = temp;
                rr_vect.erase(rr_vect.begin());//removes the PCB from the vecotr
                temp2.burst_time = temp2.burst_time - TimeQ;//subtract the time quantum from the burst
                rr_vect.push_back(temp2);
             }
        }
        loop++;//increments the amount of times it goes through the vector
    }
      //printf("simulate end \n");
 }
