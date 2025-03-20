#ifndef MINISHELL_H
# define MINISHELL_H
/*----------------------------DEFINES----------------------------------------*/
#define HIST_FILE "./my_history.txt"
#define HIST_SIZE 1000

/*----------------------------INCLUDES---------------------------------------*/
#include "color.h"
#include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>

/*****************************FUNCTION****************************************/
/*----------------------------READLINE---------------------------------------*/
void	save_history(void);
void	setup_history();
char	*get_username(void);
char	*make_prompt(void);
/*-----------------------------EXECUTE---------------------------------------*/
char	*find_path(char *cmd, char **envp);


#endif
