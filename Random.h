#ifndef RANDOM
#define RANDOM

#include <chrono>
#include <random>

namespace random
{
	inline std::mt19937 generate()
	{
		std::random_device rd;

		std::seed_seq ss
		{
			static_cast<std::seed_seq::result_type>(
				std::chrono::high_resolution_clock::now().time_since_epoch().count()),
			static_cast<std::seed_seq::result_type>(
				std::chrono::steady_clock::now().time_since_epoch().count()),
			static_cast<std::seed_seq::result_type>(
				std::chrono::system_clock::now().time_since_epoch_epoch().count()),


		}

	}


}



#endif
