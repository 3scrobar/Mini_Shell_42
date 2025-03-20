
#include "minishell.h"

#define HIST_FILE "./my_history.txt"
#define HIST_SIZE 1000

//Setup history with file and line limits and use it.
void setup_history(void)
{
	int fd;

	fd = open(HIST_FILE, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		perror("Error opening file");
	close(fd);
	// Initialiser readline pour utiliser l'historique
	using_history();
	// Limiter la taille de l'historique
	stifle_history(HIST_SIZE);
}

void save_history(void)
{
	// Sauvegarder l'historique dans le fichier d'historique
	if (write_history(HIST_FILE) != 0)
		perror("write_history");
}

char	*make_prompt(void)
{
	char	*user;
	char	*cur_path;
	char	*tmp;
	char	*prompt;

	prompt = GREEN;
	user = get_username();
	user = ft_strjoin(user, "@minishell" WHITE ":" BLUE);
	prompt = ft_strjoin(prompt, user);
	free(user);
	cur_path = getcwd(NULL, 0);
	if (cur_path == NULL)
		cur_path = ft_strdup("??");
	tmp = prompt;
	prompt = ft_strjoin(prompt, cur_path);
	free(tmp);
	free(cur_path);
	tmp = prompt;
	prompt = ft_strjoin(prompt, WHITE "$ ");
	free(tmp);
	return (prompt);
}

char	*get_username(void)
{
	char	*name;

	name = getenv("USERNAME");
	if (!name)
	{
		name = getenv("USER");
		if (!name)
		{
			name = getenv("LOGNAME");
			if (!name)
			{
				perror("couldnt retrieve username");
				name = "NULL";
			}
		}
	}
	return (name);
}
