//34567890123456789012345678901234567890123456789!123456789012345678901234!
//the above describes an optimum line length not hurting its readibility
//module;
//#include <gsl/gsl>
export module boiler;

export import boiler.acronyms;
import :internals;

export namespace plate {
	enum class Comparison: signed char {
		equal = 0,
		equivalent = equal,
		less = -1,
		greater = 1,
		unordered = -128
	};
	extern string_view defaultPath;

	template <range::forward_range R, class Projector = std::identity>
	void printer(std::ostream& ostream, R const range, Projector projector = {}) {
		unsigned char j{ 5 };
		for (auto [element, index] : zip(range | transform(projector),
													iota(1))) {
			print(ostream, "{:05}. {:7}, ", index, element);
			--j;
			if (j == 0) {
				ostream << endl;
				j = 5;
			}
		}
		if (j != 5) println(ostream, "\b.");
	}
	template <range::forward_range R, class Projector = std::identity>
	void printer(R const range, Projector projector = {}) {
		printer(std::cout, range, projector);
	}

	template <class T> requires std::floating_point<T>
	auto random(T const&& min = std::numeric_limits<T>::min(),
					  T const&& max = std::numeric_limits<T>::max()) {
		std::random_device seeder;
		std::default_random_engine generator{ seeder() };
		return std::bind(std::uniform_real_distribution{ min, max }, generator);
	}
	template <class T> requires std::integral<T>
	auto random(T const&& min = std::numeric_limits<T>::min(),
					  T const&& max = std::numeric_limits<T>::max()) {
		std::random_device seeder;
		std::default_random_engine generator{ seeder() };
		return std::bind(std::uniform_int_distribution{ min, max }, generator);
	}

	class Pest;
	class Tormentor;
}

module : private;
string_view plate::defaultPath{ R"(C:\Users\adama\Documents\bin\)"sv };