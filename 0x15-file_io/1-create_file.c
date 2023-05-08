#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL) /* check if filename is NULL */
		return (-1);

	if (text_content != NULL) /* check if text_content is not NULL */
	{
		while (text_content[len]) /* calculate the length of text_content */
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600); /* create or truncate file with rw------- permissions */
	w = write(fd, text_content, len); /* write text_content to file */

	if (fd == -1 || w == -1) /* check if file creation or writing failed */
		return (-1);

	close(fd); /* close file */

	return (1); /* return success */
}
