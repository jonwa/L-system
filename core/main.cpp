#include <iostream>
#include <string>
#include <tuple>

#include "lsystem.h"
#include "turtle.h"

const std::vector<line>& fractal_plant(int iterations, double angle) 
{
	lsystem<char, std::string> sys("X");
	sys.add_rule('X', "F-[[X]+X]+F[+FX]-X");
	sys.add_rule('F', "FF");
	auto& seq = sys.iterate(iterations);

	turtle<char, std::string> t(seq, angle);
	t.add_command('F', [&t]() { t.forward(2.0, true); });
	t.add_command('-', [&t]() { t.rotate(-25.0); });
	t.add_command('+', [&t]() { t.rotate(25.0); });
	t.add_command('[', [&t]() { t.push(); });
	t.add_command(']', [&t]() { t.pop(); });
	auto& result = t.interpret();

	return result;
}

const std::vector<line>& fractal_binary_tree(int iterations, double angle) 
{
	lsystem<char, std::string> sys("0");
	sys.add_rule('1', "11");
	sys.add_rule('0', "1[0]0");
	auto& seq = sys.iterate(iterations);

	turtle<char, std::string> t(seq, angle);
	t.add_command('0', [&t]() { t.forward(1.0, true); });
	t.add_command('1', [&t]() { t.forward(3.0, true); });
	t.add_command('[', [&t]() 
	{ 
		t.push(); 
		t.rotate(-45.0);
	});
	t.add_command(']', [&t]() 
	{ 
		t.pop(); 
		t.rotate(45.0);
	});
	auto& result = t.interpret();

	return result;	
}

const std::vector<line>& koch_curve(int iterations, double angle) 
{
	lsystem<char, std::string> sys("F");
	sys.add_rule('F', "F+F-F-F+F");
	auto& seq = sys.iterate(iterations);

	turtle<char, std::string> t(seq, angle);
	t.add_command('F', [&t]() { t.forward(3.0, true); });
	t.add_command('-', [&t]() { t.rotate(90.0); });
	t.add_command('+', [&t]() { t.rotate(-90.0); });
	auto& result = t.interpret();

	return result;	
}

const std::vector<line>& sierpinski_triangle(int iterations, double angle) 
{
	lsystem<char, std::string> sys("F-G-G");
	sys.add_rule('F', "F-G+F+G-F");
	sys.add_rule('G', "GG");
	auto& seq = sys.iterate(iterations);

	turtle<char, std::string> t(seq, angle);
	t.add_command('F', [&t]() { t.forward(5.0, true); });
	t.add_command('G', [&t]() { t.rotate(-25.0); });
	t.add_command('+', [&t]() { t.rotate(-120.0); });
	t.add_command('-', [&t]() { t.rotate(120.0); });
	auto& result = t.interpret();

	return result;
}

const std::vector<line>& dragon_curve(int iterations, double angle) 
{
	lsystem<char, std::string> sys("F");
	sys.add_rule('F', "F+G");
	sys.add_rule('G', "F-G");
	auto& seq = sys.iterate(iterations);

	turtle<char, std::string> t(seq, angle);
	t.add_command('F', [&t]() { t.forward(5.0, true); });
	t.add_command('G', [&t]() { t.forward(5.0, true); });
	t.add_command('+', [&t]() { t.rotate(-90.0); });
	t.add_command('-', [&t]() { t.rotate(90.0); });
	auto& result = t.interpret();

	return result;
}

int main()
{
	auto& result = koch_curve(2, 0);
	std::cout << result.size() << std::endl;
	return 0;
}