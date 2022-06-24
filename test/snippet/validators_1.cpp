#include <sharg/all.hpp>

int main(int argc, char const ** argv)
{
    sharg::parser myparser{"Test", argc, argv}; // initialize

    //![validator_call]
    int myint;
    sharg::arithmetic_range_validator my_validator{2, 10};

    myparser.add_option(myint,
                        sharg::config{.short_id = 'i',
                                      .long_id = "integer",
                                      .description = "Give me a number.",
                                      .validator = my_validator});
    //![validator_call]

    // an exception will be thrown if the user specifies an integer
    // that is not in range [2,10] (e.g. "./test_app -i 15")
    try
    {
        myparser.parse();
    }
    catch (sharg::parser_error const & ext) // the user did something wrong
    {
        std::cerr << "[PARSER ERROR] " << ext.what() << "\n"; // customize your error message
        return -1;
    }

    std::cerr << "integer given by user passed validation: " << myint << "\n";
    return 0;
}
