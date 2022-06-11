#include <iostream>
#include <CLI/CLI.hpp>
// #include "./main/run.hpp"


int main(int argc, char** argv) {
	CLI::App app{"Consensus Problem"};
	std::string linearSystemSolvingMethod;
	app.add_option("--linear-system-solving-method", linearSystemSolvingMethod, "Linear system solving method");
	std::string linearSystemDatatype;
	app.add_option("--linear-system-datatype", linearSystemDatatype, "Linear system datatype");
	CLI11_PARSE(app, argc, argv);
	// run(linearSystemSolvingMethod, linearSystemDatatype);
	return 0;
}
