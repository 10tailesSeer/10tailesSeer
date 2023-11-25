//34567890123456789012345678901234567890123456789!123456789012345678901234!
//the line above describes an optimal line length not hurting
module box;

namespace box {
	Box::Box()noexcept {
		++Counter;
	}

	Box::Box(double length, double width, double height) noexcept
		:Length{ std::max({length, width, height}) },
		Height{ std::min({length, width, height}) },
		Width{ length + width + height - Length - Height } {
		++Counter;
	}

	Box::Box(double side) noexcept:Box(side, side, side) {}

	Box::Box(const Box& box) noexcept
		:Length{ box.Length }, Width{ box.Width }, Height{ box.Height } {
		++Counter;
	}

	Box& Box::operator=(const Box& source) noexcept {
		Box copy{ source };
		std::swap(*this, copy);
		return *this;
	}

	Box::Box(Box&& box) noexcept
		:Length{ box.Length }, Width{ box.Width }, Height{ box.Height } {
		++Counter;
	}

	Box& Box::operator=(Box&& source) noexcept {
		Box copy{ std::move(source) };
		std::swap(*this, copy);
		return *this;
	}

	Box::~Box()noexcept {
		--Counter;
	}

	double Box::volume()const noexcept {
		return this ? Length * Width * Height : 0.0;
	}

	std::partial_ordering Box::operator<=>(const Box& abox)const noexcept {
		return this->volume() <=> abox.volume();
	}

	std::partial_ordering Box::operator<=>(const double& volume)const noexcept {
		return this->volume() <=> volume;
	}

	bool Box::operator==(const double& volume) const noexcept {
		return this->volume() == volume;
	}

	Box::operator bool()const noexcept {
		return volume() != 0;
	}

	std::ostream& operator<<(std::ostream& stream, const Box& box) {
		stream << box.volume();
		return stream;
	}
}