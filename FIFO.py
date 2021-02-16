class process_info:
    def __init__(self,process_number,arrival_time,burst_time):
        self.process_number=process_number
        self.arrival_time=arrival_time
        self.burst_time=burst_time
        self.turnaroundtime=0
        self.waiting_time=0


process_count=int(input("Process Number - "))
chart_time=cpu_idle_time=total_turnaround_time=total_waiting_time=0

process=[]
for i in range(process_count):
    print("\nProcess Number ",i)
    arrival_time=int(input("\tArrivalTime - "))
    burst_time=int(input("\tBurstTime - "))
    current_process=process_info(i,arrival_time,burst_time)
    process.append(current_process)

#Sorting processes by their arrival times
process.sort(key= lambda x: (x.arrival_time,x.process_number))

#Applying FIFO Logic
for i in range(process_count):
    if(process[i].arrival_time>chart_time):
        cpu_idle_time+=(process[i].arrival_time - chart_time)
        chart_time=process[i].arrival_time
    chart_time+=process[i].burst_time
    process[i].turnaroundtime=chart_time - (process[i].arrival_time)
    process[i].waiting_time=process[i].turnaroundtime - process[i].burst_time

for i in range(process_count):
    total_turnaround_time+=process[i].turnaroundtime
    total_waiting_time+=process[i].waiting_time


print("Applying FIFO on the above Process Data\n")
print("Average TurnAroundTime - ",(total_turnaround_time/process_count))
print("Average WaitingTime - ",(total_waiting_time/process_count))
print()
print("CPU Idle Time - ",cpu_idle_time)
print("CPU Efficiency - ",(1-(cpu_idle_time/total_turnaround_time)))
print()



