#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	std::string _name;
	unsigned int hitPt;
	unsigned int energyPt;
	unsigned int attackDamage;
public:
	void highFivesGuys(void);
};

#endif