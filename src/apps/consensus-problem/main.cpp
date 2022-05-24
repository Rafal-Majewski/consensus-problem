#include <iostream>
#include <CLI/CLI.hpp>




int main(int argc, char** argv) {
	CLI::App app{"Consensus Problem"};
	std::string linearSystemSolvingMethod;
	app.add_option("--linear-system-solving-method", linearSystemSolvingMethod, "Linear system solving method");
	std::string linearSystemDatatype;
	app.add_option("--linear-system-datatype", linearSystemDatatype, "Linear system datatype");
	std::string calculatingMethod;
	app.add_option("--calculating-method", calculatingMethod, "Calculating method");
	CLI11_PARSE(app, argc, argv);

	return 0;
}
