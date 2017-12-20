#include <iostream>
#include <vector>
#include <queue>
#include "grocerystore.h"


using namespace std;
using namespace HW6;

int findSmallest(vector<queue<unsigned int> > &);



int main() {


    cout << "Hello this is a grocery store simulation program" << endl;
    double arrival_prob;
    unsigned int total_time;
    vector<queue <unsigned int> > arrival_times(5);                //queues that holds time stamps of waiting customers
/////THE TWO INPUTS FROM THE USER//////////////////////////////////////////////////////////////////////////////////////
    cout << "Please enter the probablity of a customer from 1 - 100%, 100% being 1 and under 100  ex: .67" << endl;
    cin >> arrival_prob;

    cout << "Please enter the amount of time you want the simulation happen for" << endl;
    cin >>  total_time;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned int next;                                      //value taken from queue
    bool_source arrival(arrival_prob);
    cashier machine;
    averager wait_times;
    unsigned  int current_second;

    //writes the parameters out
    cout << "Seconds to ring one customer: " << machine.getRing()  << endl;
    cout << "Probability of customer arrival: " << arrival_prob << endl;
    cout << "Total simulation seconds: " << total_time << endl;


    for(current_second = 1; current_second <= total_time; ++current_second){
        //simulates the passage of one second per iteration
        //checks if a new customer has arrived
        if (arrival.query()) {
            //will generate a random ring time for new customer
            //finds the smallest line or if their all equal
            int smallestLine = findSmallest(arrival_times);
            if (smallestLine == 1)
                arrival_times[smallestLine-1].push(current_second);
            else if(smallestLine == 2)
                arrival_times[smallestLine-1].push(current_second);
            else if(smallestLine ==3)
                arrival_times[smallestLine-1].push(current_second);
            else if(smallestLine ==4)
                arrival_times[smallestLine-1].push(current_second);
            else if (smallestLine ==5)
                arrival_times[smallestLine-1].push(current_second);

        }
       if ((!machine.is_busy()) && (!arrival_times.empty())) {
           int smallestLine = findSmallest(arrival_times);
           next = arrival_times[smallestLine-1].front();
           arrival_times[smallestLine-1].pop();
           cout << "next: " << next << endl;
           cout << "current second " << current_second << endl;
           wait_times.next_number(current_second - next);
           machine.next_customer();
       }

        //tells the program to simulate the passage of time
        machine.one_second();
    }
    //summary of the simulation
    cout << "Total customers served: " << wait_times.how_many_numbers() << endl;
    if(wait_times.how_many_numbers() > 0)
        cout << "Average wait:" << wait_times.average() << " Sec" << endl;


    return 0;
}

int findSmallest(vector<queue<unsigned int> > &store){

    int first = store[0].size(),second = store[1].size(), third = store[2].size(), fourth = store[3].size(), fifth = store[4].size();
    if(first != 0 && second != 0 && third !=0 && fourth != 0 && fifth != 0) {
          //will the size of the line in a array
          int sizeLine[4];
          for (int i = 0; i < 4; i++) {
              if (i == 0)
                  sizeLine[i] = first;
              else if (i == 1)
                  sizeLine[i] = second;
              else if (i == 2)
                  sizeLine[i] = third;
              else if (i == 3)
                  sizeLine[i] = fourth;
              else if (i == 4)
                  sizeLine[i] = fifth;
          }

          //sorts the array
          for (int i = 0; i < 4; i++) {
              if (sizeLine[i] > sizeLine[i + 1]) {
                  int temp = sizeLine[i];
                  sizeLine[i] = sizeLine[i + 1];
                  sizeLine[i + 1] = temp;
              }

          }

          //if all the lines have the same amount of customers
          if (first == second && second == third && third == fourth && fourth == fifth) {
              return 1;
          }
          else {
              //smallest element is in the front so now we will find which variable is the smallest
              if (sizeLine[0] == first)
                  return 1;
              else if (sizeLine[0] == second)
                  return 2;
              else if (sizeLine[0] == third)
                  return 3;
              else if (sizeLine[0] == fourth)
                  return 4;
              else if (sizeLine[0] == fifth)
                  return 5;
          }
    }else
        return 1;

}



