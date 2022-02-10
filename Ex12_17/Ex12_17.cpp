// Osman Zakir
// 2 / 10 / 2022
// Beginning C++20: From Novice to Professional by Ivor Horton and Peter Van Weert
// Chapter 12 Example Code 17
// Using a linked list

import <iostream>;
import box.random;
import truckload;

int main()
{
	Truckload load1;

	const std::size_t box_count{ 12 };
	for (std::size_t i{}; i < box_count; ++i)
	{
		load1.add_box(random_shared_box());
	}

}