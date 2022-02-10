export module box.random;

import box;
import <random>;
import <functional>;
import <memory>;

auto create_from_uniform_pseudo_random_number_generator(double max)
{
	std::random_device seeder;
	std::default_random_engine generator{ seeder()};
	std::uniform_real_distribution distribution{ 0.0, max };
	return std::bind(distribution, generator);
}

export Box random_box()
{
	const int dim_limit{ 100 };
	static auto random{ create_from_uniform_pseudo_random_number_generator(dim_limit) };
	return Box{ random(), random(), random() };
}

export auto random_shared_box()
{
	return std::make_shared<Box>(random_box());
}