#include<bits/stdc++.h>
using namespace std;
struct Process{
	int status;
	int process;
	int arrival_time,burst_time,waiting_time,turnaround_time;
};


//Sorting of Structure based on Arrival Time
bool compareTwoProcesses(Process a,Process b){
	return (a.burst_time > b.burst_time);
}
bool shortestJob(Process a,Process b){
	return (a.burst_time < b.burst_time);
}

int main(){
	
	int n,i;
	cout<<"Enter the no.of processes : ";
	cin>>n;
	cout<<"\n";
	Process p[n];
	int completed_processes[n];
	for(i=0;i<n;i++){
		cout<<"Enter the arrival_time of "<<i+1<<" process : ";
		cin>>p[i].arrival_time;
		p[i].burst_time = p[i].arrival_time * 2;
		p[i].status=0;
		p[i].waiting_time=0;
		p[i].turnaround_time=0;
		p[i].process = i+1;
	}
	
	//Displaying the Entered Data
	cout<<"\tProcess \t Arrival Time \t Burst Time\n";
	for(i=0;i<n;i++){
		cout<<"\t"<<p[i].process<<"\t\t  "<<p[i].arrival_time<<"\t\t  "<<p[i].burst_time<<"\n";
	}
	
	//Executing the min arrival time in the process
	
	int minarr_loc=0,min_arrival_time=p[0].arrival_time,total_time=0;
	for(i=0;i<n;i++){
		if(min_arrival_time > p[i].arrival_time){
			min_arrival_time = p[i].arrival_time;
			minarr_loc=i;
		}
	}
	
	cout<<"\nOrder of Execution based on highest Burst Time: ";
	cout<<"\nP"<<p[minarr_loc].process<<" will be executed first \n";
	p[minarr_loc].status=1;
	total_time=total_time+p[minarr_loc].arrival_time+p[minarr_loc].burst_time;
	p[minarr_loc].turnaround_time=total_time-p[minarr_loc].arrival_time;
	p[minarr_loc].waiting_time=p[minarr_loc].turnaround_time-p[minarr_loc].burst_time;
	
	
	
	//Used for Sorting of Structure
	sort(p,p+n,compareTwoProcesses);
	
	
	//Selecting the processes and calculating the TAT and WAT
	i=0;
	int count = 1;
	while(count!=n){
		if(p[i].status==0 && (p[i].arrival_time <= total_time)){
			cout<<"\nP"<<p[i].process<<" will be executed next \n";
			p[i].status=1;
			total_time=total_time+p[i].burst_time;
			p[i].turnaround_time=total_time-p[i].arrival_time;
			p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
			count++;
		}
		i=(i+1)%n;
	}
	
	
	//Calaculating Average Waiting Time and Average Turn Around Time
	float waiting_time=0,turnaround_time=0;
	for(i=0;i<n;i++){
		waiting_time+=p[i].waiting_time;
		turnaround_time+=p[i].turnaround_time;
	}
	
	cout<<"\n Average Waiting Time = "<<waiting_time/n;
	cout<<"\n Average Turn Around Time = "<<turnaround_time/n;
	
	
	//Execution based on Shortest Job First
	for(i=0;i<n;i++){
		p[i].status=0;
		p[i].waiting_time=0;
		p[i].turnaround_time=0;
	}
	
	//Executing the min arrival time in the process
	
	total_time=0;
	min_arrival_time=p[0].arrival_time;
	minarr_loc=0;
	for(i=0;i<n;i++){
		if(min_arrival_time > p[i].arrival_time){
			min_arrival_time = p[i].arrival_time;
			minarr_loc=i;
		}
	}
	
	cout<<"\n\nOrder of Execution based on Shortest Job First";
	cout<<"\nP"<<p[minarr_loc].process<<" will be executed first \n";
	p[minarr_loc].status=1;
	total_time=total_time+p[minarr_loc].arrival_time+p[minarr_loc].burst_time;
	p[minarr_loc].turnaround_time=total_time-p[minarr_loc].arrival_time;
	p[minarr_loc].waiting_time=p[minarr_loc].turnaround_time-p[minarr_loc].burst_time;
	
	
	
	//Used for Sorting of Structure
	sort(p,p+n,shortestJob);
	
	
	//Selecting the processes and calculating the TAT and WAT
	i=0;
	count = 1;
	while(count!=n){
		if(p[i].status==0 && (p[i].arrival_time <= total_time)){
			cout<<"\nP"<<p[i].process<<" will be executed next \n";
			p[i].status=1;
			total_time=total_time+p[i].burst_time;
			p[i].turnaround_time=total_time-p[i].arrival_time;
			p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
			count++;
		}
		i=(i+1)%n;
	}
	
	
	//Calaculating Average Waiting Time and Average Turn Around Time
	waiting_time=0,turnaround_time=0;
	for(i=0;i<n;i++){
		waiting_time+=p[i].waiting_time;
		turnaround_time+=p[i].turnaround_time;
	}
	
	cout<<"\n Average Waiting Time = "<<waiting_time/n;
	cout<<"\n Average Turn Around Time = "<<turnaround_time/n;
	
	
	
}
