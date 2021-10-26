#include "get_next_line.h"

int	find_newline(int fd, char **line, char **st_arr, char *buf)
{
	int		ret;
	size_t	len;
	char	*tmp_line;
	char	*tmp_buf;

	ret = 0;
	len = gnl_strchar(buf, '\n');
	tmp_line = gnl_strnjoin(*line, buf, len);
	if (tmp_line == NULL)
		return (-1);
	free(*line);
	*line = tmp_line;
	tmp_buf = NULL;
	if (buf[len] == '\n')
	{
		tmp_buf = gnl_strdup(buf + len + 1);
		if (tmp_buf == NULL)
			return (-1);
		ret = 1;
	}
	free(st_arr[fd]);
	st_arr[fd] = tmp_buf;
	return (ret);
}

int	read_fd(int fd, char **line, char **st_arr)
{
	ssize_t	read_len;
	char	*buf;
	int		ret;

	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (buf == NULL)
		return (-1);
	ret = 0;
	while (ret == 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len <= 0)
			break ;
		buf[read_len] = '\0';
		ret = find_newline(fd, line, st_arr, buf);
	}
	free(buf);
	if (read_len == -1)
		return (gnl_free_all(line, st_arr, fd));
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*st_arr[256];
	int			ret;

	ret = 0;
	if (fd < 0 || 256 <= fd || !line)
		return (-1);
	*line = (char *)malloc(1);
	if (*line == NULL)
		return (-1);
	*line[0] = '\0';
	if (st_arr[fd] != NULL)
		ret = find_newline(fd, line, st_arr, st_arr[fd]);
	if (ret == 0)
		ret = read_fd(fd, line, st_arr);
	return (ret);
}

int	gnl_free_all(char **line, char **sv, int fd)
{
	free(*line);
	*line = NULL;
	free(sv[fd]);
	sv[fd] = NULL;
	return (-1);
}
