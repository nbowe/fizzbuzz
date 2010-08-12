// template metaprogramming implementation.
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/for_each.hpp>
#include <stdio.h>

// Our metafunction.
// contains partial specializations for each rule of fizzbuzz.
// kinda like pattern matching in functional programming languages.
// (C++ templates are a unique form of functional programming)
struct value_printer
{
	template<int n, bool div3, bool div5> struct printer;
	template<int n> struct printer<n, false,false> 	{void operator()() { printf("%d\n",n);}};
	template<int n> struct printer<n, true,false> 	{void operator()() { printf("fizz\n");}};
	template<int n> struct printer<n, false,true> 	{void operator()() { printf("buzz\n");}};
	template<int n> struct printer<n, true,true> 	{void operator()() { printf("fizzbuzz\n");}};

	template< int N > void operator()( boost::mpl::integral_c<int,N> )
	{
		printer<N, N%3==0, N%5==0>()();
	}
};

template <int N, int M> 
inline void fizzbuzz()
{
	boost::mpl::for_each< boost::mpl::range_c<int,N,M+1> >( value_printer() );
}

int main()
{
	fizzbuzz<1,100>();
	return 0;
}