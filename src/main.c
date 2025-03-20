#include "minishell.h"








int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	char * prompt;
	char *line;

	setup_history();
	while(1)
	{
		prompt = make_prompt();
		line = readline(prompt);
		if (prompt)
			free(prompt);
		if (!line)
			break ;
		if (line[0] != '\0')
		{
			add_history(line);
			printf("%s\n",line);
		}
		free(line);
	}
	save_history();
	return(0);
}
