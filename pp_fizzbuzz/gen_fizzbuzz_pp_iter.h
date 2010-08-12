
// this block is repeatedly included by gen_fizzbuzz
#define n BOOST_PP_ITERATION()
#if n%5==0 && n%3==0
#pragma message("fizzbuzz")
#elif n%3==0
#pragma message("fizz")
#elif n%5==0
#pragma message("buzz")
#else
#pragma message( BOOST_PP_STRINGIZE(n) )
#endif
