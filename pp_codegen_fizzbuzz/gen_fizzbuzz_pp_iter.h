
// this block is repeatedly included by gen_fizzbuzz
// emit the appropriate line for the current n.
#define n BOOST_PP_ITERATION()
#if n%5==0 && n%3==0
printf("fizzbuzz\n");
#elif n%3==0
printf("fizz\n");
#elif n%5==0
printf("buzz\n");
#else
printf("%d\n", n);
#endif
