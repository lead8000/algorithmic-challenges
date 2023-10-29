#include "solution.h"

int Solution::poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    return ceil(log2(buckets)/log2(int(minutesToTest/minutesToDie)+1));
}