#ifndef USER_INPUT_H
    #define USER_INPUT_H

    typedef enum
    {
	    INPUT_SUCCESSFUL,
	    INPUT_TOOLONG,
        INPUT_FAILED
    } input_status;

void flush_input();

input_status get_user_input(const char *prompt, char *user_input, size_t size);

#endif
