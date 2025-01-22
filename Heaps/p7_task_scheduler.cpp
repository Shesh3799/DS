#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. 
Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

Example:
Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, 
so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Link: https://leetcode.com/problems/task-scheduler/description/

*/


int leastInterval(vector<char>& tasks, int n) {
    int map[256]={0};
    for(int i=0;i<tasks.size(); i++){
        map[tasks[i]]++;
    }
    //Use priority queue to schedule most frequent task first
    priority_queue<int> pq;
    for(int i=0;i<256;i++){
        if(map[i]>0){
            pq.push(map[i]);
        }
    }
    
    int time = 0;

    while(pq.empty()==false){
        //We will schedule all the task from priority queue in the order of most frequent task first followed by next frequent and so on.
        //Once we schedule this task we remove that task from queue and will wait for current cycle to end and add back to queue if required.
        vector<int> remaining_tasks;
        //In one cycle we try to schedule all diff tasks and after schedling all taks if we still left with some time then it is considered as idle time
        //We add idle time directly to out time as we can't schedule any other task
        int cycle = n+1;
        while(cycle && pq.empty()==false){
            int max_freq=pq.top();
            pq.pop();
            //If the freq is 1 then it means after scheduling the task is done so don't add it to remaining jobs
            if(max_freq>1){
                remaining_tasks.push_back(max_freq-1);
            }
            ++time;
            --cycle;
        }
        //Add remaining task back to priority queue
        for(int count : remaining_tasks){
            pq.push(count);
        }
        if(pq.empty()==true) break;
        time+=cycle;
    }
    return time;      
}

int main() {
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    //Expected output is 8
    cout<<leastInterval(tasks, n)<<endl;


    return 0;
}