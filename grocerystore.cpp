//
// Created by Brian on 3/7/2016.
//
#include <cassert>                  //so that we can use assert
#include <cstdlib>
#include <iostream>
#include "grocerystore.h"




namespace HW6 {
    bool_source::bool_source(double p) {
        assert(p >= 0);
        assert(p <= 1);
        probability = p;
    }

    bool bool_source::query() const {
        return (rand() < probability * RAND_MAX);
    }

    averager::averager() {
        count = 0;
        sum = 0;
    }

    void averager::next_number(double value) {
        ++count;
        sum += value;
    }

    double averager::average() const {
       assert(how_many_numbers() > 0);
        return sum / count;
    }

    cashier::cashier() {
        unsigned int s = rand() %100 +1;
        seconds_for_cashier = s;
        cashier_time_left = 0;
    }

    void cashier::one_second() {
        if (is_busy())
            --cashier_time_left;
    }

    void cashier::next_customer() {
        assert(!is_busy());
        cashier_time_left = seconds_for_cashier;
    }

    bool cashier::is_busy() const {
        return (cashier_time_left > 0);
    }

    std::size_t averager::how_many_numbers() const {
        return count;
    }

    int cashier::getRing() {
        return seconds_for_cashier;
    }

}
