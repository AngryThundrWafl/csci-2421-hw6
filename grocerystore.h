//
// Created by Brian on 3/7/2016.
//

#ifndef PINAHW6_GROCERYSTORE_H
#define PINAHW6_GROCERYSTORE_H
#include <cstdlib>      //to use std::size_t

namespace HW6 {
    class bool_source {
    public:
        bool_source(double p = 0.5 );                      //Constructor
        bool query() const;                        //Constant Member Function
    private:
        double probability;                         //probability of query returning true value
    };

    class averager {
    public:
        averager();                                  //Constructor
        void next_number(double value);              //modification member function
        std::size_t how_many_numbers() const;        //returns the value of count
        double average() const;

    private:
        std::size_t count;                          //how many numbers have been given to the averager
        double sum;                                 //sum of all the numbers given to the averager
    };

    class cashier {
    public:
        cashier();                    //constructor S is value needed for one cashier to finishing one cycle
        int getRing();
        void one_second();                          //modeification member functions
        void next_customer();

        bool is_busy() const;                       //returns next_customer > 0
    private:
        unsigned int seconds_for_cashier;           //seconds for a single customer being rung
        unsigned int cashier_time_left;             //seconds until cashier isn't busy
    };
}
#endif //PINAHW6_GROCERYSTORE_H
