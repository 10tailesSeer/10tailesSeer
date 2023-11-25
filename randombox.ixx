//34567890123456789012345678901234567890123456789!123456789012345678901234!
//the above describes an optimum line length not hurting its readibility
export module randombox;

import std;

export import box;

namespace box {
	auto prng(const double& min, const double& max) {
		std::random_device seeder; // True random number generator to obtain a seed (slow)
		std::default_random_engine generator{ seeder() }; // Efficient pseudo-random generator
		std::uniform_real_distribution distribution{ min, max }; // Generate in [0, max) interval
		return std::bind(distribution, generator); //... and in the darkness bind them!
	}

	export auto randomBox(const double& min = 0.0, const double& max = 10000000.0) {
		auto random{ prng(min, max) };
		return Box{ random(), random(), random() };
	}
}