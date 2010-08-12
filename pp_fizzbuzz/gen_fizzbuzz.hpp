#ifndef gen_fizzbuzz_h__
#define gen_fizzbuzz_h__
// gen_fizzbuzz
// Abuses the preprocessor to print fizzbuzz solution at compile time

#include <boost/preprocessor.hpp>

#if !defined(GEN_FIZZBUZZ_RANGE_LOW) || !defined(GEN_FIZZBUZZ_RANGE_HIGH)
#error "must define a valid GEN_FIZZBUZZ_RANGE_LOW and GEN_FIZZBUZZ_RANGE_HIGH before including gen_fizzbuzz"
#endif
#define BOOST_PP_ITERATION_LIMITS (GEN_FIZZBUZZ_RANGE_LOW, GEN_FIZZBUZZ_RANGE_HIGH)
#define BOOST_PP_FILENAME_1       "gen_fizzbuzz_pp_iter.h" // this file

// loop and print
#include BOOST_PP_ITERATE()


#undef GEN_FIZZBUZZ_RANGE_LOW
#undef GEN_FIZZBUZZ_RANGE_HIGH

#endif // gen_fizzbuzz_h__
