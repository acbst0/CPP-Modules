#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_name = "No-name";
	this->hitPt = 100;
	this->energyPt = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap default constructor called!" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->hitPt = 100;
	this->energyPt = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructor called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref)
{
	std::cout << "FragTrap copy constructor called!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " has been destroyed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->_name = other._name;
	this->hitPt = other.hitPt;
	this->energyPt = other.energyPt;
	this->attackDamage = other.attackDamage;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": Let's high five?\n\t*OOOOLEYY*" << std::endl;
}