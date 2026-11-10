#ifndef RANDOM
#define RANDOM

#include <chrono>
#include <random>

// namepsace used for random number generation
namespace random
{

	// inline (for ODR collisions) std:mt19937 -> (class/type) generate -> (function name)
	inline std::mt19937 generate()
	{

		// class/object |  object/variable | rd object is a functor
		std::random_device rd;

		std::seed_seq ss {
			// Three different clocks used to seed the mersenne twister
			static_cast<std::seed_seq::result_type>(
				std::chrono::high_resolution_clock::now().time_since_epoch().count()),
			static_cast<std::seed_seq::result_type>(
				std::chrono::steady_clock::now().time_since_epoch().count()),
			static_cast<std::seed_seq::result_type>(
				std::chrono::system_clock::now().time_since_epoch().count()),

				// A dozen rd vals from random_device
				rd(), rd(), rd(), rd(),
				rd(), rd(), rd(), rd(),
				rd(), rd(), rd(), rd()


		};
		// create temporary object of type std::mt19937 and return it to the caller
		return std::mt19937{ ss };
	}

	// The single global engine used by everything in this header. This is a definition.
	// 'inline' lets us define it in a header without linker errors.
	inline std::mt19937 mt{ generate() };

	// ---------------------------------------------------------------
	// Integer uniform in the closed range [min, max]
	// ---------------------------------------------------------------

	template <typename T>
	T get(T min, T max)
	{
		return std::uniform_int_distribution<T>{min, max}(mt);
	}

	template <typename R, typename S, typename T>
	R get(S min, T max)
	{
		return get<R>(static_cast<R>(min), static_cast<R>(max));
	}

	inline int get(int min, int max)
	{
		return get<int>(min, max);
	}

}



#endif
