export module truckload;

export import :shared_box;
import :package;
import <vector>;

export class Truckload
{
public:
	Truckload() = default;

	Truckload(SharedBox box) { m_head = m_tail = new Package{ box }; }
	Truckload(const std::vector<SharedBox>& boxes);
	Truckload(const Truckload& src);

	~Truckload() { delete m_head; }

	SharedBox get_first_box();
	SharedBox get_next_box();
	void add_box(SharedBox box);
	bool remove_box(SharedBox box);
	void list_boxes() const;

private:
	Package* m_head{};
	Package* m_tail{};
	Package* m_current{};
};