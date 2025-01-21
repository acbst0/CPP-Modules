#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPt(10), energyPt(10), attackDamage(0)
{
	this->_name = "No-name";
	std::cout << "ClapTrap has been created with default!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), hitPt(10), energyPt(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap " << this->_name << " has been created with copy consturctor!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assigment operator has been called!" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->hitPt = other.hitPt;
		this->energyPt = other.energyPt;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPt == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is like dead. It can't attack!" << std::endl;
	}
	else if (this->energyPt > 0)
	{
		if (this->attackDamage > 0)
		{
			std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
			this->energyPt--;
		}
		else
		{
			std::cout << "ClapTrap " << this->_name << " could not damage " << target << " because of it has no attack damage!" << std::endl;
		}
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has no energy for attacking to " << target << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPt > amount)
		this->hitPt -= amount;
	else if (this->hitPt > 0)
		this->hitPt = 0;
	else
	{
		std::cout << "ClapTrap " << this->_name << " is already dead, stop beating it!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " was attacked and lost " << amount << " hit points, he now has " << this->hitPt << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPt == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is like dead. It can't repair it self! Too late" << std::endl;
	}
	else if (this->hitPt + amount > 10)
	{
		std::cout << "ClapTrap " << this->_name << " can't has more than 10 point!" << std::endl;
	}
	else if (this->energyPt > 0)
	{
		this->hitPt += amount;
		std::cout << "ClapTrap " << this->_name << " gets hit point back in the amount of " << amount << std::endl;
		this->energyPt--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has no energy for repairing!" << std::endl;
	}
}