#include<stdio.h>
#include<stdlib.h>

struct process_info{
    
    int process_number;
    int arrival_time;
    int burst_time;
    float waiting_time;
    float turnaround_time;
};

int comparator(const void* p,const  void* q)
{
    struct process_info* a=(struct process_info*)p;
    struct process_info* b=(struct process_info*)q;
    if(a->arrival_time==b->arrival_time)
        return (a->process_number-b->process_number);
    return (a->arrival_time-b->arrival_time);
}

int main()
{
    int process_count=0,chart_time=0,cpu_idle_time=0;
    float total_waiting_time,total_turnaround_time;

    printf("Enter the Number of Processes - ");
    scanf("%d",&process_count);
    printf("\n\nProcess Number\n\n");
    
    struct process_info* process=(struct process_info*)malloc(sizeof(struct process_info)*(process_count));

    /*Taking input about the process arrival and burst times*/
    for(int i=0;i<process_count;i++)
    {
        printf("Process %d\n",i);
        process[i].process_number=i+1;
        printf("\tArrival Time - ");
        scanf("%d",&process[i].arrival_time);
        printf("\tBurst Time - ");
        scanf("%d",&process[i].burst_time);
    }

    /*Sort Structures before implementing by Arrival Times*/
    qsort((void*)process,process_count,sizeof(process[0]),comparator);
    /*Implementing Logic*/
    
    for(int i=0;i<process_count;i++)
    {
        if(process[i].arrival_time>chart_time)
        {
            cpu_idle_time+=(process[i].arrival_time - chart_time);
            chart_time=process[i].arrival_time;
        }
        chart_time+=process[i].burst_time;
        process[i].turnaround_time=chart_time-process[i].arrival_time;
        process[i].waiting_time=process[i].turnaround_time-process[i].burst_time;
    }

    for(int i=0;i<process_count;i++)
    {
        total_turnaround_time+=process[i].turnaround_time;
        total_waiting_time+=process[i].waiting_time;
    }

    printf("\n\nApplying FIFO Logic for the above Process Data\n\n");
    printf("Average TurnAround Time is - %f\n",(float)total_turnaround_time/process_count);
    printf("Average Waiting Time is - %f\n\n",(float)total_waiting_time/process_count);
    printf("CPU Idle Time is - %d\n",cpu_idle_time);
    printf("CPU Efficiency is - %f \n\n",(1-((float)cpu_idle_time/total_turnaround_time)));
 
    return 0;
}