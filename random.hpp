#ifndef __RANDOM_HPP__
#define __RANDOM_HPP__

#include<chrono>
#include<random>

class Random{
	private:
		std::default_random_engine generator;
		std::uniform_int_distribution<int> int_dist;
	public:
		Random(){
			unsigned seed = std::chrono::system_clock::now().time_since_epoch().cont();
			std::default_random_engine g (seed);
		}
};

#endif
