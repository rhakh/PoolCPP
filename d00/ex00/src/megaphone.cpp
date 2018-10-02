#include <iostream>
#include <string>

int		main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else {
		for (int i = 1; i < argc; i++) {
			std::string s(argv[i]);

			for (size_t i = 0; i < s.size(); i++) {
				s[i] = std::toupper(s[i]);
				std::cout << s[i];
			}

		}
	}

	std::cout << std::endl;
	return (0);
}
