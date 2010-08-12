#ifndef gen_fizzbuzz_h__
#define gen_fizzbuzz_h__
// gen_fizzbuzz
// Abuses the preprocessor as a code generator for the fizzbuzz problem.
// I laughed at Enterprise Fizzbuzz and decided to do so some other ridiculous fizzbuzz implementations
//
// Some neat things:
//  * you can debug it. Its hard to follow, but debuggers do a decent job of stepping through the generated function.
//  * works with C89. The technique only uses plain old preprocessor.
//  * no external tools needed for code generation. 
//    Of course in reality you would almost certainly want to use a code generator. 
//    I like string template (and antlr)
//
// The following generates the function fizzbuzz_1_to_100()
// #define GEN_FIZZBUZZ_RANGE_LOW 1
// #define GEN_FIZZBUZZ_RANGE_HIGH 100
// #include "gen_fizzbuzz.hpp"
// To generate more than a single func you will need a seperate compilation unit per fizzbuzz "instantiation"
// 

#include <boost/preprocessor.hpp>

#if !defined(GEN_FIZZBUZZ_RANGE_LOW) || !defined(GEN_FIZZBUZZ_RANGE_HIGH)
#error "must define a valid GEN_FIZZBUZZ_RANGE_LOW and GEN_FIZZBUZZ_RANGE_HIGH before including gen_fizzbuzz"
#endif
#define BOOST_PP_ITERATION_LIMITS (GEN_FIZZBUZZ_RANGE_LOW, GEN_FIZZBUZZ_RANGE_HIGH)
#define BOOST_PP_FILENAME_1       "gen_fizzbuzz_pp_iter.h" // this file

void 
// generate our function name. eg fizzbuzz_1_to_100
BOOST_PP_CAT(fizzbuzz_,BOOST_PP_CAT(GEN_FIZZBUZZ_RANGE_LOW,BOOST_PP_CAT(_to_,GEN_FIZZBUZZ_RANGE_HIGH)))
()
{
	// generate our function body
	#include BOOST_PP_ITERATE()
}
#undef GEN_FIZZBUZZ_RANGE_LOW
#undef GEN_FIZZBUZZ_RANGE_HIGH

#endif // gen_fizzbuzz_h__
