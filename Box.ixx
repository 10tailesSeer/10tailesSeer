//34567890123456789012345678901234567890123456789!123456789012345678901234!
//the above describes an optimum line length not hurting its readibility
export module box;

import std;

export namespace box {
	class Box {
	public:
		Box()noexcept;
		Box(double, double, double) noexcept;
		explicit Box(double)noexcept;
		Box(const Box&)noexcept;
		Box& operator=(const Box&)noexcept;
		Box(Box&&)noexcept;
		Box& operator=(Box&&)noexcept;
		~Box()noexcept;
		double volume()const noexcept;
		std::partial_ordering operator<=>(const Box&)const noexcept;
		std::partial_ordering operator<=>(const double&)const noexcept;
		bool operator==(const Box&)const = default;
		bool operator==(const double&)const noexcept;
		explicit operator bool()const noexcept;
		static inline size_t Counter{};
	private:
		double Length{ 1.0 };
		double Height{ 1.0 };
		double Width{ 1.0 };
	};
	std::ostream& operator<<(std::ostream&, const Box&);
}