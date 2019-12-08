#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

float calculate_average(int t[], int n)
{
    int sum=0;
    for(int i=0; i<n; i++)
        sum += t[i];
    float avg = sum/n;
    return avg;
}

void sort_array(int a[], int b[], int Pid[], int p[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                swap(b[j], b[j+1]);
                swap(Pid[j], Pid[j+1]);
                swap(p[j], p[j+1]);
            }
        }
    }
}

int main()
{
    int n,i; 
    double th;
    cout<<"Enter the number of process: ";
    cin>>n;
    cout<<endl;
    int at[n], bt[n], ct[n], tat[n], wt[n], Pid[n], btc[n], rt[n], flag[n], priority[n];
    for(i=0; i<n; i++)
        flag[i] = 1;
    for(i=0; i<n; i++)
    {
        cout<<"Process id is "<<i<<endl;
        Pid[i]=i;
        cout<<"Enter the priority for process "<<i<<" : ";
        cin>>priority[i];
        cout<<"Enter the arrival time for process "<<i<<" : ";
        cin>>at[i];
        cout<<"Enter the burst time for process "<<i<<" : ";
        cin>>bt[i];
        //btc[i] = bt[i];
        cout<<endl;
    }
    sort_array(at,bt,Pid,priority,n);
    int time=at[0], max_p=priority[0],k=1,j=0,p=n,t=1,h=0;
    while(p != 0)
    {
        for (i = 1; i < n; i++)
        {
            if (at[i] <= time && flag[Pid[i]] == 1)
            {
                if (priority[i] > max_p)
                {
                    if(priority[i] == priority[k] && i != k){
                    		i = min(Pid[i], Pid[k]);
                    }
                    if(at[i] == 0)
                    {
                    	if(priority[h] < priority[k])
                    	{
                			i = h;
                			k = Pid[k];
                			h += 1;
                		}
                    }
                    max_p = priority[i];
                    swap(at[i], at[k]);
                    swap(bt[i], bt[k]);
                    swap(Pid[i], Pid[k]);
                    swap(priority[i], priority[k]);
                }
            }
        }
        if(j == 0)
            ct[j] = at[j] + bt[j];
        else if(at[j] > ct[j-1]){
            ct[j] = bt[j] + at[j];
            k += 1;}
        else{
            ct[j] = ct[j-1] + bt[j];
            k += 1;}
        flag[Pid[j]] = 0;
        time = ct[j];
        j += 1;
        p -= 1;
        max_p = 0;
    }
    for(i=0; i<n; i++)
    {
        if(i == 0)
            ct[i] = at[i] + bt[i];
        else if(at[i] > ct[i-1])
            ct[i] = bt[i] + at[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }
    for(i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    cout<<endl<<"Pid\tAT\tBT\tPriority\tCT\tTAT\tWT"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<Pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<priority[i]<<"\t\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\t"<<endl;
    }
    cout<<endl<<"Average Turn Around Time = "<<calculate_average(tat,n);
    cout<<endl<<"Waiting Time = "<<calculate_average(wt,n)<<endl;
    th = (float)n/(float)ct[n-1];
    cout<<"Throughput = "<<th<<endl;
    return 0;
}
