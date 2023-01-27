/*The main function starts by checking if there is an input provided by the user. If there is no input, it tells the user to provide one and returns an error code of 1.

If an input is provided, it is stored in a string variable called "input".

Then, the code checks the length of the input string. If the length is 1, it is assumed to be a char literal and the function "handleCharLiteral" is called with the input as an argument.

If the length is not 1, the code checks if the input string contains a "." character. If it does not, it is assumed to be an int literal and the function "handleIntLiteral" is called with the input as an argument.

If the input string contains a "." and a "f" character, it is assumed to be a float literal and the function "handleFloatLiteral" is called with the input as an argument.

If the input string contains a "." but no "f", it is assumed to be a double literal and the function "handleDoubleLiteral" is called with the input as an argument.

The main function then returns 0, indicating that the program has completed successfully.

The four functions handleCharLiteral, handleIntLiteral, handleFloatLiteral, handleDoubleLiteral are not implemented yet. They should contain the logic for converting the input to the corresponding type, and printing the results.




*/