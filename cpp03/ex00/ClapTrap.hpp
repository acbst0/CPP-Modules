#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string _name;
	unsigned int hitPt;
	unsigned int energyPt;
	unsigned int attackDamage;
public:
	ClapTrap(std::string& name);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif