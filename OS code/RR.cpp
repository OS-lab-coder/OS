//
// Created by pt212 on 14-10-2019.
//
#include<bits/stdc++.h>
using namespace std;
#define N 50
int q[N];
int count = -1;

void insert(int q[],int *f,int *r,int val)
{
    if((*r)>=N-1)
        cout<<"Queue is Full";
    else
    {
        q[++(*r)]=val;
        if((*f)==-1)
           { *f=0;}
    }
}

void display(int q[N],int *f,int *r)
{
    int n;
    if((*f)==-1&&(*r)==-1)
        cout<<"Queue is Empty";
    else
        {
            for(n=(*f);n<=(*r);n++)
            {
                cout<<q[n]<<"  ";
            }
        }
}

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

void sort_array(int a[], int b[], int Pid[], int n)
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
            }
        }
    }
}

int main()
{
    int f, r, tq;
    f=-1;r=-1;
    int n,i; 
    double th;
    cout<<"Enter the number of process: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the time quantum: ";
    cin>>tq;
    cout<<endl;
    int at[n], bt[n], ct[n], tat[n], wt[n], Pid[n], btc[n], rt[n], fo[n];
    for(i=0; i<n; i++)
        fo[n] = 0;
    for(i=0; i<n; i++)
    {
        cout<<"Process id is "<<i<<endl;
        Pid[i]=i;
        cout<<"Enter the arrival time for process "<<i<<" : ";
        cin>>at[i];
        cout<<endl;
        cout<<"Enter the burst time for process "<<i<<" : ";
        cin>>bt[i];
        btc[i] = bt[i];
        cout<<endl;
    }
    sort_array(at,bt,Pid,n);
    int time = at[0], pid, b, flag, complete;
    for(i=0; i<n; i++)
    {
        if(at[i] <= time && bt[i] != 0)
        {
            insert(q,&f,&r,Pid[i]);
        }
    }
    while(1)
    {
        pid = q[f];
        for(i=0; i<n; i++)
        {
            if(pid == Pid[i])
            {
                if(bt[i] > tq)
                {
                    if(fo[i] != 1)
                    {
                        rt[i] = time - at[i];
                        fo[i] = 1;
                    }
                    bt[i] -= tq;
                    b = bt[i];
                    time += tq;
                }
                else
                {
                    if(fo[i] != 1)
                    {
                        rt[i] = time - at[i];
                        fo[i] = 1;
                    }
                    time += bt[i];
                    bt[i] = 0;
                    b = bt[i];
                    for(int j=0; j<n; j++)
                    {
                        if(pid == Pid[j])
                        {
                            ct[j] = time;
                        }
                    }
                }
            }
        }

        for(i=0; i<n; i++)
        {
            if(at[i] <= time && bt[i] != 0)
            {
                flag = 0;
                for(int j=f; j<=r; j++)
                {
                    if(Pid[i] == q[j])
                        flag = 1;
                }
                if(flag == 0)
                    insert(q,&f,&r,Pid[i]);
            }
        }

        if(b != 0)
            insert(q,&f,&r,q[f]);
        f++;
        complete = 0;
        for(i=0; i<n; i++)
        {
            if(bt[i] != 0)
                complete = 1;
        }
        if(complete == 0)
            break;
    }
    for(i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - btc[i];
    }
    f=0;
    cout<<"Displaying Queue"<<endl;
    display(q,&f,&r);
    cout<<endl;
    cout<<endl<<"Pid\tAT\tBT\tCT\tTAT\tWT\tRT"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<Pid[i]<<"\t"<<at[i]<<"\t"<<btc[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\t"<<rt[i]<<endl;
    }
    cout<<endl<<"Average Turn Around Time = "<<calculate_average(tat,n);
    cout<<endl<<"Waiting Time = "<<calculate_average(wt,n)<<endl;
    th = (float)n/(float)ct[n-1];
    cout<<"Throughput = "<<th<<endl;
    return 0;
}
