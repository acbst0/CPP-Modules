#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& ref);
		virtual ~FragTrap();
		FragTrap& operator=(const FragTrap& other);
		void highFivesGuys(void);
};

#endif