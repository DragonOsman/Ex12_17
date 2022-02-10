module truckload;
import :package;
import <iostream>;

void Truckload::list_boxes() const
{
	const std::size_t box_perline{ 4 };
	std::size_t count{};
	for (Package* package{ m_head }; package; package = package->get_next())
	{
		std::cout << ' ';
		package->get_box()->list_box();
		if (!(++count % boxes_perline))
		{
			std::cout << std::endl;
		}
	}
	if (count % boxes_perline)
	{
		std::cout << std::endl;
	}
}

SharedBox Truckload::get_first_box()
{
	m_current = m_head;
	return m_current ? m_current->get_box() : nullptr;
}

SharedBox Truckload::get_next_box()
{
	if (!m_current)
	{
		return get_first_box();
	}

	m_current = m_current->get_next();

	return m_current ? m_current->get_box() : nullptr;
}

Truckload::Truckload(const std::vector<SharedBox>& boxes)
{
	for (const auto& box : boxes)
	{
		add_box(box);
	}
}

Truckload::Truckload(const Truckload& src)
{
	for (Package* package{ src.m_head }; package; package = package->get_next())
	{
		addbox(package->get_box());
	}
}

void Truckload::add_box(SharedBox box)
{
	auto package{ new Package{box} };
	if (m_tail)
	{
		m_tail->set_next(package);
	}
	else
	{
		m_head = package;
	}

	m_tail = package;
}

bool Truckload::remove_box(SharedBox box_to_remove)
{
	Package* previous{ nullptr };
	Package* current{ m_head };
	while (current)
	{
		if (current->get_box() == box_to_remove)
		{
			if (previous)
			{
				previous->set_next(current->get_next());
			}
			
			if (current == m_head)
			{
				m_head = current->get_next();
			}
			if (current == m_tail)
			{
				m_tail = previous;
			}
			if (current == m_current)
			{
				m_current = m_current->get_next();
			}

			current->set_next(nullptr);
			delete current;

			return true;
		}
		previous = current;
		current = current->get_next();
	}
	return false;
}