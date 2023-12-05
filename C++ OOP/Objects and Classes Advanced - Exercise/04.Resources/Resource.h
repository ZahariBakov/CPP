#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <iostream>

#include "ResourceType.h"

namespace SoftUni {
	class Resource {
	public:

		ResourceType getType() const {
			return _type;
		}

		bool operator<(const Resource& other) const {
			return _id < other._id;
		}

		friend std::istream& operator>> (std::istream& in, Resource& resource);
		friend std::ostream& operator<< (std::ostream& out, const Resource& resource);

	private:
		int _id = 0;
		ResourceType _type;
		std::string _link;
	};

	std::istream& operator>> (std::istream& in, Resource& resource) {
		std::string typeStr;
		in >> resource._id >> typeStr >> resource._link;

		if (typeStr == "Presentation") {
			resource._type = PRESENTATION;
		}
		else if (typeStr == "Demo") {
			resource._type = DEMO;
		}
		else if (typeStr == "Video") {
			resource._type = VIDEO;
		}
		else {
			std::cerr << "Received unsupported type: " << typeStr << std::endl;
		}

		return in;
	}

	std::ostream& operator<< (std::ostream& out, const Resource& resource) {
		out << resource._id << " " << resource._type << " " << resource._link;
		
		return out;
	}
}

#endif // !RESOURCE_H