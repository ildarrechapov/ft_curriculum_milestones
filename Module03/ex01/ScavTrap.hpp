#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(const ScavTrap &S);
	ScavTrap& operator=(const ScavTrap &S);
	void attack(const std::string &target);
};
