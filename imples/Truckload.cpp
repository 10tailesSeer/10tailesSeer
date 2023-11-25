//34567890123456789012345678901234567890123456789!123456789012345678901234!
//the above describes an optimum line length not hurting its readibility
module truckload;

std::ostream& Truckload::print(std::ostream& stream)const {
	size_t i{}, j{};
	for (auto box : Boxes) {
		stream << std::format("Box{:04}: {:7} | ",
			i, box.volume());
		j = ++i % 5;
		if (j == 0) stream << std::endl;
	}
	if (j != 0) stream << std::endl;
	return stream;
}
void Truckload::print()const {
	size_t i{}, j{};
	for (auto box : Boxes) {
		std::cout << std::format("Box{:04}: {:7e} | ",
			i, box.volume());
		j = ++i % 5;
		if (j == 0) std::cout << std::endl;
	}
	if (j != 0) std::cout << std::endl;
}
//std::ostream& operator<<(std::ostream& stream, const Truckload& truck)
//	{
//		return truck.print(stream);
//	}