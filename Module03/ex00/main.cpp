<<<<<<< HEAD
#include "Fixed.hpp"

int	main()
{
	
=======
#include "ClapTrap.hpp"

int	main()
{
	ClapTrap A("first");
	ClapTrap B("second");

	A.attack(B.GetName());
	B.takeDamage(A.GetAD());
>>>>>>> c88813b833d07bf48c85be3b9aa8a7a075733bf3
	return (0);
}
