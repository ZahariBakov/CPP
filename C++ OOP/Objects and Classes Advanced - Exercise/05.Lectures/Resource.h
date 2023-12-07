#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <ostream>
#include <istream>

#include "ResourceType.h"

namespace SoftUni {
	class Resource {
	public:
		Resource() {}

		Resource(int id, ResourceType type, std::string link)
			: _id(id), _type(type), _link(link) {}

		int getId() const {
			return this->_id;
		}

		ResourceType getType() const {
			return this->_type;
		}

		std::string getLink() const {
			return this->_link;
		}

		bool operator<(const Resource& other) const {
			return this->_id < other._id;
		}

	private:
		int _id = 0;
		ResourceType _type;
		std::string _link;
	};

	std::ostream& operator<<(std::ostream& out, const Resource& r) {
		return out << r.getId() << " " << r.getType() << " " << r.getLink();
	}

	std::istream& operator>>(std::istream& in, Resource& r) {
		int id;
		std::string typeString;
		std::string link;

		in >> id >> typeString >> link;

		ResourceType type;
		if (typeString == "Presentation") {
			type = ResourceType::PRESENTATION;
		}
		else if (typeString == "Demo") {
			type = ResourceType::DEMO;
		}
		else if (typeString == "Video") {
			type = ResourceType::VIDEO;
		}

		r = Resource(id, type, link);

		return in;
	}

}

#endif // !RESOURCE_H
