#include<bits/stdc++.h>
using namespace std;

struct Process{
	int arrival_time;
	int burst_time;
	int process;
};


//Function for Sorting the Structure
bool sorting_process(Process a, Process b)
{
	return a.arrival_time < b.arrival_time;
}


int main()
{
	int n,i,j,k;
	cout<<"Enter the number of processes : ";
	cin>>n;	
	cout<<"\n";
	Process p[n];
	int burst_times[n];
	//Taking Input's of Arrival Time and Burst Time
	for(i=0;i<n;i++)
	{
		cout<<"Enter the arrival time of "<<i+1<<" Process : ";
		cin>>p[i].arrival_time;
		p[i].process = i+1;
	}
	cout<<"\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter the burst time of "<<i+1<<" Process : ";
		cin>>p[i].burst_time;
		burst_times[i]=p[i].burst_time;
		
	}
	
	//Sorting the structure based on Arrival Times
	sort(p,p+n, sorting_process);
	
	//Displaying the Data about Processes
	cout<<"\n";
	cout<<"PROCESS"<<"\t"<<"ARRIVAL TIME"<<"\t"<<"BURST TIME"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"  P"<<p[i].process<<"\t    "<<p[i].arrival_time<<"\t            "<<p[i].burst_time<<endl;
	}
	cout<<"\n";
	
	//Taking the TIMEQUANTUM and calculating the TurnAround Time and Waiting Time
	int time_quantum,waiting_time=0,turnaround_time=0,time,count,remaining,flag;
	cout<<"Enter Time Quantum : ";
	cin>>time_quantum;
	remaining=n;
	cout<<"\n";
	cout<<"\n\nProcess\t|Turnaround Time|Waiting Time\n\n";
	for(time=0,count=0;remaining!=0;) 
    { 
   		if(burst_times[count]<=time_quantum && burst_times[count]>0) 
    	{ 
      		time+=burst_times[count]; 
      		burst_times[count]=0; 
      		flag=1; 
    	} 
    
    	else if(burst_times[count]>0) 
    	{ 
      		burst_times[count]=burst_times[count]-time_quantum; 
      		time+=time_quantum; 
    	} 
    
    
    	if(burst_times[count]==0 && flag==1) 
    	{ 
      		remaining--; 
      		cout<<"  P"<<count+1<<"\t|\t"<<time-p[count].arrival_time<<"\t|\t"
			  <<time-p[count].arrival_time-p[count].burst_time<<endl;
      		waiting_time+=time-p[count].arrival_time-p[count].burst_time; 
	  		turnaround_time+=time-p[count].arrival_time;
			flag=0; 
    	} 
    
    	if(count==n-1) 
      		count=0; 
    	else if(p[count+1].arrival_time<=time) 
      		count++; 
    	else 
      		count=0; 
  } 
  cout<<"\nTotal Waiting Time of All Processes : "<<waiting_time<<endl;
  cout<<"\nAverage Waiting Time : "<<(waiting_time*1.0)/n<<endl; 
  cout<<"\nTurnAround Time : "<<(turnaround_time*1.0)/n<<endl; 	
}
