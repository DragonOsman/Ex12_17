export module truckload:package;
import :shared_box;

class Package
{
public:
	Package(SharedBox box) : m_box{ box }, m_next{ nullptr } {}
	~Package() { delete m_next; }

	SharedBox get_box() const { return m_box; }

	Package* get_next() { return m_next; }
	void set_next(Package* package) { m_next = package; }

private:
	SharedBox m_box;
	Package* m_next;
};