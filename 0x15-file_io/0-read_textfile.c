#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - creates a file
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd; /* file descriptor */
	ssize_t bytes_written; /* number of bytes written */

	if (filename == NULL) /* check if filename is NULL */
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600); /* create or truncate file with rw------- permissions */

	if (fd == -1) /* check if file creation or opening failed */
		return (-1);

	if (text_content != NULL) /* check if text_content is not NULL */
	{
		bytes_written = write(fd, text_content, strlen(text_content)); /* write text_content to file */

		if (bytes_written == -1) /* check if write failed */
		{
			close(fd); /* close file */
			return (-1);
		}
	}

	close(fd); /* close file */
	return (1); /* return success */
}
