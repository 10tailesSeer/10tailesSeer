//34567890123456789012345678901234567890123456789!123456789012345678901234!
//the above describes an optimum line length not hurting its readibility
export module truckload;

import std;
import box;

export class Truckload {
public:
	Truckload() = default;
	explicit Truckload(std::span<const box::Box> span):Boxes{ span } {}
	std::ostream& print(std::ostream&)const;
	void print()const;
private:
	std::span<const box::Box> Boxes;
};

std::ostream& operator<<(std::ostream&, const Truckload&);
