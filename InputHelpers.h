/* This InputHelpers.h serves in helping remove code from the main program and declares several functions
 * that help with input.
 */

#ifndef AIRGEAD_BANKING_INPUT_HELPERS_H_
#define AIRGEAD_BANKING_INPUT_HELPERS_H_

#include <string>

// removes remaining code that was causing errors with the user input
void clearInputBuffer();

bool getDoubleInput(const std::string& t_prompt, double& t_value);

bool getIntInput(const std::string& t_prompt, int& t_value);

#endif // AIRGEAD_BANKING_INPUT_HELPERS_H_
