#include <iostream>
using namespace std;
int mat[10][6]; 

void swap(int* a, int* b) //function to interchange processes based on burst time
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Arrivals(int num, int mat[][6]) //to check the shortest job first from the given matirx
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (mat[j][1] > mat[j + 1][1]) {
				for (int k = 0; k < 5; k++) {
					swap(mat[j][k], mat[j + 1][k]);
				}
			}
		}
	}
}

void completionTime(int num, int mat[][6]) //to compute the completion time
{
	int temp, val;
	mat[0][3] = mat[0][1] + mat[0][2]; //to cal the waiting time(columnwise)
	mat[0][5] = mat[0][3] - mat[0][1];
	mat[0][4] = mat[0][5] - mat[0][2];//to cal the turnaround time

	for (int i = 1; i < num; i++) {
		temp = mat[i - 1][3];
		int low = mat[i][2];
		for (int j = i; j < num; j++) {
			if (temp >= mat[j][1] && low >= mat[j][2]) {
				low = mat[j][2];
				val = j;
			}
		}
		mat[val][3] = temp + mat[val][2];
		mat[val][5] = mat[val][3] - mat[val][1];
		mat[val][4] = mat[val][5] - mat[val][2];
		for (int k = 0; k < 6; k++) {
			swap(mat[val][k], mat[i][k]);
		}
	}
}

void SJF()
{
		int num, temp;

	cout << "Enter number of Process: ";
	cin >> num;

	cout << "...Enter the process ID...\n";
	for (int i = 0; i < num; i++) {
		cout << "...Process " << i + 1 << "...\n";
		cout << "Enter Process Id: ";
		cin >> mat[i][0];
		cout << "Enter Arrival Time: ";
		cin >> mat[i][1];
		cout << "Enter Burst Time: ";
		cin >> mat[i][2];
	}

	cout << "Before Arrange...\n";
	cout << "Process ID\tArrival Time\tBurst Time\n";
	for (int i = 0; i < num; i++) {
		cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t"
			<< mat[i][2] << "\n";
	}

	Arrivals(num, mat);
	completionTime(num, mat);
	cout << "Final Result...\n";
	cout << "Process ID\tArrival Time\tBurst Time\tWaiting "
			"Time\tTurnaround Time\n";
	for (int i = 0; i < num; i++) {
		cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t"
			<< mat[i][2] << "\t\t" << mat[i][4] << "\t\t"
			<< mat[i][5] << "\n";
	}

}

void FCFS()

	{
    	int n,btime[20],wtime[20],tat[20],avwtime=0,avtat=0,i,j;
    	cout<<"Enter total number of processes(maximum 20):";
    	cin>>n;
    	cout<<"\nEnter Process Burst Timen";
    	for (i=0;i<n;i++) {
    		cout<<"P["<<i+1<<"]:";
    		cin>>btime[i];
    	}
    	wtime[0]=0;
    	//waiting time for first process is 0
    	//calculating waiting time
    	for (i=1;i<n;i++) {
    		wtime[i]=0;
    		for (j=0;j<i;j++)
    		            wtime[i]+=btime[j];
    	}
    	cout<<"\nProcessttBurst TimetWaiting TimetTurnaround Time";
    	//calculating turnaround time
    	for (i=0;i<n;i++) {
    		tat[i]=btime[i]+wtime[i];
    		avwtime+=wtime[i];
    		avtat+=tat[i];
    		cout<<"\nP["<<i+1<<"]"<<" burst time "<<btime[i]<<" waiting time "<<wtime[i]<<" TAT "<<tat[i];
    	}
    	avwtime/=i; //avwtime=avwtime/i
    	avtat/=i;
    	cout<<"\nAverage Waiting Time:"<<avwtime;
    	cout<<"\nAverage Turnaround Time:"<<avtat;
    
}

int main()
{
	int choice;
	cout<<"\nChoose Scheduling Algorithm : 1. FCFS 2.SJF"<<endl;
	cin>>choice;
	if (choice == 1)
	{
		cout<<"\nFCFS Scheduling :: "<<endl;
		FCFS();
	}
	else
	{
		cout<<"\nSJF Scheduling :: "<<endl;
		SJF();
		
	}
	return 0;
	
}
