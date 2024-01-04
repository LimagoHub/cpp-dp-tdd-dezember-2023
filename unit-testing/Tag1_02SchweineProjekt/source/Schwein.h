#pragma once
#include <ostream>
#include <string>
#include <stdexcept>

class Schwein
{
	std::string name;
	int gewicht;

	void set_gewicht(const int gewicht)
	{
		this->gewicht = gewicht;
	}

public:
	Schwein(const std::string& name = "nobody")
		: gewicht(10)
	{
		set_name(name);
	}
	void fuettern();
	
	void set_name(const std::string& name)
	{
		if (name == "Elsa")
			throw std::invalid_argument("name nicht erlaubt");
		this->name = name;
	}

	// Generated
	[[nodiscard]] std::string get_name() const
	{
		return name;
	}
	[[nodiscard]] int get_gewicht() const
	{
		return gewicht;
	}
	friend bool operator==(const Schwein& lhs, const Schwein& rhs)
	{
		return lhs.name == rhs.name
			&& lhs.gewicht == rhs.gewicht;
	}
	friend bool operator!=(const Schwein& lhs, const Schwein& rhs)
	{
		return !(lhs == rhs);
	}
	friend std::ostream& operator<<(std::ostream& os, const Schwein& obj)
	{
		return os
			<< "name: " << obj.name
			<< " gewicht: " << obj.gewicht;
	}
};


