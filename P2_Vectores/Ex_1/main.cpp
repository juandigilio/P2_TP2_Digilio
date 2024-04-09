#include "String.h"




void main()
{
	String myString("Hola, yo soy un string");
	String otherString("y yo me vengo a sumar");

	String sum = myString + otherString;
	//sum.Print();

	String charSum = myString + "y yo tambien me quiero sumar";
	//charSum.Print();

	//myString += otherString;
	myString += "y yo otro que se suma en fomra de array de chars";
	//myString.Print();

	String smaller("abc");
	String bigger("def");

	std::cout << (smaller < bigger);
	std::cout << std::endl;
	std::cout << (smaller > bigger);

	std::cin.get();
}